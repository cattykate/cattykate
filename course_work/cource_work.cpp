#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

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
	void addUser(Student st);
	void deleteUser(int studentID);
	void deleteUser(string surname);
	void findUser(string surname);
};

Student::Student() {
	userID ++;
}

Student::Student(string sn, string n, string mn, string gen, int a, string ph,
	string em, string ht, string spec, int c, string gr, string fos, vector<int> s) {
	
	userID++;
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
	ofstream out("C:/Users/Vit/Desktop/cattykate/course_work/database.txt"); 
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
	ifstream in("C:/Users/Vit/Desktop/cattykate/course_work/database.txt");
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
		i++;
	} while(getline(in, line));

	in.close();
}

void Database::printDB() {
	for (int i = 0; i < data.size(); i++) data[i].printAllInform();
}

void Database::addUser(Student st){
	data.push_back(st);
}

void Database::deleteUser(int userID) {
    data.erase(data.begin() + (userID-1)); /* (numberOfStudent - 1) because we have vector with elements from 0...
		 to n, but our user doesn't know it! the user thinks "i would like to delete the first student! i push the button 1" */
}

void Database::deleteUser(string surname){
	bool result = 0;
	for (int i = 0; i < data.size(); i++){
		if (surname == data[i].surname) {
			data.erase(data.begin() + (data[i].userID-1));
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
	bool result = 0;
	for (int i = 0; i < data.size(); i++){
		if (surname == data[i].surname) {
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
	const char separator    = ' | ';

    cout << left  <<setw(3) << setfill(separator) << userID;
	cout <<setw(10) << setfill(separator) << surname;
	cout << setw(10) << setfill(separator) <<name;
	cout << setw(15) << setfill(separator) << middle_name ;
	cout << setw(8) << setfill(separator) << gender;
	cout << setw(2) << setfill(separator) << age;
	cout << setw(12) << setfill(separator) << phone ;
	cout << setw(20) << setfill(separator) << email ;
	cout << setw(14) << setfill(separator) << hometown ;
	cout << setw(20) << setfill(separator) << specialty ;
	cout << setw(1) << setfill(separator) << course  ;
	cout << setw(11) << setfill(separator) << group;
	cout << setw(12) << setfill(separator) << form_of_study ;

	for (int i = 0; i < score.size(); i++){
		cout << setfill(separator) << score[i] << " ";
	}

	cout << setprecision(2) << avg << " ";
	cout << setw(4) << scholarship << endl;
}

void clearConsole() {
	for (int i = 0 ; i < 100; i++) std::cout<<std::endl;
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
		 << "5. Find the student \n" 
		 << "6. Delete the student \n" 
		 << "7. Leave the app \n\n";
	cout << "Your choice is \t";
}

int main() {

	/*Student Maria("Belova", "Maria", "Andreevna", "female", 18, "89167547685",
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
		"katerinka@mail.ru", "Tomsk", "Information Systems and Technology", 4, "MK-01-2012", "full-time", { 5, 5, 5, 5, 5 }); */

	Database db;
	db.readFromTheFile();

	/*db.addUser(Maria); 
	db.addUser(Elena);
	db.addUser(Alexandra); 
	*/
	//db.writeToTheFile(); // Masha, Lena, Sasha are in the file

	//db.deleteUser("Petrova"); 
	//db.writeToTheFile(); // Petrova is deleted from the file
	//db.deleteUser(2); // student 2 is deleted (Lena deleted)
	//db.writeToTheFile(); // only Alexandra in the file

	/* so, in my mind all functions work well, I checked it!
	but now i want to go to the bed( but i think that i need to add a function that will display our menu. 
	and i cause it to the end of each "case". then it will be work more correctly. what do you say on it? :)
	*/
	
	//this is a test mode!!!i know that it's necessary to edit
	
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
			cout << "ok!" << endl;
			break;
		case 3:
			//db.addUser(Maria);
			//db.addUser(Elena);
			//db.addUser(Alexandra);
			cout << "ok!students are in the database" << endl;
			break;
		case 4:
			db.printDB();
			break;
		case 5:
			cout << "Please, enter the surname: \b";
			cin >> surname;
			clearConsole();
			db.findUser(surname);
			break;
		case 6:
			std:: cout << "ID- 1, Surname - 2: ";
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
		
		case 7:
			cout << "Good bye!" << endl;
			break;
		default:
			cout << "Please! Enter 1, 2, 3, 4, 5 or 6!" << endl;
		} 
	} while (iteam != 7);
	
	//system("pause");
	return 0;
}
