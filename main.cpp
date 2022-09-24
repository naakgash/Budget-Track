#include <iostream>
#include "Category.h"
#include "Transaction.h"
#include <iomanip>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	cout << fixed << setprecision(2);
	
	Transaction transactions;
	transactions.storeDataFromFile();
	transactions.printResult();
		
	return 0;
}


