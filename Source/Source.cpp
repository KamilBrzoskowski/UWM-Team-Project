#include "login.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Serwis2017::login form;
	Application::Run(%form);

	return 0;
}