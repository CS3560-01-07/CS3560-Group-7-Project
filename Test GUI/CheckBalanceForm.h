#pragma once

namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CheckBalanceForm
	/// </summary>
	public ref class CheckBalanceForm : public System::Windows::Forms::Form
	{
	public:
		CheckBalanceForm(void)
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
		~CheckBalanceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbWithdrawlAmount;
	private: System::Windows::Forms::Label^ lbCurrentBalance;
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
			this->lbWithdrawlAmount = (gcnew System::Windows::Forms::Label());
			this->lbCurrentBalance = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbWithdrawlAmount
			// 
			this->lbWithdrawlAmount->AutoSize = true;
			this->lbWithdrawlAmount->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWithdrawlAmount->Location = System::Drawing::Point(12, 26);
			this->lbWithdrawlAmount->Name = L"lbWithdrawlAmount";
			this->lbWithdrawlAmount->Size = System::Drawing::Size(149, 23);
			this->lbWithdrawlAmount->TabIndex = 4;
			this->lbWithdrawlAmount->Text = L"Current Balance";
			// 
			// lbCurrentBalance
			// 
			this->lbCurrentBalance->AutoSize = true;
			this->lbCurrentBalance->Location = System::Drawing::Point(36, 105);
			this->lbCurrentBalance->Name = L"lbCurrentBalance";
			this->lbCurrentBalance->Size = System::Drawing::Size(46, 17);
			this->lbCurrentBalance->TabIndex = 5;
			this->lbCurrentBalance->Text = L"label1";
			// 
			// CheckBalanceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(635, 253);
			this->Controls->Add(this->lbCurrentBalance);
			this->Controls->Add(this->lbWithdrawlAmount);
			this->Name = L"CheckBalanceForm";
			this->Text = L"CheckBalanceForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
