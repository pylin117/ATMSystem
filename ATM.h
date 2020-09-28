#ifndef ATM_H
#define ATM_H
#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
public:
	Account(int AccountNumber, int PIN, double AvailableBalance, double TotalBalance);
	void MainMenu();
	void Balance();
	void Withdraw();
	void Deposit();
	int InputAnInteger(int begin, int end);
private:
	int account;
	int pin;
	double available;
	double total;
};

Account::Account(int AccountNumber, int PIN, double AvailableBalance, double TotalBalance)
{
	account = AccountNumber;
	pin = PIN;
	available = AvailableBalance;
	total = TotalBalance;
}

void Account::MainMenu()
{
	cout << "Main Menu:" << endl;
	cout << "1 - View my balance" << endl;
	cout << "2 - Withdraw cash" << endl;
	cout << "3 - Deposit funds" << endl;
	cout << "4 - Exit" << endl;
	cout << "Enter a choice:";
	
	while (true)
	{
		int choice;
		choice = InputAnInteger(1, 4);
		switch (choice)
		{
		case 1:
			Balance();
			break;
		case 2:
			Withdraw();
			break;
		case 3:
			Deposit();
			break;
		case 4:
			cout << "\nExiting the system..." << endl << endl;
			cout << "Thank you!Goodbye!" << endl;
			break;
		default:
			cout << "Input Error! Please try again." << endl;
			break;
		}
		if (choice != -1)
			break;
	}
}

void Account::Balance()
{
	cout << "\nBalance Information:" << endl;
	cout << "\n- Available balance: $" << fixed << setprecision(2) << available << endl;
	cout << "\n- Total balance: $" << fixed << setprecision(2) << total << endl << endl;
	MainMenu();
}

void Account::Withdraw()
{
	cout << "\nWithdrawal option" << endl;
	cout << "1 - $20" << endl;
	cout << "2 - $40" << endl;
	cout << "3 - $60" << endl;
	cout << "4 - $100" << endl;
	cout << "5 - $200" << endl;
	cout << "6 - Cancel transcation" << endl;
	cout << "Choose a withdrawal option (1-6): ";
	
	while (true)
	{
		int choice;
		choice = InputAnInteger(1, 6);
		switch (choice)
		{
		case 1:
			available -= 20;
			total -= 20;
			cout << "\nPlease take your cash from the cash dispenser." << endl << endl;
			MainMenu();
			break;
		case 2:
			available -= 40;
			total -= 40;
			cout << "\nPlease take your cash from the cash dispenser." << endl << endl;
			MainMenu();
			break;
		case 3:
			available -= 60;
			total -= 60;
			cout << "\nPlease take your cash from the cash dispenser." << endl << endl;
			MainMenu();
			break;
		case 4:
			available -= 100;
			total -= 100;
			cout << "\nPlease take your cash from the cash dispenser." << endl << endl;
			MainMenu();
			break;
		case 5:
			available -= 200;
			total -= 200;
			cout << "\nPlease take your cash from the cash dispenser." << endl << endl;
			MainMenu();
			break;
		case 6:
			MainMenu();
			break;
		default:
			cout << "Input Error! Please try again." << endl;
			break;
		}
		if (choice != -1)
			break;
	}
}

void Account::Deposit()
{
	cout << "\nPlease enter a deposit amount in CENTS(or 0 to cancel) :";
	int deposit;
	cin >> deposit;
	if (deposit == 0)
		MainMenu();
	else
	{
		cout << "\nPlease insert a deposit envelope containing $10.00 in the deposit slot." << endl;
		cout << "Your envelope has been received." << endl;
		cout << "NOTE: The money deposited will not be available until we verify the amount of any enclosed cash, and any enclosed checks clear." << endl << endl;
		total += deposit / 100;
	}
	MainMenu();
}

int Account::InputAnInteger(int begin, int end)
{
	int choice;
	cin >> choice;
	if (choice >= begin&&choice <= end)
		return choice;
	else
		return -1;
}
#endif
