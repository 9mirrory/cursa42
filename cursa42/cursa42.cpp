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
	string FIO = "Поляков Иван Иванович";
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
void studentswap() {
	

}

void addStudent()
{
	int j = 0;
	Student* studentbuff = new Student[j];
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string buffer;
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
		students[i].FIO = istring();
		if (students[i].FIO.find(" ")) 
		{
			out  << students[i].FIO << ";";
		}

		cout << "\nВведите год рождения: ";
		students[i].birthYear = iint();
		if (students[i].birthYear > 1990 || students[i].birthYear <2006)
		{
			out << students[i].birthYear << ";";
		}
		
		cout << "\nВведите год поступления: ";
		students[i].startYear = iint();
		if (students[i].startYear > 2010 || students[i].startYear < 2023)
		{
			out << students[i].startYear << ";";
		}

		cout << "\nВведите название направления: ";
		students[i].faculty = istring();
		out << students[i].faculty << ";";

		cout << "\nВведите название института (сокращенно): ";
		students[i].inst = istring();
		out << students[i].inst << ";";

		cout << "\nВведите название группы: ";
		students[i].group = istring();
		out << students[i].group << ";";

		cout << "\nВведите номер зачетной книжки: ";
		students[i].booknum = istring();
		out << students[i].booknum << ";";

		cout << "\nВведите пол \n(мужской - 1 , женский - 0) : ";
		cin >> students[i].sex;
		out << students[i].sex << ";";
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
				out << ",";
			};
		}
		out << "];[";
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
				out << ",";
			};
		}
		out << "];";
		out << students[i].c << "\n";
		cin.clear();
		out.close();
	}
	delete[] students;
	cout << "Готово. Нажмите ENTER, чтобы вернуться в главное меню";
	getchar();
	getchar();
	int main();
}

void exercise() 
{
	string group1; 
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i = 0, j = 0, n = 50;
	string line, s = ";", str, sem1, sem2, c;
	size_t comma1, comma2, comma3, comma4, comma5, comma6, comma7, comma8, comma9, comma10;
	Student *student = new Student[n];
	ifstream ifs;
	ifs.open("textFile.txt");
	cout << "Введите название группы, чтобы просмотреть студентов: ";
	cin >> group1;
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			comma1 = line.find(s);
			comma2 = comma1 + 5;
			comma3 = comma2 + 5;
			comma4 = line.find(s, comma3 + 1);
			comma5 = line.find(s, comma4 + 1);
			comma6 = line.find(s, comma5 + 1);
			comma7 = line.find(s, comma6 + 1);
			comma8 = line.find(s, comma7 + 1);
			comma9 = line.find(s, comma8 + 1);
			comma10 = line.find(s, comma9 + 1);
			student[i].FIO = line.substr(0, comma1);
			student[i].birthYear = stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
			student[i].startYear = stoi(line.substr(comma2 + 1, comma3 - comma2 - 1));
			student[i].faculty = line.substr(comma3 + 1, comma4 - comma3 - 1);
			student[i].inst = line.substr(comma4 + 1, comma5 - comma4 - 1);
			student[i].group = line.substr(comma5 + 1, comma6-comma5-1);
			student[i].booknum = line.substr(comma6 + 1, comma7-comma6-1);
			student[i].sex = stoi(line.substr(comma7 + 1, comma8-comma7-1));
			sem1 = line.substr(comma8 + 1, comma9-comma8-1);
			sem2 = line.substr(comma9 + 1, comma10-comma9-1);
			c = line.substr(comma10 + 1, line.length());
			cout << "\nСтудент:\n-->" << student[i].FIO << "\nДата рождения:\n-->" << student[i].birthYear 
				<< "\nГод поступления:\n-->" << student[i].startYear << "\nНаправление:\n-->" << student[i].faculty
				<< "\nИнститут:\n-->" << student[i].inst << "\nНомер зачетной книжки:\n-->"  << student[i].booknum 
				<< "\nПол:\n-->" << student[i].sex << "\nОценки за первый семестр:\n" << sem1
				<< "\nОценки за второй семестр:\n" << sem2 << "\n";
			i++;
		}
	}
	ifs.close();
	cout << "Готово. Нажмите ENTER, чтобы вернуться в главное меню";
	getchar();
	getchar();
	int main();
}

void printall()
{
	system("cls");
	cout << "===================================" << endl;
	cout << "| ДАННЫЕ ОБ УЧЕНИКАХ              |" << endl;
	cout << "===================================" << endl;
	string line;
	ifstream in("textFile.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	cout << "\n";
	cout << "Готово. Нажмите ENTER, чтобы вернуться в главное меню";
	getchar();
	getchar();
	int main();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	cout << "Курсовая работа!\n";
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
		case 3:
			exercise();
		case 4:
			cout << "Выход из курсовой работы" << "\n";
			break;
		}
	}
}