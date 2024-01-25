#pragma once

#include "Dictionary.hpp"
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
	/// Summary for formAdd
	/// </summary>
	public ref class formAdd : public System::Windows::Forms::Form
	{
	public:
		Dictionary& dictionary = Dictionary::getInstance();
		formAdd(void)
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
		~formAdd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ addWord;
	private: System::Windows::Forms::TextBox^ meaningBox;
	private: System::Windows::Forms::TextBox^ message;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->addWord = (gcnew System::Windows::Forms::Button());
			this->meaningBox = (gcnew System::Windows::Forms::TextBox());
			this->message = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI Light", 35, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(358, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(413, 60);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Add to Dictionary";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(234, 339);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(300, 25);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Enter Word Here";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &formAdd::textBox1_TextChanged);
			// 
			// addWord
			// 
			this->addWord->BackColor = System::Drawing::Color::RoyalBlue;
			this->addWord->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addWord->ForeColor = System::Drawing::Color::White;
			this->addWord->Location = System::Drawing::Point(471, 453);
			this->addWord->Name = L"addWord";
			this->addWord->Size = System::Drawing::Size(195, 37);
			this->addWord->TabIndex = 3;
			this->addWord->Text = L"Add Word";
			this->addWord->UseVisualStyleBackColor = false;
			this->addWord->Click += gcnew System::EventHandler(this, &formAdd::addWord_Click);
			// 
			// meaningBox
			// 
			this->meaningBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->meaningBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->meaningBox->Location = System::Drawing::Point(574, 339);
			this->meaningBox->MaximumSize = System::Drawing::Size(400, 76);
			this->meaningBox->MinimumSize = System::Drawing::Size(400, 20);
			this->meaningBox->Name = L"meaningBox";
			this->meaningBox->Size = System::Drawing::Size(400, 25);
			this->meaningBox->TabIndex = 4;
			this->meaningBox->Text = L"Enter Meaning Here";
			this->meaningBox->TextChanged += gcnew System::EventHandler(this, &formAdd::meaningBox_TextChanged);
			// 
			// message
			// 
			this->message->BackColor = System::Drawing::SystemColors::Control;
			this->message->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->message->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->message->ForeColor = System::Drawing::Color::Red;
			this->message->Location = System::Drawing::Point(234, 370);
			this->message->Name = L"message";
			this->message->Size = System::Drawing::Size(300, 18);
			this->message->TabIndex = 5;
			this->message->TextChanged += gcnew System::EventHandler(this, &formAdd::message_TextChanged);
			// 
			// formAdd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(5, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1500, 1084);
			this->ControlBox = false;
			this->Controls->Add(this->message);
			this->Controls->Add(this->meaningBox);
			this->Controls->Add(this->addWord);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 6.985075F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"formAdd";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"formAdd";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void addWord_Click(System::Object^ sender, System::EventArgs^ e) {
	// code to insert word

	System::String^ text = textBox1->Text;
	string word = msclr::interop::marshal_as<std::string>(text);

	System::String^ meaningText = meaningBox->Text;
	string meaning = msclr::interop::marshal_as<std::string>(meaningText);

	bool isValid = true;
	word = dictionary.validWord(word, isValid);


	
	bool isInserted = dictionary.insert(word, meaning);
	

	
	if (!isValid) {
		string messageText = "Not Valid word, considered ( " + word + " )";
		System::String^ Message = msclr::interop::marshal_as<System::String^>(messageText);
		message->Text = Message;
	}

	if (!isInserted) {
		MessageBox::Show("Word already exists");
	}
	else {
		MessageBox::Show("Word added successfully");
	}

	
}
private: System::Void meaningBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void message_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
