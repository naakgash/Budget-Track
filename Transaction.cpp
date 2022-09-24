#include "Transaction.h"
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
/// Constructor & destructor
Transaction::Transaction(){ };Transaction::~Transaction(){ };
/// Reads data from 'transactions.txt' file. Assigns readings to temporary variables.
/// Temporary variables are deleted at the end of storage. Values are stored by number, date, transaction amount and name.
/// The values associated in the multimap are eventually stored in the map vector and the temporary multimap variable is deleted.
void Transaction::storeDataFromFile(void){
	// temporary variables as dynamic memory
	int* number = NULL; number = new int;
	double* budget = NULL; budget = new double;
	string* date = NULL; date = new string;
	string* name = NULL; name = new string;
	// Learns total number of categories through categories object
	//searches value from 'transactions.txt for each category number
	for(int j=1;j<=categories.getCategoryNumber().size();j++){ // repeat as many as the number of categories
		mapOfTransactions* temp=NULL; temp = new mapOfTransactions; // temporary multimap's container
		int temp0=categories.getCategoryNumber()[j-1]; // determines the category number to be searched in the file
		fstream readDataFromFile("C:\\Users\\Naakgash\\Desktop\\temp\\C++\\OOP1\\151220162093_omeryavuz_3\\transactions.txt"); // specify file to read data
		while(readDataFromFile >> *number >> *date >> *budget >> *name){ // start reading line by line
				// temporarily store read values in temp's multimap if category numbers match
				if( *number==temp0 ){
					pair<int,string> temp1(*number,*date);
					pair<double,string> temp2(*budget,*name);
					(*temp).insert(mapOfTransactions::value_type(temp1,temp2));
				}
		}
		delete temp; // delete temporary multimap container
		readDataFromFile.close(); // close the file that finished reading
	}	
	delete budget,name,number,date; // delete temporary variables
	sort(VOTM.begin(),VOTM.end()); // Sort vector containing multimaps in ascending order
}
/// Prints the stored values and operation results on the screen.
/// Communicates with the category class for the required values through the categories object
void Transaction::printResult(void){
	for(int j=1;j<=categories.getCategoryNumber().size();j++){
		categories.printCategoryForReport();
		for(transactionsIter=VOTM[j-1].begin();transactionsIter!=VOTM[j-1].end();transactionsIter++){
			double tempDouble=transactionsIter->second.first;
			cout<< "  " << transactionsIter->first.second<< setw(12) <<tempDouble;
			cout<< "  ------->"<<setw(7)<< categories.calculate(tempDouble,transactionsIter->first.first) <<"   " <<transactionsIter->second.second<<endl;
		}
		categories.printFinalCategoryReport();
		cout << endl;
	}
}

