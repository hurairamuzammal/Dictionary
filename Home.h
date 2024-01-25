#pragma once
#include"MyForm.h"
#include"loading.h"
#include "Dictionary.hpp"
#include<list>
namespace DictionaryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
		loading^ form;
	public:
		Home(void)
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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ loadMain;
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
			System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->loadMain = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			flowLayoutPanel1->BackColor = System::Drawing::Color::RoyalBlue;
			flowLayoutPanel1->ForeColor = System::Drawing::Color::Chocolate;
			flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			flowLayoutPanel1->Name = L"flowLayoutPanel1";
			flowLayoutPanel1->Size = System::Drawing::Size(982, 121);
			flowLayoutPanel1->TabIndex = 2;
			flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Home::flowLayoutPanel1_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rage Italic", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label2->Location = System::Drawing::Point(376, 555);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(305, 31);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Huraira, Shayan and Abdullah";
			this->label2->Click += gcnew System::EventHandler(this, &Home::label2_Click);
			// 
			// loadMain
			// 
			this->loadMain->BackColor = System::Drawing::Color::RoyalBlue;
			this->loadMain->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->loadMain->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadMain->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->loadMain->Location = System::Drawing::Point(397, 417);
			this->loadMain->Name = L"loadMain";
			this->loadMain->Size = System::Drawing::Size(214, 48);
			this->loadMain->TabIndex = 6;
			this->loadMain->Text = L"Load   YourDicionary";
			this->loadMain->UseVisualStyleBackColor = false;
			this->loadMain->Click += gcnew System::EventHandler(this, &Home::loadMain_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(57, 242);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(970, 140);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rage Italic", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::RoyalBlue;
			this->label1->Location = System::Drawing::Point(400, 524);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 31);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Developed with  ❤ by";
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(980, 598);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->loadMain);
			this->Controls->Add(this->label2);
			this->Controls->Add(flowLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1000, 650);
			this->Name = L"Home";
			this->RightToLeftLayout = true;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"YourDicrtionary";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Home_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}


private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void loadMain_Click(System::Object^ sender, System::EventArgs^ e) {
		

	loading^ loadingform = gcnew loading;

	// Show the next form

	Dictionary& dictionary = Dictionary::getInstance();

	if (dictionary.loadDictionary("dictionary.txt") == false) {
		MessageBox::Show("Error loading dictionary file");
	}

	loadingform->Show();

	loadingform->StartLoadingAnimation();

	// Optionally, hide the current form
	this->Hide();


}
};
}
