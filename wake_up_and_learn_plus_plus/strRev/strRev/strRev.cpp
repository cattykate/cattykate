//#include <iostream>
//
//int main() {
//
//	char str[] = "This is the first str";
//	char* start;
//	char* end;
//	
//	int len = 0;
//	char tmp = 0;
//
//	std::cout << "Source str: " << str << std::endl;
//	len = strlen(str);
//
//	start = str;
//	end = &str[len - 1];
//
//	while (start < end){
//		tmp = *start;
//		*start = *end;
//		*end = tmp;
//
//		start++;
//		end--;
//	}
//
//	std::cout << "Reverse str: " << str << std::endl;
//
//	system("pause");
//	return 0;
//}


/*recursion*/
#include <iostream>

int factr(int n) {
	int answer = 0;

	if (n == 1) {
		return 1;
	}
	answer = factr(n - 1)*n;
	return answer;
}

int main(){
	std::cout << "Factorial 4: " << factr(4);

	return 0;
}