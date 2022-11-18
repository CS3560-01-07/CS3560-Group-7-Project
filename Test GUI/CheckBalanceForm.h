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
	/// Summary for CheckBalanceForm
	/// </summary>
	public ref class CheckBalanceForm : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		String^ cardNum;
		CheckBalanceForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		CheckBalanceForm(Form^ _obj)
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
		~CheckBalanceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbCurBalance;
	protected:

	private: System::Windows::Forms::Label^ lbCurrentBalance;
	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Button^ btnPrev;
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
			this->lbCurBalance = (gcnew System::Windows::Forms::Label());
			this->lbCurrentBalance = (gcnew System::Windows::Forms::Label());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbCurBalance
			// 
			this->lbCurBalance->AutoSize = true;
			this->lbCurBalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCurBalance->Location = System::Drawing::Point(12, 26);
			this->lbCurBalance->Name = L"lbCurBalance";
			this->lbCurBalance->Size = System::Drawing::Size(149, 23);
			this->lbCurBalance->TabIndex = 4;
			this->lbCurBalance->Text = L"Current Balance";
			// 
			// lbCurrentBalance
			// 
			this->lbCurrentBalance->AutoSize = true;
			this->lbCurrentBalance->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->lbCurrentBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbCurrentBalance->Location = System::Drawing::Point(12, 85);
			this->lbCurrentBalance->Name = L"lbCurrentBalance";
			this->lbCurrentBalance->Size = System::Drawing::Size(131, 24);
			this->lbCurrentBalance->TabIndex = 5;
			this->lbCurrentBalance->Text = L"Click To Show";
			this->lbCurrentBalance->Click += gcnew System::EventHandler(this, &CheckBalanceForm::lbCurrentBalance_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnLogout->BackColor = System::Drawing::Color::MistyRose;
			this->btnLogout->Location = System::Drawing::Point(283, 12);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(108, 32);
			this->btnLogout->TabIndex = 12;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			// 
			// btnPrev
			// 
			this->btnPrev->Location = System::Drawing::Point(12, 155);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(90, 31);
			this->btnPrev->TabIndex = 13;
			this->btnPrev->Text = L"Prev";
			this->btnPrev->UseVisualStyleBackColor = true;
			this->btnPrev->Click += gcnew System::EventHandler(this, &CheckBalanceForm::btnPrev_Click);
			// 
			// CheckBalanceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(403, 208);
			this->Controls->Add(this->btnPrev);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->lbCurrentBalance);
			this->Controls->Add(this->lbCurBalance);
			this->MinimumSize = System::Drawing::Size(421, 255);
			this->Name = L"CheckBalanceForm";
			this->Text = L"CheckBalanceForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void lbCurrentBalance_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ curBalance = "";
		String^ consting = L"datasource=localhost;port=3306;username=root;password=storage*Queenlion5";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(consting);
		MySqlCommand^ cmDataBase = gcnew MySqlCommand("select * from testcreation.edata where Eid = 1;", conDatabase);
		MySqlDataReader^ myReader;
		try
		{
			conDatabase->Open();
			myReader = cmDataBase->ExecuteReader();

			if (myReader->Read())
			{
				curBalance = myReader->GetInt32("balance").ToString();
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
		this->lbCurrentBalance->Text = L"Current Balance: $" + curBalance;
	}
	private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}
