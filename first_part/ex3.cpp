#include <iostream>

using namespace std;

int main()
{
	/* Implemente um menu com tres opcoes: C - Fahrenheit para
	Celsius, F - Celsius para Fahrenheit e S - Sair. Depois que
	o usuario optar por uma das duas primeiras opcoes, leia um
	valor float e mostre seu valor na respectiva escala. Caso o
	usuario opte pela opcao S, encerre o programa */

	cout << "-------------------------------" << endl;
	cout << "-----Temperature converter-----" << endl;
	cout << "-------------------------------" << endl;

	bool flag = true;

	while (flag)
	{
		cout << "* * * * * * * * * " << endl;
		cout << "Fahrenheit to Celsius (c)\nCelcius to Fahrenheit (f)\nExit (q)" << endl;
		char choice;
		cin >> choice;
		choice = tolower(choice);

		float c_result = 0.0, f_result = 0.0;

		switch (choice)
		{
		case 'q':
			cout << "Exiting..." << endl;
			flag = false;
			break;
		case 'c':
		{
			cout << "You choose F to C\nWrite your temperature:";
			float fahrenheit;
			cin >> fahrenheit;
			float c_result = ((5.0 / 9.0) * (fahrenheit - 32.0));
			cout.precision(2);
			cout << fixed;
			cout << c_result << " Celcius!" << endl;
			break;
		}
		case 'f':
		{
			cout << "You choose C to F\nWrite your temperature:";
			float celcius;
			cin >> celcius;
			float f_result = (((9.0 / 5.0) * celcius) + 32.0);
			cout.precision(2);
			cout << fixed;
			cout << f_result << " Fahrenheit!" << endl;
			break;
		}
		default:
			cout << "Invalid option." << endl;
			break;
		}
	}

	return 0;
}
