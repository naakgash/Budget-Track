#ifndef CATEGORY_H
#define CATEGORY_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;
/// Defines a new variable of type 'map' to associate the attributes of the categories with the category number
typedef map<int,pair<double,string> > mapOfCategories ;
/// Defines a new variable of type 'vector' for category number
typedef vector<int> vectorOfInt;
class Category
{
	public:
		Category(); ~Category(); //constructor & destructor
		/// Returns the 'map' where its categories and properties are stored
		mapOfCategories getAllCategory(void);
		/// Returns the 'vector' where the category number is extra stored
		vectorOfInt getCategoryNumber(void);
		/// The data read from the 'budget.txt' file are stored according to the characteristics of the information they contain
		void storeDataFromFile(void);
		/// The values before the budget amount changes are printed on the screen
		void printCategoryForReport(void);
		/// The value of the budget amount at the end of the transactions is printed on the screen
		void printFinalCategoryReport(void);
		/// Calculates budget that changes line by line
		double calculate(double,int);
	private:
		/// Creates the 'map' where its categories and properties are stored
		mapOfCategories allCategory;
		/// Creates the 'vector' where the category number is extra stored
		vectorOfInt categoryNumber;
		/// Iterators created for reading data in the 'map'
		mapOfCategories::const_iterator categoriesIter1;
		mapOfCategories::const_iterator categoriesIter2;
		mapOfCategories::const_iterator categoriesIter3;

};

#endif

