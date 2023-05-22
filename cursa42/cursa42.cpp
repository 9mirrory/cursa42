#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

struct ExamsRecords {
	string name;
	int mark;
	// 0 - ne zachet  
	// 1 - zachet
	// 2,3,4,5 - octnki
	// 6 pole pustoe
};

struct Student 
{
	string FIO = "Иванов Иван Иванович";
	string faculty = "Информационная безопасность";
	int birthDay = 2;
	int birthMonth = 4;
	int birthYear = 2004;
	int startYear = 2023;
	bool sex;
	string group = "БББО-10-22";
	string booknum = "2034A69";
	string inst = "ИКБ";
	bool c;


};

int iint()
{
	int num;
	while (1) {
		cin >> num;
		/*
			fail() возвращает бит ошибки, при некорректном вводе(буква или др.)
			будет очищен поток cin, а также вывод в консоль о неправильном вводе
		*/
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Некорректный ввод числа!\nПопробуйте ещё раз:";
			continue;
		}
		return num;
	}
}

unsigned short imark()
{
	short mark;
	while (1) {
		mark = iint(); // ввод оценки
		if (mark < 1) mark = 1;
		else if (mark > 5) mark = 5;
		return mark;
	}
}

// ВАЛИДИРОВАННЫЙ ВВОД СТРОКИ
string istring()
{
	// ВВОД СТРОКИ, УЧИТЫВАЯ ПРОБЕЛЫ КАК СИМВОЛ, А НЕ КОНЕЦ СТРОКИ (ws - whitespace)
	string str;
	getline(cin >> ws, str);
	return str;
}

struct Date 
{
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
*/
void addStudent()
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "===================================" << endl;
	cout << "|  МЕНЮ ВВОДА ДАННЫХ ОБ УЧЕНИКАХ  |" << endl;
	cout << "===================================" << endl;
	cout << "Введите кол-во студентов: ";
	cin >> n;
	cin.get();
	Student* students = new Student[n];
	for (int i = 0; i < n; i++) 
	{
		students[i].c = FALSE;
		ofstream out;
		out.open("textFile.txt", std::ios_base::app);
		cout << "Введите данные ученика \n" << i + 1 << "." << endl;
		cout << "Введите ФИО: ";
		if (students[i].FIO.find(" "))
		students[i].FIO = istring();
		if (students[i].FIO.find(" ")) 
		{
			out << i + 1 << "." << students[i].FIO << endl;
		}

		cout << "\nВведите год рождения: ";
		students[i].birthYear = iint();
		if (students[i].birthYear > 1990 || students[i].birthYear <2006)
		{
			out << students[i].birthYear << endl;
		}
		
		cout << "\nВведите год поступления: ";
		students[i].startYear = iint();
		if (students[i].startYear > 2010 || students[i].startYear < 2023)
		{
			out << students[i].startYear << endl;
		}

		cout << "\nВведите название направления: ";
		students[i].faculty = istring();
		out << students[i].faculty << endl;

		cout << "\nВведите название института (сокращенно): ";
		students[i].inst = istring();
		if (!students[i].faculty.find(" "))
		{
			out << students[i].faculty << endl;
		}

		cout << "\nВведите название группы: ";
		students[i].group = istring();
		out << students[i].group << endl;

		cout << "\nВведите номер зачетной книжки: ";
		students[i].booknum = istring();
		out << students[i].booknum << endl;

		cout << "\nВведите пол \n(мужской - 1 , женский - 0) : ";
		cin >> students[i].sex;
		int NumMarks1, NumMarks2;
		cout << "\nВвести кол-во предметов за 1 семестр: ";
		cin >> NumMarks1;
		if (NumMarks1 <= 10 || NumMarks1 >= 1) {

		}
		float marks3_1 = 0, marks3_2 = 0;
		out << "[";
		for (int j = 0; j < NumMarks1; j++) 
		{
			string subject;
			int mark;
			cout << "Введите название предмета: ";
			subject = istring();
			cout << "\nВвести оценку за 1 семестр: ";
			mark = imark();
			if (mark == 3) {
				students[i].c = TRUE;
			};
			out << subject << "-" << mark;
			if (j != NumMarks1 - 1)
			{
				out << ", ";
			};
		}
		out << "]\n[";
		students[i].c = marks3_1;
		cout << "Ввести кол-во предметов за 2 семестр: ";
		cin >> NumMarks2;
		for (int j = 0; j < NumMarks2; j++) {
			string subject;
			int mark;
			cout << "Введите название предмета: ";
			subject = istring();
			cout << "Ввести оценку за 2 семестр: ";
			mark = imark();
			if (mark == 3) 
			{
				students[i].c = TRUE;
			};
			out << subject << "-" << mark;
			if (j != NumMarks2 - 1)
			{
				out << ", ";
			};
		}
		out << "]\n";
		out << students[i].c << "\n" << endl;
		cin.clear();
		out.close();
	}
	cout << "Готово. Нажмите ENTER, чтобы вернуться в главное меню";
	getchar();
	getchar();
	int main();
}

void printall()
{
	system("cls");
	cout << "===================================" << endl;
	cout << "| ДАННЫЕ ОБ УЧЕНИКАХ  |" << endl;
	cout << "===================================" << endl;
	string line;
	std::ifstream in("textFile.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	cout << "Готово. Нажмите ENTER, чтобы вернуться в главное меню";
	getchar();
	getchar();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	std::cout << "Курсовая работа!\n";
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
			printall();
		case 4:
			cout << "Выход из курсовой работы" << "\n";
			break;
		}
	}
}