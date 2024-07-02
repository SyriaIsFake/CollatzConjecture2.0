#include <iostream>
#include <cmath>


using namespace std;

long long int steps = 0;
long long int prevSteps = 0;
long long int prevLogNum = 0;


//COLLATZ 2.0 
//3.45x better than Collatz 1.0 or 345% quicker

void Collatz(long long int initNum) {

	long long int n = 0;
	n = initNum;
	long float lognum = log2(n);

	while (true)
	{

		lognum = log2(n);

		if (ceil(lognum) != floor(lognum)) {


			if ((n % 2) == 0) {
				n = (3 * n) + 1;
			}
			else {
				n = n / 2;
			}

			steps++;
			system("CLS");
			cout << "Current working integer: " << initNum << "\n";
			cout << "Number: " << n << "\n";
			cout << "steps freed using Factorisation: " << prevLogNum << "\n";
			cout << "previous steps take: " << prevSteps << "\n";
		}
		else {
			prevSteps = steps + lognum + 1;
			prevLogNum = prevLogNum + lognum;
			steps = 0;
			initNum++;
			n = initNum;
			Collatz(initNum);
			break;
		}
	}
}

int main()
{
	long long int initNum = 0;

	cout << "enter Num: ";
	cin >> initNum;
	Collatz(initNum);
}

/*
	
	long float lognum = log2(n);

	if (ceil(lognum) == floor(lognum)) {
		cout << "power of 2";
		cout << lognum;
	}
	else {
		cout << "isnt power of 2";
	}
*/
