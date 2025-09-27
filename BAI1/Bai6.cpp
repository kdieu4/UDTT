#include <iostream>
#include "mySingleLinkedList.h"
using namespace std;

int main() {
	int n = 5;
	long long m = 50000000;
	
	vectorLaptop d;
	Laptop l1("Asus", 1.5, 20000000);
	Laptop l2("Dell", 1.7, 25000000);
	Laptop l3("Lenovo", 2.5, 35000000);
	Laptop l4("Mac", 1, 24000000);
	Laptop l5("HP", 1.5, 15000000);

	d.addLast(l1);
	d.addLast(l2);
	d.addLast(l3);
	d.addLast(l4);
	d.addLast(l5);

	cout << "Danh sach vua nhap\n";
	d.show();

	d.mergeSortByPrice(4);
	cout << "Danh sach sau khi sap xep\n";
	d.show();

	return 0;
}