#include <iostream>
using namespace std;
#define N 6

void lietKe(int& p) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = i; k <= j; k++) {
				cout << *(&p + k) << " ";
			}
			cout << endl;
		}
	}
}

void maxSubarray(int& p) {
	long max = p, s[N];
	s[0] = p;
	max = s[0];
	for (int i = 1; i < N; i++) {
		s[i] = (s[i - 1] + *(&p + i) > *(&p + i) ? s[i - 1] + *(&p + i) : *(&p + i));
		max = max > s[i] ? max : s[i];
	}
	cout << "Tong chuoi con lon nhat: " << max << endl;

}

void minSubarray(int& p) {
	long min = p, s[N];
	s[0] = p;
	min = s[0];
	for (int i = 1; i < N; i++) {
		s[i] = (s[i - 1] + *(&p + i) < *(&p + i) ? s[i - 1] + *(&p + i) : *(&p + i));
		min = min < s[i] ? min : s[i];
	}
	cout << "Tong chuoi con nho nhat: " << min << endl;

}

//int main() {
//	int arr[N] = { -2, 11, -4, 13, -5, 2 };
//
//	lietKe(arr[0]);
//	maxSubarray(arr[0]);
//	minSubarray(arr[0]);
//
//	return 0;
//}