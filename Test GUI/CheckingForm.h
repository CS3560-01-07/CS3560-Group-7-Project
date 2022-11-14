#pragma once

namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CheckingForm
	/// </summary>
	public ref class CheckingForm : public System::Windows::Forms::Form
	{
	public:
		CheckingForm(void)
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
		~CheckingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Button^ btnDeposit;
	private: System::Windows::Forms::Button^ btnTransfer;
	private: System::Windows::Forms::Button^ btnWithdraw;
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Label^ lbTransactionType;
	private: System::Windows::Forms::Button^ btnCheckBalance;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnWithdraw = (gcnew System::Windows::Forms::Button());
			this->btnDeposit = (gcnew System::Windows::Forms::Button());
			this->btnTransfer = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->lbTransactionType = (gcnew System::Windows::Forms::Label());
			this->btnCheckBalance = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->btnDeposit, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnTransfer, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnWithdraw, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnCheckBalance, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 112);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1121, 212);
			this->tableLayoutPanel1->TabIndex = 8;
			// 
			// btnWithdraw
			// 
			this->btnWithdraw->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnWithdraw->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWithdraw->Location = System::Drawing::Point(283, 3);
			this->btnWithdraw->Name = L"btnWithdraw";
			this->btnWithdraw->Size = System::Drawing::Size(274, 206);
			this->btnWithdraw->TabIndex = 6;
			this->btnWithdraw->Text = L"Withdraw";
			this->btnWithdraw->UseVisualStyleBackColor = true;
			// 
			// btnDeposit
			// 
			this->btnDeposit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDeposit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeposit->Location = System::Drawing::Point(3, 3);
			this->btnDeposit->Name = L"btnDeposit";
			this->btnDeposit->Size = System::Drawing::Size(274, 206);
			this->btnDeposit->TabIndex = 4;
			this->btnDeposit->Text = L"Deposit";
			this->btnDeposit->UseVisualStyleBackColor = true;
			// 
			// btnTransfer
			// 
			this->btnTransfer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnTransfer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTransfer->Location = System::Drawing::Point(563, 3);
			this->btnTransfer->Name = L"btnTransfer";
			this->btnTransfer->Size = System::Drawing::Size(274, 206);
			this->btnTransfer->TabIndex = 5;
			this->btnTransfer->Text = L"Transfer";
			this->btnTransfer->UseVisualStyleBackColor = true;
			// 
			// btnPrev
			// 
			this->btnPrev->Location = System::Drawing::Point(24, 411);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(121, 41);
			this->btnPrev->TabIndex = 9;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = true;
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(1006, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(127, 32);
			this->btnLogout->TabIndex = 10;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			// 
			// lbTransactionType
			// 
			this->lbTransactionType->AutoSize = true;
			this->lbTransactionType->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTransactionType->Location = System::Drawing::Point(20, 12);
			this->lbTransactionType->Name = L"lbTransactionType";
			this->lbTransactionType->Size = System::Drawing::Size(288, 23);
			this->lbTransactionType->TabIndex = 11;
			this->lbTransactionType->Text = L"Please Select a Transaction Type";
			// 
			// btnCheckBalance
			// 
			this->btnCheckBalance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnCheckBalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCheckBalance->Location = System::Drawing::Point(843, 3);
			this->btnCheckBalance->Name = L"btnCheckBalance";
			this->btnCheckBalance->Size = System::Drawing::Size(275, 206);
			this->btnCheckBalance->TabIndex = 7;
			this->btnCheckBalance->Text = L"CheckBalance";
			this->btnCheckBalance->UseVisualStyleBackColor = true;
			// 
			// CheckingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1159, 538);
			this->Controls->Add(this->lbTransactionType);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnPrev);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MinimumSize = System::Drawing::Size(1177, 585);
			this->Name = L"CheckingForm";
			this->Text = L"CheckingForm";
			this->Load += gcnew System::EventHandler(this, &CheckingForm::CheckingForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void CheckingForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
