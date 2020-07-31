#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ll {
	int data;
	ll* next;
};

void append(ll** head, int data) {
	ll* headRef = *head;
	ll* temp = new ll();
	temp->data = data;
	temp->next = NULL;
	if (*head == NULL) {
		*head = temp;
		return;
	}
	while (headRef->next) {
		headRef = headRef->next;
	}

	headRef->next = temp;
	return;
}

void printll(ll* head) {
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
}

ll* reverse(ll* curr, ll* prev) {
	if (curr->next == NULL) {
		curr->next = prev;
		return curr;
	}
	ll* nextLL = curr->next;
	curr->next = prev;
	prev = curr;
	return reverse(nextLL, curr);
}

int main()
{
#ifndef PRINTOUTPUT
	freopen("output.txt", "w", stdout);
#endif
	ll* head  = new ll();
	head = NULL;
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	head = reverse(head, NULL);
	printll(head);
	return 0;
}