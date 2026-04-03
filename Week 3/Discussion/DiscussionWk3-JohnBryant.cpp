#include <iostream>
using namespace std;

int main() {
	int score; //editor note (Lane): added parentheses after 'main' to make it a function

	cout << "Enter your score (0-100): ";
	cin >> score;

	if (score >= 90) {
		cout << "Your grade is: A" << endl;
	}
	else if (score >= 80) { //editor note (Lane): changed the sytax from else (score >= 80) to else if (score >= 80)
		cout << "Your grade is: B" << endl;
	} 
	else if (score >= 70) { //editor note (Lane): changed the sytax from else (score >= 70) to else if (score >= 70)
		cout << "Your grade is: C" << endl;
	}
	else if (score >= 60) { //editor note (Lane): changed the sytax from else (score >= 60) to else if (score >= 60)
		cout << "Your grade is: D" << endl;
	}
	else {
		cout << "Your grade is: F" << endl;
	}

	
}

	 