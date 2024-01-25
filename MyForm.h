#pragma once
#include"formAbout.h"
#include"formSearch.h"
#include"formAdd.h"
#include"formDelete.h"
#include"formEdit.h"
namespace DictionaryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
		formAbout^ aboutform;
		formAdd^ addform;
		formEdit^ editform;
		formDelete^ deleteform;
		

		   formSearch^ searchform;
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ sidebar;

	protected:

	protected:

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::FlowLayoutPanel^ menuContainer;



	private: System::Windows::Forms::Button^ addWord;



	private: System::Windows::Forms::Timer^ sidebarTransition;

	private: System::Windows::Forms::Button^ Menu;
	private: System::Windows::Forms::Button^ search;
	private: System::Windows::Forms::Button^ deleteWord;
	private: System::Windows::Forms::Button^ About;
	private: System::Windows::Forms::Button^ editWord;




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		/// 
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->sidebar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Menu = (gcnew System::Windows::Forms::Button());
			this->menuContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->search = (gcnew System::Windows::Forms::Button());
			this->editWord = (gcnew System::Windows::Forms::Button());
			this->addWord = (gcnew System::Windows::Forms::Button());
			this->deleteWord = (gcnew System::Windows::Forms::Button());
			this->About = (gcnew System::Windows::Forms::Button());
			this->sidebarTransition = (gcnew System::Windows::Forms::Timer(this->components));
			this->sidebar->SuspendLayout();
			this->panel1->SuspendLayout();
			this->menuContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// sidebar
			// 
			this->sidebar->BackColor = System::Drawing::Color::RoyalBlue;
			this->sidebar->Controls->Add(this->panel1);
			this->sidebar->Controls->Add(this->menuContainer);
			this->sidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->sidebar->ForeColor = System::Drawing::Color::Cyan;
			this->sidebar->Location = System::Drawing::Point(0, 0);
			this->sidebar->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->sidebar->Name = L"sidebar";
			this->sidebar->Size = System::Drawing::Size(269, 1028);
			this->sidebar->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::RoyalBlue;
			this->panel1->Controls->Add(this->Menu);
			this->panel1->Location = System::Drawing::Point(3, 4);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(262, 175);
			this->panel1->TabIndex = 2;
			// 
			// Menu
			// 
			this->Menu->BackColor = System::Drawing::Color::RoyalBlue;
			this->Menu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Menu->Cursor = System::Windows::Forms::Cursors::SizeNWSE;
			this->Menu->Dock = System::Windows::Forms::DockStyle::Top;
			this->Menu->FlatAppearance->BorderSize = 0;
			this->Menu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Menu->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold));
			this->Menu->ForeColor = System::Drawing::SystemColors::Info;
			this->Menu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Menu.Image")));
			this->Menu->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Menu->Location = System::Drawing::Point(0, 0);
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(262, 68);
			this->Menu->TabIndex = 2;
			this->Menu->Text = L"Menu";
			this->Menu->UseVisualStyleBackColor = false;
			this->Menu->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// menuContainer
			// 
			this->menuContainer->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->menuContainer->BackColor = System::Drawing::Color::RoyalBlue;
			this->menuContainer->Controls->Add(this->search);
			this->menuContainer->Controls->Add(this->editWord);
			this->menuContainer->Controls->Add(this->addWord);
			this->menuContainer->Controls->Add(this->deleteWord);
			this->menuContainer->Controls->Add(this->About);
			this->menuContainer->Location = System::Drawing::Point(3, 187);
			this->menuContainer->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->menuContainer->Name = L"menuContainer";
			this->menuContainer->Size = System::Drawing::Size(270, 403);
			this->menuContainer->TabIndex = 1;
			this->menuContainer->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::menuContainer_Paint);
			// 
			// search
			// 
			this->search->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->search->BackColor = System::Drawing::Color::RoyalBlue;
			this->search->FlatAppearance->BorderSize = 0;
			this->search->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->search->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search->ForeColor = System::Drawing::SystemColors::Info;
			this->search->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"search.Image")));
			this->search->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->search->Location = System::Drawing::Point(3, 4);
			this->search->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(259, 71);
			this->search->TabIndex = 5;
			this->search->Text = L"   Search";
			this->search->UseVisualStyleBackColor = false;
			this->search->Click += gcnew System::EventHandler(this, &MyForm::search_Click);
			// 
			// editWord
			// 
			this->editWord->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->editWord->BackColor = System::Drawing::Color::RoyalBlue;
			this->editWord->FlatAppearance->BorderSize = 0;
			this->editWord->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editWord->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editWord->ForeColor = System::Drawing::SystemColors::Info;
			this->editWord->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"editWord.Image")));
			this->editWord->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->editWord->Location = System::Drawing::Point(3, 83);
			this->editWord->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->editWord->Name = L"editWord";
			this->editWord->Size = System::Drawing::Size(259, 71);
			this->editWord->TabIndex = 8;
			this->editWord->Text = L"   Edit Word";
			this->editWord->UseVisualStyleBackColor = false;
			this->editWord->Click += gcnew System::EventHandler(this, &MyForm::editWord_Click);
			// 
			// addWord
			// 
			this->addWord->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->addWord->BackColor = System::Drawing::Color::RoyalBlue;
			this->addWord->FlatAppearance->BorderSize = 0;
			this->addWord->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addWord->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addWord->ForeColor = System::Drawing::SystemColors::Info;
			this->addWord->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addWord.Image")));
			this->addWord->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->addWord->Location = System::Drawing::Point(3, 162);
			this->addWord->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->addWord->Name = L"addWord";
			this->addWord->Size = System::Drawing::Size(259, 71);
			this->addWord->TabIndex = 3;
			this->addWord->Text = L"   Add Word";
			this->addWord->UseVisualStyleBackColor = false;
			this->addWord->Click += gcnew System::EventHandler(this, &MyForm::addWord_Click);
			// 
			// deleteWord
			// 
			this->deleteWord->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->deleteWord->BackColor = System::Drawing::Color::RoyalBlue;
			this->deleteWord->FlatAppearance->BorderSize = 0;
			this->deleteWord->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteWord->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteWord->ForeColor = System::Drawing::SystemColors::Info;
			this->deleteWord->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deleteWord.Image")));
			this->deleteWord->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->deleteWord->Location = System::Drawing::Point(3, 241);
			this->deleteWord->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->deleteWord->Name = L"deleteWord";
			this->deleteWord->Size = System::Drawing::Size(259, 71);
			this->deleteWord->TabIndex = 7;
			this->deleteWord->Text = L"    Delete Word";
			this->deleteWord->UseVisualStyleBackColor = false;
			this->deleteWord->Click += gcnew System::EventHandler(this, &MyForm::deleteWord_Click);
			// 
			// About
			// 
			this->About->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->About->BackColor = System::Drawing::Color::RoyalBlue;
			this->About->FlatAppearance->BorderSize = 0;
			this->About->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->About->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->About->ForeColor = System::Drawing::SystemColors::Info;
			this->About->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"About.Image")));
			this->About->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->About->Location = System::Drawing::Point(3, 320);
			this->About->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(259, 71);
			this->About->TabIndex = 6;
			this->About->Text = L"  About US";
			this->About->UseVisualStyleBackColor = false;
			this->About->Click += gcnew System::EventHandler(this, &MyForm::About_Click);
			// 
			// sidebarTransition
			// 
			this->sidebarTransition->Tick += gcnew System::EventHandler(this, &MyForm::sidebarTransition_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1900, 1028);
			this->Controls->Add(this->sidebar);
			this->Font = (gcnew System::Drawing::Font(L"Symbol", 8.25F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"YourDictionary";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->sidebar->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->menuContainer->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		bool menuExpand = false;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	/*private: System::Void menuTransition_Tick(System::Object^ sender, System::EventArgs^ e) {
	}*/
private: System::Void menuContainer_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void menuContainer1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	
}
	   bool sidebarExpand = true;
private: System::Void sidebarTransition_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (sidebarExpand)
	{
		sidebar->Width -= 18;
		if (sidebar->Width <= 80)
		{
			sidebarExpand = false;
			sidebarTransition->Stop();
			menuContainer->Width = sidebar->Width;
			/*search->Width = sidebar->Width;
			deleteWord->Width = sidebar->Width;
			About->Width = sidebar->Width;
			menuContainer->Width = sidebar->Width;*/
		}
	}
	else {

			sidebar->Width += 18;
			if (sidebar->Width >=269 )
			{
				sidebarExpand = true;
				sidebarTransition->Stop();
			}
		}
	menuContainer->Width = sidebar->Width;
	/*search->Width = sidebar->Width;
	deleteWord->Width = sidebar->Width;
	About->Width = sidebar->Width;
	menuContainer->Width = sidebar->Width;*/
		
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	sidebarTransition->Start();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addWord_Click(System::Object^ sender, System::EventArgs^ e) {
	if (addform == nullptr)
	{
		addform = gcnew formAdd();
		addform->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DictionaryProject::MyForm::OnFormClosed);
		addform->MdiParent = this;
		addform->Show();
	}
	else {
		addform->Activate();
	}
}
private: System::Void About_Click(System::Object^ sender, System::EventArgs^ e) {

	if (aboutform == nullptr)
	{
		aboutform = gcnew formAbout();
		aboutform->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DictionaryProject::MyForm::OnFormClosed);
		aboutform->MdiParent = this;
		aboutform->Show();
	}
	else {
		aboutform->Activate();
	}
}
private: System::Void deleteWord_Click(System::Object^ sender, System::EventArgs^ e) {
	if (deleteform == nullptr)
	{
		deleteform = gcnew formDelete();
		deleteform->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DictionaryProject::MyForm::OnFormClosed);
		deleteform->MdiParent = this;
		deleteform->Show();
	}
	else {
		deleteform->Activate();
	}
}
private: System::Void search_Click(System::Object^ sender, System::EventArgs^ e) {
	//formSearch^ searchform = gcnew formSearch;
	if (searchform == nullptr)
	{
		searchform = gcnew formSearch();
		searchform->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DictionaryProject::MyForm::OnFormClosed);
		searchform->MdiParent = this;
		searchform->Show();
	}
	else { searchform->Activate(); }
}
	   void OnFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		   searchform = nullptr;
		   editform = nullptr;
		   aboutform = nullptr;
		   aboutform = nullptr;
		   deleteform = nullptr;
	   }
private: System::Void editWord_Click(System::Object^ sender, System::EventArgs^ e) {
	if (editform == nullptr)
	{
		editform = gcnew formEdit();
		editform->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DictionaryProject::MyForm::OnFormClosed);
		editform->MdiParent = this;
		editform->Show();

	}
	else {
		editform->Activate();
	}
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	/*Button^ exitButton = gcnew Button();
	exitButton->Text = "Exit";
	exitButton->Click += gcnew EventHandler(this, &MyForm::button);*/

	Application::Exit();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}


};
}


