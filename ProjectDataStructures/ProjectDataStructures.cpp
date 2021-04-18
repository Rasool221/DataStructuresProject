#include <iostream>
#include <stack>
#include <string>
#include <time.h>

#include "Customer_t.h"

void newLine ( )
{
    std::cout << std::endl;
}

Customer_t gatherInformation ( std::string nameLine )
{
    if ( nameLine.empty ( ) )
    {
        std::cout << "[Bank] Oops, there was an error with your input, please retry that with correct format.";
        return;
    }
}

int addRandomCustomers ( std::stack<Customer_t> gCustomerStack )
{
    srand ( time ( NULL ) );

    const static int finalCustomerSize = rand ( ) % 15 + 1;

    for ( int i = 0; i < finalCustomerSize; ++i )
    {
        const std::string firstName, middleName, lastName;
        const double currentBalance = 0.f;
        
        Customer_t newCustomer ( );
    }
}

int main()
{
    // After every five customers are processed, display the size of the stack and the name of the customer who will be served next.
    
    char chAnswer;

    do {
        std::cout << "[Bank] Welcome to DS Bank where none of our funds are backed by absolutely nothing, how may I help you? (input 1 for widthdrawal, 2 for deposit)";
        std::cin >> chAnswer;
        newLine ( );

        chAnswer = tolower ( chAnswer );

        if ( chAnswer == '1' )
        {
        nameLocation:
            std::cout << "[Bank] Would you like to randomly generate customers or create your own? (1 for random, 2 for creating your own) >>> ";
            char chAnswerForChoice;
            std::cin >> chAnswerForChoice;
            newLine ( );
           
            if ( chAnswerForChoice == '1' )
            {
                std::cout << "[Bank] Generating random customers for simulation with random size..." << std::endl;

            }
            else if ( chAnswerForChoice == '2' )
            {

            }
            else
            {
                std::cout << "[Bank] Unknown input, please try again." << std::endl;
                goto nameLocation;
            }

            std::cout << "[Bank] Perfect, I will need some more information to process your withdrawal. What is your name? (3 names required, seperated by commas) >>> ";
            std::string strNameLine;
            std::getline ( std::cin, strNameLine );

            Customer_t customer = gatherInformation ( strNameLine );

            if ( customer.isNull ( ) )
            {
                goto nameLocation;
            }



            newLine ( );
        }
        else if ( chAnswer == '2' )
        {

            newLine ( );
        }
        else
        {
            std::cout << "[Bank] Sorry, didn't catch your input, if you would like to cancel please input Q or q >>> ";
            std::cin >> chAnswer;
            newLine ( );
        }

    } while ( chAnswer != 'q' );

}