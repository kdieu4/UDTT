#include <iostream>
#include <vector>
//#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define MAX 20000

void bubbleSort(vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void selectionSort(vector<int>& a) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		int m = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[m]) {
				m = j;
			}
		}
		swap(a[i], a[m]);
	}
}

void insertionSort(vector<int>& arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void quickSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int k = (left + right) / 2;
		int t = arr[k];
		int i = left, j = right;
		while (i <= j) {
			while (arr[i] < t) i = i + 1;
			while (arr[j] > t) j = j - 1;
			if (i <= j) {
				int tg = arr[i];
				arr[i] = arr[j];
				arr[j] = tg;
				i++; j--;
			}
		}
		quickSort(arr, left, j);
		quickSort(arr, i, right);
	}
}


template <typename Func>
long long measureTime(Func f, vector<int> arr) {
	auto start = high_resolution_clock::now();
	f(arr);
	auto end = high_resolution_clock::now();
	return duration_cast<milliseconds>(end - start).count();
}

//int main() {
//	int n = 20000;
//	vector<int> a(n);
//	srand(time(0));
//	for (int i = 0; i < n; i++) {
//		a[i] = rand() % 100;
//	}
//	
//	vector<int> arr1 = a, arr2 = a, arr3 = a, arr4 = a;
//
//	auto t1 = measureTime(bubbleSort, arr1);
//	cout << "Bubble Sort time: " << t1 << " ms" << endl;
//
//	auto t2 = measureTime(selectionSort, arr2);
//	cout << "Selection Sort: " << t2 << " ms\n";
//	
//	auto t3 = measureTime(insertionSort, arr3);
//	cout << "Insertion Sort: " << t3 << " ms\n";
//
//	auto t4 = measureTime([&](vector<int> arr) { quickSort(arr, 0, arr.size() - 1); }, arr4);
//	cout << "Quick Sort: " << t4 << " ms\n";
//
//
//	return 0;
//}