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
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Button^  tab1BtnAdd;
	private: System::Windows::Forms::Button^  tab1BtnModify;
	private: System::Windows::Forms::Button^  tab1BtnDelete;
	private: System::Windows::Forms::DataGridView^  tab1DgvUsers;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::CheckBox^  tab1CbPracownik;
	private: System::Windows::Forms::TextBox^  tab1TextUserName;
	private: System::Windows::Forms::TextBox^  tab1TextSecondName;
	private: System::Windows::Forms::TextBox^  tab1TextFirstName;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  tab1BtnSearch;
	private: System::Windows::Forms::TextBox^  tab1TextSearch;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  tab0TextOldPassword;
	private: System::Windows::Forms::Button^  tab0BtnCommitPassChange;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tab0TextNewPassword2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tab0TextNewPassword;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  tab1GbHours;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::TextBox^  tab1text6end;
	private: System::Windows::Forms::TextBox^  tab1text6start;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  tab1text5end;
	private: System::Windows::Forms::TextBox^  tab1text5start;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  tab1text4end;
	private: System::Windows::Forms::TextBox^  tab1text4start;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  tab1text3end;
	private: System::Windows::Forms::TextBox^  tab1text3start;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tab1text2end;
	private: System::Windows::Forms::TextBox^  tab1text2start;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tab1text1end;
	private: System::Windows::Forms::TextBox^  tab1text1start;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::GroupBox^  tab2Gb;
	private: System::Windows::Forms::Button^  tab2BtnAdd;
	private: System::Windows::Forms::Button^  tab2BtnModify;
	private: System::Windows::Forms::Button^  tab2BtnDelete;
	private: System::Windows::Forms::TextBox^  tab2TextDesc;
	private: System::Windows::Forms::TextBox^  tab2TextTime;
	private: System::Windows::Forms::TextBox^  tab2TextPrice;
	private: System::Windows::Forms::TextBox^  tab2TextName;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::DataGridView^  tab2Dgv;
	private: System::Windows::Forms::Button^  tab2BtnSearch;
	private: System::Windows::Forms::TextBox^  tab2TextSearch;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  tab3BtnSearch;
	private: System::Windows::Forms::TextBox^  tab3TextSearch;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  tab3TextSecondName;
	private: System::Windows::Forms::TextBox^  tab3TextFirstName;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::DataGridView^  tab3DgvUslugi;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::DataGridView^  tab3DgvWork;
	private: System::Windows::Forms::DataGridView^  tab3DgvUsers;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::GroupBox^  tab4GbClient;
	private: System::Windows::Forms::DataGridView^  tab4DgvClients;
	private: System::Windows::Forms::Button^  tab4BtnSearch;
	private: System::Windows::Forms::TextBox^  tab4TextSearch;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Button^  tab4BtnAdd;
	private: System::Windows::Forms::Button^  tab4BtnModify;
	private: System::Windows::Forms::Button^  tab4BtnDelete;
	private: System::Windows::Forms::MaskedTextBox^  tab4TextPostal;
	private: System::Windows::Forms::TextBox^  tab4TextCity;
	private: System::Windows::Forms::TextBox^  tab4TextNumber;
	private: System::Windows::Forms::TextBox^  tab4TextStreet;
	private: System::Windows::Forms::TextBox^  tab4TextPhone;
	private: System::Windows::Forms::TextBox^  tab4TextEmail;
	private: System::Windows::Forms::TextBox^  tab4TextSecondName;
	private: System::Windows::Forms::TextBox^  tab4TextFirstName;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::Button^  tab5BtnDelete;
	private: System::Windows::Forms::Button^  tab5BtnModify;
	private: System::Windows::Forms::Button^  tab5BtnAdd;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::TextBox^  tab5TextTimeChoosen;
	private: System::Windows::Forms::TextBox^  tab5TextUslugaChoosen;
	private: System::Windows::Forms::TextBox^  tab5TextClientChoosen;
	private: System::Windows::Forms::DataGridView^  tab5DgvUsluga;
	private: System::Windows::Forms::DataGridView^  tab5DgvClient;
	private: System::Windows::Forms::Button^  tav5BtnSearchUser;
	private: System::Windows::Forms::TextBox^  tab5TextSearchUser;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::GroupBox^  tab5GbHours;
	private: System::Windows::Forms::DataGridView^  tab5DgvUsers;
	private: System::Windows::Forms::Button^  tab5BtnSearchClient;
	private: System::Windows::Forms::TextBox^  tab5TextSearchClient;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Button^  tab5BtnSearchUsluga;
	private: System::Windows::Forms::TextBox^  tab5TextSearchUsluga;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
			 String^ config = L"datasource=localhost;port=3306;username=root;password=lol123;database=gabinet";
			 String^ dateChoosen;
			 String^ hourChoosen;
			 int userId;
			 int pracownik;
			 int recordId;
			 int uslugaId;
			 int clientId;
			 int wizytaId;
	public:MainWindow(int user)
	{
		InitializeComponent();
		userId = user;
		//
		//TODO: Add the constructor code here
		//
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->tab5BtnDelete = (gcnew System::Windows::Forms::Button());
			this->tab5BtnModify = (gcnew System::Windows::Forms::Button());
			this->tab5BtnAdd = (gcnew System::Windows::Forms::Button());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->tab5TextTimeChoosen = (gcnew System::Windows::Forms::TextBox());
			this->tab5TextUslugaChoosen = (gcnew System::Windows::Forms::TextBox());
			this->tab5TextClientChoosen = (gcnew System::Windows::Forms::TextBox());
			this->tab5DgvUsluga = (gcnew System::Windows::Forms::DataGridView());
			this->tab5DgvClient = (gcnew System::Windows::Forms::DataGridView());
			this->tav5BtnSearchUser = (gcnew System::Windows::Forms::Button());
			this->tab5TextSearchUser = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->tab5GbHours = (gcnew System::Windows::Forms::GroupBox());
			this->tab5DgvUsers = (gcnew System::Windows::Forms::DataGridView());
			this->tab5BtnSearchClient = (gcnew System::Windows::Forms::Button());
			this->tab5TextSearchClient = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->tab5BtnSearchUsluga = (gcnew System::Windows::Forms::Button());
			this->tab5TextSearchUsluga = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tab4BtnAdd = (gcnew System::Windows::Forms::Button());
			this->tab4BtnModify = (gcnew System::Windows::Forms::Button());
			this->tab4BtnDelete = (gcnew System::Windows::Forms::Button());
			this->tab4GbClient = (gcnew System::Windows::Forms::GroupBox());
			this->tab4TextPostal = (gcnew System::Windows::Forms::MaskedTextBox());
			this->tab4TextCity = (gcnew System::Windows::Forms::TextBox());
			this->tab4TextNumber = (gcnew System::Windows::Forms::TextBox());
			this->tab4TextStreet = (gcnew System::Windows::Forms::TextBox());
			this->tab4TextPhone = (gcnew System::Windows::Forms::TextBox());
			this->tab4TextEmail = (gcnew System::Windows::Forms::TextBox());
			this->tab4TextSecondName = (gcnew System::Windows::Forms::TextBox());
			this->tab4TextFirstName = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->tab4DgvClients = (gcnew System::Windows::Forms::DataGridView());
			this->tab4BtnSearch = (gcnew System::Windows::Forms::Button());
			this->tab4TextSearch = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tab3TextSecondName = (gcnew System::Windows::Forms::TextBox());
			this->tab3TextFirstName = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->tab3DgvUslugi = (gcnew System::Windows::Forms::DataGridView());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tab3DgvWork = (gcnew System::Windows::Forms::DataGridView());
			this->tab3DgvUsers = (gcnew System::Windows::Forms::DataGridView());
			this->tab3BtnSearch = (gcnew System::Windows::Forms::Button());
			this->tab3TextSearch = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tab2Gb = (gcnew System::Windows::Forms::GroupBox());
			this->tab2BtnAdd = (gcnew System::Windows::Forms::Button());
			this->tab2BtnModify = (gcnew System::Windows::Forms::Button());
			this->tab2BtnDelete = (gcnew System::Windows::Forms::Button());
			this->tab2TextDesc = (gcnew System::Windows::Forms::TextBox());
			this->tab2TextTime = (gcnew System::Windows::Forms::TextBox());
			this->tab2TextPrice = (gcnew System::Windows::Forms::TextBox());
			this->tab2TextName = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->tab2Dgv = (gcnew System::Windows::Forms::DataGridView());
			this->tab2BtnSearch = (gcnew System::Windows::Forms::Button());
			this->tab2TextSearch = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tab1GbHours = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tab1text6end = (gcnew System::Windows::Forms::TextBox());
			this->tab1text6start = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tab1text5end = (gcnew System::Windows::Forms::TextBox());
			this->tab1text5start = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tab1text4end = (gcnew System::Windows::Forms::TextBox());
			this->tab1text4start = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tab1text3end = (gcnew System::Windows::Forms::TextBox());
			this->tab1text3start = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tab1text2end = (gcnew System::Windows::Forms::TextBox());
			this->tab1text2start = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tab1text1end = (gcnew System::Windows::Forms::TextBox());
			this->tab1text1start = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tab1BtnAdd = (gcnew System::Windows::Forms::Button());
			this->tab1BtnModify = (gcnew System::Windows::Forms::Button());
			this->tab1BtnDelete = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tab1CbPracownik = (gcnew System::Windows::Forms::CheckBox());
			this->tab1TextUserName = (gcnew System::Windows::Forms::TextBox());
			this->tab1TextSecondName = (gcnew System::Windows::Forms::TextBox());
			this->tab1TextFirstName = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tab1BtnSearch = (gcnew System::Windows::Forms::Button());
			this->tab1TextSearch = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tab1DgvUsers = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tab0TextOldPassword = (gcnew System::Windows::Forms::TextBox());
			this->tab0BtnCommitPassChange = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tab0TextNewPassword2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tab0TextNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->tabControl1->SuspendLayout();
			this->tabPage6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab5DgvUsluga))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab5DgvClient))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab5DgvUsers))->BeginInit();
			this->tabPage5->SuspendLayout();
			this->tab4GbClient->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab4DgvClients))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab3DgvUslugi))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab3DgvWork))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab3DgvUsers))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->tab2Gb->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab2Dgv))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->tab1GbHours->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab1DgvUsers))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(19, 104);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1080, 773);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->tab5BtnDelete);
			this->tabPage6->Controls->Add(this->tab5BtnModify);
			this->tabPage6->Controls->Add(this->tab5BtnAdd);
			this->tabPage6->Controls->Add(this->label39);
			this->tabPage6->Controls->Add(this->label38);
			this->tabPage6->Controls->Add(this->label37);
			this->tabPage6->Controls->Add(this->tab5TextTimeChoosen);
			this->tabPage6->Controls->Add(this->tab5TextUslugaChoosen);
			this->tabPage6->Controls->Add(this->tab5TextClientChoosen);
			this->tabPage6->Controls->Add(this->tab5DgvUsluga);
			this->tabPage6->Controls->Add(this->tab5DgvClient);
			this->tabPage6->Controls->Add(this->tav5BtnSearchUser);
			this->tabPage6->Controls->Add(this->tab5TextSearchUser);
			this->tabPage6->Controls->Add(this->label36);
			this->tabPage6->Controls->Add(this->monthCalendar1);
			this->tabPage6->Controls->Add(this->tab5GbHours);
			this->tabPage6->Controls->Add(this->tab5DgvUsers);
			this->tabPage6->Controls->Add(this->tab5BtnSearchClient);
			this->tabPage6->Controls->Add(this->tab5TextSearchClient);
			this->tabPage6->Controls->Add(this->label35);
			this->tabPage6->Controls->Add(this->tab5BtnSearchUsluga);
			this->tabPage6->Controls->Add(this->tab5TextSearchUsluga);
			this->tabPage6->Controls->Add(this->label34);
			this->tabPage6->Location = System::Drawing::Point(4, 4);
			this->tabPage6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(1072, 742);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Rezerwacje";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// tab5BtnDelete
			// 
			this->tab5BtnDelete->BackColor = System::Drawing::Color::Red;
			this->tab5BtnDelete->Enabled = false;
			this->tab5BtnDelete->FlatAppearance->BorderSize = 0;
			this->tab5BtnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tab5BtnDelete->Location = System::Drawing::Point(849, 660);
			this->tab5BtnDelete->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5BtnDelete->Name = L"tab5BtnDelete";
			this->tab5BtnDelete->Size = System::Drawing::Size(79, 32);
			this->tab5BtnDelete->TabIndex = 22;
			this->tab5BtnDelete->Text = L"Usuñ";
			this->tab5BtnDelete->UseVisualStyleBackColor = false;
			this->tab5BtnDelete->Click += gcnew System::EventHandler(this, &MainWindow::tab5BtnDelete_Click);
			// 
			// tab5BtnModify
			// 
			this->tab5BtnModify->BackColor = System::Drawing::Color::Turquoise;
			this->tab5BtnModify->Enabled = false;
			this->tab5BtnModify->FlatAppearance->BorderSize = 0;
			this->tab5BtnModify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tab5BtnModify->Location = System::Drawing::Point(936, 660);
			this->tab5BtnModify->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5BtnModify->Name = L"tab5BtnModify";
			this->tab5BtnModify->Size = System::Drawing::Size(129, 32);
			this->tab5BtnModify->TabIndex = 21;
			this->tab5BtnModify->Text = L"Modyfikuj";
			this->tab5BtnModify->UseVisualStyleBackColor = false;
			this->tab5BtnModify->Click += gcnew System::EventHandler(this, &MainWindow::tab5BtnModify_Click);
			// 
			// tab5BtnAdd
			// 
			this->tab5BtnAdd->BackColor = System::Drawing::Color::Lime;
			this->tab5BtnAdd->FlatAppearance->BorderSize = 0;
			this->tab5BtnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tab5BtnAdd->Location = System::Drawing::Point(849, 701);
			this->tab5BtnAdd->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5BtnAdd->Name = L"tab5BtnAdd";
			this->tab5BtnAdd->Size = System::Drawing::Size(217, 32);
			this->tab5BtnAdd->TabIndex = 20;
			this->tab5BtnAdd->Text = L"Dodaj";
			this->tab5BtnAdd->UseVisualStyleBackColor = false;
			this->tab5BtnAdd->Click += gcnew System::EventHandler(this, &MainWindow::tab5BtnAdd_Click);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(849, 357);
			this->label39->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(56, 18);
			this->label39->TabIndex = 19;
			this->label39->Text = L"Termin";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(849, 303);
			this->label38->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(56, 18);
			this->label38->TabIndex = 18;
			this->label38->Text = L"Us³uga";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(849, 249);
			this->label37->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(56, 18);
			this->label37->TabIndex = 17;
			this->label37->Text = L"Klient";
			// 
			// tab5TextTimeChoosen
			// 
			this->tab5TextTimeChoosen->Location = System::Drawing::Point(853, 379);
			this->tab5TextTimeChoosen->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5TextTimeChoosen->Name = L"tab5TextTimeChoosen";
			this->tab5TextTimeChoosen->Size = System::Drawing::Size(211, 25);
			this->tab5TextTimeChoosen->TabIndex = 16;
			// 
			// tab5TextUslugaChoosen
			// 
			this->tab5TextUslugaChoosen->Location = System::Drawing::Point(853, 325);
			this->tab5TextUslugaChoosen->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5TextUslugaChoosen->Name = L"tab5TextUslugaChoosen";
			this->tab5TextUslugaChoosen->Size = System::Drawing::Size(211, 25);
			this->tab5TextUslugaChoosen->TabIndex = 15;
			// 
			// tab5TextClientChoosen
			// 
			this->tab5TextClientChoosen->Location = System::Drawing::Point(853, 271);
			this->tab5TextClientChoosen->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5TextClientChoosen->Name = L"tab5TextClientChoosen";
			this->tab5TextClientChoosen->Size = System::Drawing::Size(211, 25);
			this->tab5TextClientChoosen->TabIndex = 14;
			// 
			// tab5DgvUsluga
			// 
			this->tab5DgvUsluga->AllowUserToAddRows = false;
			this->tab5DgvUsluga->AllowUserToDeleteRows = false;
			this->tab5DgvUsluga->AllowUserToOrderColumns = true;
			this->tab5DgvUsluga->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tab5DgvUsluga->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tab5DgvUsluga->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab5DgvUsluga->Location = System::Drawing::Point(4, 44);
			this->tab5DgvUsluga->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5DgvUsluga->Name = L"tab5DgvUsluga";
			this->tab5DgvUsluga->ReadOnly = true;
			this->tab5DgvUsluga->Size = System::Drawing::Size(527, 210);
			this->tab5DgvUsluga->TabIndex = 3;
			this->tab5DgvUsluga->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab5DgvUsluga_CellClick);
			// 
			// tab5DgvClient
			// 
			this->tab5DgvClient->AllowUserToAddRows = false;
			this->tab5DgvClient->AllowUserToDeleteRows = false;
			this->tab5DgvClient->AllowUserToOrderColumns = true;
			this->tab5DgvClient->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tab5DgvClient->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tab5DgvClient->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab5DgvClient->Location = System::Drawing::Point(4, 303);
			this->tab5DgvClient->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5DgvClient->Name = L"tab5DgvClient";
			this->tab5DgvClient->ReadOnly = true;
			this->tab5DgvClient->Size = System::Drawing::Size(527, 190);
			this->tab5DgvClient->TabIndex = 13;
			this->tab5DgvClient->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab5DgvClient_CellClick);
			// 
			// tav5BtnSearchUser
			// 
			this->tav5BtnSearchUser->BackColor = System::Drawing::Color::DarkOrange;
			this->tav5BtnSearchUser->FlatAppearance->BorderSize = 0;
			this->tav5BtnSearchUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tav5BtnSearchUser->Location = System::Drawing::Point(427, 501);
			this->tav5BtnSearchUser->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tav5BtnSearchUser->Name = L"tav5BtnSearchUser";
			this->tav5BtnSearchUser->Size = System::Drawing::Size(100, 32);
			this->tav5BtnSearchUser->TabIndex = 12;
			this->tav5BtnSearchUser->Text = L"Szukaj";
			this->tav5BtnSearchUser->UseVisualStyleBackColor = false;
			this->tav5BtnSearchUser->Click += gcnew System::EventHandler(this, &MainWindow::tav5BtnSearchUser_Click);
			// 
			// tab5TextSearchUser
			// 
			this->tab5TextSearchUser->Location = System::Drawing::Point(92, 504);
			this->tab5TextSearchUser->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5TextSearchUser->Name = L"tab5TextSearchUser";
			this->tab5TextSearchUser->Size = System::Drawing::Size(325, 25);
			this->tab5TextSearchUser->TabIndex = 11;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(4, 508);
			this->label36->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(88, 18);
			this->label36->TabIndex = 10;
			this->label36->Text = L"Pracownik:";
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Enabled = false;
			this->monthCalendar1->Location = System::Drawing::Point(857, 12);
			this->monthCalendar1->Margin = System::Windows::Forms::Padding(12, 12, 12, 12);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 9;
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &MainWindow::monthCalendar1_DateSelected);
			// 
			// tab5GbHours
			// 
			this->tab5GbHours->Location = System::Drawing::Point(535, 4);
			this->tab5GbHours->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5GbHours->Name = L"tab5GbHours";
			this->tab5GbHours->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5GbHours->Size = System::Drawing::Size(307, 728);
			this->tab5GbHours->TabIndex = 8;
			this->tab5GbHours->TabStop = false;
			this->tab5GbHours->Text = L"Godziny";
			// 
			// tab5DgvUsers
			// 
			this->tab5DgvUsers->AllowUserToAddRows = false;
			this->tab5DgvUsers->AllowUserToDeleteRows = false;
			this->tab5DgvUsers->AllowUserToOrderColumns = true;
			this->tab5DgvUsers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tab5DgvUsers->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tab5DgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab5DgvUsers->Location = System::Drawing::Point(4, 541);
			this->tab5DgvUsers->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5DgvUsers->Name = L"tab5DgvUsers";
			this->tab5DgvUsers->ReadOnly = true;
			this->tab5DgvUsers->Size = System::Drawing::Size(527, 191);
			this->tab5DgvUsers->TabIndex = 7;
			this->tab5DgvUsers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab5DgvUsers_CellClick);
			// 
			// tab5BtnSearchClient
			// 
			this->tab5BtnSearchClient->BackColor = System::Drawing::Color::DarkOrange;
			this->tab5BtnSearchClient->FlatAppearance->BorderSize = 0;
			this->tab5BtnSearchClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tab5BtnSearchClient->Location = System::Drawing::Point(427, 263);
			this->tab5BtnSearchClient->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5BtnSearchClient->Name = L"tab5BtnSearchClient";
			this->tab5BtnSearchClient->Size = System::Drawing::Size(100, 32);
			this->tab5BtnSearchClient->TabIndex = 6;
			this->tab5BtnSearchClient->Text = L"Szukaj";
			this->tab5BtnSearchClient->UseVisualStyleBackColor = false;
			this->tab5BtnSearchClient->Click += gcnew System::EventHandler(this, &MainWindow::tab5BtnSearchClient_Click);
			// 
			// tab5TextSearchClient
			// 
			this->tab5TextSearchClient->Location = System::Drawing::Point(92, 266);
			this->tab5TextSearchClient->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5TextSearchClient->Name = L"tab5TextSearchClient";
			this->tab5TextSearchClient->Size = System::Drawing::Size(325, 25);
			this->tab5TextSearchClient->TabIndex = 5;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(4, 270);
			this->label35->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(64, 18);
			this->label35->TabIndex = 4;
			this->label35->Text = L"Klient:";
			// 
			// tab5BtnSearchUsluga
			// 
			this->tab5BtnSearchUsluga->BackColor = System::Drawing::Color::DarkOrange;
			this->tab5BtnSearchUsluga->FlatAppearance->BorderSize = 0;
			this->tab5BtnSearchUsluga->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tab5BtnSearchUsluga->Location = System::Drawing::Point(427, 4);
			this->tab5BtnSearchUsluga->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5BtnSearchUsluga->Name = L"tab5BtnSearchUsluga";
			this->tab5BtnSearchUsluga->Size = System::Drawing::Size(100, 32);
			this->tab5BtnSearchUsluga->TabIndex = 2;
			this->tab5BtnSearchUsluga->Text = L"Szukaj";
			this->tab5BtnSearchUsluga->UseVisualStyleBackColor = false;
			this->tab5BtnSearchUsluga->Click += gcnew System::EventHandler(this, &MainWindow::tab5BtnUslugaSearch_Click);
			// 
			// tab5TextSearchUsluga
			// 
			this->tab5TextSearchUsluga->Location = System::Drawing::Point(92, 7);
			this->tab5TextSearchUsluga->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab5TextSearchUsluga->Name = L"tab5TextSearchUsluga";
			this->tab5TextSearchUsluga->Size = System::Drawing::Size(325, 25);
			this->tab5TextSearchUsluga->TabIndex = 1;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(4, 11);
			this->label34->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(64, 18);
			this->label34->TabIndex = 0;
			this->label34->Text = L"Usluga:";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->tab4BtnAdd);
			this->tabPage5->Controls->Add(this->tab4BtnModify);
			this->tabPage5->Controls->Add(this->tab4BtnDelete);
			this->tabPage5->Controls->Add(this->tab4GbClient);
			this->tabPage5->Controls->Add(this->tab4DgvClients);
			this->tabPage5->Controls->Add(this->tab4BtnSearch);
			this->tabPage5->Controls->Add(this->tab4TextSearch);
			this->tabPage5->Controls->Add(this->label25);
			this->tabPage5->Location = System::Drawing::Point(4, 4);
			this->tabPage5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1072, 747);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Klienci";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tab4BtnAdd
			// 
			this->tab4BtnAdd->Location = System::Drawing::Point(897, 125);
			this->tab4BtnAdd->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4BtnAdd->Name = L"tab4BtnAdd";
			this->tab4BtnAdd->Size = System::Drawing::Size(100, 32);
			this->tab4BtnAdd->TabIndex = 21;
			this->tab4BtnAdd->Text = L"Dodaj";
			this->tab4BtnAdd->UseVisualStyleBackColor = true;
			this->tab4BtnAdd->Click += gcnew System::EventHandler(this, &MainWindow::tab4BtnAdd_Click);
			// 
			// tab4BtnModify
			// 
			this->tab4BtnModify->Enabled = false;
			this->tab4BtnModify->Location = System::Drawing::Point(897, 66);
			this->tab4BtnModify->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4BtnModify->Name = L"tab4BtnModify";
			this->tab4BtnModify->Size = System::Drawing::Size(100, 32);
			this->tab4BtnModify->TabIndex = 20;
			this->tab4BtnModify->Text = L"Modyfikuj";
			this->tab4BtnModify->UseVisualStyleBackColor = true;
			this->tab4BtnModify->Click += gcnew System::EventHandler(this, &MainWindow::tab4BtnModify_Click);
			// 
			// tab4BtnDelete
			// 
			this->tab4BtnDelete->Enabled = false;
			this->tab4BtnDelete->Location = System::Drawing::Point(897, 11);
			this->tab4BtnDelete->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4BtnDelete->Name = L"tab4BtnDelete";
			this->tab4BtnDelete->Size = System::Drawing::Size(100, 32);
			this->tab4BtnDelete->TabIndex = 19;
			this->tab4BtnDelete->Text = L"Usuñ";
			this->tab4BtnDelete->UseVisualStyleBackColor = true;
			this->tab4BtnDelete->Click += gcnew System::EventHandler(this, &MainWindow::tab4BtnDelete_Click);
			// 
			// tab4GbClient
			// 
			this->tab4GbClient->Controls->Add(this->tab4TextPostal);
			this->tab4GbClient->Controls->Add(this->tab4TextCity);
			this->tab4GbClient->Controls->Add(this->tab4TextNumber);
			this->tab4GbClient->Controls->Add(this->tab4TextStreet);
			this->tab4GbClient->Controls->Add(this->tab4TextPhone);
			this->tab4GbClient->Controls->Add(this->tab4TextEmail);
			this->tab4GbClient->Controls->Add(this->tab4TextSecondName);
			this->tab4GbClient->Controls->Add(this->tab4TextFirstName);
			this->tab4GbClient->Controls->Add(this->label33);
			this->tab4GbClient->Controls->Add(this->label32);
			this->tab4GbClient->Controls->Add(this->label31);
			this->tab4GbClient->Controls->Add(this->label30);
			this->tab4GbClient->Controls->Add(this->label29);
			this->tab4GbClient->Controls->Add(this->label28);
			this->tab4GbClient->Controls->Add(this->label27);
			this->tab4GbClient->Controls->Add(this->label26);
			this->tab4GbClient->Location = System::Drawing::Point(229, 4);
			this->tab4GbClient->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4GbClient->Name = L"tab4GbClient";
			this->tab4GbClient->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4GbClient->Size = System::Drawing::Size(561, 174);
			this->tab4GbClient->TabIndex = 4;
			this->tab4GbClient->TabStop = false;
			this->tab4GbClient->Text = L"Edycja danych klienta:";
			// 
			// tab4TextPostal
			// 
			this->tab4TextPostal->Location = System::Drawing::Point(427, 94);
			this->tab4TextPostal->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextPostal->Mask = L"00-999";
			this->tab4TextPostal->Name = L"tab4TextPostal";
			this->tab4TextPostal->Size = System::Drawing::Size(55, 25);
			this->tab4TextPostal->TabIndex = 16;
			// 
			// tab4TextCity
			// 
			this->tab4TextCity->Location = System::Drawing::Point(383, 130);
			this->tab4TextCity->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextCity->Name = L"tab4TextCity";
			this->tab4TextCity->Size = System::Drawing::Size(169, 25);
			this->tab4TextCity->TabIndex = 15;
			// 
			// tab4TextNumber
			// 
			this->tab4TextNumber->Location = System::Drawing::Point(427, 58);
			this->tab4TextNumber->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextNumber->Name = L"tab4TextNumber";
			this->tab4TextNumber->Size = System::Drawing::Size(55, 25);
			this->tab4TextNumber->TabIndex = 13;
			// 
			// tab4TextStreet
			// 
			this->tab4TextStreet->Location = System::Drawing::Point(383, 22);
			this->tab4TextStreet->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextStreet->Name = L"tab4TextStreet";
			this->tab4TextStreet->Size = System::Drawing::Size(169, 25);
			this->tab4TextStreet->TabIndex = 12;
			// 
			// tab4TextPhone
			// 
			this->tab4TextPhone->Location = System::Drawing::Point(91, 130);
			this->tab4TextPhone->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextPhone->Name = L"tab4TextPhone";
			this->tab4TextPhone->Size = System::Drawing::Size(180, 25);
			this->tab4TextPhone->TabIndex = 11;
			// 
			// tab4TextEmail
			// 
			this->tab4TextEmail->Location = System::Drawing::Point(91, 94);
			this->tab4TextEmail->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextEmail->Name = L"tab4TextEmail";
			this->tab4TextEmail->Size = System::Drawing::Size(180, 25);
			this->tab4TextEmail->TabIndex = 10;
			// 
			// tab4TextSecondName
			// 
			this->tab4TextSecondName->Location = System::Drawing::Point(91, 58);
			this->tab4TextSecondName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextSecondName->Name = L"tab4TextSecondName";
			this->tab4TextSecondName->Size = System::Drawing::Size(180, 25);
			this->tab4TextSecondName->TabIndex = 9;
			// 
			// tab4TextFirstName
			// 
			this->tab4TextFirstName->Location = System::Drawing::Point(91, 22);
			this->tab4TextFirstName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextFirstName->Name = L"tab4TextFirstName";
			this->tab4TextFirstName->Size = System::Drawing::Size(180, 25);
			this->tab4TextFirstName->TabIndex = 8;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(280, 130);
			this->label33->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(104, 18);
			this->label33->TabIndex = 7;
			this->label33->Text = L"Miejscowoœæ:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(280, 94);
			this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(112, 18);
			this->label32->TabIndex = 6;
			this->label32->Text = L"Kod pocztowy:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(280, 58);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(56, 18);
			this->label31->TabIndex = 5;
			this->label31->Text = L"Numer:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(280, 22);
			this->label30->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(56, 18);
			this->label30->TabIndex = 4;
			this->label30->Text = L"Ulica:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(8, 134);
			this->label29->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(72, 18);
			this->label29->TabIndex = 3;
			this->label29->Text = L"Telefon:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(8, 98);
			this->label28->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(56, 18);
			this->label28->TabIndex = 2;
			this->label28->Text = L"email:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(8, 62);
			this->label27->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(80, 18);
			this->label27->TabIndex = 1;
			this->label27->Text = L"Nazwisko:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(8, 26);
			this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(48, 18);
			this->label26->TabIndex = 0;
			this->label26->Text = L"Imiê:";
			// 
			// tab4DgvClients
			// 
			this->tab4DgvClients->AllowUserToAddRows = false;
			this->tab4DgvClients->AllowUserToDeleteRows = false;
			this->tab4DgvClients->AllowUserToOrderColumns = true;
			this->tab4DgvClients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab4DgvClients->Location = System::Drawing::Point(4, 187);
			this->tab4DgvClients->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4DgvClients->Name = L"tab4DgvClients";
			this->tab4DgvClients->ReadOnly = true;
			this->tab4DgvClients->Size = System::Drawing::Size(1061, 546);
			this->tab4DgvClients->TabIndex = 3;
			this->tab4DgvClients->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab4DgvClients_CellClick);
			// 
			// tab4BtnSearch
			// 
			this->tab4BtnSearch->Location = System::Drawing::Point(48, 47);
			this->tab4BtnSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4BtnSearch->Name = L"tab4BtnSearch";
			this->tab4BtnSearch->Size = System::Drawing::Size(100, 32);
			this->tab4BtnSearch->TabIndex = 2;
			this->tab4BtnSearch->Text = L"Szukaj";
			this->tab4BtnSearch->UseVisualStyleBackColor = true;
			this->tab4BtnSearch->Click += gcnew System::EventHandler(this, &MainWindow::tab4BtnSearch_Click);
			// 
			// tab4TextSearch
			// 
			this->tab4TextSearch->Location = System::Drawing::Point(48, 11);
			this->tab4TextSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab4TextSearch->Name = L"tab4TextSearch";
			this->tab4TextSearch->Size = System::Drawing::Size(172, 25);
			this->tab4TextSearch->TabIndex = 1;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(4, 11);
			this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(56, 18);
			this->label25->TabIndex = 0;
			this->label25->Text = L"Klient";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->tab3TextSecondName);
			this->tabPage4->Controls->Add(this->tab3TextFirstName);
			this->tabPage4->Controls->Add(this->label23);
			this->tabPage4->Controls->Add(this->label24);
			this->tabPage4->Controls->Add(this->label22);
			this->tabPage4->Controls->Add(this->tab3DgvUslugi);
			this->tabPage4->Controls->Add(this->label21);
			this->tabPage4->Controls->Add(this->label20);
			this->tabPage4->Controls->Add(this->tab3DgvWork);
			this->tabPage4->Controls->Add(this->tab3DgvUsers);
			this->tabPage4->Controls->Add(this->tab3BtnSearch);
			this->tabPage4->Controls->Add(this->tab3TextSearch);
			this->tabPage4->Controls->Add(this->label19);
			this->tabPage4->Location = System::Drawing::Point(4, 4);
			this->tabPage4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage4->Size = System::Drawing::Size(1072, 747);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Pracownik-Us³ugi";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tab3TextSecondName
			// 
			this->tab3TextSecondName->Location = System::Drawing::Point(115, 96);
			this->tab3TextSecondName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab3TextSecondName->Name = L"tab3TextSecondName";
			this->tab3TextSecondName->Size = System::Drawing::Size(269, 25);
			this->tab3TextSecondName->TabIndex = 12;
			// 
			// tab3TextFirstName
			// 
			this->tab3TextFirstName->Location = System::Drawing::Point(115, 60);
			this->tab3TextFirstName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab3TextFirstName->Name = L"tab3TextFirstName";
			this->tab3TextFirstName->Size = System::Drawing::Size(269, 25);
			this->tab3TextFirstName->TabIndex = 11;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(32, 100);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(80, 18);
			this->label23->TabIndex = 10;
			this->label23->Text = L"Nazwisko:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(31, 64);
			this->label24->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(48, 18);
			this->label24->TabIndex = 9;
			this->label24->Text = L"Imiê:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(4, 332);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(104, 18);
			this->label22->TabIndex = 8;
			this->label22->Text = L"Dodaj us³ugê";
			// 
			// tab3DgvUslugi
			// 
			this->tab3DgvUslugi->AllowUserToAddRows = false;
			this->tab3DgvUslugi->AllowUserToDeleteRows = false;
			this->tab3DgvUslugi->AllowUserToOrderColumns = true;
			this->tab3DgvUslugi->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab3DgvUslugi->Location = System::Drawing::Point(8, 354);
			this->tab3DgvUslugi->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab3DgvUslugi->Name = L"tab3DgvUslugi";
			this->tab3DgvUslugi->ReadOnly = true;
			this->tab3DgvUslugi->Size = System::Drawing::Size(507, 374);
			this->tab3DgvUslugi->TabIndex = 7;
			this->tab3DgvUslugi->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab3DgvUslugi_CellClick);
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(519, 332);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(144, 18);
			this->label21->TabIndex = 6;
			this->label21->Text = L"Wykonywane us³ugi";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(519, 4);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(80, 18);
			this->label20->TabIndex = 5;
			this->label20->Text = L"Pracownik";
			// 
			// tab3DgvWork
			// 
			this->tab3DgvWork->AllowUserToAddRows = false;
			this->tab3DgvWork->AllowUserToDeleteRows = false;
			this->tab3DgvWork->AllowUserToOrderColumns = true;
			this->tab3DgvWork->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab3DgvWork->Location = System::Drawing::Point(523, 354);
			this->tab3DgvWork->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab3DgvWork->Name = L"tab3DgvWork";
			this->tab3DgvWork->ReadOnly = true;
			this->tab3DgvWork->Size = System::Drawing::Size(539, 374);
			this->tab3DgvWork->TabIndex = 4;
			this->tab3DgvWork->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab3DgvWork_CellClick);
			// 
			// tab3DgvUsers
			// 
			this->tab3DgvUsers->AllowUserToAddRows = false;
			this->tab3DgvUsers->AllowUserToDeleteRows = false;
			this->tab3DgvUsers->AllowUserToOrderColumns = true;
			this->tab3DgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab3DgvUsers->Location = System::Drawing::Point(523, 26);
			this->tab3DgvUsers->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab3DgvUsers->Name = L"tab3DgvUsers";
			this->tab3DgvUsers->ReadOnly = true;
			this->tab3DgvUsers->Size = System::Drawing::Size(539, 302);
			this->tab3DgvUsers->TabIndex = 3;
			this->tab3DgvUsers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab3DgvUsers_CellClick);
			// 
			// tab3BtnSearch
			// 
			this->tab3BtnSearch->Location = System::Drawing::Point(256, 19);
			this->tab3BtnSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab3BtnSearch->Name = L"tab3BtnSearch";
			this->tab3BtnSearch->Size = System::Drawing::Size(100, 32);
			this->tab3BtnSearch->TabIndex = 2;
			this->tab3BtnSearch->Text = L"Szukaj";
			this->tab3BtnSearch->UseVisualStyleBackColor = true;
			this->tab3BtnSearch->Click += gcnew System::EventHandler(this, &MainWindow::tab3BtnSearch_Click);
			// 
			// tab3TextSearch
			// 
			this->tab3TextSearch->Location = System::Drawing::Point(115, 22);
			this->tab3TextSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab3TextSearch->Name = L"tab3TextSearch";
			this->tab3TextSearch->Size = System::Drawing::Size(132, 25);
			this->tab3TextSearch->TabIndex = 1;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(31, 26);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(80, 18);
			this->label19->TabIndex = 0;
			this->label19->Text = L"Pracownik";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->tab2Gb);
			this->tabPage3->Controls->Add(this->tab2Dgv);
			this->tabPage3->Controls->Add(this->tab2BtnSearch);
			this->tabPage3->Controls->Add(this->tab2TextSearch);
			this->tabPage3->Controls->Add(this->label14);
			this->tabPage3->Location = System::Drawing::Point(4, 4);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Size = System::Drawing::Size(1072, 747);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Us³ugi";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tab2Gb
			// 
			this->tab2Gb->Controls->Add(this->tab2BtnAdd);
			this->tab2Gb->Controls->Add(this->tab2BtnModify);
			this->tab2Gb->Controls->Add(this->tab2BtnDelete);
			this->tab2Gb->Controls->Add(this->tab2TextDesc);
			this->tab2Gb->Controls->Add(this->tab2TextTime);
			this->tab2Gb->Controls->Add(this->tab2TextPrice);
			this->tab2Gb->Controls->Add(this->tab2TextName);
			this->tab2Gb->Controls->Add(this->label18);
			this->tab2Gb->Controls->Add(this->label17);
			this->tab2Gb->Controls->Add(this->label16);
			this->tab2Gb->Controls->Add(this->label15);
			this->tab2Gb->Location = System::Drawing::Point(8, 48);
			this->tab2Gb->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2Gb->Name = L"tab2Gb";
			this->tab2Gb->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2Gb->Size = System::Drawing::Size(473, 673);
			this->tab2Gb->TabIndex = 4;
			this->tab2Gb->TabStop = false;
			this->tab2Gb->Text = L"Zabiegi";
			// 
			// tab2BtnAdd
			// 
			this->tab2BtnAdd->Location = System::Drawing::Point(365, 633);
			this->tab2BtnAdd->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2BtnAdd->Name = L"tab2BtnAdd";
			this->tab2BtnAdd->Size = System::Drawing::Size(100, 32);
			this->tab2BtnAdd->TabIndex = 10;
			this->tab2BtnAdd->Text = L"Dodaj";
			this->tab2BtnAdd->UseVisualStyleBackColor = true;
			this->tab2BtnAdd->Click += gcnew System::EventHandler(this, &MainWindow::tab2BtnAdd_Click);
			// 
			// tab2BtnModify
			// 
			this->tab2BtnModify->Enabled = false;
			this->tab2BtnModify->Location = System::Drawing::Point(183, 633);
			this->tab2BtnModify->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2BtnModify->Name = L"tab2BtnModify";
			this->tab2BtnModify->Size = System::Drawing::Size(100, 32);
			this->tab2BtnModify->TabIndex = 9;
			this->tab2BtnModify->Text = L"Modyfikuj";
			this->tab2BtnModify->UseVisualStyleBackColor = true;
			this->tab2BtnModify->Click += gcnew System::EventHandler(this, &MainWindow::tab2BtnModify_Click);
			// 
			// tab2BtnDelete
			// 
			this->tab2BtnDelete->Enabled = false;
			this->tab2BtnDelete->Location = System::Drawing::Point(12, 633);
			this->tab2BtnDelete->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2BtnDelete->Name = L"tab2BtnDelete";
			this->tab2BtnDelete->Size = System::Drawing::Size(100, 32);
			this->tab2BtnDelete->TabIndex = 8;
			this->tab2BtnDelete->Text = L"Usuñ";
			this->tab2BtnDelete->UseVisualStyleBackColor = true;
			this->tab2BtnDelete->Click += gcnew System::EventHandler(this, &MainWindow::tab2BtnDelete_Click);
			// 
			// tab2TextDesc
			// 
			this->tab2TextDesc->Location = System::Drawing::Point(12, 186);
			this->tab2TextDesc->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2TextDesc->Multiline = true;
			this->tab2TextDesc->Name = L"tab2TextDesc";
			this->tab2TextDesc->Size = System::Drawing::Size(452, 437);
			this->tab2TextDesc->TabIndex = 7;
			// 
			// tab2TextTime
			// 
			this->tab2TextTime->Location = System::Drawing::Point(69, 98);
			this->tab2TextTime->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2TextTime->Name = L"tab2TextTime";
			this->tab2TextTime->Size = System::Drawing::Size(135, 25);
			this->tab2TextTime->TabIndex = 6;
			// 
			// tab2TextPrice
			// 
			this->tab2TextPrice->Location = System::Drawing::Point(69, 62);
			this->tab2TextPrice->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2TextPrice->Name = L"tab2TextPrice";
			this->tab2TextPrice->Size = System::Drawing::Size(132, 25);
			this->tab2TextPrice->TabIndex = 5;
			// 
			// tab2TextName
			// 
			this->tab2TextName->Location = System::Drawing::Point(69, 26);
			this->tab2TextName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2TextName->Name = L"tab2TextName";
			this->tab2TextName->Size = System::Drawing::Size(132, 25);
			this->tab2TextName->TabIndex = 4;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(8, 150);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(40, 18);
			this->label18->TabIndex = 3;
			this->label18->Text = L"Opis";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(8, 102);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(40, 18);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Czas";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(8, 66);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(40, 18);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Cena";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(8, 30);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(48, 18);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Nazwa";
			// 
			// tab2Dgv
			// 
			this->tab2Dgv->AllowUserToAddRows = false;
			this->tab2Dgv->AllowUserToDeleteRows = false;
			this->tab2Dgv->AllowUserToOrderColumns = true;
			this->tab2Dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab2Dgv->Location = System::Drawing::Point(489, 8);
			this->tab2Dgv->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2Dgv->Name = L"tab2Dgv";
			this->tab2Dgv->ReadOnly = true;
			this->tab2Dgv->Size = System::Drawing::Size(572, 713);
			this->tab2Dgv->TabIndex = 3;
			this->tab2Dgv->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::tab2Dgv_CellClick);
			// 
			// tab2BtnSearch
			// 
			this->tab2BtnSearch->Location = System::Drawing::Point(381, 8);
			this->tab2BtnSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2BtnSearch->Name = L"tab2BtnSearch";
			this->tab2BtnSearch->Size = System::Drawing::Size(100, 32);
			this->tab2BtnSearch->TabIndex = 2;
			this->tab2BtnSearch->Text = L"Szukaj";
			this->tab2BtnSearch->UseVisualStyleBackColor = true;
			this->tab2BtnSearch->Click += gcnew System::EventHandler(this, &MainWindow::tab2BtnSearch_Click);
			// 
			// tab2TextSearch
			// 
			this->tab2TextSearch->Location = System::Drawing::Point(69, 11);
			this->tab2TextSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab2TextSearch->Name = L"tab2TextSearch";
			this->tab2TextSearch->Size = System::Drawing::Size(289, 25);
			this->tab2TextSearch->TabIndex = 1;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(8, 15);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(56, 18);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Zabieg";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->tab1GbHours);
			this->tabPage2->Controls->Add(this->tab1BtnAdd);
			this->tabPage2->Controls->Add(this->tab1BtnModify);
			this->tabPage2->Controls->Add(this->tab1BtnDelete);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->tab1BtnSearch);
			this->tabPage2->Controls->Add(this->tab1TextSearch);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->tab1DgvUsers);
			this->tabPage2->Location = System::Drawing::Point(4, 4);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(1072, 747);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Pracownicy";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tab1GbHours
			// 
			this->tab1GbHours->Controls->Add(this->groupBox4);
			this->tab1GbHours->Controls->Add(this->tab1text6end);
			this->tab1GbHours->Controls->Add(this->tab1text6start);
			this->tab1GbHours->Controls->Add(this->label13);
			this->tab1GbHours->Controls->Add(this->tab1text5end);
			this->tab1GbHours->Controls->Add(this->tab1text5start);
			this->tab1GbHours->Controls->Add(this->label12);
			this->tab1GbHours->Controls->Add(this->tab1text4end);
			this->tab1GbHours->Controls->Add(this->tab1text4start);
			this->tab1GbHours->Controls->Add(this->label11);
			this->tab1GbHours->Controls->Add(this->tab1text3end);
			this->tab1GbHours->Controls->Add(this->tab1text3start);
			this->tab1GbHours->Controls->Add(this->label10);
			this->tab1GbHours->Controls->Add(this->tab1text2end);
			this->tab1GbHours->Controls->Add(this->tab1text2start);
			this->tab1GbHours->Controls->Add(this->label9);
			this->tab1GbHours->Controls->Add(this->tab1text1end);
			this->tab1GbHours->Controls->Add(this->tab1text1start);
			this->tab1GbHours->Controls->Add(this->label8);
			this->tab1GbHours->Location = System::Drawing::Point(13, 248);
			this->tab1GbHours->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1GbHours->Name = L"tab1GbHours";
			this->tab1GbHours->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1GbHours->Size = System::Drawing::Size(581, 440);
			this->tab1GbHours->TabIndex = 8;
			this->tab1GbHours->TabStop = false;
			this->tab1GbHours->Text = L"Godziny pracy";
			this->tab1GbHours->Visible = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Controls->Add(this->button3);
			this->groupBox4->Controls->Add(this->button2);
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Location = System::Drawing::Point(12, 354);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Size = System::Drawing::Size(552, 78);
			this->groupBox4->TabIndex = 21;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Szablony";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(432, 26);
			this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 32);
			this->button4->TabIndex = 3;
			this->button4->Text = L"10-18";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainWindow::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(285, 26);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 32);
			this->button3->TabIndex = 2;
			this->button3->Text = L"9-17";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainWindow::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(153, 26);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 32);
			this->button2->TabIndex = 1;
			this->button2->Text = L"8-16";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 26);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"7-15";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// tab1text6end
			// 
			this->tab1text6end->Location = System::Drawing::Point(377, 212);
			this->tab1text6end->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text6end->Name = L"tab1text6end";
			this->tab1text6end->Size = System::Drawing::Size(195, 25);
			this->tab1text6end->TabIndex = 17;
			// 
			// tab1text6start
			// 
			this->tab1text6start->Location = System::Drawing::Point(173, 212);
			this->tab1text6start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text6start->Name = L"tab1text6start";
			this->tab1text6start->Size = System::Drawing::Size(195, 25);
			this->tab1text6start->TabIndex = 16;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(28, 216);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(56, 18);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Sobota";
			// 
			// tab1text5end
			// 
			this->tab1text5end->Location = System::Drawing::Point(377, 176);
			this->tab1text5end->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text5end->Name = L"tab1text5end";
			this->tab1text5end->Size = System::Drawing::Size(195, 25);
			this->tab1text5end->TabIndex = 14;
			// 
			// tab1text5start
			// 
			this->tab1text5start->Location = System::Drawing::Point(173, 176);
			this->tab1text5start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text5start->Name = L"tab1text5start";
			this->tab1text5start->Size = System::Drawing::Size(195, 25);
			this->tab1text5start->TabIndex = 13;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(28, 180);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(56, 18);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Pi¹tek";
			// 
			// tab1text4end
			// 
			this->tab1text4end->Location = System::Drawing::Point(377, 140);
			this->tab1text4end->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text4end->Name = L"tab1text4end";
			this->tab1text4end->Size = System::Drawing::Size(195, 25);
			this->tab1text4end->TabIndex = 11;
			// 
			// tab1text4start
			// 
			this->tab1text4start->Location = System::Drawing::Point(173, 140);
			this->tab1text4start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text4start->Name = L"tab1text4start";
			this->tab1text4start->Size = System::Drawing::Size(195, 25);
			this->tab1text4start->TabIndex = 10;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(28, 144);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(72, 18);
			this->label11->TabIndex = 9;
			this->label11->Text = L"Czwartek";
			// 
			// tab1text3end
			// 
			this->tab1text3end->Location = System::Drawing::Point(377, 104);
			this->tab1text3end->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text3end->Name = L"tab1text3end";
			this->tab1text3end->Size = System::Drawing::Size(195, 25);
			this->tab1text3end->TabIndex = 8;
			// 
			// tab1text3start
			// 
			this->tab1text3start->Location = System::Drawing::Point(173, 104);
			this->tab1text3start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text3start->Name = L"tab1text3start";
			this->tab1text3start->Size = System::Drawing::Size(195, 25);
			this->tab1text3start->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(28, 108);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 18);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Œroda";
			// 
			// tab1text2end
			// 
			this->tab1text2end->Location = System::Drawing::Point(377, 68);
			this->tab1text2end->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text2end->Name = L"tab1text2end";
			this->tab1text2end->Size = System::Drawing::Size(195, 25);
			this->tab1text2end->TabIndex = 5;
			// 
			// tab1text2start
			// 
			this->tab1text2start->Location = System::Drawing::Point(173, 68);
			this->tab1text2start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text2start->Name = L"tab1text2start";
			this->tab1text2start->Size = System::Drawing::Size(195, 25);
			this->tab1text2start->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(28, 72);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(56, 18);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Wtorek";
			// 
			// tab1text1end
			// 
			this->tab1text1end->Location = System::Drawing::Point(377, 32);
			this->tab1text1end->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text1end->Name = L"tab1text1end";
			this->tab1text1end->Size = System::Drawing::Size(195, 25);
			this->tab1text1end->TabIndex = 2;
			// 
			// tab1text1start
			// 
			this->tab1text1start->Location = System::Drawing::Point(173, 32);
			this->tab1text1start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1text1start->Name = L"tab1text1start";
			this->tab1text1start->Size = System::Drawing::Size(195, 25);
			this->tab1text1start->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(28, 36);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(104, 18);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Poniedzia³ek";
			// 
			// tab1BtnAdd
			// 
			this->tab1BtnAdd->Location = System::Drawing::Point(467, 696);
			this->tab1BtnAdd->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1BtnAdd->Name = L"tab1BtnAdd";
			this->tab1BtnAdd->Size = System::Drawing::Size(100, 32);
			this->tab1BtnAdd->TabIndex = 7;
			this->tab1BtnAdd->Text = L"Dodaj";
			this->tab1BtnAdd->UseVisualStyleBackColor = true;
			this->tab1BtnAdd->Click += gcnew System::EventHandler(this, &MainWindow::tab1BtnAdd_Click);
			// 
			// tab1BtnModify
			// 
			this->tab1BtnModify->Enabled = false;
			this->tab1BtnModify->Location = System::Drawing::Point(241, 696);
			this->tab1BtnModify->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1BtnModify->Name = L"tab1BtnModify";
			this->tab1BtnModify->Size = System::Drawing::Size(100, 32);
			this->tab1BtnModify->TabIndex = 6;
			this->tab1BtnModify->Text = L"Modyfikuj";
			this->tab1BtnModify->UseVisualStyleBackColor = true;
			this->tab1BtnModify->Click += gcnew System::EventHandler(this, &MainWindow::tab1BtnModify_Click);
			// 
			// tab1BtnDelete
			// 
			this->tab1BtnDelete->Enabled = false;
			this->tab1BtnDelete->Location = System::Drawing::Point(25, 696);
			this->tab1BtnDelete->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1BtnDelete->Name = L"tab1BtnDelete";
			this->tab1BtnDelete->Size = System::Drawing::Size(100, 32);
			this->tab1BtnDelete->TabIndex = 5;
			this->tab1BtnDelete->Text = L"Usuñ";
			this->tab1BtnDelete->UseVisualStyleBackColor = true;
			this->tab1BtnDelete->Click += gcnew System::EventHandler(this, &MainWindow::tab1BtnDelete_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tab1CbPracownik);
			this->groupBox2->Controls->Add(this->tab1TextUserName);
			this->groupBox2->Controls->Add(this->tab1TextSecondName);
			this->groupBox2->Controls->Add(this->tab1TextFirstName);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Location = System::Drawing::Point(13, 48);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(581, 191);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Edycja danych";
			// 
			// tab1CbPracownik
			// 
			this->tab1CbPracownik->AutoSize = true;
			this->tab1CbPracownik->Location = System::Drawing::Point(452, 54);
			this->tab1CbPracownik->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1CbPracownik->Name = L"tab1CbPracownik";
			this->tab1CbPracownik->Size = System::Drawing::Size(99, 22);
			this->tab1CbPracownik->TabIndex = 6;
			this->tab1CbPracownik->Text = L"Pracownik";
			this->tab1CbPracownik->UseVisualStyleBackColor = true;
			this->tab1CbPracownik->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::tab1CbPracownik_CheckedChanged);
			// 
			// tab1TextUserName
			// 
			this->tab1TextUserName->Location = System::Drawing::Point(156, 96);
			this->tab1TextUserName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1TextUserName->Name = L"tab1TextUserName";
			this->tab1TextUserName->Size = System::Drawing::Size(269, 25);
			this->tab1TextUserName->TabIndex = 5;
			// 
			// tab1TextSecondName
			// 
			this->tab1TextSecondName->Location = System::Drawing::Point(156, 54);
			this->tab1TextSecondName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1TextSecondName->Name = L"tab1TextSecondName";
			this->tab1TextSecondName->Size = System::Drawing::Size(269, 25);
			this->tab1TextSecondName->TabIndex = 4;
			// 
			// tab1TextFirstName
			// 
			this->tab1TextFirstName->Location = System::Drawing::Point(156, 18);
			this->tab1TextFirstName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1TextFirstName->Name = L"tab1TextFirstName";
			this->tab1TextFirstName->Size = System::Drawing::Size(269, 25);
			this->tab1TextFirstName->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 100);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(152, 18);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Nazwa u¿ytkownika:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 64);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(80, 18);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Nazwisko:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 28);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 18);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Imiê:";
			// 
			// tab1BtnSearch
			// 
			this->tab1BtnSearch->Location = System::Drawing::Point(495, 8);
			this->tab1BtnSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1BtnSearch->Name = L"tab1BtnSearch";
			this->tab1BtnSearch->Size = System::Drawing::Size(100, 32);
			this->tab1BtnSearch->TabIndex = 3;
			this->tab1BtnSearch->Text = L"Szukaj";
			this->tab1BtnSearch->UseVisualStyleBackColor = true;
			this->tab1BtnSearch->Click += gcnew System::EventHandler(this, &MainWindow::btnSearch_Click);
			// 
			// tab1TextSearch
			// 
			this->tab1TextSearch->Location = System::Drawing::Point(91, 8);
			this->tab1TextSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1TextSearch->Name = L"tab1TextSearch";
			this->tab1TextSearch->Size = System::Drawing::Size(395, 25);
			this->tab1TextSearch->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 8);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 18);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Wyszukaj:";
			// 
			// tab1DgvUsers
			// 
			this->tab1DgvUsers->AllowUserToAddRows = false;
			this->tab1DgvUsers->AllowUserToDeleteRows = false;
			this->tab1DgvUsers->AllowUserToOrderColumns = true;
			this->tab1DgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tab1DgvUsers->Location = System::Drawing::Point(603, 8);
			this->tab1DgvUsers->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab1DgvUsers->Name = L"tab1DgvUsers";
			this->tab1DgvUsers->ReadOnly = true;
			this->tab1DgvUsers->RowHeadersWidth = 30;
			this->tab1DgvUsers->Size = System::Drawing::Size(459, 720);
			this->tab1DgvUsers->TabIndex = 0;
			this->tab1DgvUsers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::dgvUsers_CellClick);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 4);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(1072, 747);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Zmiana Hasla";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tab0TextOldPassword);
			this->groupBox1->Controls->Add(this->tab0BtnCommitPassChange);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->tab0TextNewPassword2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->tab0TextNewPassword);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Location = System::Drawing::Point(352, 237);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(151, 242);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Zmiana has³a";
			// 
			// tab0TextOldPassword
			// 
			this->tab0TextOldPassword->Location = System::Drawing::Point(8, 50);
			this->tab0TextOldPassword->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab0TextOldPassword->Name = L"tab0TextOldPassword";
			this->tab0TextOldPassword->Size = System::Drawing::Size(132, 25);
			this->tab0TextOldPassword->TabIndex = 3;
			this->tab0TextOldPassword->TextChanged += gcnew System::EventHandler(this, &MainWindow::textOldPassword_TextChanged);
			// 
			// tab0BtnCommitPassChange
			// 
			this->tab0BtnCommitPassChange->Enabled = false;
			this->tab0BtnCommitPassChange->Location = System::Drawing::Point(25, 202);
			this->tab0BtnCommitPassChange->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab0BtnCommitPassChange->Name = L"tab0BtnCommitPassChange";
			this->tab0BtnCommitPassChange->Size = System::Drawing::Size(100, 32);
			this->tab0BtnCommitPassChange->TabIndex = 6;
			this->tab0BtnCommitPassChange->Text = L"ZatwierdŸ";
			this->tab0BtnCommitPassChange->UseVisualStyleBackColor = true;
			this->tab0BtnCommitPassChange->Click += gcnew System::EventHandler(this, &MainWindow::btnCommitPassChange_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Stare has³o:";
			// 
			// tab0TextNewPassword2
			// 
			this->tab0TextNewPassword2->Location = System::Drawing::Point(8, 158);
			this->tab0TextNewPassword2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab0TextNewPassword2->Name = L"tab0TextNewPassword2";
			this->tab0TextNewPassword2->Size = System::Drawing::Size(132, 25);
			this->tab0TextNewPassword2->TabIndex = 5;
			this->tab0TextNewPassword2->TextChanged += gcnew System::EventHandler(this, &MainWindow::textNewPassword2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 82);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nowe has³o:";
			// 
			// tab0TextNewPassword
			// 
			this->tab0TextNewPassword->Location = System::Drawing::Point(8, 104);
			this->tab0TextNewPassword->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tab0TextNewPassword->Name = L"tab0TextNewPassword";
			this->tab0TextNewPassword->Size = System::Drawing::Size(132, 25);
			this->tab0TextNewPassword->TabIndex = 4;
			this->tab0TextNewPassword->TextChanged += gcnew System::EventHandler(this, &MainWindow::textNewPassword_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 136);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Powtórz has³o:";
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::SystemColors::Highlight;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(60, 60);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripButton4,
					this->toolStripButton2, this->toolStripButton3, this->toolStripButton5, this->toolStripButton6, this->toolStripButton1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->MinimumSize = System::Drawing::Size(0, 100);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1112, 100);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(92, 97);
			this->toolStripButton4->Text = L"Rezerwacje";
			this->toolStripButton4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &MainWindow::toolStripButton4_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(68, 97);
			this->toolStripButton2->Text = L"Klienci";
			this->toolStripButton2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MainWindow::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(92, 97);
			this->toolStripButton3->Text = L"Pracownicy";
			this->toolStripButton3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &MainWindow::toolStripButton3_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(64, 97);
			this->toolStripButton5->Text = L"Uslugi";
			this->toolStripButton5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &MainWindow::toolStripButton5_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(64, 97);
			this->toolStripButton6->Text = L"Praca";
			this->toolStripButton6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &MainWindow::toolStripButton6_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->toolStripButton1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(92, 97);
			this->toolStripButton1->Text = L"Ustawienia";
			this->toolStripButton1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MainWindow::toolStripButton1_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(1112, 885);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainWindow";
			this->tabControl1->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab5DgvUsluga))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab5DgvClient))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab5DgvUsers))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->tab4GbClient->ResumeLayout(false);
			this->tab4GbClient->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab4DgvClients))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab3DgvUslugi))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab3DgvWork))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab3DgvUsers))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tab2Gb->ResumeLayout(false);
			this->tab2Gb->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab2Dgv))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tab1GbHours->ResumeLayout(false);
			this->tab1GbHours->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tab1DgvUsers))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		Void btnCommitPassChange_Show();
		Void showGrid();
		Void userType();
		Void clearBox(Control^ list);
		Void fillBoxWithWorkTime(int beginTime);
		Void fillGrid(TextBox^ textBox, DataGridView^ dataGrid);
		Void userSearch(TextBox^ textBox, DataGridView^ dataGrid);
		Void showUslugi(int rowIndex);
		Void updateKlienci(TextBox^ textBox, DataGridView^ dataGrid);
		Void textBoxClick(System::Object^  sender, System::EventArgs^  e);
		Void showTermin();

	private: System::Void textOldPassword_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textNewPassword_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textNewPassword2_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCommitPassChange_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void dgvUsers_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tab1BtnAdd_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab1BtnModify_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab1BtnDelete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab1CbPracownik_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab2BtnSearch_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab2BtnDelete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab2BtnModify_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab2BtnAdd_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab2Dgv_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tab3BtnSearch_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab3DgvUsers_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tab3DgvUslugi_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tab3DgvWork_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tab4BtnSearch_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab4BtnAdd_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab4BtnModify_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab4BtnDelete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab4DgvClients_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tav5BtnSearchUser_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab5BtnSearchClient_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab5BtnUslugaSearch_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab5DgvUsluga_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tab5DgvClient_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void tab5DgvUsers_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	private: System::Void monthCalendar1_DateSelected(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e);
	private: System::Void tab5BtnAdd_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab5BtnModify_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tab5BtnDelete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripButton5_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void toolStripButton6_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
