#pragma once
#include <cmath>
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
		String^ cID;
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	public:
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

		DepositForm(Form^ _obj, String^ _cID)
		{
			obj = _obj;
			cID = _cID;
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

		DepositForm(Form^ _obj, Form^ _prev, String^ _cID)
		{
			obj = _obj;
			prev = _prev;
			cID = _cID;
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
		//Rounds up a double
		double round_up(double value, int decimal_places) {
			const double multiplier = std::pow(10.0, decimal_places);
			return std::ceil(value * multiplier) / multiplier;
		}
		//Makes a deposit
		void makeDeposit(String^ transactionID, String^ depositAmount, String^ date, String^ time)
		{
			String^ newBalance = "";
			String^ accountNo = "";
			double minDeposit;
			double minBalance;
			//Make connecions to MySql using log in credentials
			String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
			MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToDeposit = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToTransaction = gcnew MySqlConnection(consting);
			//Check whether the user is in Checking or Savings Mode
			if (prev->Text == L"CheckingForm")
			{
				//Create query to update checking account balance
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + this->tbDeposit->Text + "' where customerID = '" + cID + "';", conDatabase);
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader;
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to update checking account balance
					conDatabase->Open();
					myReader = cmDataBase->ExecuteReader();

					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
						accountNo = myReader1->GetInt32("accountNo").ToString();
					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + transactionID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					//Create query to insert a new entry into Deposit table
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + transactionID + "', '" + this->tbDeposit->Text + "');", conDatabaseInsertToDeposit);
					MySqlDataReader^ myReaderInsertToTransaction;
					MySqlDataReader^ myReaderInsertToDeposit;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();
					//this->tbDeposit->Text = accountNo;
					//Execute query to insert a new entry into Deposit table
					conDatabaseInsertToDeposit->Open();
					myReaderInsertToDeposit = cmDataBaseInsertToDeposit->ExecuteReader();

					//Display Success Message box with current checking balance
					MessageBox::Show("You Have Succsesfully Deposited $" + depositAmount + " into your checkings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
			else if (prev->Text == L"SavingForm")
			{
				//Create query to update saving account balance
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + this->tbDeposit->Text + "' where customerID = '" + cID + "';", conDatabase);
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader;
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get saving account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();


					//Store the current saving account balance and accountNo into variables
					if (myReader1->Read())
					{
						minDeposit = round_up(myReader1->GetDouble("minDeposit"), 2);
						if (minDeposit < Double::Parse(depositAmount))
						{
							//Execute query to update saving account balance
							conDatabase->Open();
							myReader = cmDataBase->ExecuteReader();

							newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
							accountNo = myReader1->GetInt32("accountNo").ToString();
						}
						else
						{
							MessageBox::Show("Error: You must deposit an amount greater than or equal to  $" + minDeposit + "!", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}

					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + transactionID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					//Create query to insert a new entry into Deposit table
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + transactionID + "', '" + this->tbDeposit->Text + "');", conDatabaseInsertToDeposit);
					MySqlDataReader^ myReaderInsertToTransaction;
					MySqlDataReader^ myReaderInsertToDeposit;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();
					//this->tbDeposit->Text = accountNo;
					//Execute query to insert a new entry into Deposit table
					conDatabaseInsertToDeposit->Open();
					myReaderInsertToDeposit = cmDataBaseInsertToDeposit->ExecuteReader();

					//Display Success Message box with current savings balance
					MessageBox::Show("You Have Succsesfully Deposited $" + depositAmount + " into your savings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}

			}
		}

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
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbDepositAmount
			// 
			this->lbDepositAmount->AutoSize = true;
			this->lbDepositAmount->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDepositAmount->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
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
			this->tbDeposit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
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
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
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
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnClear->Location = System::Drawing::Point(181, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(172, 58);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &DepositForm::btnClear_Click);
			// 
			// btnSubmit
			// 
			this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSubmit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnSubmit->Location = System::Drawing::Point(3, 3);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(172, 58);
			this->btnSubmit->TabIndex = 3;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = false;
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
			// btnPrev
			// 
			this->btnPrev->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnPrev->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnPrev->Location = System::Drawing::Point(3, 3);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(83, 32);
			this->btnPrev->TabIndex = 14;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = false;
			this->btnPrev->Click += gcnew System::EventHandler(this, &DepositForm::btnPrev_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->btnPrev, 0, 0);
			this->tableLayoutPanel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 227);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(89, 38);
			this->tableLayoutPanel2->TabIndex = 16;
			// 
			// DepositForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(480, 268);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbDeposit);
			this->Controls->Add(this->lbDepositAmount);
			this->MinimumSize = System::Drawing::Size(498, 315);
			this->Name = L"DepositForm";
			this->Text = L"DepositForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lbDepositAmount_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txtDeposit_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	//Submits user inputed deposit amount to database and updates balance amount
	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		//Get current date and time and store them in respective variables after properly formating them
		DateTime datetime = DateTime::Now;
		String^month = datetime.ToString()->Substring(0, 2);
		String^ day = datetime.ToString()->Substring(3, 2);
		String^ year = datetime.ToString()->Substring(6, 4);
		String^ date = year + "-" + month + "-" + day + " 00:00:00";
		String^ time = datetime.ToString()->Substring(10,8);
		if (time->Substring(0, 1) == " ")
		{
			time = "0" + datetime.ToString()->Substring(11, 7);
		}
		
		String^ transactionID = "0331";//For testing use only
		//Display a message box asking if user wants to deposit their specified amount (yes/no)
		if (MessageBox::Show("Do you really want to deposit $" + this->tbDeposit->Text + "?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			String^ depositAmount = this->tbDeposit->Text;
			
			makeDeposit(transactionID, depositAmount, date, time);

			//Clear Deposit text box
			this->tbDeposit->Text = "";
		}
		else
		{

		}
	}
	//Allows user to logout of their account
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//Sends conformation box asking user if they want to logout
		if (MessageBox::Show("Do you really want to logout?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			//takes user back to login page
			this->Close();
			obj->Show();
		}
		else
		{
			//do nothing
		}
	}
//Clears Deposit text box
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tbDeposit->Text = "";
}

//Hides this form and shows previous one
private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	prev->Show();
}
};
}