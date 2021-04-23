#include <iostream>
#include <stack>
#include <string>
#include <time.h>

#include "Customer_t.h"
#include "BankService.h"
#include "BankTeller_t.h"

void newLine ( )
{
    std::cout << std::endl;
}

int addRandomCustomers ( std::stack<Customer_t> &gCustomerStack )
{
    srand ( time ( NULL ) );

    const int finalCustomerSize = rand ( ) % 15 + 1;

    std::cout << "[Bank] Generating line of " << finalCustomerSize << " customers..." << std::endl;

    for ( int i = 0; i < finalCustomerSize; ++i )
    {
        std::string firstName, middleName, lastName;
        const double currentBalance = 0.f;
        
        firstName = BankService::NAMES_LIST [ rand ( ) % BankService::NAMES_LIST.size ( ) ];
        middleName = BankService::NAMES_LIST [ rand ( ) % BankService::NAMES_LIST.size ( ) ];
        lastName = BankService::NAMES_LIST [ rand ( ) % BankService::NAMES_LIST.size ( ) ];

        Customer_t *customer = new Customer_t ( firstName, middleName, lastName, currentBalance, NULL );
        Transaction_t *transactionRef = NULL;
        transactionRef->setTransactionAmount ( static_cast< double >( rand ( ) % 5000 ) + 302 );

        if ( BankService::randomBool ( ) == true ) 
        {
            transactionRef->setTransactionType ( TransactionType::WIDTHRAWAL );
        }
        else
        {
            transactionRef->setTransactionType ( TransactionType::DEPOSIT );
        }

        customer->setTransactionReference ( transactionRef );
        gCustomerStack.push ( *customer );
    }

    return finalCustomerSize;
}

int main()
{
    // After every five customers are processed, display the size of the stack and the name of the customer who will be served next.
    std::stack<Customer_t> dsBankStack;    
    char chAnswer = NULL;

    std::cout << "[Bank] Welcome to DS Bank where our funds are backed by absolutely nothing " << std::endl;
    std::cout << "[Bank] Would you like to randomly generate customers or create your own? (1 for random, 2 for creating your own) >>> ";

    do {        
        char chAnswerForChoice;
        std::cin >> chAnswerForChoice;
        newLine ( );
        BankTeller_t *bankTeller = new BankTeller_t ( );
      
        if ( chAnswer == '1' )
        {
            std::cout << "[Bank] Generating random customers for simulation with random size..." << std::endl;
            const int generatedAmt = addRandomCustomers ( dsBankStack );
            std::cout << "[Bank] Succesfully generated " << generatedAmt << " customers" << std::endl;

            do {
                if ( ( bankTeller->getCurrentTick ( ) % 5 ) == 0 )
                {
                    std::cout << "=========== Statistics ========= " << std::endl;
                    std::cout << "Stack size: " << dsBankStack.size ( ) << std::endl;
                    std::cout << "Name of customer to be served next: " << dsBankStack.top ( ).getLastName ( ) << "," << dsBankStack.top ( ).getFirstName ( ) << std::endl;
                    std::cout << "================================= " << std::endl;
                    newLine ( );
                    newLine ( );
                }

                Customer_t currentCustomer = dsBankStack.top ( );
                std::cout << "[Bank] Beginning to process customer " << currentCustomer.getFirstName ( ) << "'s request..." << std::endl;
                system ( "pause" );
                
                if ( currentCustomer.getTransactionRef ( )->transactionType == TransactionType::WIDTHRAWAL )
                {
                    std::cout << "[Bank] " << currentCustomer.getFirstName ( ) << " wants to withdraw " << currentCustomer.getTransactionRef ( )->flTransactionAmount << std::endl;
                }
                else
                {
                    std::cout << "[Bank] " << currentCustomer.getFirstName ( ) << " wants to deposit " << currentCustomer.getTransactionRef ( )->flTransactionAmount << std::endl;
                }

                std::cout << "[Bank] Process transaction?" << std::endl;
                system ( "pause" );
                std::cout << "[Bank] Processing..." << std::endl;
                newLine ( );

                bankTeller->processCustomer ( &currentCustomer );
                std::cout << "[Bank] Succesfully processed customer!" << std::endl;

                system ( "pause" );
                bankTeller->setCurrentTick ( bankTeller->getCurrentTick ( ) + 1 );
            } while ( dsBankStack.size ( ) > 0 );
        }

    } while ( chAnswer != 'q' );

}