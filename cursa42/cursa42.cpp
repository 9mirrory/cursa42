#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

struct Student 
{
	string FIO;
	string faculty;
	int birthDay;
	int birthMonth;
	int birthYear;
	int startYear;
	string sex;
	string group;
	string booknum;
	string inst;
	int c;
	string sess[9];
};

int iint()
{
	int num;
	while (1) 
	{
		cin >> num;
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Некорректный ввод числа!\nПопробуйте ещё раз:";
			continue;
		}
		return num;
	}
}

int iyear() {
	int year;
	while (1) {
		year = iint();
		if (year < 1990 || year > 2023) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Некорректный ввод года! \nВведите число от  1990 до 2023: ";
			continue;
		}
		return year;
	}
}
int imonth() {
	int month;
	while (1)
	{	
		month = iint();
		if (month < 1 && month > 12)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Некорректный ввод месяца!\nВведите число от 1 до 12: ";
			continue;
		}
		return month;
	}
}

int iday(int month) 
{
	int day;
	while (1) {
		day = iint();
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month ==10 || month == 12)
		{
			if (day < 1 || day >31)
			{
				cin.clear();
				cin.ignore(100,'\n');
				cout << "Некорректный ввод дня!\n Введите число от 1 до 31: ";
				continue;

			}			
		}
		if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day >30)
			{
				cin.clear();
				cin.ignore();
				cout << "Некорректный ввод дня!\nВведите число от 1 до 30: ";
				continue;
			}
		}
		return day;
	}
}

unsigned short imark()
{
	short mark;
	while (1) 
	{
		mark = iint(); // ввод оценки
		if (mark < 1) mark = 1;
		else if (mark > 5) mark = 5;
		return mark;
	}
}

string istring()
{
	string str;
	getline(cin >> ws, str);
	return str;
}

