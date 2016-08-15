//********************************************************************************************
//File: MergeSort.h
//Programmer: Tyler Weiss
//Date Modified: 10/27/2015
//Description: Recursive inmplementation of merge sort algorithm on a Doubly Linked List.
//				
//********************************************************************************************
#pragma once

#include "DLL.h"

using namespace std;

template <class T>
Node<T>* split(Node<T>* head);

template <class T>
Node<T>* mergeSort(Node<T>* head);

template <class T>
Node<T>* merge(Node<T>* first, Node<T>* second);

template <class T>
void mergeSortDLL(DLL<T>* dll) {

	//Set the head and tail of the dll after sorting is complete
	dll->setHead(mergeSort(dll->getHead()));
	dll->setTail(dll->getNodeAtIndex(dll->getLength() - 1));
}

template <class T>
Node<T>* mergeSort(Node<T>* head) {
	if (!head || !head->next)
		return head;
	Node<T> *second = split(head);

	// Recur for left and right halves
	head = mergeSort(head);
	second = mergeSort(second);

	// Merge the two sorted halves
	return merge(head, second);
}

// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
template <class T>
Node<T>* split(Node<T>* head)
{
	Node<T> *fast = head, *slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node<T>* temp = slow->next;
	slow->next = NULL;
	return temp;
}

// Function to merge two linked lists
template <class T>
Node<T>* merge(Node<T>* first, Node<T>* second)
{
	// If first linked list is empty
	if (!first)
		return second;

	// If second linked list is empty
	if (!second)
		return first;

	// Pick the smaller value
	if (first->item < second->item)
	{
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}