//********************************************************************************************
//File: Main.cpp
//Programmer: Tyler Weiss
//Date Modified: 9/27/2015
//Description: Test a Doubly Linked List Class by creating two list of different datatypes
//				and using all the accompanying methods within the Class
//********************************************************************************************

#include <iostream>
#include <string>
#include <cmath>
#include <chrono>		//Used for timing algorithms
#include "DLL.h"		//Doubly Linked List header file
#include "MergeSort.h"

using namespace std;
using namespace chrono;

//Helper function to change string to lower case for input verification
void toLowerCase(string &str){
	for (int i = 0; str[i] != '\0'; i++){
		str[i] = tolower(str[i]);
	}
}

void main(){

	time_point<high_resolution_clock> start; //Used for timing the merge sort algorithm
	time_point<high_resolution_clock> stop;

	int sizeOfList = 0; //control variables for running the main program interface
	string dataType;
	string cont;
	bool isStillUsing = true;

	//Char array for randomizing character lists
	const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*";

	//Lists representing basic datatypes
	DLL<int> intList;
	DLL<double> doubList;
	DLL<char> charList;
	DLL<string> stringList;
	

	cout << endl << "*************************************************************" << endl << endl;

	//Loops user iinterface
	while (isStillUsing){

		cout << "Enter size of doubly linked list:" << endl;
		cin >> sizeOfList;
		cout << endl;

		//Check for proper input
		do{
			cout << "Enter data type (int, double, char):" << endl;
			cin >> dataType;
			cout << endl;
			toLowerCase(dataType);
		} while (dataType.compare("int") != 0 &&
				 dataType.compare("double") != 0 &&
				 dataType.compare("char") != 0 );

		start = high_resolution_clock::now(); //start clock

											  //Integer list randomize and run
		if (dataType.compare("int") == 0){ 
			for (int i = 0; i < sizeOfList; i++) {
				if (i % 2 != 0) intList.insert((int)-floor(rand()));
				else intList.insert((int)floor(rand()));
			}

			cout << endl << endl << "*************List Unsorted***********************************" << endl << endl;
			intList.print();//print list
			//start = high_resolution_clock::now();
			cout << endl << endl << "*************List Sorted***************************************" << endl << endl;
			mergeSortDLL(&intList);
			stop = high_resolution_clock::now();
			intList.print();
			cout << endl << endl << "*************************************************************" << endl;
			cout << endl << "It took " << duration_cast<microseconds>(stop - start).count() << " microseconds to sort the list." << endl;
			cout << endl << "*************************************************************" << endl << endl;

		}
		//Double list randomize and run
		else if (dataType.compare("double") == 0){	
			for (int i = 0; i < sizeOfList; i++) {
				if (i % 2 != 0) doubList.insert((double)-rand()/rand());
				else doubList.insert((double)rand()/rand());
			}

			cout << endl << "*************List Unsorted***********************************" << endl << endl;
			doubList.print();//print list
			//start = high_resolution_clock::now();
			cout << endl << endl << "*************List Sorted*************************************" << endl << endl;
			mergeSortDLL(&doubList);
			stop = high_resolution_clock::now();
			doubList.print();
			cout << endl << endl << "*************************************************************" << endl;
			cout << endl << "It took " << duration_cast<microseconds>(stop - start).count() << " microseconds to sort the list." << endl;
			cout << endl << "*************************************************************" << endl << endl;

		}
		//Character list randomize and run
		else if (dataType.compare("char") == 0){

			for (int i = 0; i < sizeOfList; i++) {
				charList.insert(characters[rand()%sizeof(characters)]);
			}

			cout << endl << "*************List Unsorted***********************************" << endl << endl;
			charList.print();//print list
			//start = high_resolution_clock::now();
			cout << endl << endl << "*************List Sorted*************************************" << endl << endl;
			mergeSortDLL(&charList);
			stop = high_resolution_clock::now();
			charList.print();
			cout << endl << endl << "*************************************************************" << endl;
			cout << endl << "It took " << duration_cast<microseconds>(stop - start).count() << " microseconds to sort the list." << endl;
			cout << endl << "*************************************************************" << endl << endl;
			
		}

		//Prompt for reporting/terminating the program
		cout << "Would you like to sort another list (Y/N) ?" << endl;
		cin >> cont;
		cout << endl << endl << "*************************************************************" << endl << endl;

		if (cont.compare("N") == 0 || cont.compare("n") == 0) isStillUsing = !isStillUsing;
		
	}// End of program loop
	


}	//END OF Main (DLL Test File)
