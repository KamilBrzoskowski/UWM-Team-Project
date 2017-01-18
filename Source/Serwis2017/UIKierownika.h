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
	/// Summary for UIKierownika
	/// </summary>
	public ref class UIKierownika : public System::Windows::Forms::Form
	{
	public:
		String^ config = L"datasource=localhost;port=3306;username=root;password=lol123;database=serwis";
		int idUzytkownika = -1, idWybranejCzesci = -1, idWybranegoZlecenia = -1, idWybranegoKlienta = -1, idWybranegoSamochodu = -1, idWybranegoPracownika;
		UIKierownika(int id)
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
		~UIKierownika()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabZlecenia;
	private: System::Windows::Forms::TabPage^  tabMagazyn;
	private: System::Windows::Forms::TabPage^  tabKlienci;
	private: System::Windows::Forms::TabPage^  tabSamochody;
	private: System::Windows::Forms::TabPage^  tabPracownicy;
	private: System::Windows::Forms::Button^  pracownicyDodaj;
	private: System::Windows::Forms::Button^  pracownicyModyfikuj;
	private: System::Windows::Forms::Button^  pracownicyUsun;
	private: System::Windows::Forms::GroupBox^  pracownicyGp;
	private: System::Windows::Forms::TextBox^  pracownicyNazwaUzytkownika;
	private: System::Windows::Forms::TextBox^  pracownicyNazwisko;
	private: System::Windows::Forms::TextBox^  pracownicyImie;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  pracownicyPrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  pracownicyTextSzukaj;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DataGridView^  pracownicyTabela;
	private: System::Windows::Forms::Button^  klientDodaj;
	private: System::Windows::Forms::Button^  klientModyfikuj;
	private: System::Windows::Forms::Button^  klientUsun;
	private: System::Windows::Forms::Button^  klientPrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  klientTextSzukaj;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::DataGridView^  klientTabela;
	private: System::Windows::Forms::Button^  samochodyDodaj;
	private: System::Windows::Forms::Button^  samochodyModyfikuj;
	private: System::Windows::Forms::Button^  samochodyUsun;
	private: System::Windows::Forms::GroupBox^  samochodyGb;
	private: System::Windows::Forms::TextBox^  samochodyRejestrcyjny;
	private: System::Windows::Forms::TextBox^  samochodyModel;
	private: System::Windows::Forms::TextBox^  samochodyMarka;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  samochodySamochodPrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  szmochodySamochodTextSzukaj;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::DataGridView^  samochodySamochodTabela;
	private: System::Windows::Forms::GroupBox^  klientGb;
	private: System::Windows::Forms::MaskedTextBox^  klientKod;
	private: System::Windows::Forms::TextBox^  klientMiejscowosc;
	private: System::Windows::Forms::TextBox^  klientNumer;
	private: System::Windows::Forms::TextBox^  klientUlica;
	private: System::Windows::Forms::TextBox^  klientFirma;
	private: System::Windows::Forms::TextBox^  klientEmail;
	private: System::Windows::Forms::TextBox^  klientNazwisko;
	private: System::Windows::Forms::TextBox^  klientImie;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TextBox^  klientPesel;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  klientNip;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  samochodyKlientPrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  samochodyKlientTextSzukaj;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::DataGridView^  samochodyKlientTabela;
	private: System::Windows::Forms::TextBox^  samochodyEwidencyjny;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Button^  magazynCzescPrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  magazynCzescTextSzukaj;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::DataGridView^  magazynCzescTabela;
	private: System::Windows::Forms::DataGridView^  magazynZlecenieTabela;
	private: System::Windows::Forms::Button^  magazynZleceniePrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  magazynZlecenieTextSzukaj;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::DataGridView^  zlecenieZlecenieTabela;
	private: System::Windows::Forms::DataGridView^  zleceniePracownicyTabela;
	private: System::Windows::Forms::TextBox^  zlecenieOpis;
	private: System::Windows::Forms::DataGridView^  zlecenieSamochodTabela;
	private: System::Windows::Forms::Button^  zleceniaSamochodPrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  zleceniaSamochodTextSzukaj;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::DataGridView^  zlecenieKlientTabela;
	private: System::Windows::Forms::Button^  zleceniaKlientPrzyciskSzukaj;
	private: System::Windows::Forms::TextBox^  zleceniaKlientTextSzukaj;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Button^  zlecenieDodaj;
	private: System::Windows::Forms::Button^  zlecenieModyfikuj;
	private: System::Windows::Forms::Button^  zlecenieUsun;

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
			this->tabZlecenia = (gcnew System::Windows::Forms::TabPage());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->zlecenieDodaj = (gcnew System::Windows::Forms::Button());
			this->zlecenieModyfikuj = (gcnew System::Windows::Forms::Button());
			this->zlecenieUsun = (gcnew System::Windows::Forms::Button());
			this->zlecenieZlecenieTabela = (gcnew System::Windows::Forms::DataGridView());
			this->zleceniePracownicyTabela = (gcnew System::Windows::Forms::DataGridView());
			this->zlecenieOpis = (gcnew System::Windows::Forms::TextBox());
			this->zlecenieSamochodTabela = (gcnew System::Windows::Forms::DataGridView());
			this->zleceniaSamochodPrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->zleceniaSamochodTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->zlecenieKlientTabela = (gcnew System::Windows::Forms::DataGridView());
			this->zleceniaKlientPrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->zleceniaKlientTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->tabMagazyn = (gcnew System::Windows::Forms::TabPage());
			this->magazynZlecenieTabela = (gcnew System::Windows::Forms::DataGridView());
			this->magazynZleceniePrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->magazynZlecenieTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->magazynCzescPrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->magazynCzescTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->magazynCzescTabela = (gcnew System::Windows::Forms::DataGridView());
			this->tabKlienci = (gcnew System::Windows::Forms::TabPage());
			this->klientGb = (gcnew System::Windows::Forms::GroupBox());
			this->klientPesel = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->klientNip = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->klientKod = (gcnew System::Windows::Forms::MaskedTextBox());
			this->klientMiejscowosc = (gcnew System::Windows::Forms::TextBox());
			this->klientNumer = (gcnew System::Windows::Forms::TextBox());
			this->klientUlica = (gcnew System::Windows::Forms::TextBox());
			this->klientFirma = (gcnew System::Windows::Forms::TextBox());
			this->klientEmail = (gcnew System::Windows::Forms::TextBox());
			this->klientNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->klientImie = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->klientDodaj = (gcnew System::Windows::Forms::Button());
			this->klientModyfikuj = (gcnew System::Windows::Forms::Button());
			this->klientUsun = (gcnew System::Windows::Forms::Button());
			this->klientPrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->klientTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->klientTabela = (gcnew System::Windows::Forms::DataGridView());
			this->tabSamochody = (gcnew System::Windows::Forms::TabPage());
			this->samochodyKlientTabela = (gcnew System::Windows::Forms::DataGridView());
			this->samochodyKlientPrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->samochodyKlientTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->samochodyDodaj = (gcnew System::Windows::Forms::Button());
			this->samochodyModyfikuj = (gcnew System::Windows::Forms::Button());
			this->samochodyUsun = (gcnew System::Windows::Forms::Button());
			this->samochodyGb = (gcnew System::Windows::Forms::GroupBox());
			this->samochodyEwidencyjny = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->samochodyRejestrcyjny = (gcnew System::Windows::Forms::TextBox());
			this->samochodyModel = (gcnew System::Windows::Forms::TextBox());
			this->samochodyMarka = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->samochodySamochodPrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->szmochodySamochodTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->samochodySamochodTabela = (gcnew System::Windows::Forms::DataGridView());
			this->tabPracownicy = (gcnew System::Windows::Forms::TabPage());
			this->pracownicyDodaj = (gcnew System::Windows::Forms::Button());
			this->pracownicyModyfikuj = (gcnew System::Windows::Forms::Button());
			this->pracownicyUsun = (gcnew System::Windows::Forms::Button());
			this->pracownicyGp = (gcnew System::Windows::Forms::GroupBox());
			this->pracownicyNazwaUzytkownika = (gcnew System::Windows::Forms::TextBox());
			this->pracownicyNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->pracownicyImie = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pracownicyPrzyciskSzukaj = (gcnew System::Windows::Forms::Button());
			this->pracownicyTextSzukaj = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pracownicyTabela = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1->SuspendLayout();
			this->tabZlecenia->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlecenieZlecenieTabela))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zleceniePracownicyTabela))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlecenieSamochodTabela))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlecenieKlientTabela))->BeginInit();
			this->tabMagazyn->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magazynZlecenieTabela))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magazynCzescTabela))->BeginInit();
			this->tabKlienci->SuspendLayout();
			this->klientGb->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klientTabela))->BeginInit();
			this->tabSamochody->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->samochodyKlientTabela))->BeginInit();
			this->samochodyGb->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->samochodySamochodTabela))->BeginInit();
			this->tabPracownicy->SuspendLayout();
			this->pracownicyGp->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pracownicyTabela))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
			this->tabControl1->Controls->Add(this->tabZlecenia);
			this->tabControl1->Controls->Add(this->tabMagazyn);
			this->tabControl1->Controls->Add(this->tabKlienci);
			this->tabControl1->Controls->Add(this->tabSamochody);
			this->tabControl1->Controls->Add(this->tabPracownicy);
			this->tabControl1->ItemSize = System::Drawing::Size(70, 30);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(984, 706);
			this->tabControl1->TabIndex = 0;
			// 
			// tabZlecenia
			// 
			this->tabZlecenia->Controls->Add(this->label35);
			this->tabZlecenia->Controls->Add(this->label34);
			this->tabZlecenia->Controls->Add(this->label25);
			this->tabZlecenia->Controls->Add(this->label24);
			this->tabZlecenia->Controls->Add(this->label23);
			this->tabZlecenia->Controls->Add(this->zlecenieDodaj);
			this->tabZlecenia->Controls->Add(this->zlecenieModyfikuj);
			this->tabZlecenia->Controls->Add(this->zlecenieUsun);
			this->tabZlecenia->Controls->Add(this->zlecenieZlecenieTabela);
			this->tabZlecenia->Controls->Add(this->zleceniePracownicyTabela);
			this->tabZlecenia->Controls->Add(this->zlecenieOpis);
			this->tabZlecenia->Controls->Add(this->zlecenieSamochodTabela);
			this->tabZlecenia->Controls->Add(this->zleceniaSamochodPrzyciskSzukaj);
			this->tabZlecenia->Controls->Add(this->zleceniaSamochodTextSzukaj);
			this->tabZlecenia->Controls->Add(this->label22);
			this->tabZlecenia->Controls->Add(this->zlecenieKlientTabela);
			this->tabZlecenia->Controls->Add(this->zleceniaKlientPrzyciskSzukaj);
			this->tabZlecenia->Controls->Add(this->zleceniaKlientTextSzukaj);
			this->tabZlecenia->Controls->Add(this->label21);
			this->tabZlecenia->Location = System::Drawing::Point(4, 34);
			this->tabZlecenia->Name = L"tabZlecenia";
			this->tabZlecenia->Padding = System::Windows::Forms::Padding(3);
			this->tabZlecenia->Size = System::Drawing::Size(976, 668);
			this->tabZlecenia->TabIndex = 0;
			this->tabZlecenia->Text = L"Zlecenia";
			this->tabZlecenia->UseVisualStyleBackColor = true;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(535, 330);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(84, 15);
			this->label35->TabIndex = 55;
			this->label35->Text = L"Pracownicy:";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(260, 330);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(42, 15);
			this->label34->TabIndex = 54;
			this->label34->Text = L"Opis:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(6, 330);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(126, 15);
			this->label25->TabIndex = 53;
			this->label25->Text = L"Aktywne zlecenia:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(6, 98);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(119, 15);
			this->label24->TabIndex = 52;
			this->label24->Text = L"Wybierz Klienta:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(7, 259);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(126, 15);
			this->label23->TabIndex = 51;
			this->label23->Text = L"Wybierz samochod:";
			// 
			// zlecenieDodaj
			// 
			this->zlecenieDodaj->Location = System::Drawing::Point(820, 549);
			this->zlecenieDodaj->Margin = System::Windows::Forms::Padding(4);
			this->zlecenieDodaj->Name = L"zlecenieDodaj";
			this->zlecenieDodaj->Size = System::Drawing::Size(149, 112);
			this->zlecenieDodaj->TabIndex = 50;
			this->zlecenieDodaj->Text = L"Dodaj";
			this->zlecenieDodaj->UseVisualStyleBackColor = true;
			this->zlecenieDodaj->Click += gcnew System::EventHandler(this, &UIKierownika::zlecenieDodaj_Click);
			// 
			// zlecenieModyfikuj
			// 
			this->zlecenieModyfikuj->Enabled = false;
			this->zlecenieModyfikuj->Location = System::Drawing::Point(820, 402);
			this->zlecenieModyfikuj->Margin = System::Windows::Forms::Padding(4);
			this->zlecenieModyfikuj->Name = L"zlecenieModyfikuj";
			this->zlecenieModyfikuj->Size = System::Drawing::Size(149, 139);
			this->zlecenieModyfikuj->TabIndex = 49;
			this->zlecenieModyfikuj->Text = L"Modyfikuj";
			this->zlecenieModyfikuj->UseVisualStyleBackColor = true;
			this->zlecenieModyfikuj->Click += gcnew System::EventHandler(this, &UIKierownika::zlecenieModyfikuj_Click);
			// 
			// zlecenieUsun
			// 
			this->zlecenieUsun->Enabled = false;
			this->zlecenieUsun->Location = System::Drawing::Point(820, 348);
			this->zlecenieUsun->Margin = System::Windows::Forms::Padding(4);
			this->zlecenieUsun->Name = L"zlecenieUsun";
			this->zlecenieUsun->Size = System::Drawing::Size(149, 46);
			this->zlecenieUsun->TabIndex = 48;
			this->zlecenieUsun->Text = L"Anuluj";
			this->zlecenieUsun->UseVisualStyleBackColor = true;
			this->zlecenieUsun->Click += gcnew System::EventHandler(this, &UIKierownika::zlecenieUsun_Click);
			// 
			// zlecenieZlecenieTabela
			// 
			this->zlecenieZlecenieTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->zlecenieZlecenieTabela->Location = System::Drawing::Point(9, 348);
			this->zlecenieZlecenieTabela->Name = L"zlecenieZlecenieTabela";
			this->zlecenieZlecenieTabela->Size = System::Drawing::Size(248, 314);
			this->zlecenieZlecenieTabela->TabIndex = 47;
			this->zlecenieZlecenieTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::zlecenieZlecenieTabela_CellClick);
			// 
			// zleceniePracownicyTabela
			// 
			this->zleceniePracownicyTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->zleceniePracownicyTabela->Location = System::Drawing::Point(538, 348);
			this->zleceniePracownicyTabela->Name = L"zleceniePracownicyTabela";
			this->zleceniePracownicyTabela->Size = System::Drawing::Size(275, 314);
			this->zleceniePracownicyTabela->TabIndex = 46;
			this->zleceniePracownicyTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::zleceniePracownicyTabela_CellClick);
			// 
			// zlecenieOpis
			// 
			this->zlecenieOpis->Location = System::Drawing::Point(263, 348);
			this->zlecenieOpis->Multiline = true;
			this->zlecenieOpis->Name = L"zlecenieOpis";
			this->zlecenieOpis->Size = System::Drawing::Size(269, 313);
			this->zlecenieOpis->TabIndex = 45;
			// 
			// zlecenieSamochodTabela
			// 
			this->zlecenieSamochodTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->zlecenieSamochodTabela->Location = System::Drawing::Point(136, 206);
			this->zlecenieSamochodTabela->Name = L"zlecenieSamochodTabela";
			this->zlecenieSamochodTabela->Size = System::Drawing::Size(834, 121);
			this->zlecenieSamochodTabela->TabIndex = 44;
			this->zlecenieSamochodTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::zlecenieSamochodTabela_CellClick);
			// 
			// zleceniaSamochodPrzyciskSzukaj
			// 
			this->zleceniaSamochodPrzyciskSzukaj->Location = System::Drawing::Point(432, 173);
			this->zleceniaSamochodPrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->zleceniaSamochodPrzyciskSzukaj->Name = L"zleceniaSamochodPrzyciskSzukaj";
			this->zleceniaSamochodPrzyciskSzukaj->Size = System::Drawing::Size(100, 26);
			this->zleceniaSamochodPrzyciskSzukaj->TabIndex = 43;
			this->zleceniaSamochodPrzyciskSzukaj->Text = L"Szukaj";
			this->zleceniaSamochodPrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->zleceniaSamochodPrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::zleceniaSamochodPrzyciskSzukaj_Click);
			// 
			// zleceniaSamochodTextSzukaj
			// 
			this->zleceniaSamochodTextSzukaj->Location = System::Drawing::Point(136, 175);
			this->zleceniaSamochodTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->zleceniaSamochodTextSzukaj->Name = L"zleceniaSamochodTextSzukaj";
			this->zleceniaSamochodTextSzukaj->Size = System::Drawing::Size(288, 23);
			this->zleceniaSamochodTextSzukaj->TabIndex = 42;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(6, 178);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(126, 15);
			this->label22->TabIndex = 41;
			this->label22->Text = L"Szukaj samochodu:";
			// 
			// zlecenieKlientTabela
			// 
			this->zlecenieKlientTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->zlecenieKlientTabela->Location = System::Drawing::Point(136, 37);
			this->zlecenieKlientTabela->Name = L"zlecenieKlientTabela";
			this->zlecenieKlientTabela->Size = System::Drawing::Size(834, 131);
			this->zlecenieKlientTabela->TabIndex = 40;
			this->zlecenieKlientTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::zlecenieKlientTabela_CellClick);
			// 
			// zleceniaKlientPrzyciskSzukaj
			// 
			this->zleceniaKlientPrzyciskSzukaj->Location = System::Drawing::Point(432, 7);
			this->zleceniaKlientPrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->zleceniaKlientPrzyciskSzukaj->Name = L"zleceniaKlientPrzyciskSzukaj";
			this->zleceniaKlientPrzyciskSzukaj->Size = System::Drawing::Size(100, 23);
			this->zleceniaKlientPrzyciskSzukaj->TabIndex = 39;
			this->zleceniaKlientPrzyciskSzukaj->Text = L"Szukaj";
			this->zleceniaKlientPrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->zleceniaKlientPrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::zleceniaKlientPrzyciskSzukaj_Click);
			// 
			// zleceniaKlientTextSzukaj
			// 
			this->zleceniaKlientTextSzukaj->Location = System::Drawing::Point(133, 7);
			this->zleceniaKlientTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->zleceniaKlientTextSzukaj->Name = L"zleceniaKlientTextSzukaj";
			this->zleceniaKlientTextSzukaj->Size = System::Drawing::Size(291, 23);
			this->zleceniaKlientTextSzukaj->TabIndex = 38;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(7, 12);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(112, 15);
			this->label21->TabIndex = 37;
			this->label21->Text = L"Szukaj klienta:";
			// 
			// tabMagazyn
			// 
			this->tabMagazyn->Controls->Add(this->magazynZlecenieTabela);
			this->tabMagazyn->Controls->Add(this->magazynZleceniePrzyciskSzukaj);
			this->tabMagazyn->Controls->Add(this->magazynZlecenieTextSzukaj);
			this->tabMagazyn->Controls->Add(this->label20);
			this->tabMagazyn->Controls->Add(this->magazynCzescPrzyciskSzukaj);
			this->tabMagazyn->Controls->Add(this->magazynCzescTextSzukaj);
			this->tabMagazyn->Controls->Add(this->label17);
			this->tabMagazyn->Controls->Add(this->magazynCzescTabela);
			this->tabMagazyn->Location = System::Drawing::Point(4, 34);
			this->tabMagazyn->Name = L"tabMagazyn";
			this->tabMagazyn->Padding = System::Windows::Forms::Padding(3);
			this->tabMagazyn->Size = System::Drawing::Size(976, 668);
			this->tabMagazyn->TabIndex = 1;
			this->tabMagazyn->Text = L"Magazyn";
			this->tabMagazyn->UseVisualStyleBackColor = true;
			// 
			// magazynZlecenieTabela
			// 
			this->magazynZlecenieTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->magazynZlecenieTabela->Location = System::Drawing::Point(10, 70);
			this->magazynZlecenieTabela->Name = L"magazynZlecenieTabela";
			this->magazynZlecenieTabela->Size = System::Drawing::Size(404, 592);
			this->magazynZlecenieTabela->TabIndex = 37;
			this->magazynZlecenieTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::magazynZlecenieTabela_CellClick);
			// 
			// magazynZleceniePrzyciskSzukaj
			// 
			this->magazynZleceniePrzyciskSzukaj->Location = System::Drawing::Point(313, 38);
			this->magazynZleceniePrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->magazynZleceniePrzyciskSzukaj->Name = L"magazynZleceniePrzyciskSzukaj";
			this->magazynZleceniePrzyciskSzukaj->Size = System::Drawing::Size(100, 24);
			this->magazynZleceniePrzyciskSzukaj->TabIndex = 36;
			this->magazynZleceniePrzyciskSzukaj->Text = L"Szukaj";
			this->magazynZleceniePrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->magazynZleceniePrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::magazynZleceniePrzyciskSzukaj_Click);
			// 
			// magazynZlecenieTextSzukaj
			// 
			this->magazynZlecenieTextSzukaj->Location = System::Drawing::Point(136, 37);
			this->magazynZlecenieTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->magazynZlecenieTextSzukaj->Name = L"magazynZlecenieTextSzukaj";
			this->magazynZlecenieTextSzukaj->Size = System::Drawing::Size(169, 23);
			this->magazynZlecenieTextSzukaj->TabIndex = 35;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(6, 40);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(119, 15);
			this->label20->TabIndex = 34;
			this->label20->Text = L"Szukaj zlecenia:";
			// 
			// magazynCzescPrzyciskSzukaj
			// 
			this->magazynCzescPrzyciskSzukaj->Location = System::Drawing::Point(401, 7);
			this->magazynCzescPrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->magazynCzescPrzyciskSzukaj->Name = L"magazynCzescPrzyciskSzukaj";
			this->magazynCzescPrzyciskSzukaj->Size = System::Drawing::Size(102, 23);
			this->magazynCzescPrzyciskSzukaj->TabIndex = 28;
			this->magazynCzescPrzyciskSzukaj->Text = L"Szukaj";
			this->magazynCzescPrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->magazynCzescPrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::magazynCzescPrzyciskSzukaj_Click);
			// 
			// magazynCzescTextSzukaj
			// 
			this->magazynCzescTextSzukaj->Location = System::Drawing::Point(120, 7);
			this->magazynCzescTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->magazynCzescTextSzukaj->Name = L"magazynCzescTextSzukaj";
			this->magazynCzescTextSzukaj->Size = System::Drawing::Size(273, 23);
			this->magazynCzescTextSzukaj->TabIndex = 27;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(7, 7);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(105, 15);
			this->label17->TabIndex = 26;
			this->label17->Text = L"Szukaj czêœci:";
			// 
			// magazynCzescTabela
			// 
			this->magazynCzescTabela->AllowUserToAddRows = false;
			this->magazynCzescTabela->AllowUserToDeleteRows = false;
			this->magazynCzescTabela->AllowUserToOrderColumns = true;
			this->magazynCzescTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->magazynCzescTabela->Location = System::Drawing::Point(421, 38);
			this->magazynCzescTabela->Margin = System::Windows::Forms::Padding(4);
			this->magazynCzescTabela->Name = L"magazynCzescTabela";
			this->magazynCzescTabela->ReadOnly = true;
			this->magazynCzescTabela->RowHeadersWidth = 30;
			this->magazynCzescTabela->Size = System::Drawing::Size(551, 625);
			this->magazynCzescTabela->TabIndex = 25;
			this->magazynCzescTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::magazynCzescTabela_CellClick);
			// 
			// tabKlienci
			// 
			this->tabKlienci->Controls->Add(this->klientGb);
			this->tabKlienci->Controls->Add(this->klientDodaj);
			this->tabKlienci->Controls->Add(this->klientModyfikuj);
			this->tabKlienci->Controls->Add(this->klientUsun);
			this->tabKlienci->Controls->Add(this->klientPrzyciskSzukaj);
			this->tabKlienci->Controls->Add(this->klientTextSzukaj);
			this->tabKlienci->Controls->Add(this->label12);
			this->tabKlienci->Controls->Add(this->klientTabela);
			this->tabKlienci->Location = System::Drawing::Point(4, 34);
			this->tabKlienci->Name = L"tabKlienci";
			this->tabKlienci->Size = System::Drawing::Size(976, 668);
			this->tabKlienci->TabIndex = 2;
			this->tabKlienci->Text = L"Klienci";
			this->tabKlienci->UseVisualStyleBackColor = true;
			// 
			// klientGb
			// 
			this->klientGb->Controls->Add(this->klientPesel);
			this->klientGb->Controls->Add(this->label10);
			this->klientGb->Controls->Add(this->klientNip);
			this->klientGb->Controls->Add(this->label9);
			this->klientGb->Controls->Add(this->klientKod);
			this->klientGb->Controls->Add(this->klientMiejscowosc);
			this->klientGb->Controls->Add(this->klientNumer);
			this->klientGb->Controls->Add(this->klientUlica);
			this->klientGb->Controls->Add(this->klientFirma);
			this->klientGb->Controls->Add(this->klientEmail);
			this->klientGb->Controls->Add(this->klientNazwisko);
			this->klientGb->Controls->Add(this->klientImie);
			this->klientGb->Controls->Add(this->label33);
			this->klientGb->Controls->Add(this->label32);
			this->klientGb->Controls->Add(this->label31);
			this->klientGb->Controls->Add(this->label30);
			this->klientGb->Controls->Add(this->label29);
			this->klientGb->Controls->Add(this->label28);
			this->klientGb->Controls->Add(this->label27);
			this->klientGb->Controls->Add(this->label26);
			this->klientGb->Location = System::Drawing::Point(295, 10);
			this->klientGb->Margin = System::Windows::Forms::Padding(4);
			this->klientGb->Name = L"klientGb";
			this->klientGb->Padding = System::Windows::Forms::Padding(4);
			this->klientGb->Size = System::Drawing::Size(520, 205);
			this->klientGb->TabIndex = 33;
			this->klientGb->TabStop = false;
			this->klientGb->Text = L"Edycja danych klienta:";
			// 
			// klientPesel
			// 
			this->klientPesel->Location = System::Drawing::Point(343, 165);
			this->klientPesel->Margin = System::Windows::Forms::Padding(4);
			this->klientPesel->Name = L"klientPesel";
			this->klientPesel->Size = System::Drawing::Size(169, 23);
			this->klientPesel->TabIndex = 20;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(253, 168);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 15);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Pesel:";
			// 
			// klientNip
			// 
			this->klientNip->Location = System::Drawing::Point(86, 165);
			this->klientNip->Margin = System::Windows::Forms::Padding(4);
			this->klientNip->Name = L"klientNip";
			this->klientNip->Size = System::Drawing::Size(159, 23);
			this->klientNip->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(8, 168);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 15);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Nip:";
			// 
			// klientKod
			// 
			this->klientKod->Location = System::Drawing::Point(359, 98);
			this->klientKod->Margin = System::Windows::Forms::Padding(4);
			this->klientKod->Mask = L"00-999";
			this->klientKod->Name = L"klientKod";
			this->klientKod->Size = System::Drawing::Size(55, 23);
			this->klientKod->TabIndex = 16;
			// 
			// klientMiejscowosc
			// 
			this->klientMiejscowosc->Location = System::Drawing::Point(343, 134);
			this->klientMiejscowosc->Margin = System::Windows::Forms::Padding(4);
			this->klientMiejscowosc->Name = L"klientMiejscowosc";
			this->klientMiejscowosc->Size = System::Drawing::Size(169, 23);
			this->klientMiejscowosc->TabIndex = 15;
			// 
			// klientNumer
			// 
			this->klientNumer->Location = System::Drawing::Point(359, 62);
			this->klientNumer->Margin = System::Windows::Forms::Padding(4);
			this->klientNumer->Name = L"klientNumer";
			this->klientNumer->Size = System::Drawing::Size(55, 23);
			this->klientNumer->TabIndex = 13;
			// 
			// klientUlica
			// 
			this->klientUlica->Location = System::Drawing::Point(343, 26);
			this->klientUlica->Margin = System::Windows::Forms::Padding(4);
			this->klientUlica->Name = L"klientUlica";
			this->klientUlica->Size = System::Drawing::Size(169, 23);
			this->klientUlica->TabIndex = 12;
			// 
			// klientFirma
			// 
			this->klientFirma->Location = System::Drawing::Point(86, 134);
			this->klientFirma->Margin = System::Windows::Forms::Padding(4);
			this->klientFirma->Name = L"klientFirma";
			this->klientFirma->Size = System::Drawing::Size(159, 23);
			this->klientFirma->TabIndex = 11;
			// 
			// klientEmail
			// 
			this->klientEmail->Location = System::Drawing::Point(86, 98);
			this->klientEmail->Margin = System::Windows::Forms::Padding(4);
			this->klientEmail->Name = L"klientEmail";
			this->klientEmail->Size = System::Drawing::Size(159, 23);
			this->klientEmail->TabIndex = 10;
			// 
			// klientNazwisko
			// 
			this->klientNazwisko->Location = System::Drawing::Point(86, 62);
			this->klientNazwisko->Margin = System::Windows::Forms::Padding(4);
			this->klientNazwisko->Name = L"klientNazwisko";
			this->klientNazwisko->Size = System::Drawing::Size(159, 23);
			this->klientNazwisko->TabIndex = 9;
			// 
			// klientImie
			// 
			this->klientImie->Location = System::Drawing::Point(86, 26);
			this->klientImie->Margin = System::Windows::Forms::Padding(4);
			this->klientImie->Name = L"klientImie";
			this->klientImie->Size = System::Drawing::Size(159, 23);
			this->klientImie->TabIndex = 8;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(253, 137);
			this->label33->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(91, 15);
			this->label33->TabIndex = 7;
			this->label33->Text = L"Miejscowoœæ:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(253, 101);
			this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(98, 15);
			this->label32->TabIndex = 6;
			this->label32->Text = L"Kod pocztowy:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(253, 65);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(49, 15);
			this->label31->TabIndex = 5;
			this->label31->Text = L"Numer:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(253, 29);
			this->label30->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(49, 15);
			this->label30->TabIndex = 4;
			this->label30->Text = L"Ulica:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(8, 137);
			this->label29->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(49, 15);
			this->label29->TabIndex = 3;
			this->label29->Text = L"Firma:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(8, 101);
			this->label28->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(49, 15);
			this->label28->TabIndex = 2;
			this->label28->Text = L"email:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(8, 65);
			this->label27->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(70, 15);
			this->label27->TabIndex = 1;
			this->label27->Text = L"Nazwisko:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(8, 29);
			this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(42, 15);
			this->label26->TabIndex = 0;
			this->label26->Text = L"Imiê:";
			// 
			// klientDodaj
			// 
			this->klientDodaj->Location = System::Drawing::Point(823, 163);
			this->klientDodaj->Margin = System::Windows::Forms::Padding(4);
			this->klientDodaj->Name = L"klientDodaj";
			this->klientDodaj->Size = System::Drawing::Size(149, 52);
			this->klientDodaj->TabIndex = 32;
			this->klientDodaj->Text = L"Dodaj";
			this->klientDodaj->UseVisualStyleBackColor = true;
			this->klientDodaj->Click += gcnew System::EventHandler(this, &UIKierownika::klientDodaj_Click);
			// 
			// klientModyfikuj
			// 
			this->klientModyfikuj->Enabled = false;
			this->klientModyfikuj->Location = System::Drawing::Point(823, 79);
			this->klientModyfikuj->Margin = System::Windows::Forms::Padding(4);
			this->klientModyfikuj->Name = L"klientModyfikuj";
			this->klientModyfikuj->Size = System::Drawing::Size(149, 76);
			this->klientModyfikuj->TabIndex = 31;
			this->klientModyfikuj->Text = L"Modyfikuj";
			this->klientModyfikuj->UseVisualStyleBackColor = true;
			this->klientModyfikuj->Click += gcnew System::EventHandler(this, &UIKierownika::klientModyfikuj_Click);
			// 
			// klientUsun
			// 
			this->klientUsun->Enabled = false;
			this->klientUsun->Location = System::Drawing::Point(823, 22);
			this->klientUsun->Margin = System::Windows::Forms::Padding(4);
			this->klientUsun->Name = L"klientUsun";
			this->klientUsun->Size = System::Drawing::Size(149, 49);
			this->klientUsun->TabIndex = 30;
			this->klientUsun->Text = L"Usuñ";
			this->klientUsun->UseVisualStyleBackColor = true;
			this->klientUsun->Click += gcnew System::EventHandler(this, &UIKierownika::klientUsun_Click);
			// 
			// klientPrzyciskSzukaj
			// 
			this->klientPrzyciskSzukaj->Location = System::Drawing::Point(7, 67);
			this->klientPrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->klientPrzyciskSzukaj->Name = L"klientPrzyciskSzukaj";
			this->klientPrzyciskSzukaj->Size = System::Drawing::Size(280, 148);
			this->klientPrzyciskSzukaj->TabIndex = 28;
			this->klientPrzyciskSzukaj->Text = L"Szukaj";
			this->klientPrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->klientPrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::klientPrzyciskSzukaj_Click);
			// 
			// klientTextSzukaj
			// 
			this->klientTextSzukaj->Location = System::Drawing::Point(7, 36);
			this->klientTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->klientTextSzukaj->Name = L"klientTextSzukaj";
			this->klientTextSzukaj->Size = System::Drawing::Size(280, 23);
			this->klientTextSzukaj->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(4, 10);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(112, 15);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Szukaj klienta:";
			// 
			// klientTabela
			// 
			this->klientTabela->AllowUserToAddRows = false;
			this->klientTabela->AllowUserToDeleteRows = false;
			this->klientTabela->AllowUserToOrderColumns = true;
			this->klientTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->klientTabela->Location = System::Drawing::Point(4, 223);
			this->klientTabela->Margin = System::Windows::Forms::Padding(4);
			this->klientTabela->Name = L"klientTabela";
			this->klientTabela->ReadOnly = true;
			this->klientTabela->RowHeadersWidth = 30;
			this->klientTabela->Size = System::Drawing::Size(968, 441);
			this->klientTabela->TabIndex = 25;
			this->klientTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::klientTabela_CellClick);
			// 
			// tabSamochody
			// 
			this->tabSamochody->Controls->Add(this->samochodyKlientTabela);
			this->tabSamochody->Controls->Add(this->samochodyKlientPrzyciskSzukaj);
			this->tabSamochody->Controls->Add(this->samochodyKlientTextSzukaj);
			this->tabSamochody->Controls->Add(this->label11);
			this->tabSamochody->Controls->Add(this->samochodyDodaj);
			this->tabSamochody->Controls->Add(this->samochodyModyfikuj);
			this->tabSamochody->Controls->Add(this->samochodyUsun);
			this->tabSamochody->Controls->Add(this->samochodyGb);
			this->tabSamochody->Controls->Add(this->samochodySamochodPrzyciskSzukaj);
			this->tabSamochody->Controls->Add(this->szmochodySamochodTextSzukaj);
			this->tabSamochody->Controls->Add(this->label8);
			this->tabSamochody->Controls->Add(this->samochodySamochodTabela);
			this->tabSamochody->Location = System::Drawing::Point(4, 34);
			this->tabSamochody->Name = L"tabSamochody";
			this->tabSamochody->Size = System::Drawing::Size(976, 668);
			this->tabSamochody->TabIndex = 3;
			this->tabSamochody->Text = L"Samochody";
			this->tabSamochody->UseVisualStyleBackColor = true;
			// 
			// samochodyKlientTabela
			// 
			this->samochodyKlientTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->samochodyKlientTabela->Location = System::Drawing::Point(7, 269);
			this->samochodyKlientTabela->Name = L"samochodyKlientTabela";
			this->samochodyKlientTabela->Size = System::Drawing::Size(520, 395);
			this->samochodyKlientTabela->TabIndex = 36;
			this->samochodyKlientTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::samochodyKlientTabela_CellClick);
			// 
			// samochodyKlientPrzyciskSzukaj
			// 
			this->samochodyKlientPrzyciskSzukaj->Location = System::Drawing::Point(409, 230);
			this->samochodyKlientPrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->samochodyKlientPrzyciskSzukaj->Name = L"samochodyKlientPrzyciskSzukaj";
			this->samochodyKlientPrzyciskSzukaj->Size = System::Drawing::Size(118, 32);
			this->samochodyKlientPrzyciskSzukaj->TabIndex = 35;
			this->samochodyKlientPrzyciskSzukaj->Text = L"Szukaj";
			this->samochodyKlientPrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->samochodyKlientPrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::samochodyKlientPrzyciskSzukaj_Click);
			// 
			// samochodyKlientTextSzukaj
			// 
			this->samochodyKlientTextSzukaj->Location = System::Drawing::Point(121, 236);
			this->samochodyKlientTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->samochodyKlientTextSzukaj->Name = L"samochodyKlientTextSzukaj";
			this->samochodyKlientTextSzukaj->Size = System::Drawing::Size(280, 23);
			this->samochodyKlientTextSzukaj->TabIndex = 34;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(4, 239);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(112, 15);
			this->label11->TabIndex = 33;
			this->label11->Text = L"Szukaj klienta:";
			// 
			// samochodyDodaj
			// 
			this->samochodyDodaj->Location = System::Drawing::Point(359, 190);
			this->samochodyDodaj->Margin = System::Windows::Forms::Padding(4);
			this->samochodyDodaj->Name = L"samochodyDodaj";
			this->samochodyDodaj->Size = System::Drawing::Size(168, 32);
			this->samochodyDodaj->TabIndex = 32;
			this->samochodyDodaj->Text = L"Dodaj";
			this->samochodyDodaj->UseVisualStyleBackColor = true;
			this->samochodyDodaj->Click += gcnew System::EventHandler(this, &UIKierownika::samochodyDodaj_Click);
			// 
			// samochodyModyfikuj
			// 
			this->samochodyModyfikuj->Enabled = false;
			this->samochodyModyfikuj->Location = System::Drawing::Point(164, 190);
			this->samochodyModyfikuj->Margin = System::Windows::Forms::Padding(4);
			this->samochodyModyfikuj->Name = L"samochodyModyfikuj";
			this->samochodyModyfikuj->Size = System::Drawing::Size(187, 32);
			this->samochodyModyfikuj->TabIndex = 31;
			this->samochodyModyfikuj->Text = L"Modyfikuj";
			this->samochodyModyfikuj->UseVisualStyleBackColor = true;
			this->samochodyModyfikuj->Click += gcnew System::EventHandler(this, &UIKierownika::samochodyModyfikuj_Click);
			// 
			// samochodyUsun
			// 
			this->samochodyUsun->Enabled = false;
			this->samochodyUsun->Location = System::Drawing::Point(6, 190);
			this->samochodyUsun->Margin = System::Windows::Forms::Padding(4);
			this->samochodyUsun->Name = L"samochodyUsun";
			this->samochodyUsun->Size = System::Drawing::Size(149, 32);
			this->samochodyUsun->TabIndex = 30;
			this->samochodyUsun->Text = L"Usuñ";
			this->samochodyUsun->UseVisualStyleBackColor = true;
			this->samochodyUsun->Click += gcnew System::EventHandler(this, &UIKierownika::samochodyUsun_Click);
			// 
			// samochodyGb
			// 
			this->samochodyGb->Controls->Add(this->samochodyEwidencyjny);
			this->samochodyGb->Controls->Add(this->label13);
			this->samochodyGb->Controls->Add(this->samochodyRejestrcyjny);
			this->samochodyGb->Controls->Add(this->samochodyModel);
			this->samochodyGb->Controls->Add(this->samochodyMarka);
			this->samochodyGb->Controls->Add(this->label1);
			this->samochodyGb->Controls->Add(this->label2);
			this->samochodyGb->Controls->Add(this->label3);
			this->samochodyGb->Location = System::Drawing::Point(7, 38);
			this->samochodyGb->Margin = System::Windows::Forms::Padding(4);
			this->samochodyGb->Name = L"samochodyGb";
			this->samochodyGb->Padding = System::Windows::Forms::Padding(4);
			this->samochodyGb->Size = System::Drawing::Size(520, 144);
			this->samochodyGb->TabIndex = 29;
			this->samochodyGb->TabStop = false;
			this->samochodyGb->Text = L"Edycja danych samochodu";
			// 
			// samochodyEwidencyjny
			// 
			this->samochodyEwidencyjny->Location = System::Drawing::Point(156, 111);
			this->samochodyEwidencyjny->Margin = System::Windows::Forms::Padding(4);
			this->samochodyEwidencyjny->Name = L"samochodyEwidencyjny";
			this->samochodyEwidencyjny->Size = System::Drawing::Size(356, 23);
			this->samochodyEwidencyjny->TabIndex = 7;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(8, 114);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(112, 15);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Nr ewidencyjny:";
			// 
			// samochodyRejestrcyjny
			// 
			this->samochodyRejestrcyjny->Location = System::Drawing::Point(156, 80);
			this->samochodyRejestrcyjny->Margin = System::Windows::Forms::Padding(4);
			this->samochodyRejestrcyjny->Name = L"samochodyRejestrcyjny";
			this->samochodyRejestrcyjny->Size = System::Drawing::Size(356, 23);
			this->samochodyRejestrcyjny->TabIndex = 5;
			// 
			// samochodyModel
			// 
			this->samochodyModel->Location = System::Drawing::Point(156, 49);
			this->samochodyModel->Margin = System::Windows::Forms::Padding(4);
			this->samochodyModel->Name = L"samochodyModel";
			this->samochodyModel->Size = System::Drawing::Size(356, 23);
			this->samochodyModel->TabIndex = 4;
			// 
			// samochodyMarka
			// 
			this->samochodyMarka->Location = System::Drawing::Point(156, 18);
			this->samochodyMarka->Margin = System::Windows::Forms::Padding(4);
			this->samochodyMarka->Name = L"samochodyMarka";
			this->samochodyMarka->Size = System::Drawing::Size(356, 23);
			this->samochodyMarka->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 83);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nr rejestracyjny:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 52);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Model:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 21);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 15);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Marka:";
			// 
			// samochodySamochodPrzyciskSzukaj
			// 
			this->samochodySamochodPrzyciskSzukaj->Location = System::Drawing::Point(427, 6);
			this->samochodySamochodPrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->samochodySamochodPrzyciskSzukaj->Name = L"samochodySamochodPrzyciskSzukaj";
			this->samochodySamochodPrzyciskSzukaj->Size = System::Drawing::Size(100, 24);
			this->samochodySamochodPrzyciskSzukaj->TabIndex = 28;
			this->samochodySamochodPrzyciskSzukaj->Text = L"Szukaj";
			this->samochodySamochodPrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->samochodySamochodPrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::samochodySamochodPrzyciskSzukaj_Click);
			// 
			// szmochodySamochodTextSzukaj
			// 
			this->szmochodySamochodTextSzukaj->Location = System::Drawing::Point(143, 7);
			this->szmochodySamochodTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->szmochodySamochodTextSzukaj->Name = L"szmochodySamochodTextSzukaj";
			this->szmochodySamochodTextSzukaj->Size = System::Drawing::Size(276, 23);
			this->szmochodySamochodTextSzukaj->TabIndex = 27;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(4, 10);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(126, 15);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Szukaj samochodu:";
			// 
			// samochodySamochodTabela
			// 
			this->samochodySamochodTabela->AllowUserToAddRows = false;
			this->samochodySamochodTabela->AllowUserToDeleteRows = false;
			this->samochodySamochodTabela->AllowUserToOrderColumns = true;
			this->samochodySamochodTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->samochodySamochodTabela->Location = System::Drawing::Point(535, 4);
			this->samochodySamochodTabela->Margin = System::Windows::Forms::Padding(4);
			this->samochodySamochodTabela->Name = L"samochodySamochodTabela";
			this->samochodySamochodTabela->ReadOnly = true;
			this->samochodySamochodTabela->RowHeadersWidth = 30;
			this->samochodySamochodTabela->Size = System::Drawing::Size(437, 660);
			this->samochodySamochodTabela->TabIndex = 25;
			this->samochodySamochodTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::samochodySamochodTabela_CellClick);
			// 
			// tabPracownicy
			// 
			this->tabPracownicy->Controls->Add(this->pracownicyDodaj);
			this->tabPracownicy->Controls->Add(this->pracownicyModyfikuj);
			this->tabPracownicy->Controls->Add(this->pracownicyUsun);
			this->tabPracownicy->Controls->Add(this->pracownicyGp);
			this->tabPracownicy->Controls->Add(this->pracownicyPrzyciskSzukaj);
			this->tabPracownicy->Controls->Add(this->pracownicyTextSzukaj);
			this->tabPracownicy->Controls->Add(this->label4);
			this->tabPracownicy->Controls->Add(this->pracownicyTabela);
			this->tabPracownicy->Location = System::Drawing::Point(4, 34);
			this->tabPracownicy->Name = L"tabPracownicy";
			this->tabPracownicy->Size = System::Drawing::Size(976, 668);
			this->tabPracownicy->TabIndex = 4;
			this->tabPracownicy->Text = L"Pracownicy";
			this->tabPracownicy->UseVisualStyleBackColor = true;
			// 
			// pracownicyDodaj
			// 
			this->pracownicyDodaj->Location = System::Drawing::Point(823, 108);
			this->pracownicyDodaj->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyDodaj->Name = L"pracownicyDodaj";
			this->pracownicyDodaj->Size = System::Drawing::Size(149, 32);
			this->pracownicyDodaj->TabIndex = 24;
			this->pracownicyDodaj->Text = L"Dodaj";
			this->pracownicyDodaj->UseVisualStyleBackColor = true;
			this->pracownicyDodaj->Click += gcnew System::EventHandler(this, &UIKierownika::pracownicyDodaj_Click);
			// 
			// pracownicyModyfikuj
			// 
			this->pracownicyModyfikuj->Enabled = false;
			this->pracownicyModyfikuj->Location = System::Drawing::Point(823, 61);
			this->pracownicyModyfikuj->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyModyfikuj->Name = L"pracownicyModyfikuj";
			this->pracownicyModyfikuj->Size = System::Drawing::Size(149, 32);
			this->pracownicyModyfikuj->TabIndex = 23;
			this->pracownicyModyfikuj->Text = L"Modyfikuj";
			this->pracownicyModyfikuj->UseVisualStyleBackColor = true;
			this->pracownicyModyfikuj->Click += gcnew System::EventHandler(this, &UIKierownika::pracownicyModyfikuj_Click);
			// 
			// pracownicyUsun
			// 
			this->pracownicyUsun->Enabled = false;
			this->pracownicyUsun->Location = System::Drawing::Point(823, 16);
			this->pracownicyUsun->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyUsun->Name = L"pracownicyUsun";
			this->pracownicyUsun->Size = System::Drawing::Size(149, 32);
			this->pracownicyUsun->TabIndex = 22;
			this->pracownicyUsun->Text = L"Usuñ";
			this->pracownicyUsun->UseVisualStyleBackColor = true;
			this->pracownicyUsun->Click += gcnew System::EventHandler(this, &UIKierownika::pracownicyUsun_Click);
			// 
			// pracownicyGp
			// 
			this->pracownicyGp->Controls->Add(this->pracownicyNazwaUzytkownika);
			this->pracownicyGp->Controls->Add(this->pracownicyNazwisko);
			this->pracownicyGp->Controls->Add(this->pracownicyImie);
			this->pracownicyGp->Controls->Add(this->label7);
			this->pracownicyGp->Controls->Add(this->label6);
			this->pracownicyGp->Controls->Add(this->label5);
			this->pracownicyGp->Location = System::Drawing::Point(291, 7);
			this->pracownicyGp->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyGp->Name = L"pracownicyGp";
			this->pracownicyGp->Padding = System::Windows::Forms::Padding(4);
			this->pracownicyGp->Size = System::Drawing::Size(524, 133);
			this->pracownicyGp->TabIndex = 21;
			this->pracownicyGp->TabStop = false;
			this->pracownicyGp->Text = L"Edycja danych pracownika";
			// 
			// pracownicyNazwaUzytkownika
			// 
			this->pracownicyNazwaUzytkownika->Location = System::Drawing::Point(156, 96);
			this->pracownicyNazwaUzytkownika->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyNazwaUzytkownika->Name = L"pracownicyNazwaUzytkownika";
			this->pracownicyNazwaUzytkownika->Size = System::Drawing::Size(360, 23);
			this->pracownicyNazwaUzytkownika->TabIndex = 5;
			// 
			// pracownicyNazwisko
			// 
			this->pracownicyNazwisko->Location = System::Drawing::Point(156, 54);
			this->pracownicyNazwisko->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyNazwisko->Name = L"pracownicyNazwisko";
			this->pracownicyNazwisko->Size = System::Drawing::Size(360, 23);
			this->pracownicyNazwisko->TabIndex = 4;
			// 
			// pracownicyImie
			// 
			this->pracownicyImie->Location = System::Drawing::Point(156, 18);
			this->pracownicyImie->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyImie->Name = L"pracownicyImie";
			this->pracownicyImie->Size = System::Drawing::Size(360, 23);
			this->pracownicyImie->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 100);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(133, 15);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Nazwa u¿ytkownika:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 64);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 15);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Nazwisko:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 28);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 15);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Imiê:";
			// 
			// pracownicyPrzyciskSzukaj
			// 
			this->pracownicyPrzyciskSzukaj->Location = System::Drawing::Point(7, 74);
			this->pracownicyPrzyciskSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyPrzyciskSzukaj->Name = L"pracownicyPrzyciskSzukaj";
			this->pracownicyPrzyciskSzukaj->Size = System::Drawing::Size(276, 66);
			this->pracownicyPrzyciskSzukaj->TabIndex = 20;
			this->pracownicyPrzyciskSzukaj->Text = L"Szukaj";
			this->pracownicyPrzyciskSzukaj->UseVisualStyleBackColor = true;
			this->pracownicyPrzyciskSzukaj->Click += gcnew System::EventHandler(this, &UIKierownika::pracownicyPrzyciskSzukaj_Click);
			// 
			// pracownicyTextSzukaj
			// 
			this->pracownicyTextSzukaj->Location = System::Drawing::Point(7, 38);
			this->pracownicyTextSzukaj->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyTextSzukaj->Name = L"pracownicyTextSzukaj";
			this->pracownicyTextSzukaj->Size = System::Drawing::Size(276, 23);
			this->pracownicyTextSzukaj->TabIndex = 19;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 7);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(133, 15);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Szukaj pracownika:";
			// 
			// pracownicyTabela
			// 
			this->pracownicyTabela->AllowUserToAddRows = false;
			this->pracownicyTabela->AllowUserToDeleteRows = false;
			this->pracownicyTabela->AllowUserToOrderColumns = true;
			this->pracownicyTabela->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->pracownicyTabela->Location = System::Drawing::Point(7, 148);
			this->pracownicyTabela->Margin = System::Windows::Forms::Padding(4);
			this->pracownicyTabela->Name = L"pracownicyTabela";
			this->pracownicyTabela->ReadOnly = true;
			this->pracownicyTabela->RowHeadersWidth = 30;
			this->pracownicyTabela->Size = System::Drawing::Size(965, 516);
			this->pracownicyTabela->TabIndex = 17;
			this->pracownicyTabela->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UIKierownika::pracownicyTabela_CellClick);
			// 
			// UIKierownika
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 730);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Name = L"UIKierownika";
			this->Text = L"UIKierownika";
			this->tabControl1->ResumeLayout(false);
			this->tabZlecenia->ResumeLayout(false);
			this->tabZlecenia->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlecenieZlecenieTabela))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zleceniePracownicyTabela))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlecenieSamochodTabela))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zlecenieKlientTabela))->EndInit();
			this->tabMagazyn->ResumeLayout(false);
			this->tabMagazyn->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magazynZlecenieTabela))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->magazynCzescTabela))->EndInit();
			this->tabKlienci->ResumeLayout(false);
			this->tabKlienci->PerformLayout();
			this->klientGb->ResumeLayout(false);
			this->klientGb->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->klientTabela))->EndInit();
			this->tabSamochody->ResumeLayout(false);
			this->tabSamochody->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->samochodyKlientTabela))->EndInit();
			this->samochodyGb->ResumeLayout(false);
			this->samochodyGb->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->samochodySamochodTabela))->EndInit();
			this->tabPracownicy->ResumeLayout(false);
			this->tabPracownicy->PerformLayout();
			this->pracownicyGp->ResumeLayout(false);
			this->pracownicyGp->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pracownicyTabela))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pracownicyPrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pracownicyUsun_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pracownicyModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pracownicyDodaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void samochodySamochodTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void samochodyKlientTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void pracownicyTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void samochodySamochodPrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void samochodyUsun_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void samochodyModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void samochodyDodaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void samochodyKlientPrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void klientPrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void klientUsun_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void klientModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void klientDodaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void klientTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void magazynCzescPrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void magazynZleceniePrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void magazynCzescTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void magazynZlecenieTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void zleceniaKlientPrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void zleceniaSamochodPrzyciskSzukaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void zlecenieUsun_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void zlecenieModyfikuj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void zlecenieDodaj_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void zlecenieKlientTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void zlecenieSamochodTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void zlecenieZlecenieTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void zleceniePracownicyTabela_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	};
}
