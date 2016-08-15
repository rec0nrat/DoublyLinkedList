//********************************************************************************************
//File: DLL.h
//Programmer: Tyler Weiss
//Date Modified: 9/27/2015
//Description: Node struct and Doubly Linked List class. Proviodes methods for Creating,
//				Finding, Adding and Deleting nodes to/from a Doubly Linked List.
//********************************************************************************************

#pragma once
#include <iostream>
#include <string>

using namespace std;

//Struct for Nodes used as elements in list
template <class T>
struct Node
{
	
	T item;					//Item stored in node
	Node<T>* next;			//Pointers to next/previous nodes
	Node<T>* prev;
	
	//Constructs a node that points to nowhere
	Node(T s){		
		item = s;			//Set item to value s
		next = prev = NULL;	//Set next/previous pointers to null because they don't point to anything yet
	}

	Node() {
		next = prev = NULL;
	}
};	//END OF Node Struct

//***************************************
//Doubly Linked List Class
//Methods:
//DLL()
//void insert(datatype item)
//void print()
//void printItem(Node* node)
//Node* find(datatype dataToFind)
//bool deleteNode(datatype item)
//***************************************
template <class T>
class DLL
{
private:
	//Head and Tail of the list
	Node<T>* head;
	Node<T>* tail;
	int length;

public:
	//Constructor
	DLL(){
		head = NULL;	//head and tail = NULL upon creation so list can be traversed
		tail = NULL; 
		length = 0;
	}

	DLL(Node<T>* headNode) {
		Node<T>* current = headNode;
		while (current != NULL) {
			insertBack(current->item);
			current = current->next;
		}
	}

	void copyDLL(DLL<T>* newDLL) {

		Node<T>* current = head;
		while (current != NULL) {
			newDLL->insertBack(current->item);
			current = current->next;
		}
	}

	//insterts an item into the list
	void insert(T item){

		Node<T> *node = new Node<T>(item);	//create a new node

		if (head == NULL){		//set head/tail to node being inserted if list is empty
			head = node;
			tail = node;
		}
		else {					//places new node and the beginning of the list
			head->prev = node;
			node->next = head;
			head = node;
		}

		length++;
	}

	//insterts an item into the list
	void insertBack(T item) {

		Node<T> *node = new Node<T>(item);	//create a new node

		if (head == NULL) {		//set head/tail to node being inserted if list is empty
			head = node;
			tail = node;
		}
		else {					//places new node and the end of the list
			tail->next = node;
			node->prev = tail;
			tail = node;
		}

		length++;
	}

	//Prints the current list from head to tail
	void print(){

		Node<T> *current = head; //start at the head

		while (current != NULL){	//travers through list until NULL is reached while printing
			if (head == current)
				cout << "[";
			cout << current->item;
			if (current != tail)
				cout << "] <-> [";
			else
				cout << "]" << endl;
			current = current->next;
		}
	}

	//Prints a specified item from a specific node
	void printItem(Node<T>* node){

		if (node == NULL) cout << "NULL" << endl;	//Prints NULL if item doesn't exist
		else  cout << node->item << endl;			//Prints item
	}

	//**********************************************************************************************
	//The find method is overloaded to accept all basic datatypes due to string comparison problems
	//******************************Start of Overloaded Functions***********************************

	//Finds a specific item within the list
	Node<string>* find(string dataToFind){

		Node<string> *current = head;	//starts at the head

		while (current != NULL){		//traverses list to scan for item

			if (current->item.compare(dataToFind) == 0){	//if item found return node
				return current;
			}

			current = current->next;	//Moves to next node to look at
		}

		return current;		//Will return NULL if item is not found
	}

	Node<int>* find(int dataToFind){
		Node<int> *current = head;

		while (current != NULL){

			if (current->item == dataToFind){
				return current;
			}

			current = current->next;
		}

		return current;
	}

	Node<double>* find(double dataToFind){
		Node<double> *current = head;

		while (current != NULL){

			if (current->item == dataToFind){
				return current;
			}

			current = current->next;
		}

		return current;
	}

	Node<char>* find(char dataToFind){
		Node<char> *current = head;

		while (current != NULL){

			if (current->item == dataToFind){
				return current;
			}

			current = current->next;
		}

		return current;
	}

	Node<float>* find(float dataToFind){
		Node<float> *current = head;

		while (current != NULL){

			if (current->item == dataToFind){
				return current;
			}

			current = current->next;
		}

		return current;
	}

	//******************************End of Overloaded Functions*************************************
	
	//Deletes an item from the list if it exists
	bool deleteNode(T item){

		Node<T> *element = find(item);			//Calls find function to retrieve items node

		if (element == NULL){					//returns false if item doesn't exist
			return false;
		}
		else{

			length--;

			Node<T> *nextnode = element->next;	//Locate next node
			Node<T> *prevnode = element->prev;	//Locate previous node

			if (prevnode == NULL){				//if head of the list head is next node
				head = nextnode;
				nextnode->prev = NULL;
			}
			else if (nextnode == NULL){			//if tail of the list tail is previous node
				tail = prevnode;
				prevnode->next = NULL;
			}
			else{								//else previous/next nodes = eachother
				nextnode->prev = prevnode;
				prevnode->next = nextnode;
			}
			delete(element);					//delete the the node to be deleted
			return true;						//return true to confirm deletion
		}
	}

	

	Node<T>* getNodeAtIndex(int index) {

		Node<T> *current = head;	//starts at the head

		for (int i = 0; i < index; i++) {		//traverses list to scan for item

			if (current == NULL) {	//if item found return node
				return NULL;
			}

			current = current->next;	//Moves to next node to look at
		}

		return current;		//Will return NULL if item is not found
	}
	
	T getItemAtIndex(int index) {

		Node<T> *current = head;	//starts at the head

		for (int i = 0; i < index; i++) {		//traverses list to scan for item

			if (current == NULL) {	//if item found return node
				return NULL;
			}

			current = current->next;	//Moves to next node to look at
		}

		return current->item;		//Will return NULL if item is not found
	}

	void setLength(int len) {
		length = len;
	}

	int getLength() {
		return length;
	}

	Node<T>* getHead() {
		return head;
	}

	Node<T>* getTail() {
		return tail;
	}

	void setHead(Node<T>* node) {
		 head = node;
	}

	void setTail(Node<T>* node) {
		tail = node;
	}

};	//END OF Class DLL

