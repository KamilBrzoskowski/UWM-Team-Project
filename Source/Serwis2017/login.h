#pragma once

#include "UiPracownika.h"
#include "UiKierownika.h"

namespace Serwis2017 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

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
			this->btnLogin->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btnLogin->FlatAppearance->BorderSize = 0;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Location = System::Drawing::Point(16, 125);
			this->btnLogin->Margin = System::Windows::Forms::Padding(4);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(100, 32);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Zaloguj";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &login::button1_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::SystemColors::HotTrack;
			this->btnCancel->FlatAppearance->BorderSize = 0;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Location = System::Drawing::Point(185, 125);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(100, 32);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Anuluj";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &login::btnCancel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nazwa u¿ytkownika";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 66);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Has³o";
			// 
			// textUser
			// 
			this->textUser->Location = System::Drawing::Point(16, 35);
			this->textUser->Margin = System::Windows::Forms::Padding(4);
			this->textUser->Name = L"textUser";
			this->textUser->Size = System::Drawing::Size(268, 25);
			this->textUser->TabIndex = 4;
			this->textUser->Text = L"admin";
			// 
			// textPassword
			// 
			this->textPassword->Location = System::Drawing::Point(16, 89);
			this->textPassword->Margin = System::Windows::Forms::Padding(4);
			this->textPassword->Name = L"textPassword";
			this->textPassword->PasswordChar = '*';
			this->textPassword->Size = System::Drawing::Size(268, 25);
			this->textPassword->TabIndex = 5;
			this->textPassword->Text = L"lol123";
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(305, 170);
			this->Controls->Add(this->textPassword);
			this->Controls->Add(this->textUser);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnLogin);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		

		String^ config = L"datasource=localhost;port=3306;username=root;password=lol123;database=serwis";
		MySqlConnection^ db = gcnew MySqlConnection(config);
		MySqlCommand^ query = gcnew MySqlCommand("select id, pozycja from pracownik where nazwa = '" + textUser->Text + "' AND haslo = password('" + textPassword->Text + "');", db);
		MySqlDataReader^ result;

		try
		{
			db->Open();
			result = query->ExecuteReader();

			if (result->Read())
			{
				int id = result->GetInt32(0);
				this->Hide();
				if (result->GetString(1) == "pracownik")
				{
					UIPracownika^ newWindow = gcnew UIPracownika(id);
					newWindow->ShowDialog();
				}
				else if (result->GetString(1) == "kierownik")
				{
					UIKierownika^ newWindow = gcnew UIKierownika(id);
					newWindow->ShowDialog();
				}
				this->Close();
			}
			else
			{
				MessageBox::Show("Bledna nazwa uzytkownika lub haslo");
			}
			db->Close();
		}
		catch ( Exception^ err)
		{
			MessageBox::Show(err->Message);
			return;
		}
	}
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
	}
};
}