void addStudent()
{
	int j = 0, NumMarks, sesscount;
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
		students[i].birthYear = iyear();
		
		cout << "Введите месяц рождения: ";
		students[i].birthMonth = imonth();

		cout << "Введите день рождения: ";
		students[i].birthDay = iday(students[i].birthMonth);
		out << students[i].birthDay << "." << students[i].birthMonth << "." << students[i].birthYear << ";";

		cout << "\nВведите год поступления: ";
		students[i].startYear = iyear();

		cout << "\nВведите название кафедры: ";
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

		cout << "\nВведите пол \n(М, Ж) : ";
		students[i].sex = istring();

		cout << "\nВведите количество сессий ( до 9 ): ";
		sesscount = iint();
		if (sesscount > 9)
		{
			sesscount = 9;
		}

		for (int k = 0; k < sesscount; k++) 
		{
			string sess = "[", subj;
			int mark;
			cout << "\nВвести кол-во предметов за " << k+1 << " сессию: ";
			cin >> NumMarks;
			if (NumMarks > 10)
			{
				NumMarks = 10;
			}
			for (int k1 = 0; k1 < NumMarks; k1++) 
			{
				cout << "\nВведите название предмета" << k1+1 << ": ";
				subj = istring();
				cout << "\nВведите оценку за предмет" << subj << ": ";
				mark = imark();
				if (mark <= 3) 
				{
					students[i].c = TRUE;
				}
				sess = sess + subj + "-" + to_string(mark) + ",";
			}
			sess = sess + "];";
			out << sess; 
		}
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
	int c, i = 0, i2 = 0, j = 0, j1 = 0, n = 50, k = 0, i1 = 0, k1 = 0, semicolonCount, min = 2022, max = 0;
	string line, s = ";", str, sem1, sem2;
	size_t comma1, comma2, comma3, comma4, comma5, comma6, comma7, comma8, comma9, comma10, dot1, dot2;
	Student *student = new Student[n];
	ifstream ifs;
	ifs.open("textFile.txt");
	cout << "Введите название группы, чтобы просмотреть студентов: ";
	cin >> group1;
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			comma1 = 0;
			dot1 = 0;
			semicolonCount = 0;
			char ch = ';';
			semicolonCount = count(line.begin(), line.end(), ch);
			comma1 = line.find(s);
			dot1 = line.find(".", comma1 + 1);
			dot2 = line.find(".", dot1 + 1);
			comma2 = line.find(s, comma1 + 1);
			comma3 = line.find(s, comma2 + 1);
			comma4 = line.find(s, comma3 + 1);
			comma5 = line.find(s, comma4 + 1);
			comma6 = line.find(s, comma5 + 1);
			comma7 = line.find(s, comma6 + 1);
			comma8 = line.find(s, comma7 + 1);
			student[i].FIO = line.substr(0, comma1);
			student[i].birthDay = stoi(line.substr(comma1 + 1, dot1 - comma1 - 1));
			student[i].birthMonth = stoi(line.substr(dot1 + 1, dot2 - dot1 - 1));
			student[i].birthYear = stoi(line.substr(dot2 + 1, comma2 - dot2 - 1));
			student[i].startYear = stoi(line.substr(comma2 + 1, comma3 - comma2 - 1));
			student[i].faculty = line.substr(comma3 + 1, comma4 - comma3 - 1);
			student[i].inst = line.substr(comma4 + 1, comma5 - comma4 - 1);
			student[i].group = line.substr(comma5 + 1, comma6-comma5-1);
			student[i].booknum = line.substr(comma6 + 1, comma7-comma6-1);
			student[i].sex = line.substr(comma7 + 1, comma8-comma7-1);
			comma9 = line.find(s, comma8 + 1);
			comma10 = 0;
			for (int k1 = 0; k1 < (semicolonCount - 8); k1++)
			{
				comma9 = line.find(s, comma8 + 1);
				student[i].sess[k1] = line.substr(comma8 + 1, comma9 - comma8-1);
				comma8 = comma9;
			}
			if (student[i].birthYear << min)
			{
				min = student[i].birthYear;
			}
			if (student[i].birthYear > max)
			{
				max = student[i].birthYear;
			}
			student[i].c = stoi(line.substr(comma9 + 1, comma9 + 2));
			if (student[i].group == group1)
			{
				i++;
			}
			else continue;
		}
		i1 = i;
		while (i1--)
		{
			bool swapped = false;
			for (k = 0; k < i1; k++)
			{
				if (student[k].booknum > student[k + 1].booknum && student[k].c > student[k + 1].c)
				{
					swap(student[k], student[k + 1]);
					swapped = true;
				}
			}	
			if (swapped == false)
				break;
		}
		c = 0;
		cout << min << "-" << max;
		for (j = 0; j<i;j++)
		{
			if (j == 0)
			{	
				cout << "\n_______________________________\n";
				cout << "Студенты с оценками 4 и 5 :\n_______________________________\n";
			}
			cout << "\nСтудент:		    " << student[j].FIO << "\nНомер зачетной книжки:	    " << student[j].booknum
				<< "\nДата рождения:		    " << student[j].birthDay << "." << student[j].birthMonth << "." << student[j].birthYear
				<< "\nПол:		            " << student[j].sex
				<< "\nИнститут:		    " << student[j].inst << "\nНаправление:		    " << student[j].faculty
				<< "\nГод поступления:	    " << student[j].startYear;
			for (int k2 = 0; k2 < size(student[j].sess); k2++)
			{
				if (student[j].sess[k2] != "")
				{
					cout << "\nОценки за " << k2 + 1 << " сессию:\n               " << student[j].sess[k2];
				}
				else
				{
					continue;
				}
			}
			cout << "\n_______________________________\n";
			if (j != 0 && j != i-1)
			{
				if (student[j].c != student[j + 1].c) {
					cout << "Студенты с оценками 3 :\n_______________________________\n";
				}
			}

		}
	}
	delete[] student;
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
	cout << "|        ДАННЫЕ ОБ УЧЕНИКАХ       |" << endl;
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