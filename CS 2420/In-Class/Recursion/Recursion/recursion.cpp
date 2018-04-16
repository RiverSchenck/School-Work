#include <iostream>

using std::cout;

template <typename T>
void printArray(T* arr, int size)  {
	if (arr == nullptr || size < 1) return;

	cout << arr[0]<< endl;
	printArray(arr +1, size -1);
	return;

};

int main() {

	


}