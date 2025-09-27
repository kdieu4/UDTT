#include <iostream>
#include "myStack.h"
using namespace std;

#define MAX 100

myStack sortStack(myStack& st) {
	myStack tmpStack;
	while (!st.isEmpty()) {
		int tmp = st.peek();
		st.pop();
		while (!tmpStack.isEmpty() && tmpStack.peek() < tmp) {
			st.push(tmpStack.peek());
			tmpStack.pop();
		}
		tmpStack.push(tmp);
	}
	return tmpStack;
}

//int main() {
//	myStack st;
//	st.push(4);
//	st.push(8);
//	st.push(9);
//	st.push(14);
//	st.push(-15);
//	st.push(16);
//	st.push(17);
//	st.push(-5);
//	st.push(6);
//	st.push(7);
//	st.push(1);
//	st.push(2);
//	st.push(-3);
//	st.push(18);
//	st.push(19);
//	st.push(20);
//	st.push(-10);
//	st.push(11);
//	st.push(12);
//	st.push(13);
//	myStack sortedStack = sortStack(st);
//	cout << "Stack sau khi sap xep: ";
//	while (!sortedStack.isEmpty()) {
//		cout << sortedStack.peek() << " ";
//		sortedStack.pop();
//	}
//	return 0;
//}