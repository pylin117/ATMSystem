#include <iostream>
#include "ATM.h"
using namespace std;

int main()
{
	Account Account1(12345, 54321, 1000.0, 1200.0);
	Account Account2(98765, 56789, 200.0, 200.0);
	int account = 0;
	int pin = 0;
	cout << "Welcome!" << endl << endl;
	while (true)
	{
		cout << "Please enter your account number:";
		cin >> account;
		cout << "Enter your PIN :";
		cin >> pin;
		if (account == 12345 && pin == 54321 || account == 98765 && pin == 56789)
			break;
	}
	cout << endl;
	if (account == 12345 && pin == 54321)
		Account1.MainMenu();
	else if (account == 98765 && pin == 56789)
		Account2.MainMenu();

	system("pause");
}