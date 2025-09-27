#pragma once
#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;

class Student {
public:
	char studentId[10];
	char lastName[20];
	char firstName[10];
	int yob;
	float gpa;
	Student(const char* sId,
		const char* lName,
		const char* fName,
		int y,
		float _gpa) {
		strcpy_s(studentId, sId);
		strcpy_s(lastName, lName);
		strcpy_s(firstName, fName);
		yob = y;
		gpa = _gpa;
	}
};

class Laptop {
public:
	char brand[20];
	double weight;
	long long price;

	Laptop() {
		strcpy_s(brand, "");
		price = 0.0;
		price = 0;
	}

	Laptop(const char* _brand, double w, long long p) {
		strcpy_s(brand, _brand);
		weight = w;
		price = p;
	}
};

class Node {
public:
	Student data;
	Node* next;
	Node(Student x) : data(x) {
		next = NULL;
	}
};

class mySinglyLinkedList {
private:

public:
	Node* head;
	mySinglyLinkedList() {
		head = NULL;
	}
	void addFirst(Student x) {
		Node* temp = new Node(x);
		if (head == NULL) {
			head = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}
	void show() {
		Node* p = head;
		if (p == NULL) {
			cout << "Danh sach rong!\n";
			return;
		}

		cout << left << setw(10) << "ID"
			<< setw(15) << "Ho"
			<< setw(15) << "Ten"
			<< setw(10) << "Nam sinh"
			<< setw(6) << "GPA" << endl;

		while (p != NULL) {
			cout << left << setw(10) << p->data.studentId
				<< setw(15) << p->data.lastName
				<< setw(15) << p->data.firstName
				<< setw(10) << p->data.yob
				<< setw(6) << fixed << setprecision(2) << p->data.gpa
				<< endl;
			p = p->next;
		}
		cout << endl;
	}
	void addLast(Student x) {
		Node* temp = new Node(x);
		if (head == NULL) {
			head = temp;
			return;
		}
		Node* p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
	Node* split(Node* head) {
		Node* fast = head;
		Node* slow = head;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			if (fast != NULL) {
				slow = slow->next;
			}
		}
		Node* temp = slow->next;
		slow->next = NULL;
		return temp;
	}
	Node* merge(Node* first, Node* second) {
		if (first == NULL) return second;
		if (second == NULL) return first;
		if (strcmp(first->data.firstName, second->data.firstName) < 0) {
			first->next = merge(first->next, second);
			return first;
		}
		else {
			second->next = merge(first, second->next);
			return second;
		}
	}
	Node* mergeSort(Node* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		Node* second = split(head);
		head = mergeSort(head);
		second = mergeSort(second);

		return merge(head, second);
	}

	Node* getTail(Node* cur) {
		while (cur != NULL && cur->next != NULL) {
			cur = cur->next;
		}
		return cur;
	}

	Node* partition(Node* head, Node* tail) {
		Node* pivot = head;
		Node* pre = head;
		Node* curr = head;
		while (curr != tail->next) {
			if (curr->data.gpa < pivot->data.gpa) {
				swap(curr->data, pre->next->data);
				pre = pre->next;
			}
			curr = curr->next;
		}
		swap(pivot->data, pre->data);
		return pre;
	}

	void quickSortHelper(Node* head, Node* tail) {
		if (head == NULL || head == tail) {
			return;
		}
		Node* pivot = partition(head, tail);
		quickSortHelper(head, pivot);
		quickSortHelper(pivot->next, tail);
	}

	Node* quickSort(Node* head) {
		Node* tail = getTail(head);
		quickSortHelper(head, tail);
		return head;
	}

	void heapify(Node** arr, int n, int i) {
		int largest = i;
		int right = 2 * i + 2;
		int left = 2 * i + 1;
		if (left < n && (arr[left]->data.yob > arr[largest]->data.yob)) {
			largest = left;
		}
		if (right < n && (arr[right]->data.yob > arr[largest]->data.yob)) {
			largest = right;
		}
		if (largest != i) {
			swap(arr[i]->data, arr[largest]->data);
			heapify(arr, n, largest);
		}
	}

	void sortArray(Node** arr, int n) {
		// Build heap
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(arr, n, i);
		}
		// Moving current root to end
		for (int i = n - 1; i > 0; i--) {
			swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
	}

	void heapSort(Node* node) {
		Node* head = node;
		int i = 0;
		Node** arr = new Node * [7];
		while (head != NULL) {
			arr[i] = head;
			i++;
			head = head->next;
		}
		sortArray(arr, 7);
		delete[] arr;
	}

	void heapSortByYOB() {
		heapSort(head);
	}

	void quickSortByGPA() {
		head = quickSort(head);
	}

	void mergeSortByFirstName() {
		head = mergeSort(head);
	}
};

class vectorLaptop {
public:
	int count;
	Laptop e[MAX];

	vectorLaptop() {
		count = -1;
	}

	void addLast(Laptop& x) {
		if (count + 1 < MAX) {
			count++;
			e[count] = x;
		}
		else {
			cout << "Danh sach da day";
		}
	}

	void show() {
		cout << left << setw(5) << "STT";
		cout << setw(15) << "Brand";
		cout << setw(10) << "Weight";
		cout << setw(15) << "Price" << endl;

		for (int i = 0; i <= count; i++) {
			cout << left << setw(5) << (i + 1);
			cout << setw(15) << e[i].brand;
			cout << setw(10) << e[i].weight;
			cout << setw(15) << e[i].price << endl;
		}
		cout << endl;
	}

	void merge(Laptop arr[], int left, int mid, int right) {
		int i, j, k;
		int n1 = mid - left + 1;
		int n2 = right - mid;
		Laptop leftArr[MAX], rightArr[MAX];
		for (i = 0; i < n1; i++) {
			leftArr[i] = arr[left + i];
		}
		for (j = 0; j < n2; j++) {
			rightArr[j] = arr[mid + 1 + j];
		}

		i = 0;
		j = 0;
		k = left;
		while (i < n1 && j < n2) {
			if (leftArr[i].price <= rightArr[j].price) {
				arr[k] = leftArr[i];
				i++;
			}
			else {
				arr[k] = rightArr[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			arr[k] = leftArr[i];
			i++;
			k++;
		}
		while (j < n2) {
			arr[k] = rightArr[j];
			j++;
			k++;
		}
	}

	void mergeSort(Laptop arr[], int left, int right) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}

	void mergeSortByPrice(int n) {
		mergeSort(e, 0, n);
	}
};

inline void printList(Node* head) {
	Node* curr = head;
	while (curr != nullptr) {
		cout << curr->data.firstName << " ";
		if (curr->next) {
			cout << "-> ";
		}
		curr = curr->next;
	}
	cout << endl;
}
