#include "Category.h"
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
/// Start reading 'budget.txt' when invoked by transaction object
/// Assign iterators to the starting line of the allCategory map for reading values from map
Category::Category()
{
	storeDataFromFile();
	categoriesIter1=allCategory.begin();
	categoriesIter2=allCategory.begin();
	categoriesIter3=allCategory.begin();
}
/// It reads the values from 'budget.txt' file and 
/// categorizes the read values according to category number, 
/// category budget and category name and stores them in the map caontainer
void Category::storeDataFromFile(void){
	int* number = NULL; number = new int;
	double* budget = NULL; budget = new double;
	string* name = NULL; name = new string;
	
	fstream readDataFromFile("C:\\Users\\Naakgash\\Desktop\\temp\\C++\\OOP1\\151220162093_omeryavuz_3\\budget.txt");
	
	while (readDataFromFile >> *number >> *budget >> *name){
		categoryNumber.push_back(*number);
		pair<double,string> temp(*budget,*name);
		allCategory.insert(mapOfCategories::value_type( *number, temp ));
	}
	delete budget,name,number;
	readDataFromFile.close();
}
/// Communicates with the Transaction class when creating the first portion of the screen output
void Category::printCategoryForReport(void){
	cout << categoriesIter1->second.second << endl;
	cout << "Category:"<< setw(7) << categoriesIter1->first << "\t  Balance:" << setw(7) << categoriesIter1->second.first <<endl;
	categoriesIter1++;
}
/// updates budget based on expenses
double Category::calculate(double x,int y){
	if(y!=categoriesIter2->first){
		categoriesIter2++;
	}
	double newBalance=(categoriesIter2->second.first)+x;
	int presentNumber=categoriesIter2->first;
	pair<double,string> tempx(newBalance,categoriesIter2->second.second);
	allCategory.at(presentNumber)=tempx;
	return newBalance;
}
/// communicates with the Transaction class while creating the last portion of the screen output
void Category::printFinalCategoryReport(void){
	cout << "Category:"<< setw(7) << categoriesIter3->first << "\t  Balance:" << setw(7) << categoriesIter3->second.first <<endl;
	categoriesIter3++;
}
mapOfCategories Category::getAllCategory(void){
	return allCategory;
}
vectorOfInt Category::getCategoryNumber(void){
	return categoryNumber;
}
Category::~Category(){
	
}

