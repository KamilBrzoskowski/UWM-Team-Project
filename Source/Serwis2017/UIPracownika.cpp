#include "UIPracownika.h"

System::Void Serwis2017::UIPracownika::czyscPolaTekstowe(Control ^ list)
{
	for each(Control^ textBox in list->Controls)
	{
		if (textBox->GetType() == TextBox::typeid)
			textBox->Text = "";
		else if (textBox->GetType() == MaskedTextBox::typeid)
			textBox->Text = "";
	}
}

System::Void Serwis2017::UIPracownika::szukajCzesci_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("Select * from magazyn where concat(nazwa, ' ', nr_katalogowy, ' ', nr_fabryczny) like  '%" + textSzukajCzesc->Text + "%' order by nazwa;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		tabelaCzesci->DataSource = source;
		tabelaCzesci->Columns[0]->Visible = false;
		tabelaCzesci->Columns["zlecenie"]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIPracownika::usunCzesc_Click(System::Object ^ sender, System::EventArgs ^ e)
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
		if (MessageBox::Show("Jesteœ pewny? Operacji nie mo¿na cofn¹æ!!", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			query->CommandText = "delete from magazyn where id = " + idWybranejCzesci + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Usunieto czêœæ!");
		}
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
		transaction->Rollback();
	}

	db->Close();
}

System::Void Serwis2017::UIPracownika::modyfikujCzesc_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (czescNazwa->Text->Length < 2 || dataKupna->Text->Length < 8)
		MessageBox::Show("Brakuje danych!");
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
			query->CommandText = "update magazyn set nazwa = '" + czescNazwa->Text + "', nr_katalogowy = '" + czescKatalogowy->Text + "', nr_fabryczny = '" + czescFabryczny->Text + "', data_kupna = '" + dataKupna->Text + "' where id = " + idWybranejCzesci + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zaktualizowano czêœæ!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIPracownika::dodajCzesc_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (czescNazwa->Text->Length < 2 || dataKupna->Text->Length < 8)
		MessageBox::Show("Brakuje danych!");
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
			query->CommandText = "insert into magazyn set nazwa = '" + czescNazwa->Text + "', nr_katalogowy = '" + czescKatalogowy->Text + "', nr_fabryczny = '" + czescFabryczny->Text + "', data_kupna = '" + dataKupna->Text + "';";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Dodano czêœæ!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIPracownika::szukajZlecen_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("Select * from zlecenie where opis like '%" + textSzukajZlecenie->Text + "%' and pracownik = " + idUzytkownika + " order by id;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		magazynTabelaZlecen->DataSource = source;
		magazynTabelaZlecen->Columns[0]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIPracownika::tabelaCzesci_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranejCzesci = Convert::ToInt32(tabelaCzesci->Rows[e->RowIndex]->Cells[0]->Value);
		czescNazwa->Text = tabelaCzesci->Rows[e->RowIndex]->Cells["nazwa"]->Value->ToString();
		czescFabryczny->Text = tabelaCzesci->Rows[e->RowIndex]->Cells["nr_fabryczny"]->Value->ToString();
		czescKatalogowy->Text = tabelaCzesci->Rows[e->RowIndex]->Cells["nr_katalogowy"]->Value->ToString();
		dataKupna->Text = tabelaCzesci->Rows[e->RowIndex]->Cells["data_kupna"]->Value->ToString();
		dataSprzedarzy->Text = tabelaCzesci->Rows[e->RowIndex]->Cells["data_sprzedazy"]->Value->ToString();
		modyfikujCzesc->Enabled = true;
		usunCzesc->Enabled = true;
	}
}

System::Void Serwis2017::UIPracownika::magazynTabelaZlecen_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoZlecenia = Convert::ToInt32(magazynTabelaZlecen->Rows[e->RowIndex]->Cells[0]->Value);

		if (tabelaCzesci->Rows[e->RowIndex]->Cells["zlecenie"]->Value != nullptr && idWybranejCzesci >= -1 && MessageBox::Show("Czy chcesz pszypisaæ czêœæ do zlecenia?", "Uwaga", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
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
				query->CommandText = "update magazyn set zlecenie = " + idWybranegoZlecenia + " where id = " + idWybranejCzesci + ";";
				query->ExecuteNonQuery();

				transaction->Commit();
				MessageBox::Show("Czêœæ dodana do zlecenia!");
			}
			catch (Exception^ err)
			{
				MessageBox::Show(err->Message);
				transaction->Rollback();
			}

			db->Close();
		}
	}
}

System::Void Serwis2017::UIPracownika::aktualizujZlecenia_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("Select * from zlecenie where pracownik = " + idUzytkownika + " order by id;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		zleceniaTabelaZlecen->DataSource = source;
		zleceniaTabelaZlecen->Columns[0]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIPracownika::zleceniaZakoncz_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (Raport->Text->Length < 5 || (dataZakonczenia->Text->Length < 8 && (!autoData->Checked)))
		MessageBox::Show("Brakuje wymaganych informacji!");
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
			DateTime^ nowa = gcnew DateTime();
			if (autoData->Checked)
				nowa = DateTime::Now;
			else
				nowa = Convert::ToDateTime(dataZakonczenia->Text);

			query->CommandText = "update zlecenie set raport = '" + Raport->Text + "', zakonczenie = '" + nowa->ToString() + "' where id = " + idWybranegoZlecenia + ";";
			query->ExecuteNonQuery();

			query->CommandText = "update magazyn set data_sprzedazy = '" + nowa->ToString() + "' where zlecenie = " + idWybranegoZlecenia + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zlecenie zakonczono!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIPracownika::zleceniaTabelaZlecen_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	try
	{
		if (e->RowIndex >= 0)
			idWybranegoZlecenia = Convert::ToInt32(zleceniaTabelaZlecen->Rows[e->RowIndex]->Cells[0]->Value);
	}
	catch (...)
	{
		idWybranegoZlecenia = 0;
	}
}

System::Void Serwis2017::UIPracownika::autoData_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (autoData->Checked)
		dataZakonczenia->Enabled = false;
	else if (!autoData->Checked)
		dataZakonczenia->Enabled = true;
}
