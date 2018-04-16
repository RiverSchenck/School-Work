#include <iostream>
#include <cmath>

using namespace std;

void histogram(int[], int);

double gmean(int, int);

double standard_deviation(int *, double, int);

void print_histogram(int[]);

int main()
{
	int bins[10];

	int array[100000];

	int count = 0;

	int i = 0;
	int add = 0;


	for (i = 0; i<10; i++)

		bins[i] = 0;

	while (1)
	{
		int x;
		cin >> x;

		if (x == -1)
			break;

		if (x <= 100)
		histogram(bins, x);

		array[count++] = x;

		add += x;
	}

	double mean = gmean(add, count);

	double st = standard_deviation(array, mean, count);

	cout << "Histogram" << endl;

	print_histogram(bins);

	cout << "SD : " << st << endl;

	return 0;
}

void histogram(int bins[], int n)
{
	if (n >= 100)
		
	bins[9] ++;

	else

	bins[n / 10]++;
}
void print_histogram(int bins[])
{
	int i, j;

	for (i = 9; i >= 0; i--)
	{

		cout << "Bin "<< i << ": ";

		for (j = 1; j <= bins[i]; j++)
			cout << "*";

		cout << endl;
	}
}


double gmean(int add, int n)
{
	return (double)add / (double)n;
}


double standard_deviation(int *array, double mean, int n)
{
	double st = 0;

	int i;

	double t = 0;

	for (i = 0; i < n; i++)

	t += pow(((double)array[i] - mean), 2);

	st = sqrt(t / (double)(n - 1));

	return st;
}