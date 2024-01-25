#pragma once


#include "Dictionary.hpp"
#include <msclr/marshal_cppstd.h>
#include <string>
namespace DictionaryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for formDelete
	/// </summary>
	public ref class formDelete : public System::Windows::Forms::Form
	{
	public:
		Dictionary& dictionary = Dictionary::getInstance();
		formDelete(void)
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
		~formDelete()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ deleteTextBox;
	private: System::Windows::Forms::Button^ deleteWord;
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
			this->deleteTextBox = (gcnew System::Windows::Forms::TextBox());
			this->deleteWord = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 35, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->label1->Location = System::Drawing::Point(424, 83);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(305, 60);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Delete Word";
			// 
			// deleteTextBox
			// 
			this->deleteTextBox->Location = System::Drawing::Point(184, 290);
			this->deleteTextBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->deleteTextBox->MinimumSize = System::Drawing::Size(750, 36);
			this->deleteTextBox->Multiline = true;
			this->deleteTextBox->Name = L"deleteTextBox";
			this->deleteTextBox->Size = System::Drawing::Size(800, 76);
			this->deleteTextBox->TabIndex = 3;
			this->deleteTextBox->Text = L"     Enter Text to Delete";
			this->deleteTextBox->UseWaitCursor = true;
			this->deleteTextBox->TextChanged += gcnew System::EventHandler(this, &formDelete::deleteTextBox_TextChanged);
			// 
			// deleteWord
			// 
			this->deleteWord->BackColor = System::Drawing::Color::RoyalBlue;
			this->deleteWord->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteWord->ForeColor = System::Drawing::Color::White;
			this->deleteWord->Location = System::Drawing::Point(494, 430);
			this->deleteWord->Name = L"deleteWord";
			this->deleteWord->Size = System::Drawing::Size(178, 41);
			this->deleteWord->TabIndex = 4;
			this->deleteWord->Text = L"Delete Word";
			this->deleteWord->UseVisualStyleBackColor = false;
			this->deleteWord->Click += gcnew System::EventHandler(this, &formDelete::deleteWord_Click);
			// 
			// formDelete
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1500, 1084);
			this->ControlBox = false;
			this->Controls->Add(this->deleteWord);
			this->Controls->Add(this->deleteTextBox);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"formDelete";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"formDelete";
			this->Load += gcnew System::EventHandler(this, &formDelete::formDelete_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void formDelete_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void deleteTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void deleteWord_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ text = deleteTextBox->Text;
	string word = msclr::interop::marshal_as<std::string>(text);

	if (dictionary.contains(word)) {
		HashMapEntry* deletionNode = dictionary.getEntry(word);
		dictionary.deleteWord(word);
		dictionary.deleteFromFileData(deletionNode->offset);
		MessageBox::Show("Word deleted successfully");
	}
	else {
		MessageBox::Show("Word not found");
	}
}
};
}
