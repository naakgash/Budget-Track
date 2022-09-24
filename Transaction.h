#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <map>
#include <vector>
#include "Category.h"
using namespace std;
/// Defines a new variable of type 'multimap' to associate the attributes of the transactions
typedef multimap<pair<int,string>,pair<double,string> > mapOfTransactions;
/// Defines the vector where the 'multimaps' will be stored
typedef vector<mapOfTransactions> vectorOfTransactionsMaps;

class Transaction
{
	public:
		Transaction(); ~Transaction(); //constructor & destructor
		/// The data read from the 'transactions.txt' file are stored according to the characteristics of the information they contain
		void storeDataFromFile(void);
		/// Prints the result to the screen with help from the category class
		void printResult(void);
	private:
		/// Creates the vector where the 'multimaps' will be stored
		vectorOfTransactionsMaps VOTM;
		/// Iterators created for reading data in the 'multimap'
		mapOfTransactions::const_iterator transactionsIter;
		/// Creates an object in category class as composition to analyze operations by categories.
		Category categories;
};

#endif

