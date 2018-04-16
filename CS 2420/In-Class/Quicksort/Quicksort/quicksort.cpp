#include <iostream> //divide and conquer
using std::cout;
using std::endl;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int divideList(int* arr, int size) {
	
	int pivot = rand() % size; //pick a pivot
	int small = 1;
	swap(arr[0], arr[pivot]);
	pivot = 0;

		for (int i = 0; i < size; i++) {		
			if (arr[i] < arr[pivot]) { //smaller left
				swap(arr[i], arr[small]);
				small++;
			}
		}
		swap(arr[pivot], arr[small-1]);
		pivot = small - 1;
		return pivot;
}

void quicksort(int* arr, int size) {
	//Base case
	if (size < 2) {
		return;
	}

	int pivot = divideList(arr, size);
	quicksort(arr, pivot);
	quicksort(arr + pivot + 1, size - pivot - 1);
}


int main() {
	int array[10];
	cout << "Original: ";
	srand(0);
	for (int i = 0; i < 10; i++) {

		array[i] = rand() % 10000;
		cout << array[i] << ' ';
	}
	cout << endl;
	quicksort(array, 10);
	cout << "Sorted: ";
	for (int i = 0; i < 10; i++) {

		array[i] = rand() % 10000;
		cout << array[i] << ' ';
	}
	cout << endl;


}