#pragma once

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnGenerate;
	protected:



	protected:




	private: System::Windows::Forms::TextBox^ TbOutputResult;




	private: System::Windows::Forms::ComboBox^ CbDisciplineSelection;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BtnGenerate = (gcnew System::Windows::Forms::Button());
			this->TbOutputResult = (gcnew System::Windows::Forms::TextBox());
			this->CbDisciplineSelection = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// BtnGenerate
			// 
			this->BtnGenerate->Location = System::Drawing::Point(15, 46);
			this->BtnGenerate->Name = L"BtnGenerate";
			this->BtnGenerate->Size = System::Drawing::Size(273, 31);
			this->BtnGenerate->TabIndex = 0;
			this->BtnGenerate->Text = L"Сгенерировать билет";
			this->BtnGenerate->UseVisualStyleBackColor = true;
			this->BtnGenerate->Click += gcnew System::EventHandler(this, &MyForm::BtnGenerate_Click);
			// 
			// TbOutputResult
			// 
			this->TbOutputResult->Location = System::Drawing::Point(15, 83);
			this->TbOutputResult->Multiline = true;
			this->TbOutputResult->Name = L"TbOutputResult";
			this->TbOutputResult->ReadOnly = true;
			this->TbOutputResult->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->TbOutputResult->Size = System::Drawing::Size(637, 297);
			this->TbOutputResult->TabIndex = 5;
			// 
			// CbDisciplineSelection
			// 
			this->CbDisciplineSelection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CbDisciplineSelection->FormattingEnabled = true;
			this->CbDisciplineSelection->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Предмет", L"Математика", L"Социология",
					L"Биология"
			});
			this->CbDisciplineSelection->Location = System::Drawing::Point(15, 16);
			this->CbDisciplineSelection->Name = L"CbDisciplineSelection";
			this->CbDisciplineSelection->Size = System::Drawing::Size(273, 24);
			this->CbDisciplineSelection->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 392);
			this->Controls->Add(this->CbDisciplineSelection);
			this->Controls->Add(this->TbOutputResult);
			this->Controls->Add(this->BtnGenerate);
			this->Name = L"MyForm";
			this->Text = L"Генератор экзаменационных билетов";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnGenerate_Click(System::Object^ sender, System::EventArgs^ e);
};
}
