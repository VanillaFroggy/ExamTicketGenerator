#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "Questions.cpp"
using namespace std;

void read_file(string path, string resultPath, int questionNum, int count) {
	ifstream fin;
	fstream fs;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "Wrong opening of the file!" << endl;
	}
	else {
		string number;
		char search[4];
		number = questionNum + '0';
		number = number + ". ";
		while (!fin.eof()) {
			string tempstr;
			fin >> search;
			string searchStr = search;
			searchStr += " ";
			if (number == searchStr) {
				fs.open(resultPath, fstream::out | fstream::app);
				if (!fs.is_open()) {
					cout << "Wrong opening of the file!" << endl;
				}
				else {
					vector<string> vec;
					getline(fin, tempstr);
					vec.push_back(tempstr);
					fs << vec[0];
					fs << '\n';
				}
				break;
			}
		}
		fs.close();
	}
	fin.close();
}

inline void generateBilet() {
	setlocale(LC_ALL, "");
	string path, resultPath;
	int num = 0;
	while ((int)(num) <= 0) {
		cout << "Выберете дисциплину, по которой нужно сгенерировать билет" << endl;
		cout << "1. Математика" << endl;
		cout << "2. Социология" << endl;
		cout << "3. Биология" << endl;
		cin >> num;
	}
	switch (num) {
	case 1:
		path = "Math\\";
		break;
	case 2:
		path = "Sociology\\";
		break;
	case 3:
		path = "Biology\\";
		break;
	default:
		break;
	}

	int count, questionNum;
	if (num == 1)
		count = 3;
	else
		count = 2;

	resultPath = path;
	if (path == "Math\\")
		resultPath += "4.txt";
	else
		resultPath += "3.txt";

	string indexPath = path + "indices_1.txt";
	fstream fin;
	fin.open(indexPath, fstream::in | fstream::out | fstream::app);
	if (!fin.is_open()) {
		cout << "Wrong opening of the file!" << endl;
	}
	else {
		bool isOriginal = false;
		int value;
		questionNum = rand() % 11;
		while (!fin.eof() || !isOriginal) {
			fin >> value;
			if (value == questionNum) {
				questionNum = rand() % 11;
				isOriginal = false;
				continue;
			}
			else if (value != questionNum && !fin.eof())
				isOriginal = true;
			else if (fin.eof() && isOriginal) {
				fin << questionNum << '\n';
				break;
			}
			else if (fin.eof() && !isOriginal) {
				fin.clear();
				fin << questionNum << '\n';
				break;
			}
		}
	}
	string* result;
	result = getQuestion(num, questionNum, count);
	fstream fs;
	fs.open(resultPath, fstream::out);
	if (!fs.is_open()) {
		cout << "Wrong opening of the file!" << endl;
	}
	else {
		for (int i = 0; i < count; i++)
			fs << result[i] << '\n';
	}
	fs.close();

	ifstream flin;
	flin.open(resultPath);
	if (!flin.is_open()) {
		cout << "Wrong opening of the file!" << endl;
	}
	else {
		cout << endl;
		while (!flin.eof()) {
			for (int i = 1; i <= count; i++) {
				if (flin.eof())
					break;
				cout << i << ". ";
				string str;
				getline(flin, str);
				cout << str << endl;
			}
			break;
		}
	}
	flin.close();
}

void createBilet() {
	int count;
	setlocale(LC_ALL, "");
	string str, path, result_path, sec_res_path;
	int num = 0;
	while ((int)(num) <= 0) {
		cout << "Выберете дисциплину, по которой нужно сгенерировать билет" << endl;
		cout << "1. Математика" << endl;
		cout << "2. Социология" << endl;
		cout << "3. Биология" << endl;
		cin >> num;
	}
	switch (num) {
	case 1:
		path = "Math\\";
		break;
	case 2:
		path = "Sociology\\";
		break;
	case 3:
		path = "Biology\\";
		break;
	default:
		break;
	}
	if (num == 1) {
		result_path = "C:\\Users\\Vano\\source\\repos\\My labs\\My labs\\" + path + "4.txt";
		count = 3;
	}
	else {
		result_path = "C:\\Users\\Vano\\source\\repos\\My labs\\My labs\\" + path + "3.txt";
		count = 2;
	}

	ifstream header;
	header.open(R"(C:\Users\Vano\source\repos\My labs\header.docx)");
	if (!header.is_open()) {
		cout << "Wrong opening of the file!" << endl;
	}
	else {
		ifstream footer;
		footer.open(R"(C:\Users\Vano\source\repos\My labs\footer.docx)");
		if (!footer.is_open()) {
			cout << "Wrong opening of the file!" << endl;
		}
		else {
			ifstream result;
			result.open(result_path);
			if (!result.is_open()) {
				cout << "Wrong opening of the file!" << endl;
			}
			else {
				fstream fout;
				fout.open(R"(C:\Users\Vano\source\repos\My labs\bilet.docx)", std::ios_base::app);
				if (!fout.is_open()) {
					cout << "Wrong opening of the file!" << endl;
				}
				else {
					fstream sec_res;
					sec_res.open(R"(C:\Users\Vano\source\repos\My labs\result.docx)", std::ios_base::app);
					if (!sec_res.is_open()) {
						cout << "Wrong opening of the file!" << endl;
					}
					else {
						string* arr = new string[count];
						//do {
							for (int i = 0; i < count; i++) {
								getline(result, arr[i]);
							}
							/*if (result.eof())
								break;*/
							/*getline(result, str);
							sec_res << str;*/
						//} while (result);
						do {
							getline(header, str);
							fout << str << endl;
						} while (header);
						//do {
							//for (int i = 0; i <= count; i++) {
							//	fout << i << ". ";
							//	//getline(sec_res, str);
							//	fout << arr[i] << endl;
							//}
						//} while (sec_res);
						do {
							getline(footer, str);
							fout << str << endl;
						} while (footer);
						header.close();
						result.close();
						footer.close();
						fout.close();
						cout << "Готовый билет лежит в папке University на рабочем столе" << endl;
					}
				}
			}
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color f0");
	while (1) {
		int num;
		string str;
		cout << "Введите число, чтобы выбрать, что вы хотите сделать." << endl;
		cout << "1. Сгенерировать экзаменационный билет" << endl;
		cout << "2. Создать экзаменационный билет" << endl;
		cout << "3. Чтобы выйти из программы" << endl;
		cin >> num;
		switch (num) {
		case 1:
			generateBilet();
			cout << endl;
			break;
		case 2:
			createBilet();
			cout << endl;
			break;
		case 3:
			return 0;
		}
	}
}