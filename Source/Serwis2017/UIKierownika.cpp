#include "UIKierownika.h"

System::Void Serwis2017::UIKierownika::pracownicyPrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("Select * from pracownik where concat(imie, ' ', nazwisko, ' ', miejscowosc) like  '%" + pracownicyTextSzukaj->Text + "%' and pozycja = 'pracownik' order by nazwa;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		pracownicyTabela->DataSource = source;
		pracownicyTabela->Columns[0]->Visible = false;
		pracownicyTabela->Columns["haslo"]->Visible = false;
		pracownicyTabela->Columns["pozycja"]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::pracownicyUsun_Click(System::Object ^ sender, System::EventArgs ^ e)
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
			query->CommandText = "update pracownik set pozycja ='zwolniony' where id = " + idWybranegoPracownika + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zwolniono pracownika!");
		}
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
		transaction->Rollback();
	}

	db->Close();
}

System::Void Serwis2017::UIKierownika::pracownicyModyfikuj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (pracownicyImie->Text->Length < 2 || pracownicyNazwisko->Text->Length < 4)
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
			query->CommandText = "update pracownik set imie = '" + pracownicyImie->Text + "', nazwisko = '" + pracownicyNazwisko->Text + "', nazwa = '" + pracownicyNazwaUzytkownika->Text + "' where id = " + idWybranegoPracownika + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zaktualizowano pracownika!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::pracownicyDodaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (pracownicyImie->Text->Length < 2 || pracownicyNazwisko->Text->Length < 4)
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
			query->CommandText = "insert into pracownik set imie = '" + pracownicyImie->Text + "', nazwisko = '" + pracownicyNazwisko->Text + "', nazwa = '" + pracownicyNazwaUzytkownika->Text + "', pozycja = 'pracownik', haslo = password('123'), where id = " + idWybranegoPracownika + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Dodano pracownika!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::samochodySamochodTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoSamochodu = Convert::ToInt32(samochodySamochodTabela->Rows[e->RowIndex]->Cells[0]->Value);
		samochodyMarka->Text = samochodySamochodTabela->Rows[e->RowIndex]->Cells["model"]->Value->ToString();
		samochodyModel->Text = samochodySamochodTabela->Rows[e->RowIndex]->Cells["marka"]->Value->ToString();
		samochodyRejestrcyjny->Text = samochodySamochodTabela->Rows[e->RowIndex]->Cells["nr_rejestracyjny"]->Value->ToString();
		samochodyEwidencyjny->Text = samochodySamochodTabela->Rows[e->RowIndex]->Cells["nr_ewidencyjny"]->Value->ToString();
		samochodyModyfikuj->Enabled = true;
		samochodyUsun->Enabled = true;
	}
}

System::Void Serwis2017::UIKierownika::samochodyKlientTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoKlienta = Convert::ToInt32(samochodySamochodTabela->Rows[e->RowIndex]->Cells[0]->Value);

		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("select samochod.id, samochod.model, samochod.marka, samochod.nr_rejestracyjny, samochod.nr_ewidencyjny, samochod.wlasciciel, concat(klient.imie, ' ', klient.nazwisko) from samochod, klient where samochod.wlasciciel = " + idWybranegoKlienta + " order by model;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			pracownicyTabela->DataSource = source;
			pracownicyTabela->Columns[0]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
}

System::Void Serwis2017::UIKierownika::pracownicyTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoPracownika = Convert::ToInt32(pracownicyTabela->Rows[e->RowIndex]->Cells[0]->Value);
		pracownicyImie->Text = pracownicyTabela->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
		pracownicyNazwisko->Text = pracownicyTabela->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
		pracownicyNazwaUzytkownika->Text = pracownicyTabela->Rows[e->RowIndex]->Cells["nazwa"]->Value->ToString();
		pracownicyModyfikuj->Enabled = true;
		pracownicyUsun->Enabled = true;
	}
}

