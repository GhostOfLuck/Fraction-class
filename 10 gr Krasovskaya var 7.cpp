#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include "FractionHome.h"
#include "Exception.h"
using namespace std;
void randomPart(Fraction *a) {
	srand(time(NULL));
	for (int j = 0; j < 5; j++)	{
		a[j].setDenominator(rand() % (5 - (-5) + 1) + (-5));
		a[j].setNumerator(rand() % (5 - (-5) + 1) + (-5));
	}
}

void summaPart(Fraction *a) {
	a[5] = a[0] + a[2];
	a[6] = a[1] + a[3];
}

void rulePart(Fraction *a) {
	for (int i = 7; i < 10; i++){
		a[i] = 3 * ((++a[i - 1] + a[i - 7]) /(a[i-7].getID()) );
	}
}
void sortMas(Fraction *a)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main(){
	try {
		
		Fraction array[10];
		randomPart(array);
		summaPart(array);
		rulePart(array);
		sortMas(array);
		for (int i = 0; i < 10; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;

	}
	catch (const MyException& a){
		cout << a.getMessage() << endl;
	}

}
