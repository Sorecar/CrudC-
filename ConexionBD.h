#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class ConexionBD
{
private:
	MYSQL* conn;
public:
	ConexionBD()
	{
		conn = mysql_init(0);
	}
	void conectar()
	{
		conn = mysql_real_connect(conn, "localhost", "root", "1234", "db_sorecar", 3306, NULL, 0);
	}
	MYSQL* getConexion()
	{
		return conn;
	}
	void desconectar()
	{
		mysql_close(conn);
	}

};

