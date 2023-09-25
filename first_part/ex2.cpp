#include <iostream>

using namespace std;

int main()
{

	/* Aplique estruturas de decicao e lacos para verificar se um
	numero fornecido pelo usuario e primo ou nao */

	cout << "-------------------------------" << endl;
	cout << "---------Prime testing---------" << endl;
	cout << "-------------------------------" << endl;

	bool flag = true;

	int number;

	while (flag)
	{
		cout << "Choose a number" << endl;
		cin >> number;

		if (number == 0)
		{
			flag = false;
			break;
		}

		int divisors = 0;

		for (int i = 1; i <= number; i++)
		{
			int result = number % i;
			if (result == 0)
			{
				divisors += 1;
			}
		}
		if (divisors == 2)
		{
			cout << number << " is prime\n" << endl;
		}
		else
		{
			cout << number << " is not prime\n" << endl;
		}
	}
	return 0;
}
