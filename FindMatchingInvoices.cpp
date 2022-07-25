// FindMatchingInvoices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>

std::vector<double> invoices(std::vector<double> PossibleInvoices, double target);
int main()
{
    std::vector<double> ListOfPossibleInvoices;
    double input;
    std::string buffer;
    std::cout << "Give me the list of possible invoice costs. \nEnter a letter to finish\n";
 
    while (std::cin >> input) {
        ListOfPossibleInvoices.push_back(input);
        std::cout << "The current list is:\n";
        for (int i = 0; i < ListOfPossibleInvoices.size(); i++) {
            std::cout << ListOfPossibleInvoices[i] << ", ";
        }
        std::cout << "\nEnter a letter to finish\n";
    }
    std::cout << "Here is your list\n";
    for (int i = 0; i < ListOfPossibleInvoices.size(); i++) {
        std::cout << ListOfPossibleInvoices[i]<<", " ;
    }
    std::cout << "\nEnter a target sum\n";
    double sum;
    std::cin.clear();
    //std::cin.ignore(1000, '\n');
    std::cin >> buffer;
    std::cin >> sum;
   //srand(time(NULL));
    std::vector<double>myInvoices = invoices(ListOfPossibleInvoices, sum);
    std::cout << "\n Your list is\n";
    for (int i = 0; i < myInvoices.size(); i++) {
        std::cout << myInvoices[i] << "£¬ ";
    }
    return 0;
}
//Enter the list of invoice costs and a target sum, return the list of invoices that add to this sum
//invoice could be negative (credit)

std::vector<double> invoices(std::vector<double> PossibleInvoices, double target) {
    std::vector <double> output;
    double sum = 0;
    int count = 0;
    while (sum != target && count < 1000) {
        for (int i = 0; i < PossibleInvoices.size(); i++) {
            bool test = rand() % 2;
            if (test) {
                std::cout <<"test\n"<< count ;
                output.push_back(PossibleInvoices[i]);
                sum += PossibleInvoices[i];
            }
        }
        if (sum == target) {
            return output;
        }
        else {
            output.clear();
            count++;
            sum = 0;
        }
    }
    std::cout << "\n No Solution\n";
    return PossibleInvoices;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
