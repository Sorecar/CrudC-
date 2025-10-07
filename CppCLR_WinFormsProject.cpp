#include "pch.h"
#include "ConexionBD.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
	ConexionBD con = ConexionBD();
	con.conectar();
	if (con.getConexion()) {
		MessageBox::Show("Conexion Exitosa");
	}
	else {
		MessageBox::Show("Error en la Conexion");
	}
	con.desconectar();

  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::Form1());
  return 0;
}