System::Void Serwis2017::UIKierownika::samochodySamochodPrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("select samochod.id, samochod.model, samochod.marka, samochod.nr_rejestracyjny, samochod.nr_ewidencyjny, samochod.wlasciciel, concat(klient.imie, ' ', klient.nazwisko) from samochod, klient where samochod.wlasciciel = klient.id and concat(model, ' ', marka) like  '%" + szmochodySamochodTextSzukaj->Text + "%' order by model;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		samochodySamochodTabela->DataSource = source;
		samochodySamochodTabela->Columns[0]->Visible = false;
		samochodySamochodTabela->Columns["wlasciciel"]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::samochodyUsun_Click(System::Object ^ sender, System::EventArgs ^ e)
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
			query->CommandText = "delete from samochod where id = " + idWybranegoSamochodu + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Usunieto samochod!");
		}
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
		transaction->Rollback();
	}

	db->Close();
}

System::Void Serwis2017::UIKierownika::samochodyModyfikuj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (samochodyMarka->Text->Length < 3 || samochodyModel->Text->Length < 3 || samochodyRejestrcyjny->Text->Length < 6)
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
			query->CommandText = "update samochod set marka = '" + samochodyMarka->Text + "', model = '" + samochodyModel->Text + "', nr_rejestracyjny = '" + samochodyRejestrcyjny->Text + "', nr_ewidencyjny = '" + samochodyEwidencyjny->Text + "', where id = " + idWybranegoSamochodu + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zaktualizowano samochod!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::samochodyDodaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (samochodyMarka->Text->Length < 3 || samochodyModel->Text->Length < 3 || samochodyRejestrcyjny->Text->Length < 6)
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
			query->CommandText = "insert into samochod set marka = '" + samochodyMarka->Text + "', model = '" + samochodyModel->Text + "', nr_rejestracyjny = '" + samochodyRejestrcyjny->Text + "', nr_ewidencyjny = '" + samochodyEwidencyjny->Text + "';";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zaktualizowano samochod!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::samochodyKlientPrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("select * from klient where concat(imie, ' ', nazwisko, ' ', miejscowosc) like  '%" + samochodyKlientTextSzukaj->Text + "%' order by nazwisko;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		samochodyKlientTabela->DataSource = source;
		samochodyKlientTabela->Columns[0]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::klientPrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("select * from klient where concat(imie, ' ', nazwisko, ' ', miejscowosc) like  '%" + samochodyKlientTextSzukaj->Text + "%' order by nazwisko;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		klientTabela->DataSource = source;
		klientTabela->Columns[0]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::klientUsun_Click(System::Object ^ sender, System::EventArgs ^ e)
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
		if (MessageBox::Show("Jesteœ pewny?\n Operacji nie mo¿na cofn¹æ!!/n Wraz z klientem zostan¹ usuniête wszystkie jego samochody", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			query->CommandText = "delete from samochod where wlasciciel = " + idWybranegoKlienta + ";";
			query->ExecuteNonQuery();

			query->CommandText = "delete from klient where id = " + idWybranegoKlienta + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Usunieto klienta wraz z samochodami!");
		}
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
		transaction->Rollback();
	}

	db->Close();
}

System::Void Serwis2017::UIKierownika::klientModyfikuj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (samochodyMarka->Text->Length < 3 || samochodyModel->Text->Length < 3 || samochodyRejestrcyjny->Text->Length < 6)
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
			query->CommandText = "update klient set imie = '" + klientImie + "', nazwisko = '" + klientNazwisko + "', nazwa_firmy = '" + klientFirma + "', nip = '" + klientNip+ "', pesel = '" + klientPesel + "', email = '" + klientEmail + "', miejscowosc = '" + klientMiejscowosc + "', kod_pocztowy = '" + klientKod + "', ulica = '" + klientUlica + "', mieszkanie = '" + klientNumer + "' where id = " + idWybranegoKlienta + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zaktualizowano klienta!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::klientDodaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (samochodyMarka->Text->Length < 3 || samochodyModel->Text->Length < 3 || samochodyRejestrcyjny->Text->Length < 6)
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
			query->CommandText = "insert into klient set imie = '" + klientImie + "', nazwisko = '" + klientNazwisko + "', nazwa_firmy = '" + klientFirma + "', nip = '" + klientNip + "', pesel = '" + klientPesel + "', email = '" + klientEmail + "', miejscowosc = '" + klientMiejscowosc + "', kod_pocztowy = '" + klientKod + "', ulica = '" + klientUlica + "', mieszkanie = '" + klientNumer + "' where id = " + idWybranegoKlienta + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Dodano klienta!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::klientTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoKlienta = Convert::ToInt32(klientTabela->Rows[e->RowIndex]->Cells[0]->Value);
		klientImie->Text = klientTabela->Rows[e->RowIndex]->Cells["imie"]->Value->ToString();
		klientNazwisko->Text = klientTabela->Rows[e->RowIndex]->Cells["nazwisko"]->Value->ToString();
		klientFirma->Text = klientTabela->Rows[e->RowIndex]->Cells["nazwa_firmy"]->Value->ToString();
		klientNip->Text = klientTabela->Rows[e->RowIndex]->Cells["nip"]->Value->ToString();
		klientPesel->Text = klientTabela->Rows[e->RowIndex]->Cells["pesel"]->Value->ToString();
		klientEmail->Text = klientTabela->Rows[e->RowIndex]->Cells["email"]->Value->ToString();
		klientMiejscowosc->Text = klientTabela->Rows[e->RowIndex]->Cells["miejscowosc"]->Value->ToString();
		klientKod->Text = klientTabela->Rows[e->RowIndex]->Cells["kod_pocztowy"]->Value->ToString();
		klientUlica->Text = klientTabela->Rows[e->RowIndex]->Cells["ulica"]->Value->ToString();
		klientNumer->Text = klientTabela->Rows[e->RowIndex]->Cells["mieszkanie"]->Value->ToString();
		klientModyfikuj->Enabled = true;
		klientUsun->Enabled = true;
	}
}

