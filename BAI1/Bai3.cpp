#include <iostream>

using namespace std;

#define MAX 100

struct List {
	int count;
	int e[MAX];
};

void init(List& l) {
	l.count = -1;
}

int isEmpty(List l) {
	return l.count == -1;
}

int isFull(List l) {
	return l.count == MAX - 1;
}

int insertLast(List& l, int x) {
	if (isFull(l)) {
		return 0;
	}
	l.count++;
	l.e[l.count] = x;
	return 1;
}

void enterList(List& l) {
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	if (n < 0 || n > MAX) {
		return;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		insertLast(l, x);
	}
}

void display(List l) {
	if (isEmpty(l)) {
		return;
	}
	for (int i = 0; i <= l.count; i++) {
		cout << l.e[i] << " ";
	}
	cout << endl;
}

int maxValue(List l) {
	int max = l.e[0];
	for (int i = 1; i <= l.count; i++) {
		if (l.e[i] > max) {
			max = l.e[i];
		}
	}
	return max;
}

int minValue(List l) {
	int min = l.e[0];
	for (int i = 1; i <= l.count; i++) {
		if (l.e[i] < min) {
			min = l.e[i];
		}
	}
	return min;
}

void quickSort(List& l, int left, int right) {
	if (left < right) {
		int i = left, j = right;
		int mid = l.e[(left + right) / 2];
		while (i <= j) {
			while (l.e[i] < mid) i++;
			while (l.e[j] > mid) j--;
			if (i <= j) {
				swap(l.e[i], l.e[j]);
				i++; j--;
			}
		}
		quickSort(l, left, j);
		quickSort(l, i, right);
	}
	
}

//int main() {
//	List l;
//	init(l);
//	enterList(l);
//	cout << "Day vua nhap la: ";
//	display(l);
//	cout << "Gia tri lon nhat: " << maxValue(l) << endl;
//	cout << "Gia tri nho nhat: " << minValue(l) << endl;
//	cout << "Day sau khi sap xep: ";
//	quickSort(l, 0, l.count);
//	display(l);
//	return 0;
//}