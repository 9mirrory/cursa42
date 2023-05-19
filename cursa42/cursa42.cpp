#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <system>
using namespace std;

struct ExamsRecords {
	string name;
	int mark;
	// 0 - ne zachet  
	// 1 - zachet
	// 2,3,4,5 - octnki
	// 6 pole pustoe
};

struct Student {
	string FIO = "Иванов Иван Иванович";
	
	int birthYear = 2004;
	float sem = 4.1;
	float sem1 = 4.1;
	float sem2 = 4.1;
};
/*
struct StudentNode1
{	
	
	string surname;
	string name;
	string middlename;
	string faculty;
	string inst;
	string group;
	string birthDateString;
	bool sex;
};
*/
struct Date {
	int day, month, year;

	void operator = (string date);

	string GetDate();
};
/*
void Date::operator=(string date)
{

	size_t dot = date.find(".");
	this->day = stoi(date.substr(0, dot));
	date.erase(0, dot + 1);
	dot = date.find(".");
	this->month = stoi(date.substr(0, dot));
	date.erase(0, dot + 1);
	this->year = stoi(date.substr(0, 4));
}

struct DATA
{
	string name, surname, patronimyc, faculty, department, group;
	bool sex;
	int admision_year, record_book;
	Date birth;
	vector <Session> sessions;

	string DataToString();
};

string DATA::DataToString()
{
	StudentNode s;
	string data;
	data = s.name + " " + s.surname + " " + +" " + birth.GetDate() + " " +
		to_string(admision_year) + " " + faculty + " " + department + " " + group + " " +
		to_string(record_book) + " " + (sex ? "ìóæ" : "æåí") + " ";
	for (auto cur : sessions) {
		data += cur.GetAllSub() + " ";
	}

	return data;
}
*/
void addStudent()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Ввести кол-во студентов: ";
	cin >> n;
	cin.get();
	Student* students = new Student[n];

	ofstream fout("textFile.txt"); // открытие файла

	for (int i = 0; i < n; i++) {
		cout << "Введите данные ученика \n" << i + 1 << ".";
		cout << "Ввести ФИО: ";
		getline(cin, students[i].FIO);
		fout << i + 1 << "." << students[i].FIO << endl;
		cout << "Ввести год рождения: ";
		cin >> students[i].birthYear;
		fout << students[i].birthYear << endl;
		int NumMarks1, NumMarks2;
		cout << "Ввести кол-во оценок за 1 семестр:";
		cin >> NumMarks1;
		float marks3_1 = 0, marks3_2 = 0;
		for (int j = 0; j < NumMarks1; j++) {
			int mark;
			cout << "Ввести оценку за 1 семестр: ";
			cin >> mark;
			if (4.0 > mark && mark >= 3.0) {
				marks3_1++;
			}
		}
		students[i].sem1 = marks3_1;
		cout << "Ввести кол-во оценок за 2 семестр: ";
		cin >> NumMarks2;
		for (int j = 0; j < NumMarks2; j++) {
			int mark;
			cout << "Ввести оценку за 2 семестр: ";
			cin >> mark;
			if (4.0 > mark && mark >= 3.0) {
				marks3_2++;
			}
		}
		students[i].sem2 = marks3_2;
		students[i].sem = ((students[i].sem1 + students[i].sem2) / (NumMarks1 + NumMarks2)) * 100;
		fout << students[i].sem << "%" << endl;
		cout << "--------------------------------------------\n";
		cin.get();
	}
	fout.close();

}
/*{
	string faculty;
	system("cls");
	StudentNode s;
	ofstream out;
	out.open("textFile.txt");
	cout << "================================================================\n";
	cout << "МЕНЮ ВВОДА ДАННЫХ УЧЕНИКА\n";
	cout << "================================================================\n\n";
	cout << "Введите фамилию: " << endl;
	cin >> s.surname;
	cout << "\nВведите имя:  " << endl;
	cin >> s.name;
	cout << "\nВведите отчество:  " << endl;
	cin >> s.middlename;
	cout << "\nВведите название направления:  " << endl;
	getline(cin, faculty);
	cout << "\nВведите название института:  " << endl;
	cin >> s.inst;
	cout << "\nВведите название группы:  " << endl;
	cin >> s.group;
	cout << "\nВведите дату рождения:  " << endl;
	cin >> s.birthDateString;
	if (out.is_open())
	{
		out << s.surname << " " << s.name << " " << s.middlename << " " << s.faculty << " " << s.inst << " " << s.group << " " << s.birthDateString << " " << "\n";
	}
	out.close();
	cout << "Done. Press ENTER to continue... ";
	getchar();
	getchar();
}*/

void studentsinfo() {

}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);

	std::cout << "Курсовая работа!\n";
	//menu
	int meniu = -1;
	while (meniu != 4)
	{
		system("cls");
		cout << " МЕНЮ:\n";
		cout << "  1.Ввод данных об студенте:\n";
		cout << "  2.Просмотр всех данных\n";
		cout << "  3.Показать информацию об ученике:\n";
		cout << "  4.Выход\n\n";
		cin >> meniu;
		switch (meniu) {
		case 1:
			addStudent();
		case 2:
			studentsinfo();
		default:
			cout << "Выход из курсовой работы" << "\n";
			break;
		}
	}
}