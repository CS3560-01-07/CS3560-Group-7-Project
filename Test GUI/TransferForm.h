#pragma once

namespace TestGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TransferForm
	/// </summary>
	public ref class TransferForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		TransferForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		TransferForm(Form^ _obj)
		{
			obj = _obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TransferForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbTransferAmount;
	protected:

	private: System::Windows::Forms::TextBox^ tbTransfer;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Button^ btnLogout;

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
			this->lbTransferAmount = (gcnew System::Windows::Forms::Label());
			this->tbTransfer = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbTransferAmount
			// 
			this->lbTransferAmount->AutoSize = true;
			this->lbTransferAmount->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTransferAmount->Location = System::Drawing::Point(12, 21);
			this->lbTransferAmount->Name = L"lbTransferAmount";
			this->lbTransferAmount->Size = System::Drawing::Size(283, 23);
			this->lbTransferAmount->TabIndex = 2;
			this->lbTransferAmount->Text = L"Please Enter A Transfer Amount";
			// 
			// tbTransfer
			// 
			this->tbTransfer->Location = System::Drawing::Point(16, 74);
			this->tbTransfer->Name = L"tbTransfer";
			this->tbTransfer->Size = System::Drawing::Size(344, 22);
			this->tbTransfer->TabIndex = 3;
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
			this->tableLayoutPanel1->Location = System::Drawing::Point(16, 139);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(344, 63);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// btnClear
			// 
			this->btnClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(175, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(166, 57);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			// 
			// btnSubmit
			// 
			this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->Location = System::Drawing::Point(3, 3);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(166, 57);
			this->btnSubmit->TabIndex = 3;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = true;
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
			this->btnLogout->Click += gcnew System::EventHandler(this, &TransferForm::btnLogout_Click);
			// 
			// TransferForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(480, 235);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->tbTransfer);
			this->Controls->Add(this->lbTransferAmount);
			this->MinimumSize = System::Drawing::Size(498, 282);
			this->Name = L"TransferForm";
			this->Text = L"TransferForm";
			this->Load += gcnew System::EventHandler(this, &TransferForm::TransferForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		obj->Show();
	}
private: System::Void TransferForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
