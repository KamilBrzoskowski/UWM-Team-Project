#pragma once

namespace Serwis2017 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for UIPracownika
	/// </summary>
	public ref class UIPracownika : public System::Windows::Forms::Form
	{
	public:
		int idUzytkownika = -1, idWybranejCzesci = -1, idWybranegoZlecenia = -1;
			 String^ config = L"datasource=localhost;port=3306;username=root;password=lol123;database=serwis";
		UIPracownika(int id)
		{
			idUzytkownika = id;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UIPracownika()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  zlecenia;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  aktualizujZlecenia;
	private: System::Windows::Forms::TabPage^  magazyn;
	private: System::Windows::Forms::Button^  zleceniaZakoncz;
	private: System::Windows::Forms::CheckBox^  autoData;
	private: System::Windows::Forms::MaskedTextBox^  dataZakonczenia;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  Raport;
	private: System::Windows::Forms::DataGridView^  zleceniaTabelaZlecen;
	private: System::Windows::Forms::DataGridView^  tabelaCzesci;
	private: System::Windows::Forms::Button^  szukajCzesci;
	private: System::Windows::Forms::TextBox^  textSzukajCzesc;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataGridView^  magazynTabelaZlecen;
	private: System::Windows::Forms::Button^  szukajZlecen;
	private: System::Windows::Forms::TextBox^  textSzukajZlecenie;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::GroupBox^  zleceniaData;
	private: System::Windows::Forms::GroupBox^  daneCzesci;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  czescFabryczny;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  czescKatalogowy;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  czescNazwa;
	private: System::Windows::Forms::Button^  dodajCzesc;
	private: System::Windows::Forms::Button^  modyfikujCzesc;
	private: System::Windows::Forms::Button^  usunCzesc;
	private: System::Windows::Forms::MaskedTextBox^  dataSprzedarzy;
	private: System::Windows::Forms::MaskedTextBox^  dataKupna;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->zlecenia = (gcnew System::Windows::Forms::TabPage());
			this->zleceniaData = (gcnew System::Windows::Forms::GroupBox());
			this->autoData = (gcnew System::Windows::Forms::CheckBox());
			this->dataZakonczenia = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->zleceniaZakoncz = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Raport = (gcnew System::Windows::Forms::TextBox());
			this->zleceniaTabelaZlecen = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->aktualizujZlecenia = (gcnew System::Windows::Forms::Button());
			this->magazyn = (gcnew System::Windows::Forms::TabPage());
			this->dodajCzesc = (gcnew System::Windows::Forms::Button());
			this->modyfikujCzesc = (gcnew System::Windows::Forms::Button());
			this->usunCzesc = (gcnew System::Windows::Forms::Button());
			this->daneCzesci = (gcnew System::Windows::Forms::GroupBox());
			this->dataSprzedarzy = (gcnew System::Windows::Forms::MaskedTextBox());
			this->dataKupna = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->czescFabryczny = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->czescKatalogowy = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->czescNazwa = (gcnew System::Windows::Forms::TextBox());
			this->magazynTabelaZlecen = (gcnew System::Windows::Forms::DataGridView());
			this->szukajZlecen = (gcnew System::Windows::Forms::Button());
			this->textSzukajZlecenie = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tabelaCzesci = (gcnew System::Windows::Forms::DataGridView());
			this->szukajCzesci = (gcnew System::Windows::Forms::Button());
			this->textSzukajCzesc = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->zlecenia->SuspendLayout();
			this->zleceniaData->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zleceniaTabelaZlecen))->BeginInit();
			this->magazyn->SuspendLayout();
			this->daneCzesci->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magazynTabelaZlecen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabelaCzesci))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
			this->tabControl1->Controls->Add(this->zlecenia);
			this->tabControl1->Controls->Add(this->magazyn);
			this->tabControl1->ItemSize = System::Drawing::Size(75, 30);
			this->tabControl1->Location = System::Drawing::Point(14, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(982, 706);
			this->tabControl1->TabIndex = 0;
			// 
			// zlecenia
			// 
			this->zlecenia->Controls->Add(this->zleceniaData);
			this->zlecenia->Controls->Add(this->zleceniaZakoncz);
			this->zlecenia->Controls->Add(this->label2);
			this->zlecenia->Controls->Add(this->Raport);
			this->zlecenia->Controls->Add(this->zleceniaTabelaZlecen);
			this->zlecenia->Controls->Add(this->label1);
			this->zlecenia->Controls->Add(this->aktualizujZlecenia);
			this->zlecenia->Location = System::Drawing::Point(4, 34);
			this->zlecenia->Name = L"zlecenia";
			this->zlecenia->Padding = System::Windows::Forms::Padding(3);
			this->zlecenia->Size = System::Drawing::Size(974, 668);
			this->zlecenia->TabIndex = 0;
			this->zlecenia->Text = L"Zlecenia";
			this->zlecenia->UseVisualStyleBackColor = true;
			// 
			// zleceniaData
			// 
			this->zleceniaData->Controls->Add(this->autoData);
			this->zleceniaData->Controls->Add(this->dataZakonczenia);
			this->zleceniaData->Controls->Add(this->label3);
			this->zleceniaData->Location = System::Drawing::Point(740, 429);
			this->zleceniaData->Name = L"zleceniaData";
			this->zleceniaData->Size = System::Drawing::Size(228, 100);
			this->zleceniaData->TabIndex = 12;
			this->zleceniaData->TabStop = false;
			this->zleceniaData->Text = L"Data";
			// 
			// autoData
			// 
			this->autoData->AutoSize = true;
			this->autoData->Checked = true;
			this->autoData->CheckState = System::Windows::Forms::CheckState::Checked;
			this->autoData->Location = System::Drawing::Point(9, 70);
			this->autoData->Name = L"autoData";
			this->autoData->Size = System::Drawing::Size(208, 19);
			this->autoData->TabIndex = 2;
			this->autoData->Text = L"Pobierz date automatycznie";
			this->autoData->UseVisualStyleBackColor = true;
			this->autoData->CheckedChanged += gcnew System::EventHandler(this, &UIPracownika::autoData_CheckedChanged);
			// 
			// dataZakonczenia
			// 
			this->dataZakonczenia->Enabled = false;
			this->dataZakonczenia->Location = System::Drawing::Point(138, 22);
			this->dataZakonczenia->Mask = L"0000-00-00";
			this->dataZakonczenia->Name = L"dataZakonczenia";
			this->dataZakonczenia->Size = System::Drawing::Size(79, 23);
			this->dataZakonczenia->TabIndex = 1;
			this->dataZakonczenia->Text = L"20000101";
			this->dataZakonczenia->ValidatingType = System::DateTime::typeid;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 15);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Data zakoñczenia:";
			// 
			// zleceniaZakoncz
			// 
			this->zleceniaZakoncz->Location = System::Drawing::Point(740, 535);
			this->zleceniaZakoncz->Name = L"zleceniaZakoncz";
			this->zleceniaZakoncz->Size = System::Drawing::Size(228, 127);
			this->zleceniaZakoncz->TabIndex = 11;
			this->zleceniaZakoncz->Text = L"Zakoncz";
			this->zleceniaZakoncz->UseVisualStyleBackColor = true;
			this->zleceniaZakoncz->Click += gcnew System::EventHandler(this, &UIPracownika::zleceniaZakoncz_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 411);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 15);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Wype³nij raport:";
			// 
			// Raport
			// 
			this->Raport->Location = System::Drawing::Point(7, 429);
			this->Raport->Multiline = true;
			this->Raport->Name = L"Raport";
			this->Raport->Size = System::Drawing::Size(727, 233);
			this->Raport->TabIndex = 3;
			// 
			// zleceniaTabelaZlecen
			// 
			this->zleceniaTabelaZlecen->AllowUserToAddRows = false;
			this->zleceniaTabelaZlecen->AllowUserToDeleteRows = false;
			this->zleceniaTabelaZlecen->AllowUserToOrderColumns = true;
			this->zleceniaTabelaZlecen->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->zleceniaTabelaZlecen->Location = System::Drawing::Point(138, 78);
			this->zleceniaTabelaZlecen->Name = L"zleceniaTabelaZlecen";
			this->zleceniaTabelaZlecen->ReadOnly = true;
			this->zleceniaTabelaZlecen->Size = System::Drawing::Size(830, 322);
			this->zleceniaTabelaZlecen->TabIndex = 2;
			this->zleceniaTabelaZlecen->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIPracownika::zleceniaTabelaZlecen_CellClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 232);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Zaznacz zlecenie:";
			// 
			// aktualizujZlecenia
			// 
			this->aktualizujZlecenia->Location = System::Drawing::Point(7, 7);
			this->aktualizujZlecenia->Name = L"aktualizujZlecenia";
			this->aktualizujZlecenia->Size = System::Drawing::Size(961, 65);
			this->aktualizujZlecenia->TabIndex = 0;
			this->aktualizujZlecenia->Text = L"Aktualizuj zlecenia";
			this->aktualizujZlecenia->UseVisualStyleBackColor = true;
			this->aktualizujZlecenia->Click += gcnew System::EventHandler(this, &UIPracownika::aktualizujZlecenia_Click);
			// 
			// magazyn
			// 
			this->magazyn->Controls->Add(this->dodajCzesc);
			this->magazyn->Controls->Add(this->modyfikujCzesc);
			this->magazyn->Controls->Add(this->usunCzesc);
			this->magazyn->Controls->Add(this->daneCzesci);
			this->magazyn->Controls->Add(this->magazynTabelaZlecen);
			this->magazyn->Controls->Add(this->szukajZlecen);
			this->magazyn->Controls->Add(this->textSzukajZlecenie);
			this->magazyn->Controls->Add(this->label7);
			this->magazyn->Controls->Add(this->tabelaCzesci);
			this->magazyn->Controls->Add(this->szukajCzesci);
			this->magazyn->Controls->Add(this->textSzukajCzesc);
			this->magazyn->Controls->Add(this->label6);
			this->magazyn->Location = System::Drawing::Point(4, 34);
			this->magazyn->Name = L"magazyn";
			this->magazyn->Padding = System::Windows::Forms::Padding(3);
			this->magazyn->Size = System::Drawing::Size(974, 668);
			this->magazyn->TabIndex = 1;
			this->magazyn->Text = L"Magazyn";
			this->magazyn->UseVisualStyleBackColor = true;
			// 
			// dodajCzesc
			// 
			this->dodajCzesc->Location = System::Drawing::Point(285, 211);
			this->dodajCzesc->Name = L"dodajCzesc";
			this->dodajCzesc->Size = System::Drawing::Size(94, 23);
			this->dodajCzesc->TabIndex = 13;
			this->dodajCzesc->Text = L"Dodaj czêœc";
			this->dodajCzesc->UseVisualStyleBackColor = true;
			this->dodajCzesc->Click += gcnew System::EventHandler(this, &UIPracownika::dodajCzesc_Click);
			// 
			// modyfikujCzesc
			// 
			this->modyfikujCzesc->Enabled = false;
			this->modyfikujCzesc->Location = System::Drawing::Point(87, 211);
			this->modyfikujCzesc->Name = L"modyfikujCzesc";
			this->modyfikujCzesc->Size = System::Drawing::Size(192, 23);
			this->modyfikujCzesc->TabIndex = 12;
			this->modyfikujCzesc->Text = L"Modyfikuj czêœc";
			this->modyfikujCzesc->UseVisualStyleBackColor = true;
			this->modyfikujCzesc->Click += gcnew System::EventHandler(this, &UIPracownika::modyfikujCzesc_Click);
			// 
			// usunCzesc
			// 
			this->usunCzesc->Enabled = false;
			this->usunCzesc->Location = System::Drawing::Point(6, 211);
			this->usunCzesc->Name = L"usunCzesc";
			this->usunCzesc->Size = System::Drawing::Size(75, 23);
			this->usunCzesc->TabIndex = 11;
			this->usunCzesc->Text = L"Usuñ czêœc";
			this->usunCzesc->UseVisualStyleBackColor = true;
			this->usunCzesc->Click += gcnew System::EventHandler(this, &UIPracownika::usunCzesc_Click);
			// 
			// daneCzesci
			// 
			this->daneCzesci->Controls->Add(this->dataSprzedarzy);
			this->daneCzesci->Controls->Add(this->dataKupna);
			this->daneCzesci->Controls->Add(this->label12);
			this->daneCzesci->Controls->Add(this->label11);
			this->daneCzesci->Controls->Add(this->label10);
			this->daneCzesci->Controls->Add(this->czescFabryczny);
			this->daneCzesci->Controls->Add(this->label9);
			this->daneCzesci->Controls->Add(this->czescKatalogowy);
			this->daneCzesci->Controls->Add(this->label8);
			this->daneCzesci->Controls->Add(this->czescNazwa);
			this->daneCzesci->Location = System::Drawing::Point(6, 35);
			this->daneCzesci->Name = L"daneCzesci";
			this->daneCzesci->Size = System::Drawing::Size(373, 170);
			this->daneCzesci->TabIndex = 10;
			this->daneCzesci->TabStop = false;
			this->daneCzesci->Text = L"Czêœæ";
			// 
			// dataSprzedarzy
			// 
			this->dataSprzedarzy->Location = System::Drawing::Point(131, 135);
			this->dataSprzedarzy->Mask = L"0000-00-00";
			this->dataSprzedarzy->Name = L"dataSprzedarzy";
			this->dataSprzedarzy->Size = System::Drawing::Size(82, 23);
			this->dataSprzedarzy->TabIndex = 18;
			this->dataSprzedarzy->Text = L"20000101";
			this->dataSprzedarzy->ValidatingType = System::DateTime::typeid;
			// 
			// dataKupna
			// 
			this->dataKupna->Location = System::Drawing::Point(131, 106);
			this->dataKupna->Mask = L"00/00/0000";
			this->dataKupna->Name = L"dataKupna";
			this->dataKupna->Size = System::Drawing::Size(82, 23);
			this->dataKupna->TabIndex = 17;
			this->dataKupna->ValidatingType = System::DateTime::typeid;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 135);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(112, 15);
			this->label12->TabIndex = 16;
			this->label12->Text = L"Data sprzedazy:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 106);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(84, 15);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Data kupna:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 77);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 15);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Nr fabryczny:";
			// 
			// czescFabryczny
			// 
			this->czescFabryczny->Location = System::Drawing::Point(131, 74);
			this->czescFabryczny->Name = L"czescFabryczny";
			this->czescFabryczny->Size = System::Drawing::Size(236, 23);
			this->czescFabryczny->TabIndex = 13;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 48);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(98, 15);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Nr katalogowy";
			// 
			// czescKatalogowy
			// 
			this->czescKatalogowy->Location = System::Drawing::Point(131, 45);
			this->czescKatalogowy->Name = L"czescKatalogowy";
			this->czescKatalogowy->Size = System::Drawing::Size(236, 23);
			this->czescKatalogowy->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 19);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(49, 15);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Nazwa:";
			// 
			// czescNazwa
			// 
			this->czescNazwa->Location = System::Drawing::Point(131, 16);
			this->czescNazwa->Name = L"czescNazwa";
			this->czescNazwa->Size = System::Drawing::Size(236, 23);
			this->czescNazwa->TabIndex = 9;
			// 
			// magazynTabelaZlecen
			// 
			this->magazynTabelaZlecen->AllowUserToAddRows = false;
			this->magazynTabelaZlecen->AllowUserToDeleteRows = false;
			this->magazynTabelaZlecen->AllowUserToOrderColumns = true;
			this->magazynTabelaZlecen->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->magazynTabelaZlecen->Location = System::Drawing::Point(6, 498);
			this->magazynTabelaZlecen->Name = L"magazynTabelaZlecen";
			this->magazynTabelaZlecen->ReadOnly = true;
			this->magazynTabelaZlecen->Size = System::Drawing::Size(962, 164);
			this->magazynTabelaZlecen->TabIndex = 7;
			this->magazynTabelaZlecen->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIPracownika::magazynTabelaZlecen_CellClick);
			// 
			// szukajZlecen
			// 
			this->szukajZlecen->Location = System::Drawing::Point(304, 468);
			this->szukajZlecen->Name = L"szukajZlecen";
			this->szukajZlecen->Size = System::Drawing::Size(75, 23);
			this->szukajZlecen->TabIndex = 6;
			this->szukajZlecen->Text = L"Szukaj";
			this->szukajZlecen->UseVisualStyleBackColor = true;
			this->szukajZlecen->Click += gcnew System::EventHandler(this, &UIPracownika::szukajZlecen_Click);
			// 
			// textSzukajZlecenie
			// 
			this->textSzukajZlecenie->Location = System::Drawing::Point(128, 469);
			this->textSzukajZlecenie->Name = L"textSzukajZlecenie";
			this->textSzukajZlecenie->Size = System::Drawing::Size(170, 23);
			this->textSzukajZlecenie->TabIndex = 5;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 472);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 15);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Szukaj zlecenie:";
			// 
			// tabelaCzesci
			// 
			this->tabelaCzesci->AllowUserToAddRows = false;
			this->tabelaCzesci->AllowUserToDeleteRows = false;
			this->tabelaCzesci->AllowUserToOrderColumns = true;
			this->tabelaCzesci->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tabelaCzesci->Location = System::Drawing::Point(385, 6);
			this->tabelaCzesci->Name = L"tabelaCzesci";
			this->tabelaCzesci->ReadOnly = true;
			this->tabelaCzesci->Size = System::Drawing::Size(583, 486);
			this->tabelaCzesci->TabIndex = 3;
			this->tabelaCzesci->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIPracownika::tabelaCzesci_CellClick);
			// 
			// szukajCzesci
			// 
			this->szukajCzesci->Location = System::Drawing::Point(304, 6);
			this->szukajCzesci->Name = L"szukajCzesci";
			this->szukajCzesci->Size = System::Drawing::Size(75, 23);
			this->szukajCzesci->TabIndex = 2;
			this->szukajCzesci->Text = L"Szukaj";
			this->szukajCzesci->UseVisualStyleBackColor = true;
			this->szukajCzesci->Click += gcnew System::EventHandler(this, &UIPracownika::szukajCzesci_Click);
			// 
			// textSzukajCzesc
			// 
			this->textSzukajCzesc->Location = System::Drawing::Point(114, 6);
			this->textSzukajCzesc->Name = L"textSzukajCzesc";
			this->textSzukajCzesc->Size = System::Drawing::Size(184, 23);
			this->textSzukajCzesc->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 10);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(105, 15);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Szukaj czêœci:";
			// 
			// UIPracownika
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Name = L"UIPracownika";
			this->Text = L"UIPracownika";
			this->tabControl1->ResumeLayout(false);
			this->zlecenia->ResumeLayout(false);
			this->zlecenia->PerformLayout();
			this->zleceniaData->ResumeLayout(false);
			this->zleceniaData->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zleceniaTabelaZlecen))->EndInit();
			this->magazyn->ResumeLayout(false);
			this->magazyn->PerformLayout();
			this->daneCzesci->ResumeLayout(false);
			this->daneCzesci->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magazynTabelaZlecen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabelaCzesci))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:Void czyscPolaTekstowe(Control^ list);
	private: System::Void szukajCzesci_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void usunCzesc_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void modyfikujCzesc_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void dodajCzesc_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void szukajZlecen_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tabelaCzesci_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void magazynTabelaZlecen_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void aktualizujZlecenia_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void zleceniaZakoncz_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void zleceniaTabelaZlecen_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
private: System::Void autoData_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
}
