#pragma once

#include "Dictionary.hpp"
#include <string>
#include <msclr/marshal_cppstd.h>
namespace DictionaryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for formEdit
	/// </summary>
	public ref class formEdit : public System::Windows::Forms::Form
	{
	public:
		Dictionary& dictionary = Dictionary::getInstance();
		formEdit(void)
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
		~formEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ wordBox;
	private: System::Windows::Forms::TextBox^ MeaningBox;


	private: System::Windows::Forms::Button^ button1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->wordBox = (gcnew System::Windows::Forms::TextBox());
			this->MeaningBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 35, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(419, 84);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(266, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Edit Word ";
			this->label1->Click += gcnew System::EventHandler(this, &formEdit::label1_Click);
			// 
			// wordBox
			// 
			this->wordBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI Light", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wordBox->Location = System::Drawing::Point(253, 292);
			this->wordBox->Margin = System::Windows::Forms::Padding(2);
			this->wordBox->MinimumSize = System::Drawing::Size(300, 45);
			this->wordBox->Name = L"wordBox";
			this->wordBox->Size = System::Drawing::Size(300, 45);
			this->wordBox->TabIndex = 1;
			this->wordBox->Text = L"Enter Word";
			this->wordBox->TextChanged += gcnew System::EventHandler(this, &formEdit::wordBox_TextChanged);
			// 
			// MeaningBox
			// 
			this->MeaningBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI Light", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MeaningBox->Location = System::Drawing::Point(601, 292);
			this->MeaningBox->Margin = System::Windows::Forms::Padding(2);
			this->MeaningBox->MinimumSize = System::Drawing::Size(300, 45);
			this->MeaningBox->Name = L"MeaningBox";
			this->MeaningBox->Size = System::Drawing::Size(300, 45);
			this->MeaningBox->TabIndex = 2;
			this->MeaningBox->Text = L"Enter Meaning";
			this->MeaningBox->TextChanged += gcnew System::EventHandler(this, &formEdit::MeaningBox_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::RoyalBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(508, 429);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 33);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Edit Word";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &formEdit::button1_Click);
			// 
			// formEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1500, 1100);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->MeaningBox);
			this->Controls->Add(this->wordBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"formEdit";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"formEdit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ text = wordBox->Text;
	string word = msclr::interop::marshal_as<std::string>(text);

	bool isValid = true;
	word = dictionary.validWord(word, isValid);

	System::String^ meaning = MeaningBox->Text;
	string newMeaning = msclr::interop::marshal_as<std::string>(meaning);


	if (isValid && dictionary.contains(word)) {
		string& wordMeaning = dictionary.getMeaning(word);
		dictionary.editMeaning(word, newMeaning);
		//MeaningBox->Text = gcnew String(wordMeaning.c_str());
		wordMeaning = newMeaning;
		MessageBox::Show("Meaning changed successfully");
	}
	else {

		MeaningBox->Clear();
		if (!isValid) {

			MessageBox::Show("Invalid word!!!");
			return;
		}
		
		MessageBox::Show("Word not found");
	}

}
private: System::Void wordBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void MeaningBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
