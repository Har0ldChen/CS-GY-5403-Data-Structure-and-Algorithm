// Hw3.cpp : Defines the entry point for the console application.
// Imageine thatt people have decided to commit mass suicide by arranging themselves in circle and killing the mth person around the circle.
// Closimh the ranks as each person drops out of the circle. 
// Find out which person is the last to die, or, more generally, find the order in which those peole are executed.

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class circleLinkedList {
	Node *head;

public:

	circleLinkedList() { head = NULL;}

	void appendToTail(int n) {
		Node *end = new Node;
		end->data = n;
		if (head == NULL) {
			head = end;
			head->next = head;
		}
		else {
			Node *current = head;
			while (current->next != head) {
				current = current->next;
			}
			current->next = end;
			current->next->next = head;
		}
	}

	int deleteKthNode(int k) {
		if (head == NULL) {
			cout << "The Linkedlist is empty!";
			return 0;
		}
		else {
			int i;
			Node *current = head;
			for (int i = 0; i < k - 2; i++) {
				current = current->next;
			}
			i = current->next->data;
			current->next = current->next->next;
			return i;
		}
	}

	void resetHead(int n) {
		if (head == NULL) {
			cout << "The Linkedlist is empty!";
		}
		else {
			Node *current = head;
			for (int i = 0; i < n - 2; i++) {
				current = current->next;
			}
			head = current->next;
		}
	}

};

int main()
{
	int N;
	int M;

	cout << "N = ";
	cin >> N;
	cout << endl;
	cout << "M = ";
	cin >> M;
	cout << endl;

	int *porder = new int[N];

	circleLinkedList *plist = new circleLinkedList();
	circleLinkedList list = *plist;

	for (int i = 0; i < N; i++) {
		list.appendToTail(i + 1);
	}

	for (int i = 0; i < N; i++) {
		porder[i] = list.deleteKthNode(M);
		list.resetHead(M);
	}

	cout << "The people are killed in the following order: ";

	for (int i = 0; i < N-1; i++) {
		cout << porder[i] << ", ";
	}

	cout << porder[N - 1] << ". " << endl;
	cout << endl;

	delete plist;
	delete [] porder;
    return 0;
}

