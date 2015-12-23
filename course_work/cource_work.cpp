#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int counter = 0;

class Student {
public:
	Student();
	Student(string sn, string n, string mn, string gen, int a, string ph,
			string em, string ht, string spec, int c, string gr, string fos, vector<int> s);
	int userID;
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
	void getSizeOfScholarship();
};

class Database {
public:
	vector <Student> data; 

	void writeToTheFile();
	void readFromTheFile();
	void printDB();
	void deleteDB();
	void addUser(Student st);
	void deleteUser(int studentID);
	void deleteUser(string surname);
	void findUser(string surname);
};

Student::Student() {
	counter++;
	userID = counter;
}

Student::Student(string sn, string n, string mn, string gen, int a, string ph,
	string em, string ht, string spec, int c, string gr, string fos, vector<int> s) {
	
	counter++;
	userID = counter;
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

void Database::writeToTheFile() { 
	ofstream out("database.txt"); 
	if (!out) {
		cout << "can't open the file ;(" << endl;
	}

	for (int i = 0; i < data.size(); i++)
	{
		out << data[i].userID << "\t" << data[i].surname << "\t" << data[i].name << "\t" << data[i].middle_name << "\t"
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
	int i = 0 ;
	string line;
	do {
		Student currentStudent = Student();
		in >> currentStudent.userID;
		in >> currentStudent.surname;
		in >> currentStudent.name; 
		in >> currentStudent.middle_name;
		in >> currentStudent.gender;
		in >> currentStudent.age;
		in >> currentStudent.phone;
		in >> currentStudent.email;
		in >> currentStudent.hometown;
		in >> currentStudent.specialty;
		in >> currentStudent.course;
		in >> currentStudent.group;
		in >> currentStudent.form_of_study;

		for (int j = 0; j < 5; j++){
			currentStudent.score.push_back(0);
			in >> currentStudent.score[j];
		}
		in >> currentStudent.avg >> currentStudent.scholarship;
		
		if (currentStudent.surname != "") data.push_back(currentStudent);
		else counter--;
		i++;
	} while(getline(in, line));

	in.close();
}

void Database::printDB() {
	for (int i = 0; i < data.size(); i++) data[i].printAllInform();
}

void Database::deleteDB() {
	data.clear();
}

void Database::addUser(Student st){
	data.push_back(st);
}

void Database::deleteUser(int userID) {
	bool result = 0;
	for (int i = 0; i < data.size(); i++){
		if (userID == data[i].userID) {
			data.erase(data.begin() + i);
			result = 1;
		}
	}
	if (result == false) {
		cout << "Student not found! \n" << endl;
	}
	else
		cout << "Student is deleted! \n" << endl;
}

void Database::deleteUser(string surname){
	bool result = 0;
	for (int i = 0; i < data.size(); i++){
		if (surname == data[i].surname) {
			data.erase(data.begin() + i);
			result = 1;
		}
	}
	if (result == false) {
		cout << "Student " << surname << " not found! \n" << endl;
	}
	else 
		cout << "Student " << surname << " is deleted! \n" << endl;
}

void Database::findUser(string surname) {
	transform(surname.begin(), surname.end(), surname.begin(), tolower);
	bool result = 0;
	for (int i = 0; i < data.size(); i++){
		string temp = data[i].surname;
		transform(temp.begin(), temp.end(), temp.begin(), tolower);
		if (surname == temp) {
			data[i].printAllInform();
			result = 1;
		}
	} 
	if (result == false) {
		cout << "Student " << surname << " not found! \n" << "Maybe this student was expelled from the university ? ;)" << endl;
	}
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

	const char separator = ' ';

    cout << left << setw(4) << setfill(separator) << userID;
	cout << setw(11) << setfill(separator) << surname;
	cout << setw(10) << setfill(separator) <<name;
	cout << setw(15) << setfill(separator) << middle_name;
	cout << setw(8) << setfill(separator) << gender;
	cout << setw(4) << setfill(separator) << age;
	cout << setw(12) << setfill(separator) << phone;
	cout << setw(20) << setfill(separator) << email;
	cout << setw(14) << setfill(separator) << hometown ;
	cout << setw(20) << setfill(separator) << specialty ;
	cout << setw(8) << setfill(separator) << course ;
	cout << setw(11) << setfill(separator) << group;
	cout << setw(14) << setfill(separator) << form_of_study;

	for (int i = 0; i < score.size(); i++){
		cout << setfill(separator) << score[i] << " ";
	}
	cout << " ";
	cout << setw(5) << setprecision(2) << avg;
	cout << setw(11) << scholarship << endl;
}

ostream &operator<<(ostream &out, Database &db){ 
	for (int i = 0; i < db.data.size(); i++){
		const char separator = ' ';
		out << left << setw(4) << setfill(separator) << db.data[i].userID;
		out << setw(11) << setfill(separator) << db.data[i].surname;
		out << setw(10) << setfill(separator) << db.data[i].name;
		out << setw(12) << setfill(separator) << db.data[i].phone << endl;
		}
	return out;
}

istream &operator>>(istream &in, Student &st){
	cout << "Surname: "; 
	in >> st.surname;

	cout << "Name: ";
	in >> st.name;

	cout << "Middle Name: ";
	in >> st.middle_name;

	cout << "Gender: ";
	in >> st.gender;

	cout << "Age: ";
	in >> st.age;

	cout << "Phone: ";
	in >> st.phone;

	cout << "E-mail: ";
	in >> st.email;

	cout << "Hometown: ";
	in >> st.hometown;

	cout << "Specialty: ";
	in >> st.specialty;

	cout << "Course: ";
	in >> st.course;

	cout << "Group: ";
	in >> st.group;

	cout << "Form of study: ";
	in >> st.form_of_study;

	cout << "Scores: ";
	for (int i = 0; i < 5; i++){
		st.score.push_back(0);
		in >> st.score[i];	
	}
	return in;
}

void printCapConsole(){
	const char separator = ' ';

	cout << left << setw(4) << "ID";
	cout << setw(11) << setfill(separator) << "Surname";
	cout << setw(10) << setfill(separator) << "Name";
	cout << setw(15) << setfill(separator) << "Middle name";
	cout << setw(8) << setfill(separator) << "Gender";
	cout << setw(4) << setfill(separator) << "Age";
	cout << setw(12) << setfill(separator) << "Phone";
	cout << setw(20) << setfill(separator) << "Email";
	cout << setw(14) << setfill(separator) << "Hometown";
	cout << setw(20) << setfill(separator) << "Specialty";
	cout << setw(8) << setfill(separator) << "Course";
	cout << setw(11) << setfill(separator) << "Group";
	cout << setw(14) << setfill(separator) << "Form of study";
	cout << setw(11) << setfill(separator) << "Scores";
	cout << setw(5) << setfill(separator) << "Avg";
	cout << setw(11) << setfill(separator) << "Scholarship\n\n";
}

void clearConsole() {
	system("cls");
}

void showTheMenu(){
	cout << endl << endl;
	cout << "****************************************************";
	cout << endl;

	cout << "You can ... \n\n";
	cout << "1. Read the database \n"
		<< "2. Write the database to the file \n"
		<< "3. Add the student to the database \n"
		<< "4. Print the database to the screen \n"
		<< "5. Phonebook \n"
		<< "6. Find the student \n"
		<< "7. Delete the student \n"
		<< "8. Delete the database \n"
		<< "9. Leave the app \n\n";
	cout << "Your choice is \t";
}

int main() {

	Database db;
	db.readFromTheFile();
	
	cout << endl << "==========================================\n\n";
	cout << "Welcome to the database **Students** \n\n";
	cout << endl << "==========================================" << endl;
	
	int iteam = 0;
	int id = 0;
	string surname;

	do {
		showTheMenu();
		cin >> iteam;
		clearConsole();

		switch (iteam){
		case 1:
			db.readFromTheFile();
			cout << "The database is read!" << endl;
			break;
		case 2:
			db.writeToTheFile();
			cout << "Ok!" << endl;
			break;
		case 3: {
			Student newStudent = Student();
			cin >> newStudent;
			newStudent.getAverageScore();
			newStudent.getSizeOfScholarship(); 
			db.addUser(newStudent);
			db.writeToTheFile();
			cout << "The student is added to the database!";
			break; }
		case 4:
			printCapConsole();
			db.printDB();
			break;
		case 5:
			cout << endl << "==========================================\n\n";
			cout << "Phonebook \n\n";
			cout << endl << "==========================================" << endl;
			cout << db;
			break;
		case 6:
			cout << "Please, enter the surname: \b";
			cin >> surname;
			clearConsole();
			db.findUser(surname);
			break;
		case 7:
			cout << "ID- 1, Surname - 2: ";
			cin >> iteam;
			clearConsole();
			
			switch (iteam)
			{
			case 1:
				cout << "Enter the Student ID\n";
				cin >> id;
				clearConsole();
				db.deleteUser(id);
				break;
			case 2:
				cout << "Enter the Student surname\n";
				cin >> surname;
				clearConsole();
				db.deleteUser(surname);
				break;
			default:
				cout << "Please! Enter 1, 2!" << endl;
				break;
			}
			break;
		case 8: 
			db.deleteDB();
			cout << "The database is clear!" << endl;
			break;
		case 9:
			break;
		default:
			cout << "Please! Enter 1, 2, 3, 4, 5, 6, 7!" << endl;
			break;
		} 
	} while (iteam != 9);
	
	return 0;
}
