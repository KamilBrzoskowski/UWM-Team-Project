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
				int hasRow = result->HasRows;
				result->Close();

				if (hasRow && tab1CbPracownik->Checked)
				{
					query->CommandText = "update godziny set pon_od = '" + tab1text1start->Text + "', pon_do = '" + tab1text1end->Text + "', wt_od = '" + tab1text2start->Text + "', wt_do = '" + tab1text2end->Text + "', sr_od = '" + tab1text3start->Text + "', sr_do = '" + tab1text3end->Text + "', cz_od = '" + tab1text4start->Text + "', cz_do = '" + tab1text4end->Text + "', pt_od = '" + tab1text5start->Text + "', pt_do = '" + tab1text5end->Text + "', so_od = '" + tab1text6start->Text + "', so_do = '" + tab1text6end->Text + "' where uzytkownik_id = '" + recordId + "';";
					query->ExecuteNonQuery();
				}
				else if (hasRow == false && tab1CbPracownik->Checked)
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
					query->CommandText = "delete from uzytkownik_usluga where uzytkownik_id = " + recordId + ";";
					query->ExecuteNonQuery();
					query->CommandText = "delete from wizyty where uzytkownik_id = " + recordId + ";";
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

	System::Void MainWindow::tab1CbPracownik_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (tab1CbPracownik->Checked)
			tab1GbHours->Visible = true;
		else
			tab1GbHours->Visible = false;
		clearBox(tab1GbHours);
	}

	System::Void MainWindow::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		fillBoxWithWorkTime(7);
	}

	System::Void MainWindow::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		fillBoxWithWorkTime(8);
	}

	System::Void MainWindow::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		fillBoxWithWorkTime(9);
	}

	System::Void MainWindow::button4_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		fillBoxWithWorkTime(10);
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
				query->CommandText = "delete from uzytkownik_uslugi where uslugi_id = " + recordId + ";";
				query->ExecuteNonQuery();
				query->CommandText = "delete from wizyty where uslugi_id = " + recordId + ";";
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
		updateKlienci(tab4TextSearch, tab4DgvClients);
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
			updateKlienci(tab4TextSearch, tab4DgvClients);
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
		updateKlienci(tab4TextSearch, tab4DgvClients);
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
				query->CommandText = "delete from wizyty where klienci_id = " + recordId + ";";
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
		updateKlienci(tab4TextSearch, tab4DgvClients);
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

	System::Void MainWindow::tav5BtnSearchUser_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		userSearch(tab5TextSearchUser, tab5DgvUsers);
	}

	System::Void MainWindow::tab5BtnSearchClient_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		updateKlienci(tab5TextSearchClient, tab5DgvClient);
	}

	System::Void MainWindow::tab5BtnUslugaSearch_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		fillGrid(tab5TextSearchUsluga, tab5DgvUsluga);
	}

	System::Void MainWindow::tab5DgvUsluga_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		if (e->RowIndex >= 0)
		{
			uslugaId = Convert::ToInt32(tab5DgvUsluga->Rows[e->RowIndex]->Cells[0]->Value);
			tab5TextUslugaChoosen->Text = tab5DgvUsluga->Rows[e->RowIndex]->Cells["nazwa"]->Value->ToString();

			MySqlConnection^ db = gcnew MySqlConnection(config);
			MySqlCommand^ query = gcnew MySqlCommand("Select uzytkownik.uzytkownik_id, uzytkownik.imie as Imie, uzytkownik.nazwisko as Nazwisko, uzytkownik.pracownik as Pracownik, uzytkownik.uzytkownik_nazwa as `Nazwa uzytkownika` from uzytkownik, uzytkownik_usluga where uzytkownik.uzytkownik_id = uzytkownik_usluga.uzytkownik_id and uzytkownik_usluga.uslugi_id = " + uslugaId + " and uzytkownik.pracownik = 1 order by Nazwisko;", db);

			try
			{
				db->Open();

				MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
				adapter->SelectCommand = query;
				DataTable^ table = gcnew DataTable();
				adapter->Fill(table);

				BindingSource^ source = gcnew BindingSource();
				source->DataSource = table;
				tab5DgvUsers->DataSource = source;
				tab5DgvUsers->Columns[0]->Visible = false;

				db->Close();
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
			}
		}
	}

	System::Void MainWindow::tab5DgvClient_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		if (e->RowIndex >= 0)
		{
			clientId = Convert::ToInt32(tab5DgvClient->Rows[e->RowIndex]->Cells[0]->Value);
			tab5TextClientChoosen->Text = tab5DgvClient->Rows[e->RowIndex]->Cells["imie"]->Value->ToString() + " " + tab5DgvClient->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
		}
	}

	System::Void MainWindow::tab5DgvUsers_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
	{
		monthCalendar1->Enabled = true;
		recordId = e->RowIndex;
		userId = recordId;
		showTermin();
	}

	System::Void MainWindow::monthCalendar1_DateSelected(System::Object ^ sender, System::Windows::Forms::DateRangeEventArgs ^ e)
	{
		dateChoosen = String::Format(e->Start.ToShortDateString());
		tab5TextTimeChoosen->Text = dateChoosen;
		showTermin();
	}

	System::Void MainWindow::tab5BtnAdd_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (clientId <= 0 || userId <= 0 || uslugaId <= 0 || tab5TextTimeChoosen->Text->Length < 14)
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
				DateTime^ startTime = Convert::ToDateTime(dateChoosen + " " + hourChoosen);
				query->CommandText = "insert into wizyty set klienci_id = '" + clientId + "', uslugi_id = '" + uslugaId + "', uzytkownik_id = '" + userId + "', rezerwacja_od = '" + startTime + "', rezerwacja_do = '" + startTime + "', status = 'oczekuje';";
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
			showTermin();
		}
	}

	System::Void MainWindow::tab5BtnModify_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (clientId <= 0 || userId <= 0 || uslugaId <= 0 || tab5TextTimeChoosen->Text->Length < 14)
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
				query->CommandText = "update wizyty set klienci_id = '" + clientId + "', uslugi_id = '" + uslugaId + "', uzytkownik_id = '" + userId + "', status = 'oczekuje' where wizyty_id = " + wizytaId + ";";
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
			showTermin();
		}
		
	}

	System::Void MainWindow::tab5BtnDelete_Click(System::Object ^ sender, System::EventArgs ^ e)
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
				query->CommandText = "delete from wizyty where wizyty_id = " + wizytaId + ";";
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
		showTermin();
	}

	System::Void MainWindow::toolStripButton1_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->tabControl1->SelectedTab = this->tabPage1;
	}

	System::Void MainWindow::toolStripButton4_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->tabControl1->SelectedTab = this->tabPage6;
	}

	System::Void MainWindow::toolStripButton2_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->tabControl1->SelectedTab = this->tabPage5;
	}

	System::Void MainWindow::toolStripButton3_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->tabControl1->SelectedTab = this->tabPage4;
	}

	System::Void MainWindow::toolStripButton5_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->tabControl1->SelectedTab = this->tabPage3;
	}

	System::Void MainWindow::toolStripButton6_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->tabControl1->SelectedTab = this->tabPage2;
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
	Void MainWindow::updateKlienci(TextBox^ textBox, DataGridView^ dataGrid)
	{
		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select * from klienci where concat(imie, ' ', nazwisko, ' ', miejscowosc) like  '%" + textBox->Text + "%' order by nazwisko;", db);

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
			dataGrid->Columns[9]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}

	Void MainWindow::textBoxClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		TextBox^ textBox = safe_cast<TextBox^> (sender);
		hourChoosen = textBox->Text;
		tab5TextTimeChoosen->Text = dateChoosen + " " + hourChoosen;

		wizytaId = Convert::ToInt32(textBox->Tag);
		
		if (textBox->BackColor == System::Drawing::Color::Red)
		{
			try
			{
				MySqlConnection^ db = gcnew MySqlConnection(config);
				db->Open();
				MySqlCommand^ query = gcnew MySqlCommand("select concat(klienci.imie, ' ', klienci.nazwisko) as klient, wizyty.klienci_id, wizyty.uzytkownik_id, wizyty.uslugi_id, wizyty.uslugi_id, uslugi.nazwa from wizyty, klienci, uslugi where wizyty.wizyty_id = " + wizytaId + " and klienci.klienci_id = wizyty.klienci_id and uslugi.uslugi_id = wizyty.uslugi_id ;", db);
				MySqlDataReader^ data;
				data = query->ExecuteReader();
				data->Read();

				tab5TextClientChoosen->Text = data->GetString("klient");
				tab5TextUslugaChoosen->Text = data->GetString("nazwa");

				uslugaId = data->GetInt32("uslugi_id");
				clientId = data->GetInt32("klienci_id");
				userId = data->GetInt32("uzytkownik_id");
				db->Close();
			}
			catch (Exception^ err)
			{
				MessageBox::Show("error in textBoxClick: " + err->Message);
			}
			tab5BtnDelete->Enabled = true;
			tab5BtnModify->Enabled = true;
		}
		else if (textBox->BackColor == System::Drawing::Color::White)
		{
			tab5TextClientChoosen->Text = "";
			tab5TextUslugaChoosen->Text = "";
			tab5BtnDelete->Enabled = false;
			tab5BtnModify->Enabled = false;
		}
	}

	Void MainWindow::showTermin()
	{
		if (recordId >= 0)
		{
			userId = Convert::ToInt32(tab5DgvUsers->Rows[recordId]->Cells[0]->Value);
			String^ workStart;
			String^ workEnd;
			int startHour;
			int stopHour;
			String^ klient = "";
			String^ usluga = "";

			DateTime^ dayOfWeek = Convert::ToDateTime(dateChoosen);
			int Day = Convert::ToInt32(dayOfWeek->DayOfWeek);


			tab5GbHours->Controls->Clear();

			switch (Day) {
			case 1:
				workStart = "pon_od";
				workEnd = "pon_do";
				break;
			case 2:
				workStart = "wt_od";
				workEnd = "wt_do";
				break;
			case 3:
				workStart = "sr_od";
				workEnd = "sr_do";
				break;
			case 4:
				workStart = "cz_od";
				workEnd = "cz_do";
				break;
			case 5:
				workStart = "pt_od";
				workEnd = "pt_do";
				break;
			case 6:
				workStart = "so_od";
				workEnd = "so_do";
				break;
			case 0:
				MessageBox::Show("Niedziela jest dniem wolnym");
				workStart = "pon_od";
				workEnd = "pon_do";
			}

			MySqlConnection^ db = gcnew MySqlConnection(config);
			db->Open();

			MySqlCommand^ query = gcnew MySqlCommand("select date_format(" + workStart + ", '%H') as work_start, date_format(" + workEnd + ", '%H') as work_stop from godziny where uzytkownik_id=" + userId + "", db);
			MySqlDataReader^ data;
			data = query->ExecuteReader();
			data->Read();

			if (data->HasRows) {
				startHour = Convert::ToInt32(data->GetInt32("work_start"));
				stopHour = Convert::ToInt32(data->GetInt32("work_stop"));
			}

			db->Close();

			String^ time;
			int k = 0;

			for (int i = startHour; i < stopHour; i++)
			{
				for (int j = 0; j < 60; j += 30)
				{
					time = dateChoosen + " " + i + ":" + j + ":00";
					DateTime hour = Convert::ToDateTime(time);
					System::Windows::Forms::TextBox^ textBox = gcnew System::Windows::Forms::TextBox();
					tab5GbHours->Controls->Add(textBox);

					db->Open();

					try
					{
						query = gcnew MySqlCommand("select wizyty.wizyty_id, date_format(wizyty.rezerwacja_od, '%H') as Rod,  date_format(wizyty.rezerwacja_do, '%H') as Rdo,  uslugi.nazwa, klienci.nazwisko from wizyty, uslugi, klienci where wizyty.rezerwacja_od = '" + hour + "' and wizyty.uzytkownik_id = " + userId + " and uslugi.uslugi_id = wizyty.uslugi_id and klienci.klienci_id = wizyty.klienci_id; ", db);
						data = query->ExecuteReader();
						data->Read();
					}
					catch (Exception^ err)
					{
						MessageBox::Show(err->Message);
					}

					textBox->BackColor = System::Drawing::Color::White;
					if (data->HasRows)
					{
						textBox->BackColor = System::Drawing::Color::Red;
						klient = data->GetString("nazwisko");
						usluga = data->GetString("nazwa");
						textBox->Tag = data->GetString("wizyty_id");
					}
					else
					{
						textBox->BackColor = System::Drawing::Color::White;
						klient = "";
						usluga = "";
					}

					textBox->Width = 200;
					textBox->Text = String::Format(hour.ToShortTimeString()) + " " + usluga + " " + klient;
					textBox->Click += gcnew System::EventHandler(this, &MainWindow::textBoxClick);
					textBox->Location = System::Drawing::Point(15, k * 25 + 25);
					k++;
					db->Close();
				}
			}
		}
	}
	System::Void MainWindow::textOldPassword_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		btnCommitPassChange_Show();
	}
	System::Void MainWindow::textNewPassword_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		btnCommitPassChange_Show();
	}
	System::Void MainWindow::textNewPassword2_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		btnCommitPassChange_Show();
	}
}

