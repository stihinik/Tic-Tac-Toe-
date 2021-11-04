#include"GameForm.h"

using namespace System;
using namespace System::Windows::Forms;


void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TicTacToe::GameForm form;
	Application::Run(% form);
}