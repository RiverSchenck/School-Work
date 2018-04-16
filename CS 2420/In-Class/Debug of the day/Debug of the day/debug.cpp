#include <iostream>

using std::cout;
using std::endl;

int sum(int n) {
	int result = n;
	if (n == 0) { return result; }
	result += sum(n - 1);
	return result;
}

int main() {

	cout << "Sum from 1 to 5: " << sum(5) << endl;
	cout << "Sum from 1 to 10: " << sum(10) << endl;
	cout << "SUm from 1 to 100: " << sum(100) << endl;
}