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
	out << "Surname \t" << "Name \t" << "Middle Name \t" << "Gender \t" << "Age \t"
		<< "Phone \t" << "Email \t" << "Hometown \t" << "Specialty  \t" << "Course \t"
		<< "Group \t" << "Form of study \t" << "Scores \t" << "Average score \t" << "Scholarship \t\n\n";

	for (int i = 0; i < data.size(); i++)
	{
		out << data[i].surname << "\t" << data[i].name << "\t" << data[i].middle_name << "\t"
			<< data[i].gender << "\t" << data[i].age << "\t" << data[i].phone << "\t"
			<< data[i].email << "\t" << data[i].hometown << "\t" << data[i].specialty << "\t"
			<< data[i].course << "\t" << data[i].group << "\t" << data[i].form_of_study << "\t";

		for (int j = 0; j < data[i].score.size(); j++){
			out << data[i].score[j] << " ";
		}
		out << "\t" << data[i].avg << "\t" << data[i].scholarship << "\t" << endl;
	}
	out.close();
}

void Database::readFromTheFile() {
	ifstream in("database.txt");
	if (!in) {
		cout << "can't open the file ;(" << endl;
	}
	for (int i = 0; i < data.size(); i++){
		in >> data[i].surname >> data[i].name >> data[i].middle_name >>
			data[i].gender >> data[i].age >> data[i].phone >>
			data[i].email >> data[i].hometown >> data[i].specialty >>
			data[i].course >> data[i].group >> data[i].form_of_study;

		for (int j = 0; j < data[i].score.size(); j++){
			in >> data[i].score[j];
		}
		in >> data[i].avg >> data[i].scholarship;
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
	Student Maria("Belova", "Maria", "Andreevna", "female", 18, "89167547685",
		"masha@mail.ru", "Moscow", "Marketing", 1, "MK-01-2013", "e-learning", { 5, 5, 5, 5, 4 });
	Student Elena("Petrova", "Elena", "Olegovna", "female", 20, "89178454545",
		"lena@mail.ru", "Moscow", "Marketing", 2, "MK-01-2012", "full-time", { 3, 4, 5, 5, 4 });
	Student Alexandra("Vlasova", "Alexandra", "Yuryevna", "female", 17, "89261554242",
		"dtdtdtd@yandex.ru", "Saint Petersburg", "Innovations", 1, "IN-01-2012", "full-time", { 3, 3, 3, 3, 3 });
	Student Igor("Andreev", "Igor", "Vasilievich", "male", 17, "89056554815",
		"lena@mail.ru", "Kirov", "Innovations", 2, "IN-01-2012", "full-time", { 5, 5, 5, 5, 5 });
	Student Margarita("Eliseeva", "Margarita", "Alexeevna", "female", 22, "89031564852",
		"marggggo@yandex.ru", "Moscow", "Marketing", 2, "MK-01-2012", "full-time", { 4, 4, 5, 5, 4 });
	Student Vitali("Ivanov", "Vitali", "Olegovich", "male", 21, "89257711525",
		"ivanov@mail.ru", "Saint Petersburg", "Applied Mathematics", 3, "AM-01-2012", "full-time", { 3, 4, 4, 5, 4 });
	Student Alexandr("Kirilov", "Alexandr", "Alexandrovich", "male", 18, "89851554697",
		"alex232@mail.ru", "Moscow", "Marketing", 2, "MK-02-2012", "full-time", { 3, 5, 5, 5, 5 });
	Student Alexey("Ivashenko", "Alexey", "Igorevich", "male", 18, "89037331642",
		"llle@mail.ru", "Moscow", "Applied Mathematics", 4, "AM-01-2011", "extramural", { 4, 5, 5, 5, 5 });
	Student Vasily("Sizov", "Vasily", "Andreevich", "male", 20, "89051501243",
		"sizov@rambler.ru", "Moscow", "Information Systems and Technology", 2, "IT-01-2012", "full-time", { 4, 4, 4, 4, 4 }); 
	Student Ekaterina("Ageeva", "Ekaterina", "Petrovna", "female", 23, "89251616555",
		"katerinka@mail.ru", "Tomsk", "Information Systems and Technology", 4, "MK-01-2012", "full-time", { 5, 5, 5, 5, 5 });

	// У нас есть маша и лена, они обе типа Student, верно? Есть два человека, поэтому можно созщдавать базу данных:
	Database db; // пустой объект. создали базу, она абсолютно пустая.
	// обратимся к полю базы, которое хранит вектор из Student: db.data. - это у нас что? вектор! значит в это поле мы можем добавить студента? так? Добавляем!
	
	db.data.push_back(Maria);
	db.data.push_back(Elena);
	db.data.push_back(Alexandra);
	db.data.push_back(Igor);
	db.data.push_back(Margarita);
	db.data.push_back(Vitali);
	db.data.push_back(Alexandr);
	db.data.push_back(Alexey);
	db.data.push_back(Vasily);
	db.data.push_back(Ekaterina);
	
	db.writeToTheFile(); 
	db.readFromTheFile();
	
	// теперь в базе маша с леной!!! проверь в дебаггере!
	// далее, когда у тебя есть база, ты можешь ее записать в файл. Для этого надо вызывать вфункцию db.writeToTheFile()
	// но твоя функция не заработает	
	
	system("pause");
	return 0;
}
