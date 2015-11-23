#include <iostream>
#include <string>
#include <vector>
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

	float get_average_score();
	void print_all_inform();
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

	avg = get_average_score();
}

float Student::get_average_score(){
	int sum = 0;
	for (int i = 0; i < score.size(); i++){
		sum = sum + score[i];
	}
	return float(sum) / score.size();
}

void Student::print_all_inform(){
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
}

int main() {
	Student Masha("Belova", "Mari", "Andreevna", "female", 18, "7547685",
		"masha@mail.ru", "Moscow", "Marketing", 1, "MK-01-2013", "e-learning", { 4, 4, 5, 5 });

	Masha.print_all_inform();

	system("pause");
	return 0;
}
