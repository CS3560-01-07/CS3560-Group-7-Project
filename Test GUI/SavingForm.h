#pragma once
#include "DepositForm.h"
#include "TransferForm.h"
#include "CheckBalanceForm.h"

namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SavingForm
	/// </summary>
	public ref class SavingForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		String^ cID;
		SavingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SavingForm(Form^ _obj, String^ _cID)
		{
			obj = _obj;
			cID = _cID;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SavingForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:


	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::Label^ lbTransactionType;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnCheckBalance;
	private: System::Windows::Forms::Button^ btnDeposit;
	private: System::Windows::Forms::Button^ btnTransfer;


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
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->lbTransactionType = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnCheckBalance = (gcnew System::Windows::Forms::Button());
			this->btnDeposit = (gcnew System::Windows::Forms::Button());
			this->btnTransfer = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(988, 21);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 10;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &SavingForm::btnLogout_Click);
			// 
			// btnPrev
			// 
			this->btnPrev->Location = System::Drawing::Point(12, 335);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(162, 41);
			this->btnPrev->TabIndex = 11;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = true;
			this->btnPrev->Click += gcnew System::EventHandler(this, &SavingForm::btnPrev_Click);
			// 
			// lbTransactionType
			// 
			this->lbTransactionType->AutoSize = true;
			this->lbTransactionType->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTransactionType->Location = System::Drawing::Point(12, 21);
			this->lbTransactionType->Name = L"lbTransactionType";
			this->lbTransactionType->Size = System::Drawing::Size(288, 23);
			this->lbTransactionType->TabIndex = 12;
			this->lbTransactionType->Text = L"Please Select a Transaction Type";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.85549F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.14451F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				379)));
			this->tableLayoutPanel1->Controls->Add(this->btnCheckBalance, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnDeposit, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnTransfer, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(16, 98);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1080, 201);
			this->tableLayoutPanel1->TabIndex = 13;
			// 
			// btnCheckBalance
			// 
			this->btnCheckBalance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnCheckBalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCheckBalance->Location = System::Drawing::Point(703, 3);
			this->btnCheckBalance->Name = L"btnCheckBalance";
			this->btnCheckBalance->Size = System::Drawing::Size(374, 195);
			this->btnCheckBalance->TabIndex = 6;
			this->btnCheckBalance->Text = L"CheckBalance";
			this->btnCheckBalance->UseVisualStyleBackColor = true;
			this->btnCheckBalance->Click += gcnew System::EventHandler(this, &SavingForm::btnCheckBalance_Click);
			// 
			// btnDeposit
			// 
			this->btnDeposit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDeposit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeposit->Location = System::Drawing::Point(3, 3);
			this->btnDeposit->Name = L"btnDeposit";
			this->btnDeposit->Size = System::Drawing::Size(343, 195);
			this->btnDeposit->TabIndex = 4;
			this->btnDeposit->Text = L"Deposit";
			this->btnDeposit->UseVisualStyleBackColor = true;
			this->btnDeposit->Click += gcnew System::EventHandler(this, &SavingForm::btnDeposit_Click);
			// 
			// btnTransfer
			// 
			this->btnTransfer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnTransfer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTransfer->Location = System::Drawing::Point(352, 3);
			this->btnTransfer->Name = L"btnTransfer";
			this->btnTransfer->Size = System::Drawing::Size(345, 195);
			this->btnTransfer->TabIndex = 5;
			this->btnTransfer->Text = L"Transfer";
			this->btnTransfer->UseVisualStyleBackColor = true;
			this->btnTransfer->Click += gcnew System::EventHandler(this, &SavingForm::btnTransfer_Click);
			// 
			// SavingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1150, 498);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->lbTransactionType);
			this->Controls->Add(this->btnPrev);
			this->Controls->Add(this->btnLogout);
			this->MinimumSize = System::Drawing::Size(1168, 545);
			this->Name = L"SavingForm";
			this->Text = L"SavingForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnDeposit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		DepositForm^ f1 = gcnew DepositForm(obj, cID);
		f1->ShowDialog();
	}
	private: System::Void btnTransfer_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		TransferForm^ f2 = gcnew TransferForm(obj, cID);
		f2->ShowDialog();
	}
	private: System::Void btnCheckBalance_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		CheckBalanceForm^ f3 = gcnew CheckBalanceForm(obj, cID);
		f3->ShowDialog();
	}
	private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
	
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Do you really want to logout?", "ATM System", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			this->Close();
			obj->Show();
		}
		else
		{

		}
	}
};
}