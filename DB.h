#pragma once
using namespace std;
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;


ref class DB
{
private: 
	String^ connString;
	MySqlConnection^ conn;
public:
	DB();
	DataTable^ getData();
	void abrirConexion();
	void cerrarConexion();
	void insertarEstudiante(String^ nombre, int edad, String^ carrera);
	void editarEstudiante(int id, String^ nombre, int edad, String^ carrera);
	void eliminarEstudiante(int id);



};

