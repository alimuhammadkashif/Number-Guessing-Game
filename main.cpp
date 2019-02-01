/*Muhammad Kashif Ali
Date of delivery 30.11.2018*/
#include <iostream> 
#include <cstdlib>
#include <ctime> 
#include<string>
using namespace std;

const int minGuess = 1;
const int maxGuess = 100;
int number, guess, tries = 1;
int alreadyguessednumber = 0;
string firstName, lastName;
int arrayOfGuess[100] = { 0 };
int i = 0;
int min = 1;
int max = 100;
bool start = true;

bool checkIfNumber()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		return false;

	}

	return true;
}

bool CheckInput(int guess)
{
	if (guess < 1 || guess > 100)
	{
		return false;

	}
	else
		return true;

}
bool CheckDuplicate(int guess)

{
	for (int i = 0; i <= 100; i++)
	{
		if (arrayOfGuess[i] == guess)
		{
			return true;

		}

	}
	return false;

}

void StartToPlay()
{
	int i = 0;
	cout << "Welcome to My Number Guessing Game" << endl; // output
	cout << "**********************************"<<endl;
	
	cout << "The objective of the game is to guess a number between 1 and 100" <<endl<< endl; // output
	
	cout << "Enter your first name and your surname " << endl;
	cin >>firstName >> lastName;// Name of the player
	cout << endl;

	srand(time(0));
	number = rand() % 100 + 1;

	while (start)
	{

		tries++;
		cout << "Please enter your secret number between (1-100) : ";
		cin >> guess;

		if (checkIfNumber() == false)
		{
			cout << "The number is not valid " << endl;
			continue;

		}

		if (CheckInput(guess) == false)
		{
			cout << "The number is out of range .. " << endl;
			continue;
		}

		if (CheckDuplicate(guess) == true)
		{
			cout << "You have used this number before...try again " << endl;
			continue;
		}

		arrayOfGuess[i] = guess;
		i++;

		if (guess > number)

		{
			cout <<"The guess is higher than the number " << endl;

		}
		else if (guess < number)
		{
			cout << "The guess is lower than the number " << endl;
		}

		else if (guess == alreadyguessednumber)
		{
			cout << "You have already guessed this number, Please try another number  " << endl;
		}

		else

		{
			cout << "Congratulations! " << firstName << "  " << lastName << " You have won the game!" << endl;
			cout << "You have won in " << tries << " tries!" << endl;
			start = false;
			break;

		}
	}
}
void clearNumbers()
{
	for (int i = 0; i <= 100; i++)
	{
		if (arrayOfGuess[i] > 0)
		{
			arrayOfGuess[i] = 0;

		}

	}

}

void doYouWantToContineu()
{
	char answer;
	bool check = true;
	while (check)
	{
		cout << "Do you want to play again? " << endl<<endl;
		cout << "Please enter your answer " << endl;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			clearNumbers();
			StartToPlay();
		}
		else if (answer == 'n' || answer == 'N')
			check = false;
		cout << "finish " << endl;
		return;
	}
}

void printAllNumbers()
{
	for (int i = 0; i <= 100; i++)
	{
		if (arrayOfGuess[i] > 0) {
			cout << arrayOfGuess[i] << endl;

		}
		else
		{
			continue;

		}
	}
}

int main() {

	StartToPlay();
	doYouWantToContineu();
	printAllNumbers();

	system("pause");
	return 0;
}