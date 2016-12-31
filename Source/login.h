#pragma once

#include "MainWindow.h"

namespace Serwis2017 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Mysql::Data::MySqlClient;

	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public:
		login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnLogin;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textUser;
	private: System::Windows::Forms::TextBox^  textPassword;
	protected:


	protected:

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
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textUser = (gcnew System::Windows::Forms::TextBox());
			this->textPassword = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(12, 90);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Zaloguj";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &login::button1_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(139, 90);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Anuluj";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &login::btnCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nazwa u¿ytkownika";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Has³o";
			// 
			// textUser
			// 
			this->textUser->Location = System::Drawing::Point(12, 25);
			this->textUser->Name = L"textUser";
			this->textUser->Size = System::Drawing::Size(202, 20);
			this->textUser->TabIndex = 4;
			// 
			// textPassword
			// 
			this->textPassword->Location = System::Drawing::Point(12, 64);
			this->textPassword->Name = L"textPassword";
			this->textPassword->PasswordChar = '$';
			this->textPassword->Size = System::Drawing::Size(202, 20);
			this->textPassword->TabIndex = 5;
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(229, 123);
			this->Controls->Add(this->textPassword);
			this->Controls->Add(this->textUser);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnLogin);
			this->Name = L"login";
			this->Text = L"login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();

		String^ config = L"datasource=localhost;port=3306;username=root;password=lol123;database=gabinet";
		MainWindow^ mainWindow = gcnew MainWindow();
		mainWindow->ShowDialog();
		this->Close();
	}
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
	}
};
}
