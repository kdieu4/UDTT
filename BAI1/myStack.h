#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class myStack {
	Node* top;
	int count;
public:
	myStack() {
		top = NULL;
		count == 0;
	}
	void push(int x) {
		Node* temp = new Node(x);
		temp->next = top;
		top = temp;
		count++;
	}
	int pop() {
		if (top == NULL) {
			cout << "Stack Underflow" << endl;
			return -1;
		}
		Node* temp = top;
		top = top->next;
		int val = temp->data;
		count--;
		delete temp;
		return val;
	}
	int peek() {
		if (top == NULL) {
			cout << "Stack is empty" << endl;
			return -1;
		}
		return top->data;
	}
	bool isEmpty() {
		return top == NULL;
	}

	int size() {
		return count;
	}
};
