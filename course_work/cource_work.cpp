#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
	Student(string sn, string n, string mn, string gen, int a, string ph,
		string em, string ht, string spec, int c, string gr, string fos, vector<int> s);
	string name;
	string surname;
	string middle_name;
	string gender;
	int age;
	string phone;
	string email;
	string hometown;
	string specialty;
	int course;
	string group;
	string form_of_study;
	vector<int> score;
	float avg;
	int scholarship;

	void getAverageScore();
	void printAllInform();
	void printAllInform(bool b);
	void getSizeOfScholarship();
};

class Database {
public:
	// Database (vector <Student> db); - пока не нужно, все делаем по порядку.
	// Если не задавать конструктор - класс заполняется сам, конструктором по умолчанию .
	vector <Student> data; // вектор студентов массив значений со студентами data поле

	void writeToTheFile();
	void readFromTheFile();
};

Student::Student(string sn, string n, string mn, string gen, int a, string ph,
	string em, string ht, string spec, int c, string gr, string fos, vector<int> s) {
	surname = sn;
	name = n;
	middle_name = mn;
	gender = gen;
	age = a;
	phone = ph;
	email = em;
	hometown = ht;
	specialty = spec;
	course = c;
	group = gr;
	form_of_study = fos;
	score = s;

	getAverageScore();
	getSizeOfScholarship();
}

//Database::Database(vector<Student> db) {
//data = db;
//writeToTheFile();
//} - ты инициализируешь класс и.. СРАЗУ ПИШЕШЬ ЕГО В ФАЙЛ?! ЗАЧЕМ?!

void Database::writeToTheFile() { // функция записывающая данные о каждом студенте в файл
	ofstream out("database.txt"); // Тип файла не забываем!)
	if (!out) {
		cout << "can't open the file ;(" << endl;
	}
	for (int i = 0; i < data.size(); i++)
	{
		out << data[i].surname << "\t" << data[i].name << "\t" << data[i].middle_name << "\t"
			<< data[i].gender << "\t" << data[i].age << "\t" << data[i].phone << "\t"
			<< data[i].email << "\t" << data[i].hometown << "\t" << data[i].specialty << "\t"
			<< data[i].course << "\t" << data[i].group << "\t" << data[i].form_of_study << "\t" 
			<< endl;
		for (int j = 0; j < data[i].score.size(); j++)
		{
			out << data[i].score[j] << " ";
		}
		
	}
	out.close();
}

void Database::readFromTheFile() { // читает из файла и выводит данные о студентах в консоль
	ifstream in("database.txt");
	if (!in) {
		cout << "can't open the file ;(" << endl;
	}
	for (int i = 0; i < data.size(); i++){
		in >> data[i].surname >> data[i].name >> data[i].middle_name >>
			data[i].gender >> data[i].age >> data[i].phone >>
			data[i].email >> data[i].hometown >> data[i].specialty >>
			data[i].course >> data[i].group >> data[i].form_of_study;
	}
	in.close();
}

void Student::getAverageScore(){
	int sum = 0;
	for (int i = 0; i < score.size(); i++){
		sum = sum + score[i];
	}
	avg = float(sum) / score.size();
}

void Student::getSizeOfScholarship(){
	int counter_of_3 = 0;
	int counter_of_4 = 0;
	int counter_of_5 = 0;
	for (int i = 0; i < score.size(); i++){
		if (score[i] == 3)
			counter_of_3++;
		else if (score[i] == 4)
			counter_of_4++;
		else if (score[i] == 5)
			counter_of_5++;
	}
	if (counter_of_3 != 0)
		scholarship = 0;
	else if (counter_of_5 == score.size())
		scholarship = 3500;
	else if (counter_of_5 >= 1)
		scholarship = 2800;
	else if (counter_of_4 >= 1)
		scholarship = 2400;
}

void Student::printAllInform(){
	cout << surname << endl;
	cout << name << endl;
	cout << middle_name << endl;
	cout << gender << endl;
	cout << age << endl;
	cout << phone << endl;
	cout << email << endl;
	cout << hometown << endl;
	cout << specialty << endl;
	cout << course << endl;
	cout << group << endl;
	cout << form_of_study << endl;

	for (int i = 0; i < score.size(); i++){
		cout << score[i] << " ";
	}

	cout << endl;
	cout << avg << endl;
	cout << scholarship << endl;
}

void Student::printAllInform(bool b){
	if (b == 1){
		cout << name << endl;
		cout << surname << endl;
	}
	else if (b == 0)
	{
		cout << name << endl;
		cout << surname << endl;
		cout << phone << endl;
		cout << group << endl;
	}
}

int main() {

	Student Masha("Belova", "Mari", "Andreevna", "female", 18, "7547685",
		"masha@mail.ru", "Moscow", "Marketing", 1, "MK-01-2013", "e-learning", { 5, 5, 5, 5 });

	Student Lena("Petrova", "Lena", "Olegovna", "female", 20, "8454545",
		"lena@mail.ru", "Moscow", "Marketing", 2, "MK-01-2012", "full-time", { 3, 4, 5, 5, 4 });

	// ненжуный мусор в консольке!)
	/*Masha.printAllInform(); 
	cout << endl;
	Lena.printAllInform();
	cout << endl;

	Masha.printAllInform(0);
	cout << endl;
	Lena.printAllInform(1);
	cout << endl;  */ 

	// У нас есть маша и лена, они обе типа Student, верно? Есть два человека, поэтому можно созщдавать базу данных:
	Database db; // пустой объект. создали базу, она абсолютно пустая.
	// обратимся к полю базы, которое хранит вектор из Student: db.data. - это у нас что? вектор! значит в это поле мы можем добавить студента? так? Добавляем!
	db.data.push_back(Masha);
	db.data.push_back(Lena);

	db.writeToTheFile(); 

	db.readFromTheFile();
	
	// теперь в базе маша с леной!!! проверь в дебаггере!
	// далее, когда у тебя есть база, ты можешь ее записать в файл. Для этого надо вызывать вфункцию db.writeToTheFile()
	// но твоя функция не заработает
	
	system("pause");
	return 0;
}
