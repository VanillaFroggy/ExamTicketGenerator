#include "MyForm.h"
#include "Questions.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace System::IO;
using namespace System::Text;

CourseWork::MyForm::MyForm(void) {
	InitializeComponent();
}

System::Void CourseWork::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	CbDisciplineSelection->SelectedIndex = 0;
}

int get_original_num(int* arr, int& size);

inline System::Void CourseWork::MyForm::BtnGenerate_Click(System::Object^ sender, System::EventArgs^ e) {
	Encoding^ encoding = Encoding::GetEncoding(1251);
	string path, resultPath;
	String^ str_path; String^ result_path;
	switch (CbDisciplineSelection->SelectedIndex) {
	case 1:
		path = "Math\\";
		str_path = "Math\\";
		break;
	case 2:
		path = "Sociology\\";
		str_path = "Sociology\\";
		break;
	case 3:
		path = "Biology\\";
		str_path = "Biology\\";
		break;
	default:
		break;
	}

	int count, question_num;
	if (CbDisciplineSelection->SelectedIndex == 1)
		count = 3;
	else
		count = 2;

	result_path = str_path;
	resultPath = path;
	if (path == "Math\\") {
		resultPath += "4.txt";
		result_path += "4.txt";
	}
	else {
		resultPath += "3.txt";
		result_path += "3.txt";
	}

	string index_path = path + "indices_1.txt";
	int* arr_of_questions = new int[count];
	for (int i = 0; i < count; i++) {
		int size = 10, temp = 0;
		int* index_arr = new int[size];
		fstream fin;
		fin.open(index_path, fstream::in);
		if (!fin.is_open()) {
			TbOutputResult->Text = String::Format("Wrong opening of the file!");
		}
		else {
			while (!fin.eof()) {
				fin >> index_arr[temp];
				temp++;
			}
			size = temp;
		}
		fin.close();

		if (size >= 10) {
			fin.open(index_path, fstream::out | fstream::trunc);
			if (!fin.is_open()) {
				TbOutputResult->Text = String::Format("Wrong opening of the file!");
			}
			else {
				index_arr = nullptr;
				question_num = get_original_num(index_arr, size);
				fin << question_num << '\n';
				fin.close();
			}
		}
		else {
			fin.open(index_path, fstream::out | fstream::app);
			if (!fin.is_open()) {
				TbOutputResult->Text = String::Format("Wrong opening of the file!");
			}
			else {
				question_num = get_original_num(index_arr, size);
				delete[] index_arr;
				index_arr = nullptr;
				fin << question_num << '\n';
				fin.close();
			}
		}
		arr_of_questions[i] = question_num;
	}
	

	string* result;
	fstream fs;
	fs.open(resultPath, fstream::out);
	if (!fs.is_open()) {
		TbOutputResult->Text = String::Format("Wrong opening of the file!");
	}
	else {
		for (int i = 0; i < count; i++) {
			result = getQuestion(CbDisciplineSelection->SelectedIndex, arr_of_questions[i], count);
			int j = i + 1;
			fs << j << ". " << result[i] << '\n';
		}
	}
	fs.close();

	ifstream flin;
	flin.open(resultPath);
	if (!flin.is_open())
		TbOutputResult->Text = String::Format("Wrong opening of the file!");
	else
		TbOutputResult->Text = File::ReadAllText(result_path, encoding);
	flin.close();
}

int get_original_num(int* arr, int& size) {
	int question_num = rand() % 11;
	if (arr == nullptr) {
		if (question_num == 0)
			question_num = get_original_num(arr, size);
		else
			return question_num;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (arr[i] == question_num)
				question_num = get_original_num(arr, size);
			else if (question_num == 0)
				question_num = get_original_num(arr, size);
		}
		return question_num;
	}
}