#pragma once
#include<iostream>
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
	/// Summary for formSearch
	/// </summary>
	public ref class formSearch : public System::Windows::Forms::Form
	{
		
	public:
		Dictionary& dictionary = Dictionary::getInstance();

		formSearch(void)
		{
			InitializeComponent();
			suggestionbox->Columns->Add("Words");
			suggestionbox->Columns[0]->Text = "";
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~formSearch()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ wordTextBox;
	private: System::Windows::Forms::TextBox^ MeaningTextBox;
	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::ListView^ suggestionbox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ColumnHeader^ TopResults;
	private: System::Windows::Forms::ListView^ related;
	private: System::Windows::Forms::ColumnHeader^ RelatedWords;







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
			System::Windows::Forms::ListViewItem^ listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(L""));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->wordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MeaningTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->suggestionbox = (gcnew System::Windows::Forms::ListView());
			this->TopResults = (gcnew System::Windows::Forms::ColumnHeader());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->related = (gcnew System::Windows::Forms::ListView());
			this->RelatedWords = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 35, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(479, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(443, 86);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search Word";
			// 
			// wordTextBox
			// 
			this->wordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wordTextBox->Location = System::Drawing::Point(129, 329);
			this->wordTextBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->wordTextBox->MinimumSize = System::Drawing::Size(399, 34);
			this->wordTextBox->Name = L"wordTextBox";
			this->wordTextBox->Size = System::Drawing::Size(399, 45);
			this->wordTextBox->TabIndex = 1;
			this->wordTextBox->Text = L"Word";
			this->wordTextBox->TextChanged += gcnew System::EventHandler(this, &formSearch::wordTextBox_TextChanged);
			// 
			// MeaningTextBox
			// 
			this->MeaningTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei Light", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MeaningTextBox->Location = System::Drawing::Point(613, 329);
			this->MeaningTextBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MeaningTextBox->MinimumSize = System::Drawing::Size(399, 60);
			this->MeaningTextBox->Name = L"MeaningTextBox";
			this->MeaningTextBox->Size = System::Drawing::Size(399, 60);
			this->MeaningTextBox->TabIndex = 2;
			this->MeaningTextBox->Text = L"Meaning";
			this->MeaningTextBox->TextChanged += gcnew System::EventHandler(this, &formSearch::MeaningTextBox_TextChanged);
			// 
			// SearchButton
			// 
			this->SearchButton->BackColor = System::Drawing::Color::RoyalBlue;
			this->SearchButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->SearchButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->SearchButton->Location = System::Drawing::Point(544, 794);
			this->SearchButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(368, 54);
			this->SearchButton->TabIndex = 3;
			this->SearchButton->Text = L"Search";
			this->SearchButton->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->SearchButton->UseVisualStyleBackColor = false;
			this->SearchButton->Click += gcnew System::EventHandler(this, &formSearch::SearchButton_Click);
			// 
			// suggestionbox
			// 
			this->suggestionbox->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->TopResults });
			this->suggestionbox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestionbox->HideSelection = false;
			listViewItem2->IndentCount = 10;
			this->suggestionbox->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem2 });
			this->suggestionbox->Location = System::Drawing::Point(1081, 329);
			this->suggestionbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->suggestionbox->MultiSelect = false;
			this->suggestionbox->Name = L"suggestionbox";
			this->suggestionbox->Size = System::Drawing::Size(220, 389);
			this->suggestionbox->TabIndex = 4;
			this->suggestionbox->UseCompatibleStateImageBehavior = false;
			this->suggestionbox->View = System::Windows::Forms::View::Details;
			this->suggestionbox->SelectedIndexChanged += gcnew System::EventHandler(this, &formSearch::suggestionbox_SelectedIndexChanged);
			// 
			// TopResults
			// 
			this->TopResults->Width = 120;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1118, 286);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Suggestions\r\n";
			// 
			// related
			// 
			this->related->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->RelatedWords });
			this->related->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->related->HideSelection = false;
			this->related->Location = System::Drawing::Point(129, 426);
			this->related->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->related->MultiSelect = false;
			this->related->Name = L"related";
			this->related->Size = System::Drawing::Size(399, 194);
			this->related->TabIndex = 6;
			this->related->UseCompatibleStateImageBehavior = false;
			this->related->View = System::Windows::Forms::View::Details;
			this->related->SelectedIndexChanged += gcnew System::EventHandler(this, &formSearch::related_SelectedIndexChanged);
			// 
			// RelatedWords
			// 
			this->RelatedWords->Width = 120;
			// 
			// formSearch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1944, 1104);
			this->ControlBox = false;
			this->Controls->Add(this->related);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->suggestionbox);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->MeaningTextBox);
			this->Controls->Add(this->wordTextBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"formSearch";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"formSearch";
			this->Load += gcnew System::EventHandler(this, &formSearch::formSearch_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void formSearch_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MeaningTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

public: System::Void wordTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	suggestionbox->Items->Clear();
	related->Items->Clear();
	System::String^ newText = wordTextBox->Text;
	if (newText->Length == 0) {
		return;
	}
	string word = msclr::interop::marshal_as<std::string>(newText);

	if (dictionary.contains(word)) {
		MeaningTextBox->Text = gcnew String(dictionary.getMeaning(word).c_str());
	}
	else {
		MeaningTextBox->Clear();
	}
	
	System::String^ newText2 = wordTextBox->Text;
	if (newText2->Length == 0) {
		return;
	}
	string word2 = msclr::interop::marshal_as<std::string>(newText2);
	List<string> suggestions = dictionary.keysWithPrefix(word2, 10);
	int count = 10;
	while (!suggestions.isEmpty() && count--) {
		System::String^ suggestion = gcnew String(suggestions.shift().c_str());
		ListViewItem^ item = gcnew ListViewItem(suggestion);
		suggestionbox->Items->Add(item);
	}
	// clearing the suggestions list
	suggestions.clear();

	System::String^ newText3 = wordTextBox->Text;
	if (newText3->Length == 0) {
		return;
	}
	string word3 = msclr::interop::marshal_as<std::string>(newText3);
	List<string> relatedWords = dictionary.longestPrefixOf(word3, 5);
	count = 5;
	while (!relatedWords.isEmpty() && count--) {
		System::String^ relatedWord = gcnew String(relatedWords.shift().c_str());
		ListViewItem^ item = gcnew ListViewItem(relatedWord);
		related->Items->Add(item);
	}
	// clearing the related words list	
	relatedWords.clear();

}
private: System::Void suggestionbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// getting user selection from suggestion box
	if (suggestionbox->SelectedItems->Count > 0) {
		wordTextBox->Text = suggestionbox->SelectedItems[0]->Text;
		MeaningTextBox->Text = gcnew String(dictionary.getMeaning(msclr::interop::marshal_as<string>(wordTextBox->Text)).c_str());
	}
}
private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ newText = wordTextBox->Text;
	string word = msclr::interop::marshal_as<std::string>(newText);
	if (!dictionary.contains(word)) {
		MessageBox::Show("Word not found");
	}
	
}
private: System::Void related_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (related->SelectedItems->Count > 0) {
		wordTextBox->Text = related->SelectedItems[0]->Text;
		MeaningTextBox->Text = gcnew String(dictionary.getMeaning(msclr::interop::marshal_as<string>(wordTextBox->Text)).c_str());
	}

}
};
}
