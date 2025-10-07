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
