#pragma 
#include"MyForm.h"

namespace DictionaryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for loading
	/// </summary>
	public ref class loading : public System::Windows::Forms::Form
	{
	public: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start(); // Start the timer on form load
	}

		   void StartLoadingAnimation()
		   {
			   // Your loading animation logic, for example, starting a timer
			   timer1->Start();
		   }
		   System::Windows::Forms::Timer^ timer1;
		   int animationDuration; // Duration of the loading animation in milliseconds

		   // Method to initialize the loading animation
		   void InitializeLoadingAnimation()
		   {
			   timer1 = gcnew System::Windows::Forms::Timer();
			   animationDuration = 1000; // Set the animation duration to 3 seconds

			   // Set up the timer properties
			   timer1->Interval = animationDuration;
			   timer1->Tick += gcnew System::EventHandler(this, &loading::timer1_Tick);
			   // Set ForeColor of ProgressBar to green
			   progressBar1->ForeColor = System::Drawing::Color::Green;

			   // Set MarqueeAnimationSpeed for visual appeal
			   progressBar1->MarqueeAnimationSpeed = 50;

			   // Set the Style property to Marquee
			   progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
		   }

	public:
		loading(void)
		{
			InitializeComponent();
			InitializeLoadingAnimation();	
			//
			//TODO: Add the constructor code here
			//
		}


		   // Event handler for the timer tick event
		   System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
		   {
			   timer1->Stop(); // Stop the timer when the animation duration is reached
			   MyForm^ form = gcnew MyForm;
			   form->Show();
			   
			   // Optionally, perform any other actions or navigate to the next form
			   this->Close(); // Close the loading form (or navigate to the next form)
		   }
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~loading()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(85, 56);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Loading...";
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::Lime;
			this->progressBar1->Location = System::Drawing::Point(88, 87);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(207, 23);
			this->progressBar1->TabIndex = 1;
			this->progressBar1->Click += gcnew System::EventHandler(this, &loading::progressBar1_Click);
			// 
			// loading
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 157);
			this->ControlBox = false;
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"loading";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Loading";
			this->Load += gcnew System::EventHandler(this, &loading::loading_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void loading_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
