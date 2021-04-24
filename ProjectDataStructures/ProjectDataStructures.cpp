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

int addCustomersManually ( std::stack<Customer_t>& gCustomerStack )
{
    srand ( time ( NULL ) );

    int finalCustomerSize = 0;
customerAmountLocation:
    std::cout << "[Bank] How many customers would you like to make? >>> ";
    std::cin >> finalCustomerSize;

    if ( !finalCustomerSize )
        goto customerAmountLocation;

    newLine ( );
    std::cout << "[Bank] Okay, lets begin filling out customer list..." << std::endl;

    std::string firstName, middleName, lastName;
    double customersMoney = 0.f;
    double transactionAmount = 0.f;
    int transactionType = 0;

    for ( int i = 0; i < finalCustomerSize; ++i )
    {
        std::cin.ignore ( );
        std::cout << "[Bank] Processing customer " << i << "/" << finalCustomerSize << std::endl;
        std::cout << "[Bank] Please enter the first name of the customer: " << std::endl;
        std::getline ( std::cin, firstName );
        newLine ( );
        std::cout << "[Bank] Please enter the middle name of the customer: " << std::endl;
        std::getline ( std::cin, middleName );
        newLine ( );
        std::cout << "[Bank] Please enter the last name of the customer: " << std::endl;
        std::getline ( std::cin, lastName );
        newLine ( );
        std::cout << "[Bank] Please enter the amount of money that will be in the customer's bank account >>> ";
        std::cin >> customersMoney;
        newLine ( );
        std::cout << "[Bank] Please enter the amount of the transaction >>> ";
        std::cin >> transactionAmount;
        newLine ( );
    transactionTypeChoiceLocation:
        std::cout << "[Bank] Now please enter whether the transaction will be a withdrawal or a deposit (1 for deposit, 0 for withdrawal) >>> ";
        std::cin >> transactionType;

        if ( transactionType != 1 && transactionType != 0 )
            goto transactionTypeChoiceLocation;

        std::cout << "[Bank] Generating customer profile..." << std::endl;

        Customer_t* customer = new Customer_t ( firstName, middleName, lastName, customersMoney, NULL );
        Transaction_t* transactionRef = new Transaction_t ( );
        transactionRef->setTransactionAmount ( transactionAmount );

        if ( transactionType == 0 )
        {
            transactionRef->setTransactionType ( TransactionType::WIDTHRAWAL );
        }
        else
        {
            transactionRef->setTransactionType ( TransactionType::DEPOSIT );
        }

        customer->setTransactionReference ( transactionRef );
        gCustomerStack.push ( *customer );

        std::cout << "[Bank] Successfully created customer profile and saved it, moving ..." << std::endl;
    }

    return finalCustomerSize;
}

int addRandomCustomers ( std::stack<Customer_t> &gCustomerStack )
{
    srand ( time ( NULL ) );

    const int finalCustomerSize = rand ( ) % 15 + 1;

    std::cout << "[Bank] Generating line of " << finalCustomerSize << " customers..." << std::endl;

    for ( int i = 0; i < finalCustomerSize; ++i )
    {
        std::string firstName, middleName, lastName;
        const double currentBalance = static_cast< double >( rand ( ) % 5000 ) + 392;
        
        firstName = BankService::NAMES_LIST [ rand ( ) % BankService::NAMES_LIST.size ( ) ];
        middleName = BankService::NAMES_LIST [ rand ( ) % BankService::NAMES_LIST.size ( ) ];
        lastName = BankService::NAMES_LIST [ rand ( ) % BankService::NAMES_LIST.size ( ) ];

        Customer_t *customer = new Customer_t ( firstName, middleName, lastName, currentBalance, NULL );
        Transaction_t* transactionRef  = new Transaction_t( );
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
    std::stack<Customer_t> dsBankStack;    

    std::cout << "[Bank] Welcome to DS Bank where our funds are backed by absolutely nothing " << std::endl;
    std::cout << "[Bank] Would you like to randomly generate customers or create your own? (1 for random, 2 for creating your own) >>> ";
    char chAnswerForChoice = NULL;
    std::cin >> chAnswerForChoice;

    do {        
        newLine ( );
        BankTeller_t *bankTeller = new BankTeller_t ( );
      
        if ( chAnswerForChoice == '1' )
        {
            std::cout << "[Bank] Generating random customers for simulation with random size..." << std::endl;
            const int generatedAmt = addRandomCustomers ( dsBankStack );
            std::cout << "[Bank] Succesfully generated " << generatedAmt << " customers" << std::endl;

            do {
                if ( ( bankTeller->getCurrentTick ( ) % 5 ) == 0 && bankTeller->getCurrentTick ( ) != 0 )
                {
                    newLine ( );
                    newLine ( );
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
                dsBankStack.pop ( );
            } while ( dsBankStack.size ( ) > 0 );
        }
        else if ( chAnswerForChoice == '2' )
        {
            std::cout << "[Bank] Manual simulation processing..." << std::endl;
            addCustomersManually ( dsBankStack );
            
            do {
                if ( ( bankTeller->getCurrentTick ( ) % 5 ) == 0 && bankTeller->getCurrentTick ( ) != 0 )
                {
                    newLine ( );
                    newLine ( );
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
                dsBankStack.pop ( );
            } while ( dsBankStack.size ( ) > 0 );
        }

        std::cout << "[Bank] Would you like to randomly generate customers or create your own? (1 for random, 2 for creating your own, or q to quit) >>> ";
        std::cin >> chAnswerForChoice;
        newLine ( );

    } while ( chAnswerForChoice != 'q' );

}