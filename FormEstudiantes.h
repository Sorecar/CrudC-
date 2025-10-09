#pragma once
#include "DB.h"
#include "EditEstudiante.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
			this->db = gcnew DB();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ data_grid;
	protected:

	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ textEdad;
	private: System::Windows::Forms::TextBox^ textCarrera;
	protected:



	private: System::Windows::Forms::Button^ btn_Guardar;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: DB^ db = gcnew DB();
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btn_Eliminar;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->data_grid = (gcnew System::Windows::Forms::DataGridView());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->textEdad = (gcnew System::Windows::Forms::TextBox());
			this->textCarrera = (gcnew System::Windows::Forms::TextBox());
			this->btn_Guardar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btn_Eliminar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_grid))->BeginInit();
			this->SuspendLayout();
			// 
			// data_grid
			// 
			this->data_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->data_grid->Location = System::Drawing::Point(39, 52);
			this->data_grid->Name = L"data_grid";
			this->data_grid->ReadOnly = true;
			this->data_grid->RowHeadersVisible = false;
			this->data_grid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->data_grid->Size = System::Drawing::Size(395, 185);
			this->data_grid->TabIndex = 0;
			this->data_grid->DoubleClick += gcnew System::EventHandler(this, &Form1::data_grid_DoubleClick);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(489, 52);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(206, 20);
			this->txtNombre->TabIndex = 2;
			// 
			// textEdad
			// 
			this->textEdad->Location = System::Drawing::Point(489, 106);
			this->textEdad->Name = L"textEdad";
			this->textEdad->Size = System::Drawing::Size(206, 20);
			this->textEdad->TabIndex = 3;
			// 
			// textCarrera
			// 
			this->textCarrera->Location = System::Drawing::Point(489, 160);
			this->textCarrera->Name = L"textCarrera";
			this->textCarrera->Size = System::Drawing::Size(206, 20);
			this->textCarrera->TabIndex = 4;
			// 
			// btn_Guardar
			// 
			this->btn_Guardar->Location = System::Drawing::Point(516, 197);
			this->btn_Guardar->Name = L"btn_Guardar";
			this->btn_Guardar->Size = System::Drawing::Size(149, 23);
			this->btn_Guardar->TabIndex = 5;
			this->btn_Guardar->Text = L"Guardar";
			this->btn_Guardar->UseVisualStyleBackColor = true;
			this->btn_Guardar->Click += gcnew System::EventHandler(this, &Form1::btn_Guardar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(486, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Nombre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(486, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Edad";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(486, 144);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Carrera";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(207, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Estudiantes";
			// 
			// btnEditar
			// 
			this->btnEditar->Location = System::Drawing::Point(59, 267);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(176, 23);
			this->btnEditar->TabIndex = 10;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = true;
			this->btnEditar->Click += gcnew System::EventHandler(this, &Form1::btnEditar_Click);
			// 
			// btn_Eliminar
			// 
			this->btn_Eliminar->Location = System::Drawing::Point(276, 267);
			this->btn_Eliminar->Name = L"btn_Eliminar";
			this->btn_Eliminar->Size = System::Drawing::Size(158, 23);
			this->btn_Eliminar->TabIndex = 11;
			this->btn_Eliminar->Text = L"Eliminar";
			this->btn_Eliminar->UseVisualStyleBackColor = true;
			this->btn_Eliminar->Click += gcnew System::EventHandler(this, &Form1::btn_Eliminar_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(720, 323);
			this->Controls->Add(this->btn_Eliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_Guardar);
			this->Controls->Add(this->textCarrera);
			this->Controls->Add(this->textEdad);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->data_grid);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->consultarDatos();
	}
	public: void consultarDatos() {
		this->db->abrirConexion();
		this->data_grid->DataSource = this->db->getData();
		this->db->cerrarConexion();
	}
	private: System::Void btn_Guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->db->abrirConexion();
		String^ nombre = this->txtNombre->Text;
		int edad = Int32::Parse(this->textEdad->Text);
		String^ carrera = this->textCarrera->Text;
		this->db->insertarEstudiante(nombre, edad, carrera);
		this->db->cerrarConexion();
		this->consultarDatos();
		this->txtNombre->Text = "";
		this->textEdad->Text = "";
		this->textCarrera->Text = "";
	}
private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
	sendDatos();
	
}
private: System::Void btn_Eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ id = Convert::ToString(data_grid->SelectedRows[0]->Cells[0]->Value);
	this->db->abrirConexion();
	this->db->eliminarEstudiante(Int32::Parse(id));
	this->db->cerrarConexion();
	this->consultarDatos();
}
private: System::Void data_grid_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	sendDatos();
}

private: Void sendDatos() {
	String^ id = Convert::ToString(data_grid->SelectedRows[0]->Cells[0]->Value);
	String^ nombre = Convert::ToString(data_grid->SelectedRows[0]->Cells[1]->Value);
	String^ edad = Convert::ToString(data_grid->SelectedRows[0]->Cells[2]->Value);
	String^ carrera = Convert::ToString(data_grid->SelectedRows[0]->Cells[3]->Value);
	CRUD::EditEstudiante^ editForm = gcnew CRUD::EditEstudiante();
	editForm->sendDatos(id, nombre, edad, carrera);
	editForm->ShowDialog();
}
};
}
