#include <iostream>   //I/O
#include <fstream>    //File Input handling
#include <string>     //String convenience

#include "HashDouble.h"	              //Hash with double hashing
#include "HashQuadraticProbing.h"	    //Hash with quadratic probing

//Load a HashDouble from a (.txt) file
HashDouble<int> loadHashDouble(std::string fName) {
  std::ifstream file(fName);
  int num;
  std::cout << "\n\nAttempting to create a double hash table from file " << fName << "...";
  if (file.is_open()) {
    HashDouble<int>* hash = new HashDouble<int>(53); //Size 53 is assumed in this implementation
    while(file >> num) hash->insert(num); //Load numbers to table.
    file.close();
    return *hash;
  }
  else return HashDouble<int>(0);
}

//Load a HashQuadraticProbing from a (.txt) file
HashQuadraticProbing<int> loadHashQuadraticProbing(std::string fName) {
  std::ifstream file(fName);
  int num;
  std::cout << "\n\nAttempting to create a quadratically probed hash table from file " << fName << "...";
  if (file.is_open()) {
    HashQuadraticProbing<int>* hash = new HashQuadraticProbing<int>(53); //Size 53 is assumed in this implementation
    while(file >> num) hash->insert(num); //Load numbers to table.
    file.close();
    return *hash;
  }
  else return HashQuadraticProbing<int>(0);
}


//Main function
int main(int argc, char* argv[])
{
  if (!argv[1]) std::cout << "\nNo file arguments provided. Defaulting to 'data1.txt'.";
	std::string fileName = (argv[1]) ? argv[1] : "data1.txt"; //File name assignment

	HashQuadraticProbing<int> hashQP = loadHashQuadraticProbing(fileName);
  HashDouble<int> hashD = loadHashDouble(fileName);


  //Main IO loop - controls interaction with both Double and Quadratically Probed Hash tables.
	int choice = 0;
	do {
    std::cout << "\n\n................................................................"
									<< "\nPlease choose one of the following commands:"
									<< "\n1- Insert"
									<< "\n2- Delete"
									<< "\n3- Find"
									<< "\n4- Print"
									<< "\n5- Exit"
									<< "\n> ";
    std::cin >> choice;
		int num = 0; //Contains I/O responses
    switch(choice) {
      case 1: //Handle Insert
        std::cout << "\nEnter a number to be inserted: \n> ";
				std::cin >> num;
        hashQP.insert(num);
        hashD.insert(num);
        break;
      case 2: //Handle Delete
        std::cout << "\nEnter a number to be deleted: \n> ";
				std::cin >> num;
				hashQP.erase(num);
        hashD.erase(num);
        break;
      case 3: //Handle Find
        std::cout << "\nEnter a number to search for: \n> ";
				std::cin >> num;
        hashQP.find(num);
        hashD.find(num);
        break;
      case 4: //Handle Print
        std::cout << "\nTables:  \n................................................................";
				hashQP.print();
        hashD.print();
        break;
      case 5: break; //Handle Exit
      default:
        std::cout << "\nThat option was not found. Please try again.";
        break;
    }

  } while (choice != 5);
  std::cout << "\n\nExiting - dumping table...\n";
}
