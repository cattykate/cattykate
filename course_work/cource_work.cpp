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

	float get_average_score();
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
	}

float Student::get_average_score(){
	int sum = 0;
	for (int i = 0; i < score.size(); i++){
		sum = sum + score[i];
		}
	return float(sum) / score.size();
	}

int main() {
	Student Masha("Belova", "Mari", "Andreevna", "female", 18, "7547685",
		"masha@mail.ru", "Moscow", "Marketing", 1, "MK-01-2013", "e-learning", { 4, 4, 5, 5 });
	float avg = Masha.get_average_score();

	cout << "Parapapa" <<endl;

	system("pause");
	return 0;
	}
