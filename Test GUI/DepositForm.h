#pragma once

namespace TestGUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for DepositForm
	/// </summary>
	public ref class DepositForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		Form^ prev;
		String^ cardNum;
		String^ pinNum;
		DepositForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		DepositForm(Form^ _obj)
		{
			obj = _obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		DepositForm(Form^ _obj, String^ _cardNum)
		{
			obj = _obj;
			cardNum = _cardNum;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		DepositForm(Form^ _obj, Form^ _prev)
		{
			obj = _obj;
			prev = _prev;
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		DepositForm(Form^ _obj, Form^ _prev, String^ _cardNum)
		{
			obj = _obj;
			prev = _prev;
			cardNum = _cardNum;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DepositForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbDepositAmount;
	private: System::Windows::Forms::TextBox^ tbDeposit;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Button^ btnLogout;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbDepositAmount = (gcnew System::Windows::Forms::Label());
			this->tbDeposit = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbDepositAmount
			// 
			this->lbDepositAmount->AutoSize = true;
			this->lbDepositAmount->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDepositAmount->Location = System::Drawing::Point(12, 21);
			this->lbDepositAmount->Name = L"lbDepositAmount";
			this->lbDepositAmount->Size = System::Drawing::Size(274, 23);
			this->lbDepositAmount->TabIndex = 1;
			this->lbDepositAmount->Text = L"Please Enter A Deposit Amount";
			this->lbDepositAmount->Click += gcnew System::EventHandler(this, &DepositForm::lbDepositAmount_Click);
			// 
			// tbDeposit
			// 
			this->tbDeposit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbDeposit->Location = System::Drawing::Point(18, 73);
			this->tbDeposit->Name = L"tbDeposit";
			this->tbDeposit->Size = System::Drawing::Size(344, 22);
			this->tbDeposit->TabIndex = 2;
			this->tbDeposit->TextChanged += gcnew System::EventHandler(this, &DepositForm::txtDeposit_TextChanged);
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 135);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(356, 64);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// btnClear
			// 
			this->btnClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(181, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(172, 58);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &DepositForm::btnClear_Click);
			// 
			// btnSubmit
			// 
			this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->Location = System::Drawing::Point(3, 3);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(172, 58);
			this->btnSubmit->TabIndex = 3;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &DepositForm::btnSubmit_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(360, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 11;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &DepositForm::btnLogout_Click);
			// 
			// DepositForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(480, 235);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbDeposit);
			this->Controls->Add(this->lbDepositAmount);
			this->MinimumSize = System::Drawing::Size(498, 282);
			this->Name = L"DepositForm";
			this->Text = L"DepositForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lbDepositAmount_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txtDeposit_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ depositAmount = this->tbDeposit->Text;
		String^ newBalance = "";
		String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
		MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);
		if (prev->Name == L"CheckingForm")
		{
			MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + this->tbDeposit->Text + "' where accountNo = 1266;", conDatabase);
			MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("select * from atm_system.accounts where accountNo = 1266;", conDatabase1);
			MySqlDataReader^ myReader;
			MySqlDataReader^ myReader1;

			try
			{
				conDatabase->Open();
				myReader = cmDataBase->ExecuteReader();

				conDatabase1->Open();
				myReader1 = cmDataBase1->ExecuteReader();

				if (myReader1->Read())
				{
					newBalance = myReader1->GetInt32("balance").ToString();
				}
				MessageBox::Show("You Have Succsesfully Deposited $" + depositAmount + " into your account. \nCurrent balance is $" + newBalance);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
		else if (prev->Name == L"SavingForm")
		{
			MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + this->tbDeposit->Text + "' where accountNo = 1266;", conDatabase);
			MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("select * from atm_system.accounts where accountNo = 1266;", conDatabase1);
			MySqlDataReader^ myReader;
			MySqlDataReader^ myReader1;

			try
			{
				conDatabase->Open();
				myReader = cmDataBase->ExecuteReader();

				conDatabase1->Open();
				myReader1 = cmDataBase1->ExecuteReader();

				if (myReader1->Read())
				{
					newBalance = myReader1->GetInt32("balance").ToString();
				}
				MessageBox::Show("You Have Succsesfully Deposited $" + depositAmount + " into your account. \nCurrent balance is $" + newBalance);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}

		}
		
		this->tbDeposit->Text = "";
	}
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		obj->Show();
	}
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tbDeposit->Text = "";
}
};
}