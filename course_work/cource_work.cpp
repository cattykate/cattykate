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
	Database (vector <Student> db);
	vector <Student> data;

	void writeToTheFile();
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

Database::Database(vector<Student> db) {
	data = db;
	writeToTheFile();
}

void Database::writeToTheFile() {
	ofstream out("database");
	if (!out) {
		cout << "can't open the file ;(" << endl;
	}
	out << "This is text file! YEEEAAAH :)";
	out.close();
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

	Masha.printAllInform();
	cout << endl;
	Lena.printAllInform();
	cout << endl;

	Masha.printAllInform(0);
	cout << endl;
	Lena.printAllInform(1);
	cout << endl;


	system("pause");
	return 0;
}