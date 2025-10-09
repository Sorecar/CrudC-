#pragma once
#include "DB.h"

namespace CRUD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class EditEstudiante : public Form
	{
	public:
		EditEstudiante(void)
		{
			InitializeComponent();
		}

	protected:
		int idEstudiante;
		~EditEstudiante()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txt_Nombre;
	private: System::Windows::Forms::TextBox^ txt_edad;
	private: System::Windows::Forms::TextBox^ txt_carrera;
	private: DB^ db = gcnew DB();

	protected:

	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btn_Guardar;
	private: System::Windows::Forms::Button^ btn_Cancelar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txt_Nombre = (gcnew System::Windows::Forms::TextBox());
			this->txt_edad = (gcnew System::Windows::Forms::TextBox());
			this->txt_carrera = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btn_Guardar = (gcnew System::Windows::Forms::Button());
			this->btn_Cancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txt_Nombre
			// 
			this->txt_Nombre->Location = System::Drawing::Point(123, 47);
			this->txt_Nombre->Name = L"txt_Nombre";
			this->txt_Nombre->Size = System::Drawing::Size(163, 20);
			this->txt_Nombre->TabIndex = 0;
			// 
			// txt_edad
			// 
			this->txt_edad->Location = System::Drawing::Point(123, 116);
			this->txt_edad->Name = L"txt_edad";
			this->txt_edad->Size = System::Drawing::Size(163, 20);
			this->txt_edad->TabIndex = 1;
			// 
			// txt_carrera
			// 
			this->txt_carrera->Location = System::Drawing::Point(123, 190);
			this->txt_carrera->Name = L"txt_carrera";
			this->txt_carrera->Size = System::Drawing::Size(163, 20);
			this->txt_carrera->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Nombre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 116);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Edad";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Carrera";
			// 
			// btn_Guardar
			// 
			this->btn_Guardar->Location = System::Drawing::Point(37, 251);
			this->btn_Guardar->Name = L"btn_Guardar";
			this->btn_Guardar->Size = System::Drawing::Size(75, 23);
			this->btn_Guardar->TabIndex = 6;
			this->btn_Guardar->Text = L"Guardar";
			this->btn_Guardar->UseVisualStyleBackColor = true;
			this->btn_Guardar->Click += gcnew System::EventHandler(this, &EditEstudiante::btn_Guardar_Click);
			// 
			// btn_Cancelar
			// 
			this->btn_Cancelar->Location = System::Drawing::Point(165, 251);
			this->btn_Cancelar->Name = L"btn_Cancelar";
			this->btn_Cancelar->Size = System::Drawing::Size(75, 23);
			this->btn_Cancelar->TabIndex = 7;
			this->btn_Cancelar->Text = L"Cancelar";
			this->btn_Cancelar->UseVisualStyleBackColor = true;
			this->btn_Cancelar->Click += gcnew System::EventHandler(this, &EditEstudiante::btn_Cancelar_Click);
			// 
			// EditEstudiante
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(325, 309);
			this->Controls->Add(this->btn_Cancelar);
			this->Controls->Add(this->btn_Guardar);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_carrera);
			this->Controls->Add(this->txt_edad);
			this->Controls->Add(this->txt_Nombre);
			this->Name = L"EditEstudiante";
			this->Text = L"Editar Estudiante";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btn_Guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nombre = this->txt_Nombre->Text;
		int edad = Int32::Parse(this->txt_edad->Text);
		String^ carrera = this->txt_carrera->Text;
		this->db->abrirConexion();
		this->db->editarEstudiante(this->idEstudiante, nombre, edad, carrera);
		this->db->cerrarConexion();
		this->Close();
	}

	private: System::Void btn_Cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	public: void sendDatos(int id, String^ nombre, String^ edad, String^ carrera) {
		this->txt_Nombre->Text = nombre;
		this->txt_edad->Text = edad;
		this->txt_carrera->Text = carrera;
	}
	
	public: void sendDatos(System::String^ id, System::String^ nombre, System::String^ edad, System::String^ carrera) {
		this->idEstudiante = Int32::Parse(id);
		this->txt_Nombre->Text = nombre;
		this->txt_edad->Text = edad;
		this->txt_carrera->Text = carrera;
		MessageBox::Show("ID Recibido: " + idEstudiante);
	}

};
}