System::Void Serwis2017::UIKierownika::magazynCzescPrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("Select * from magazyn where concat(nazwa, ' ', nr_katalogowy, ' ', nr_fabryczny) like  '%" + magazynCzescTextSzukaj->Text + "%' order by nazwa;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		magazynCzescTabela->DataSource = source;
		magazynCzescTabela->Columns[0]->Visible = false;
		magazynCzescTabela->Columns["zlecenie"]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::magazynZleceniePrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("Select * from zlecenie where opis like '%" + magazynZlecenieTextSzukaj->Text + "%' order by id;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		magazynZlecenieTabela->DataSource = source;
		magazynZlecenieTabela->Columns[0]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::magazynCzescTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranejCzesci = Convert::ToInt32(magazynCzescTabela->Rows[e->RowIndex]->Cells[0]->Value);

		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select * from zlecenie where opis like '%" + magazynZlecenieTextSzukaj->Text + "%' and where id = " + idWybranejCzesci + " order by id;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			magazynZlecenieTabela->DataSource = source;
			magazynZlecenieTabela->Columns[0]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
}

System::Void Serwis2017::UIKierownika::magazynZlecenieTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoZlecenia = Convert::ToInt32(magazynZlecenieTabela->Rows[e->RowIndex]->Cells[0]->Value);

		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select * from magazyn where concat(nazwa, ' ', nr_katalogowy, ' ', nr_fabryczny) like  '%" + magazynCzescTextSzukaj->Text + "%' and id = " + idWybranegoZlecenia + "order by nazwa;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			magazynCzescTabela->DataSource = source;
			magazynCzescTabela->Columns[0]->Visible = false;
			magazynCzescTabela->Columns["zlecenie"]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
}

System::Void Serwis2017::UIKierownika::zleceniaKlientPrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("select * from klient where concat(imie, ' ', nazwisko, ' ', miejscowosc) like  '%" + samochodyKlientTextSzukaj->Text + "%' order by nazwisko;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		zlecenieKlientTabela->DataSource = source;
		zlecenieKlientTabela->Columns[0]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::zleceniaSamochodPrzyciskSzukaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	MySqlConnection^ db = gcnew MySqlConnection(config);
	MySqlCommand^ query = gcnew MySqlCommand("select samochod.id, samochod.model, samochod.marka, samochod.nr_rejestracyjny, samochod.nr_ewidencyjny, samochod.wlasciciel, concat(klient.imie, ' ', klient.nazwisko) from samochod, klient where samochod.wlasciciel = " + idWybranegoKlienta + " and concat(model, ' ', marka) like  '%" + szmochodySamochodTextSzukaj->Text + "%' order by model;", db);

	try
	{
		db->Open();

		MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
		adapter->SelectCommand = query;
		DataTable^ table = gcnew DataTable();
		adapter->Fill(table);

		BindingSource^ source = gcnew BindingSource();
		source->DataSource = table;
		zlecenieSamochodTabela->DataSource = source;
		zlecenieSamochodTabela->Columns[0]->Visible = false;
		zlecenieSamochodTabela->Columns["wlasciciel"]->Visible = false;

		db->Close();
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
	}
}

