#include <iostream>

using namespace std;

int main()
{
	/* Usando estruturas condicionais e de reperticao (implementente
	um menu), crie um programa de calculadora que le operacoes e va
	lores do usuario e mostre um resulado na tela */

	cout << "------------------------------------" << endl;
	cout << "------Welcome to calculator---------" << endl;
	cout << "------------------------------------" << endl;

	bool flag = true;

	cout << "Choose your operator" << endl;
	cout << "Sum (1) Subtraction (2) Multiplication (3) Division (4) exit (5)" << endl;

	while (flag)
	{

		int choose;
		cout << "Choose operator: ";
		cin >> choose;
		
		if (choose == 5)
		{
			break;
		}

		float first_number;
		float second_number;

		cout << "First number: ";
		cin >> first_number;
		cout << "Second number: ";
		cin >> second_number;

		switch (choose)
		{
		case 1:
			cout << "Result: " << first_number + second_number << endl;
			break;
		case 2:
			cout << "Result: " << first_number - second_number << endl;
			break;
		case 3:
			cout << "Result: " << first_number * second_number << endl;
			break;
		case 4:
			cout << "Result: " << first_number / second_number << endl;
			break;
		default:
			cout << "Write one of this numbers correctly" << endl;
			break;
		}
	}

	return 0;
}
