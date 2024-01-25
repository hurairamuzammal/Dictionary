#include "Home.h"
#include<list>
// including the header file for the dictionary
#include "Dictionary.hpp"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main()
{
	
	// 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DictionaryProject::Home form;
	Application::Run(% form);
	//

	

}