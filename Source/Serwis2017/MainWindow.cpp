#include "MainWindow.h"
namespace Serwis2017 {
	Void MainWindow::btnCommitPassChange_Show()
	{
		if (tab0TextOldPassword->Text != "" && tab0TextNewPassword->Text != "" && tab0TextNewPassword2->Text == tab0TextNewPassword->Text)
			tab0BtnCommitPassChange->Enabled = true;
		else
			tab0BtnCommitPassChange->Enabled = false;
	}

	Void MainWindow::btnCommitPassChange_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("UPDATE `gabinet`.`uzytkownik` SET `haslo`=password('" + tab0TextNewPassword2->Text + "') WHERE `uzytkownik_id`='" + userId + "' AND `haslo`=password('" + tab0TextOldPassword->Text + "');", db);
		try
		{
			db->Open();
			if (query->ExecuteNonQuery())
				MessageBox::Show("has³o zmieniono");
			else
				MessageBox::Show("podane has³o jest niepoprawne");
			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}

	Void MainWindow::btnSearch_Click(System::Object^  sender, System::EventArgs^  e)
	{
		userSearch(tab1TextSearch, tab1DgvUsers);
	}

	Void MainWindow::dgvUsers_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if (e->RowIndex >= 0)
		{
			recordId = Convert::ToInt32(tab1DgvUsers->Rows[e->RowIndex]->Cells[0]->Value);
			tab1TextFirstName->Text = tab1DgvUsers->Rows[e->RowIndex]->Cells["Imie"]->Value->ToString();
			tab1TextSecondName->Text = tab1DgvUsers->Rows[e->RowIndex]->Cells["Nazwisko"]->Value->ToString();
			tab1TextUserName->Text = tab1DgvUsers->Rows[e->RowIndex]->Cells["Nazwa uzytkownika"]->Value->ToString();
			tab1CbPracownik->Checked = Convert::ToBoolean(tab1DgvUsers->Rows[e->RowIndex]->Cells["Pracownik"]->Value->ToString());

			tab1BtnDelete->Enabled = true;
			tab1BtnModify->Enabled = true;

			if (tab1CbPracownik->Checked)
			{
				clearBox(tab1GbHours);
				MySqlConnection^ db = gcnew MySqlConnection(config);
				MySqlCommand^ query = gcnew MySqlCommand("Select * from godziny where uzytkownik_id = '" + recordId + "';", db);
				MySqlDataReader^ data;

				try
				{
					db->Open();

					data = query->ExecuteReader();
					while (data->Read())
					{
						tab1text1start->Text = data->GetString("pon_od");
						tab1text1end->Text = data->GetString("pon_do");
						tab1text2start->Text = data->GetString("wt_od");
						tab1text2end->Text = data->GetString("wt_do");
						tab1text3start->Text = data->GetString("sr_od");
						tab1text3end->Text = data->GetString("sr_do");
						tab1text4start->Text = data->GetString("cz_od");
						tab1text4end->Text = data->GetString("cz_do");
						tab1text5start->Text = data->GetString("pt_od");
						tab1text5end->Text = data->GetString("pt_do");
						tab1text6start->Text = data->GetString("so_od");
						tab1text6end->Text = data->GetString("so_do");
					}

					db->Close();
				}
				catch (Exception^ err)
				{
					MessageBox::Show(err->Message);
				}
			}
		}
	}

	Void MainWindow::tab1BtnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		if (tab1TextFirstName->Text->Length < 3 || tab1TextSecondName->Text->Length < 4 || tab1TextUserName->Text->Length < 4)
			MessageBox::Show("Uzupe³nij dane!");
		else
		{
			userType();

			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				query->CommandText = "insert into uzytkownik set imie = '" + tab1TextFirstName->Text + "', nazwisko = '" + tab1TextSecondName->Text + "', uzytkownik_nazwa = '" + tab1TextUserName->Text + "', haslo = password('" + tab1TextUserName->Text + "'), pracownik = '" + pracownik + "';";
				query->ExecuteNonQuery();

				if (tab1CbPracownik->Checked)
				{
					query->CommandText = "insert into godziny set uzytkownik_id = last_insert_id(), pon_od = '" + tab1text1start->Text + "', pon_do = '" + tab1text1end->Text + "', wt_od = '" + tab1text2start->Text + "', wt_do = '" + tab1text2end->Text + "', sr_od = '" + tab1text3start->Text + "', sr_do = '" + tab1text3end->Text + "', cz_od = '" + tab1text4start->Text + "', cz_do = '" + tab1text4end->Text + "', pt_od = '" + tab1text5start->Text + "', pt_do = '" + tab1text5end->Text + "', so_od = '" + tab1text6start->Text + "', so_do = '" + tab1text6end->Text + "';";
					query->ExecuteNonQuery();
				}

				transaction->Commit();
				MessageBox::Show("Zaktualizowano dane!");
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
		}
		showGrid();
	}
	Void MainWindow::tab1BtnModify_Click(System::Object^  sender, System::EventArgs^  e) {
		if (tab1TextFirstName->Text->Length < 3 || tab1TextSecondName->Text->Length < 4 || tab1TextUserName->Text->Length < 4)
			MessageBox::Show("Uzupe³nij dane!");
		else
		{
			userType();

			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				query->CommandText = "select * from godziny where uzytkownik_id = '" + recordId + "';";
				MySqlDataReader^ result = query->ExecuteReader();
				result->Close();

				if (result->HasRows && tab1CbPracownik->Checked)
				{
					query->CommandText = "update godziny set pon_od = '" + tab1text1start->Text + "', pon_do = '" + tab1text1end->Text + "', wt_od = '" + tab1text2start->Text + "', wt_do = '" + tab1text2end->Text + "', sr_od = '" + tab1text3start->Text + "', sr_do = '" + tab1text3end->Text + "', cz_od = '" + tab1text4start->Text + "', cz_do = '" + tab1text4end->Text + "', pt_od = '" + tab1text5start->Text + "', pt_do = '" + tab1text5end->Text + "', so_od = '" + tab1text6start->Text + "', so_do = '" + tab1text6end->Text + "' where uzytkownik_id = '" + recordId + "';";
					query->ExecuteNonQuery();
				}
				else if (tab1CbPracownik->Checked)
				{
					query->CommandText = "insert into godziny set uzytkownik_id = '" + recordId + "', pon_od = '" + tab1text1start->Text + "', pon_do = '" + tab1text1end->Text + "', wt_od = '" + tab1text2start->Text + "', wt_do = '" + tab1text2end->Text + "', sr_od = '" + tab1text3start->Text + "', sr_do = '" + tab1text3end->Text + "', cz_od = '" + tab1text4start->Text + "', cz_do = '" + tab1text4end->Text + "', pt_od = '" + tab1text5start->Text + "', pt_do = '" + tab1text5end->Text + "', so_od = '" + tab1text6start->Text + "', so_do = '" + tab1text6end->Text + "';";
					query->ExecuteNonQuery();
				}

				query->CommandText = "update uzytkownik set imie = '" + tab1TextFirstName->Text + "', nazwisko = '" + tab1TextSecondName->Text + "', uzytkownik_nazwa = '" + tab1TextUserName->Text + "', pracownik = '" + pracownik + "' where uzytkownik_id = " + recordId + ";";
				query->ExecuteNonQuery();
				transaction->Commit();

				MessageBox::Show("Zmodyfikowane dane!");
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
		}
		showGrid();
	}
	Void MainWindow::tab1BtnDelete_Click(System::Object^  sender, System::EventArgs^  e) {
		if (recordId == 1)
			MessageBox::Show("Nie mo¿na usun¹æ g³ównego u¿ytkownika!");
		else
		{
			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				if (MessageBox::Show("Definitywnie?", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					query->CommandText = "delete from godziny where uzytkownik_id = " + recordId + ";";
					query->ExecuteNonQuery();
					query->CommandText = "delete from uzytkownik where uzytkownik_id = " + recordId + ";";
					query->ExecuteNonQuery();
					transaction->Commit();

					MessageBox::Show("Usunieto dane!");
				}
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
		}
		showGrid();
	}

	System::Void MainWindow::tab2BtnSearch_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		fillGrid(tab2TextSearch, tab2Dgv);
	}

	System::Void MainWindow::tab2BtnDelete_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		db->Open();

		MySqlCommand^ query = db->CreateCommand();
		MySqlTransaction^ transaction;

		transaction = db->BeginTransaction();
		query->Connection = db;
		query->Transaction = transaction;

		try
		{
			if (MessageBox::Show("Definitywnie?", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				query->CommandText = "delete from uslugi where uslugi_id = " + recordId + ";";
				query->ExecuteNonQuery();
				transaction->Commit();

				MessageBox::Show("Usunieto dane!");
			}
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();

		fillGrid(tab2TextSearch, tab2Dgv);
		clearBox(tab2Gb);
	}

	System::Void MainWindow::tab2BtnModify_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (tab2TextName->Text->Length < 3 || tab2TextPrice->Text->Length < 1 || tab2TextTime->Text->Length < 5)
			MessageBox::Show("Uzupe³nij dane!");
		else
		{
			userType();

			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				String^ price = tab2TextPrice->Text->Replace(",", ".");
				query->CommandText = "update uslugi set nazwa = '" + tab2TextName->Text + "', cena = '" + price + "', czas = '" + tab2TextTime->Text + "', opis = '" + tab2TextDesc->Text + "' where uslugi_id = " + recordId + ";";
				query->ExecuteNonQuery();
				transaction->Commit();

				MessageBox::Show("Zmodyfikowane dane!");
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
		}
		fillGrid(tab2TextSearch, tab2Dgv);
	}

	System::Void MainWindow::tab2BtnAdd_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (tab2TextName->Text->Length < 3 || tab2TextPrice->Text->Length < 1 || tab2TextTime->Text->Length < 5)
			MessageBox::Show("Uzupe³nij dane!");
		else
		{
			userType();

			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				String^ price = tab2TextPrice->Text->Replace(",", ".");
				query->CommandText = "insert into uslugi set nazwa = '" + tab2TextName->Text + "', cena = '" + price + "', czas = '" + tab2TextTime->Text + "', opis = '" + tab2TextDesc->Text + "'  ;";
				query->ExecuteNonQuery();

				transaction->Commit();
				MessageBox::Show("Zaktualizowano dane!");
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
		}
		fillGrid(tab2TextSearch, tab2Dgv);
	}

	System::Void MainWindow::tab2Dgv_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		if (e->RowIndex >= 0)
		{
			recordId = Convert::ToInt32(tab2Dgv->Rows[e->RowIndex]->Cells[0]->Value);
			tab2TextName->Text = tab2Dgv->Rows[e->RowIndex]->Cells["nazwa"]->Value->ToString();
			tab2TextPrice->Text = tab2Dgv->Rows[e->RowIndex]->Cells["cena"]->Value->ToString();
			tab2TextTime->Text = tab2Dgv->Rows[e->RowIndex]->Cells["czas"]->Value->ToString();
			tab2TextDesc->Text = tab2Dgv->Rows[e->RowIndex]->Cells["opis"]->Value->ToString();

			tab2BtnDelete->Enabled = true;
			tab2BtnModify->Enabled = true;
		}
	}

	System::Void MainWindow::tab3BtnSearch_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		userSearch(tab3TextSearch, tab3DgvUsers);
	}

	System::Void MainWindow::tab3DgvUsers_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		if (e->RowIndex >= 0)
			showUslugi(e->RowIndex);
	}

	System::Void MainWindow::tab3DgvUslugi_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		if (e->RowIndex >= 0)
		{
			uslugaId = Convert::ToInt32(tab3DgvUslugi->Rows[e->RowIndex]->Cells[0]->Value);

			if (MessageBox::Show("Czy chcesz dodaæ us³ugê pracownikowi?", "Uwaga", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				MySqlConnection^ db = gcnew MySqlConnection(config);

				db->Open();

				MySqlCommand^ query = db->CreateCommand();
				MySqlTransaction^ transaction;

				transaction = db->BeginTransaction();
				query->Connection = db;
				query->Transaction = transaction;

				try
				{
					String^ price = tab2TextPrice->Text->Replace(",", ".");
					query->CommandText = "insert into uzytkownik_usluga set uzytkownik_id = '" + recordId + "', uslugi_id = '" + uslugaId + "';";
					query->ExecuteNonQuery();

					transaction->Commit();
					MessageBox::Show("Zaktualizowano dane!");
				}
				catch (Exception^ err)
				{
					MessageBox::Show(err->Message);
					transaction->Rollback();
				}

				db->Close();
				showUslugi(e->RowIndex);
			}
		}
	}

	System::Void MainWindow::tab3DgvWork_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		if (e->RowIndex >= 0)
		{
			uslugaId = Convert::ToInt32(tab3DgvWork->Rows[e->RowIndex]->Cells[0]->Value);
			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				if (MessageBox::Show("Definitywnie?", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					query->CommandText = "delete from uzytkownik_usluga where uslugi_id = " + uslugaId + " and uzytkownik_id = " + recordId + ";";
					query->ExecuteNonQuery();
					transaction->Commit();

					MessageBox::Show("Usunieto dane!");
				}
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();

			showUslugi(e->RowIndex);
		}
	}

	System::Void MainWindow::tab4BtnSearch_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		updateKlienci();
	}

	System::Void MainWindow::tab4BtnAdd_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (tab4TextFirstName->Text->Length < 3 || tab4TextSecondName->Text->Length < 4)
			MessageBox::Show("Uzupe³nij dane!");
		else
		{
			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				query->CommandText = "insert into klienci set imie = '" + tab4TextFirstName->Text + "', nazwisko = '" + tab4TextSecondName->Text + "', email ='" + tab4TextEmail->Text + "', telefon = '" + tab4TextPhone->Text + "', ulica = '" + tab4TextStreet->Text + "', numer = '" + tab4TextNumber->Text + "', miejscowosc = '" + tab4TextCity->Text + "', poczta = '" + tab4TextPostal->Text + "';";
				query->ExecuteNonQuery();
				transaction->Commit();
				MessageBox::Show("Zaktualizowano dane!");
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
			updateKlienci();
			clearBox(tab4GbClient);
		}
	}

	System::Void MainWindow::tab4BtnModify_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (tab4TextFirstName->Text->Length < 3 || tab4TextSecondName->Text->Length < 4)
			MessageBox::Show("Uzupe³nij dane!");
		else
		{
			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = db->CreateCommand();
			MySqlTransaction^ transaction;

			transaction = db->BeginTransaction();
			query->Connection = db;
			query->Transaction = transaction;

			try
			{
				query->CommandText = "update klienci set imie = '" + tab4TextFirstName->Text + "', nazwisko = '" + tab4TextSecondName->Text + "', email ='" + tab4TextEmail->Text + "', telefon = '" + tab4TextPhone->Text + "', ulica = '" + tab4TextStreet->Text + "', numer = '" + tab4TextNumber->Text + "', miejscowosc = '" + tab4TextCity->Text + "', poczta = '" + tab4TextPostal->Text + "' where klienci_id = " + recordId + ";";
				query->ExecuteNonQuery();
				transaction->Commit();

				MessageBox::Show("Zmodyfikowane dane!");
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
		}
		updateKlienci();
		clearBox(tab4GbClient);
	}

	System::Void MainWindow::tab4BtnDelete_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		db->Open();

		MySqlCommand^ query = db->CreateCommand();
		MySqlTransaction^ transaction;

		transaction = db->BeginTransaction();
		query->Connection = db;
		query->Transaction = transaction;

		try
		{
			if (MessageBox::Show("Definitywnie?", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				query->CommandText = "delete from klienci where klienci_id = " + recordId + ";";
				query->ExecuteNonQuery();
				transaction->Commit();

				MessageBox::Show("Usunieto dane!");
			}
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
		updateKlienci();
	}

	System::Void MainWindow::tab4DgvClients_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		if (e->RowIndex >= 0)
		{
			recordId = Convert::ToInt32(tab4DgvClients->Rows[e->RowIndex]->Cells[0]->Value);
			tab4TextFirstName->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
			tab4TextSecondName->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
			tab4TextEmail->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["email"]->Value->ToString();
			tab4TextPhone->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["telefon"]->Value->ToString();
			tab4TextStreet->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["ulica"]->Value->ToString();
			tab4TextNumber->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["numer"]->Value->ToString();
			tab4TextCity->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["miejscowosc"]->Value->ToString();
			tab4TextPostal->Text = tab4DgvClients->Rows[e->RowIndex]->Cells["poczta"]->Value->ToString();

			tab4BtnDelete->Enabled = true;
			tab4BtnModify->Enabled = true;
		}
	}

	Void MainWindow::showGrid()
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select uzytkownik_id, imie as Imie, nazwisko as Nazwisko, pracownik as Pracownik, uzytkownik_nazwa as `Nazwa uzytkownika` from uzytkownik order by nazwisko;", db);

		try
		{
			db->Open();
			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			tab1DgvUsers->DataSource = source;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
	Void MainWindow::userType()
	{
		if (tab1CbPracownik->Checked)
			pracownik = 1;
		else
			pracownik = 0;
	}

	Void MainWindow::clearBox(Control^ list) {

		for each(Control^ textBox in list->Controls)
		{
			if (textBox->GetType() == TextBox::typeid)
				textBox->Text = "";
			else if (textBox->GetType() == MaskedTextBox::typeid)
				textBox->Text = "";
		}
	}
	Void MainWindow::fillBoxWithWorkTime(int beginTime)
	{
		array<TextBox^>^ startBox = { tab1text1start, tab1text2start, tab1text3start,  tab1text4start,  tab1text5start,  tab1text6start };
		array<TextBox^>^ endBox = { tab1text1end, tab1text2end, tab1text3end, tab1text4end, tab1text5end, tab1text6end };
		for (int i = 0; i < 6; i++)
		{
			startBox[i]->Text = beginTime + ":00";
			endBox[i]->Text = (beginTime + 8) + ":00";
		}

	}
	Void MainWindow::fillGrid(TextBox ^ textBox, DataGridView ^ dataGrid)
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select * from uslugi where nazwa like  '%" + textBox->Text + "%' order by nazwa;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			dataGrid->DataSource = source;
			dataGrid->Columns[0]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
	Void MainWindow::userSearch(TextBox ^ textBox, DataGridView ^ dataGrid)
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select uzytkownik_id, imie as Imie, nazwisko as Nazwisko, pracownik as Pracownik, uzytkownik_nazwa as `Nazwa uzytkownika` from uzytkownik where concat(imie, ' ', nazwisko, ' ', uzytkownik_nazwa) like  '%" + textBox->Text + "%' order by nazwisko;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			dataGrid->DataSource = source;
			dataGrid->Columns[0]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
	Void MainWindow::showUslugi(int rowIndex)
	{
		recordId = Convert::ToInt32(tab3DgvUsers->Rows[rowIndex]->Cells[0]->Value);
		tab3TextFirstName->Text = tab3DgvUsers->Rows[rowIndex]->Cells["Imie"]->Value->ToString();
		tab3TextSecondName->Text = tab3DgvUsers->Rows[rowIndex]->Cells["Nazwisko"]->Value->ToString();

		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select uslugi.uslugi_id, uslugi.nazwa, uslugi.cena, uslugi.czas from uslugi, uzytkownik_usluga where uslugi.uslugi_id = uzytkownik_usluga.uslugi_id and uzytkownik_usluga.uzytkownik_id = " + recordId + " order by uslugi.nazwa;", db);

		try
		{
			db->Open();
			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			tab3DgvWork->DataSource = source;
			tab3DgvWork->Columns[0]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}

		query = gcnew MySqlCommand("Select * from uslugi order by uslugi.nazwa;", db);

		try
		{
			db->Open();
			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			tab3DgvUslugi->DataSource = source;
			tab3DgvUslugi->Columns[0]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
	Void MainWindow::updateKlienci()
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select * from klienci where concat(imie, ' ', nazwisko, ' ', miejscowosc) like  '%" + tab4TextSearch->Text + "%' order by nazwisko;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			tab4DgvClients->DataSource = source;
			tab4DgvClients->Columns[0]->Visible = false;
			tab4DgvClients->Columns[9]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
}

