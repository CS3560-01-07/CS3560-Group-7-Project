#pragma once

#include "Form2.h"
namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		String^ cardNum;
		String^ pinNum;
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lb16DigitCardNum;
	protected:

	private: System::Windows::Forms::TextBox^ tb16DigitCardNum;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnClear;


	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Label^ lbDisplay;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ tb4DigitPinNum;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbWelcome;


	private: System::ComponentModel::IContainer^ components;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lb16DigitCardNum = (gcnew System::Windows::Forms::Label());
			this->tb16DigitCardNum = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->lbDisplay = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tb4DigitPinNum = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lb16DigitCardNum
			// 
			this->lb16DigitCardNum->AutoSize = true;
			this->lb16DigitCardNum->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb16DigitCardNum->Location = System::Drawing::Point(33, 122);
			this->lb16DigitCardNum->Name = L"lb16DigitCardNum";
			this->lb16DigitCardNum->Size = System::Drawing::Size(195, 23);
			this->lb16DigitCardNum->TabIndex = 0;
			this->lb16DigitCardNum->Text = L"16 Digit Card Number";
			// 
			// tb16DigitCardNum
			// 
			this->tb16DigitCardNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb16DigitCardNum->Location = System::Drawing::Point(37, 160);
			this->tb16DigitCardNum->MaxLength = 16;
			this->tb16DigitCardNum->Name = L"tb16DigitCardNum";
			this->tb16DigitCardNum->Size = System::Drawing::Size(607, 22);
			this->tb16DigitCardNum->TabIndex = 1;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnClear, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnSubmit, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(37, 291);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(607, 64);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// btnClear
			// 
			this->btnClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(306, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(298, 58);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click);
			// 
			// btnSubmit
			// 
			this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->Location = System::Drawing::Point(3, 3);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(297, 58);
			this->btnSubmit->TabIndex = 3;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// lbDisplay
			// 
			this->lbDisplay->AutoSize = true;
			this->lbDisplay->Location = System::Drawing::Point(41, 441);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(0, 17);
			this->lbDisplay->TabIndex = 3;
			this->lbDisplay->Click += gcnew System::EventHandler(this, &MainForm::label1_Click_1);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// tb4DigitPinNum
			// 
			this->tb4DigitPinNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb4DigitPinNum->Location = System::Drawing::Point(37, 230);
			this->tb4DigitPinNum->MaxLength = 4;
			this->tb4DigitPinNum->Name = L"tb4DigitPinNum";
			this->tb4DigitPinNum->PasswordChar = '*';
			this->tb4DigitPinNum->Size = System::Drawing::Size(607, 22);
			this->tb4DigitPinNum->TabIndex = 6;
			this->tb4DigitPinNum->TextChanged += gcnew System::EventHandler(this, &MainForm::tb4DigitPinNum_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(33, 204);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 23);
			this->label1->TabIndex = 7;
			this->label1->Text = L"4 Digit Pin Number";
			// 
			// lbWelcome
			// 
			this->lbWelcome->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbWelcome->Location = System::Drawing::Point(30, 48);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(628, 38);
			this->lbWelcome->TabIndex = 9;
			this->lbWelcome->Text = L"Welcome To The Purloin Bank ATM System ";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(821, 435);
			this->Controls->Add(this->lbWelcome);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb4DigitPinNum);
			this->Controls->Add(this->lbDisplay);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tb16DigitCardNum);
			this->Controls->Add(this->lb16DigitCardNum);
			this->MinimumSize = System::Drawing::Size(839, 482);
			this->Name = L"MainForm";
			this->Text = L"ATM Login";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ sixTeenDigitCardNum = this->tb16DigitCardNum->Text;
		String^ fourDigitPinNum = this->tb4DigitPinNum->Text;
		pinNum = fourDigitPinNum;
		cardNum = sixTeenDigitCardNum;
		if (sixTeenDigitCardNum->Length != 16 || fourDigitPinNum->Length != 4)
		{
			this->lbDisplay->Text = "Error: You entered in a " + sixTeenDigitCardNum->Length + " card number";
		}
		if (fourDigitPinNum->Length != 4)
		{
			this->lbDisplay->Text = "Error: You entered in a " + fourDigitPinNum->Length + " ID number";
		}
		else
		{
			this->lbDisplay->Text += sixTeenDigitCardNum;
			this->lbDisplay->Text += fourDigitPinNum;
		}
		String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
		MySqlCommand^ cmDataBase = gcnew MySqlCommand("select * from atm_system.accounts where cardNo ='" + this->tb16DigitCardNum->Text + "' and accountNo='" + this->tb4DigitPinNum->Text + "';", conDatabase);
		MySqlDataReader^ myReader;
		try
		{
			conDatabase->Open();
			myReader = cmDataBase->ExecuteReader();

			int count = 0;
			while (myReader->Read())
			{
				count += 1;
			}
			if (count == 1)
			{
				MessageBox::Show("Card Number and Pin are correct");
			}
			else if (count > 1)
			{
				MessageBox::Show("There are Duplicate Card Number and Pin ...Access Denied");
			}
			else
			{
				MessageBox::Show("Card Number and/or Pin Incorrect ...Please Try Again");
			}
			this->Hide();
			this->tb16DigitCardNum->Text = "";
			this->tb4DigitPinNum->Text = "";
			Form2^ f2 = gcnew Form2(this, cardNum);
			f2->ShowDialog();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		this->tb16DigitCardNum->Text = "";
		this->tb4DigitPinNum->Text = "";
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->lbDisplay->Text = "";
	}
	
private: System::Void tb4DigitPinNum_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