System::Void Serwis2017::UIKierownika::zlecenieUsun_Click(System::Object ^ sender, System::EventArgs ^ e)
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
		if (MessageBox::Show("Jesteœ pewny?\n Operacji nie mo¿na cofn¹æ!!/n Czêœci strac¹ swoje przypisanie", "Uwaga!!!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			query->CommandText = "delete from zlecenie where id = " + idWybranegoZlecenia + ";";
			query->ExecuteNonQuery();

			query->CommandText = "update magazyn set zlecenie = null where zlecenie = " + idWybranegoZlecenia + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Usunieto zlecenie i zmieniono przypisanie czêœci !");
		}
	}
	catch (Exception^ err)
	{
		MessageBox::Show(err->Message);
		transaction->Rollback();
	}

	db->Close();
}

System::Void Serwis2017::UIKierownika::zlecenieModyfikuj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (samochodyMarka->Text->Length < 3 || samochodyModel->Text->Length < 3 || samochodyRejestrcyjny->Text->Length < 6)
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
			query->CommandText = "update zlecenie set opis = '" + zlecenieOpis + "' where id = " + idWybranegoZlecenia + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Zaktualizowano opis zlecenia!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::zlecenieDodaj_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (samochodyMarka->Text->Length < 3 || samochodyModel->Text->Length < 3 || samochodyRejestrcyjny->Text->Length < 6)
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
			query->CommandText = "insert into zlecenie set opis = '" + zlecenieOpis->Text + "', wystawienie = now(), pracownik = " + idWybranegoPracownika + ", samochod = " + idWybranegoSamochodu + ";";
			query->ExecuteNonQuery();
			transaction->Commit();

			MessageBox::Show("Dodano zlecenie!");
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
			transaction->Rollback();
		}

		db->Close();
	}
}

System::Void Serwis2017::UIKierownika::zlecenieKlientTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoKlienta = Convert::ToInt32(zlecenieKlientTabela->Rows[e->RowIndex]->Cells[0]->Value);

		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("select samochod.id, samochod.model, samochod.marka, samochod.nr_rejestracyjny, samochod.nr_ewidencyjny, samochod.wlasciciel, concat(klient.imie, ' ', klient.nazwisko) from samochod, klient where samochod.wlasciciel = " + idWybranegoKlienta + " order by model;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			samochodySamochodTabela->DataSource = source;
			samochodySamochodTabela->Columns[0]->Visible = false;
			samochodySamochodTabela->Columns["wlasciciel"]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
}

System::Void Serwis2017::UIKierownika::zlecenieSamochodTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoSamochodu = Convert::ToInt32(zlecenieSamochodTabela->Rows[e->RowIndex]->Cells[0]->Value);

		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("Select * from zlecenie where opis like '%" + magazynZlecenieTextSzukaj->Text + "%' and samochod = " + idWybranegoSamochodu + " order by id;", db);

		try
		{
			db->Open();

			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
			adapter->SelectCommand = query;
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			BindingSource^ source = gcnew BindingSource();
			source->DataSource = table;
			zlecenieZlecenieTabela->DataSource = source;
			zlecenieZlecenieTabela->Columns[0]->Visible = false;

			db->Close();
		}
		catch (Exception^ err)
		{
			MessageBox::Show(err->Message);
		}
	}
}

System::Void Serwis2017::UIKierownika::zlecenieZlecenieTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoZlecenia = Convert::ToInt32(zlecenieZlecenieTabela->Rows[e->RowIndex]->Cells[0]->Value);

		zlecenieOpis->Text = zlecenieZlecenieTabela->Rows[e->RowIndex]->Cells["opis"]->Value->ToString();
	}
}

System::Void Serwis2017::UIKierownika::zleceniePracownicyTabela_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e)
{
	if (e->RowIndex >= 0)
	{
		idWybranegoPracownika = Convert::ToInt32(zleceniePracownicyTabela->Rows[e->RowIndex]->Cells[0]->Value);
	}
}
