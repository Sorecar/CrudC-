#include "pch.h"
#include "DB.h"

DB::DB() {
	this->connString = "server=localhost;user=root;password=1234;database=db_sorecar;";
	this->conn = gcnew MySqlConnection(this->connString);
}

void DB::abrirConexion() {
	try {
		this->conn->Open();
	}
	catch (MySqlException^ ex) {
		Console::WriteLine("Error: {0}", ex->Message);
	}
}

void DB::cerrarConexion() {
	try {
		this->conn->Close();
	}
	catch (MySqlException^ ex) {
		Console::WriteLine("Error: {0}", ex->Message);
	}
}

DataTable^ DB::getData() {
	DataTable^ dt = gcnew DataTable();
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM estudiantes", this->conn);
		MySqlDataAdapter^ data = gcnew MySqlDataAdapter(cmd);
		DataTable^ tabla = gcnew DataTable();
		data->Fill(tabla);
		return tabla;
	}
	catch (MySqlException^ ex) {
		Console::WriteLine("Error: {0}", ex->Message);
	}
	return dt;
}

void DB::insertarEstudiante(String^ nombre, int edad, String^ carrera) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO estudiantes (nombre, edad, carrera) VALUES (@nombre, @edad, @carrera)", this->conn);
		cmd->Parameters->AddWithValue("@nombre", nombre);
		cmd->Parameters->AddWithValue("@edad", edad);
		cmd->Parameters->AddWithValue("@carrera", carrera);
		cmd->ExecuteNonQuery();
	}
	catch (MySqlException^ ex) {
		Console::WriteLine("Error: {0}", ex->Message);
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		MessageBox::Show("Error al insertar el estudiante: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

void DB::editarEstudiante(int id, String^ nombre, int edad, String^ carrera) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE estudiantes SET nombre = @nombre, edad = @edad, carrera = @carrera WHERE id_estudiante = @id", this->conn);
		cmd->Parameters->AddWithValue("@id", id);
		cmd->Parameters->AddWithValue("@nombre", nombre);
		cmd->Parameters->AddWithValue("@edad", edad);
		cmd->Parameters->AddWithValue("@carrera", carrera);
		cmd->ExecuteNonQuery();
	}
	catch (MySqlException^ ex) {
		Console::WriteLine("Error: {0}", ex->Message);
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		MessageBox::Show("Error al editar el estudiante: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

void DB::eliminarEstudiante(int id) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM estudiantes WHERE id_estudiante = @id", this->conn);
		cmd->Parameters->AddWithValue("@id", id);
		cmd->ExecuteNonQuery();
	}
	catch (MySqlException^ ex) {
		Console::WriteLine("Error: {0}", ex->Message);
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		MessageBox::Show("Error al eliminar el estudiante: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
