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
	/// Summary for WithdrawlForm
	/// </summary>
	public ref class WithdrawlForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		Form^ prev;
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	public:
		String^ cID;
		WithdrawlForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		WithdrawlForm(Form^ _obj)
		{
			obj = _obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		WithdrawlForm(Form^ _obj, Form^ _prev)
		{
			obj = _obj;
			prev = _prev;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		WithdrawlForm(Form^ _obj, Form^ _prev, String^ _cID)
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
		~WithdrawlForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbWithdrawlAmount;
	private: System::Windows::Forms::TextBox^ tbWithdrawl;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Button^ btnLogout;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		//Rounds up a double
		double round_up(double value, int decimal_places) {
			const double multiplier = std::pow(10.0, decimal_places);
			return std::ceil(value * multiplier) / multiplier;
		}
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
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + depositAmount + "' where customerID = '" + cID + "';", conDatabase);
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader;
				MySqlDataReader^ myReader1;

				try
				{

					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						minDeposit = round_up(myReader1->GetDouble("minDeposit"), 2);
						if (Double::Parse(depositAmount) >= minDeposit)
						{
							//Execute query to update checking account balance
							conDatabase->Open();
							myReader = cmDataBase->ExecuteReader();

							newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
							accountNo = myReader1->GetInt32("accountNo").ToString();
						}
						else
						{
							MessageBox::Show("Error: You must deposit a minimum of $" + minDeposit + ". Please enter a new deposit amount.", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}
					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + transactionID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					//Create query to insert a new entry into Deposit table
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + transactionID + "', '" + depositAmount + "');", conDatabaseInsertToDeposit);
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
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance + '" + depositAmount + "' where customerID = '" + cID + "';", conDatabase);
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
					MySqlCommand^ cmDataBaseInsertToDeposit = gcnew MySqlCommand("insert into atm_system.deposit (transactionid, ammountdeposited) values ('" + transactionID + "', '" + depositAmount  + "');", conDatabaseInsertToDeposit);
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
		void makeWithdraw(String^ transactionID, String^ withdrawAmount, String^ date, String^ time)
		{
			double curBalance;
			String^ newBalance = "";
			String^ accountNo = "";
			double minBalance;
			double maxWithdraw;
			//Make connecions to MySql using log in credentials
			String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
			MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabase1 = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToWithdraw = gcnew MySqlConnection(consting);
			MySqlConnection^ conDatabaseInsertToTransaction = gcnew MySqlConnection(consting);
			//Check whether the user is in Checking or Savings Mode
			if (prev->Text == L"CheckingForm")
			{
				//Create query to update checking account balance
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance - '" + withdrawAmount + "' where customerID = '" + cID + "';", conDatabase);
				//Create query to get user data from checking and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.checking INNER JOIN atm_system.accounts ON atm_system.checking.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader;
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current checking account balance and accountNo into variables
					if (myReader1->Read())
					{
						curBalance = round_up(myReader1->GetDouble("balance"), 2);
						maxWithdraw = round_up(myReader1->GetDouble("maxWithdrawAmt"), 2);
						minBalance = round_up(myReader1->GetDouble("minBalance"), 2);
						if (minBalance <= curBalance - Double::Parse(withdrawAmount))
						{
							if (maxWithdraw > Double::Parse(withdrawAmount))
							{
								//Execute query to update checking account balance
								conDatabase->Open();
								myReader = cmDataBase->ExecuteReader();


								newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
								accountNo = myReader1->GetInt32("accountNo").ToString();
							}
							else
							{
								MessageBox::Show("Error: You can only withdraw a maximum of $" + maxWithdraw + ". Please enter a new withdraw amount.", "ATM System", MessageBoxButtons::OK, MessageBoxIcon::Error);
								return;
							}
						}
						else if (minBalance < Double::Parse(withdrawAmount) && maxWithdraw < Double::Parse(withdrawAmount))
						{
							//Initiates overdraft protection
							if (MessageBox::Show("Error: You must have a minimum balance of $" + minBalance + " would you like to initiate an overdraft?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
							{

							}
							else
							{
								return;
							}
						}

					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + transactionID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					//Create query to insert a new entry into Withdraw table
					MySqlCommand^ cmDataBaseInsertToWithdraw = gcnew MySqlCommand("insert into atm_system.withdraw (transactionid, ammountwithdrawn) values ('" + transactionID + "', '" + withdrawAmount + "');", conDatabaseInsertToWithdraw);
					MySqlDataReader^ myReaderInsertToTransaction;
					MySqlDataReader^ myReaderInsertToWithdraw;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();
					//this->tbWithdrawl->Text = accountNo;
					//Execute query to insert a new entry into Withdraw table
					conDatabaseInsertToWithdraw->Open();
					myReaderInsertToWithdraw = cmDataBaseInsertToWithdraw->ExecuteReader();

					//Display Success Message box with current checking balance
					MessageBox::Show("You Have Succsesfully Withdrawn $" + withdrawAmount + " into your checkings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
			else if (prev->Text == L"SavingForm")
			{
				//Create query to update savings account balance
				MySqlCommand^ cmDataBase = gcnew MySqlCommand("update atm_system.accounts set balance = balance - '" + withdrawAmount + "' where customerID = '" + cID + "';", conDatabase);
				//Create query to get user data from savings and account tables
				MySqlCommand^ cmDataBase1 = gcnew MySqlCommand("SELECT * FROM atm_system.saving INNER JOIN atm_system.accounts ON atm_system.saving.accountNo = atm_system.accounts.accountNo  where customerID = '" + cID + "';", conDatabase1);
				MySqlDataReader^ myReader;
				MySqlDataReader^ myReader1;

				try
				{
					//Execute query to update savings account balance
					conDatabase->Open();
					myReader = cmDataBase->ExecuteReader();

					//Execute query to get checking account balance
					conDatabase1->Open();
					myReader1 = cmDataBase1->ExecuteReader();

					//Store the current saving account balance and accountNo into variables
					if (myReader1->Read())
					{
						newBalance = round_up(myReader1->GetDouble("balance"), 2).ToString();
						accountNo = myReader1->GetInt32("accountNo").ToString();
					}

					//Create query to insert a new entry into Transaction table
					MySqlCommand^ cmDataBaseInsertToTransaction = gcnew MySqlCommand("insert into atm_system.transaction (transactionid, accountno, dateoftransaction, timeoftransaction) values ('" + transactionID + "', '" + accountNo + "', '" + date + "', '" + time + "');", conDatabaseInsertToTransaction);
					//Create query to insert a new entry into Withdraw table
					MySqlCommand^ cmDataBaseInsertToWithdraw = gcnew MySqlCommand("insert into atm_system.withdraw (transactionid, ammountwithdrawn) values ('" + transactionID + "', '" + withdrawAmount + "');", conDatabaseInsertToWithdraw);
					MySqlDataReader^ myReaderInsertToTransaction;
					MySqlDataReader^ myReaderInsertToWithdraw;

					//Execute query to insert a new entry into Transaction table
					conDatabaseInsertToTransaction->Open();
					myReaderInsertToTransaction = cmDataBaseInsertToTransaction->ExecuteReader();
					//this->tbWithdrawl->Text = accountNo;
					//Execute query to insert a new entry into Withdraw table
					conDatabaseInsertToWithdraw->Open();
					myReaderInsertToWithdraw = cmDataBaseInsertToWithdraw->ExecuteReader();

					//Display Success Message box with current checking balance
					MessageBox::Show("You Have Succsesfully Withdrawn $" + withdrawAmount + " into your savings account. \nCurrent balance is $" + newBalance);
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
		}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method d the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbWithdrawlAmount = (gcnew System::Windows::Forms::Label());
			this->tbWithdrawl = (gcnew System::Windows::Forms::TextBox());
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
			// lbWithdrawlAmount
			// 
			this->lbWithdrawlAmount->AutoSize = true;
			this->lbWithdrawlAmount->BackColor = System::Drawing::Color::Transparent;
			this->lbWithdrawlAmount->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWithdrawlAmount->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->lbWithdrawlAmount->Location = System::Drawing::Point(12, 20);
			this->lbWithdrawlAmount->Name = L"lbWithdrawlAmount";
			this->lbWithdrawlAmount->Size = System::Drawing::Size(298, 23);
			this->lbWithdrawlAmount->TabIndex = 3;
			this->lbWithdrawlAmount->Text = L"Please Enter A Withdrawl Amount";
			this->lbWithdrawlAmount->Click += gcnew System::EventHandler(this, &WithdrawlForm::lbTransferAmount_Click);
			// 
			// tbWithdrawl
			// 
			this->tbWithdrawl->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->tbWithdrawl->Location = System::Drawing::Point(13, 62);
			this->tbWithdrawl->Name = L"tbWithdrawl";
			this->tbWithdrawl->Size = System::Drawing::Size(344, 22);
			this->tbWithdrawl->TabIndex = 4;
			this->tbWithdrawl->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &WithdrawlForm::tbWithdrawl_KeyPress);
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(13, 116);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(339, 64);
			this->tableLayoutPanel1->TabIndex = 5;
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
			this->btnClear->Location = System::Drawing::Point(172, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(164, 58);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &WithdrawlForm::btnClear_Click);
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
			this->btnSubmit->Size = System::Drawing::Size(163, 58);
			this->btnSubmit->TabIndex = 3;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = false;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &WithdrawlForm::btnSubmit_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(360, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 12;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &WithdrawlForm::btnLogout_Click);
			// 
			// btnPrev
			// 
			this->btnPrev->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->btnPrev->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnPrev->Location = System::Drawing::Point(3, 3);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(96, 32);
			this->btnPrev->TabIndex = 15;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = false;
			this->btnPrev->Click += gcnew System::EventHandler(this, &WithdrawlForm::btnPrev_Click);
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
			this->tableLayoutPanel2->Location = System::Drawing::Point(16, 218);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(102, 38);
			this->tableLayoutPanel2->TabIndex = 20;
			// 
			// WithdrawlForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(172)), static_cast<System::Int32>(static_cast<System::Byte>(214)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(480, 268);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbWithdrawl);
			this->Controls->Add(this->lbWithdrawlAmount);
			this->MaximumSize = System::Drawing::Size(498, 315);
			this->MinimumSize = System::Drawing::Size(498, 315);
			this->Name = L"WithdrawlForm";
			this->Text = L"WithdrawlForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lbTransferAmount_Click(System::Object^ sender, System::EventArgs^ e) {
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
//Submits user inputed deposit amount to database and updates balance amount
private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
	//Get current date and time and store them in respective variables after properly formating them
	DateTime datetime = DateTime::Now;
	String^ month = datetime.ToString()->Substring(0, 2);
	String^ day = datetime.ToString()->Substring(3, 2);
	String^ year = datetime.ToString()->Substring(6, 4);
	String^ date = year + "-" + month + "-" + day + " 00:00:00";
	String^ time = datetime.ToString()->Substring(10, 8);
	if (time->Substring(0, 1) == " ")
	{
		time = "0" + datetime.ToString()->Substring(11, 7);
	}
	String^ transactionID = "28894"; // For testing purposes
	
	//Display a message box asking if user wants to deposit their specified amount (yes/no)
	if (MessageBox::Show("Do you really want to withdraw $" + this->tbWithdrawl->Text + "?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		String^ withdrawAmount = this->tbWithdrawl->Text;
		
		makeWithdraw(transactionID, withdrawAmount, date, time);

		//Clear Withdrawl text box
		this->tbWithdrawl->Text = "";
	}
	else
	{
		//do nothing
	}
	
}
//Clears Withdrawl text box
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	this->tbWithdrawl->Text = "";
}
private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	prev->Show();
}
private: System::Void tbWithdrawl_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == '.') {
		if (this->tbWithdrawl->Text->Contains(".") && !this->tbWithdrawl->SelectedText->Contains("."))
			e->Handled = true;
	}

	// Accept only digits ".", and the Backspace character
	else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
		e->Handled = true;
	}
}
};
}
