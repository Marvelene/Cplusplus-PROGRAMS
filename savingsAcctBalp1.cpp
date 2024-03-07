// This program calculates the balance of a savings account
// at the end of a period of time.

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main(){
    double interestRate, startingBalance, endingBalance, totalDeposits, totalWithdrawals, totalInterest;
    int months;

    // Get the annual interest rate, the starting balance, and
    //the number of months from the user
    cout << "Enter the annual interest rate: ";
    cin >> interestRate;
    cout << "Enter the starting balance: ";
    cin >> startingBalance;
    cout << "Enter the number of months that have passed since the account was established: ";
    cin >> months;

    //Open a file
    ofstream outputFile;
    outputFile.open("savings_account.txt");

    //Loop
    for (int amount = 1; amount <= months; amount++) {
        double amountDeposited, amountWithdrawn;

        cout << "Enter the amount deposited into the account in month " << amount << ": ";
        cin >> amountDeposited;
        while (amountDeposited<0){
            cout << "Amount deposited cannot be negative!";
            cin >> amountDeposited;
        }

        cout << "Enter the amount withdrawn from the account in month " << amount << ": ";
        cin >> amountWithdrawn;
        while (amountWithdrawn < 0)
        {
            cout << "Amount withdrawn cannot be negative!";
            cin >> amountWithdrawn;
        }

        //Add and subtract the amount from the balance
        endingBalance += startingBalance + (amountDeposited - amountWithdrawn);

        //Total deposits and withdrawals
        totalDeposits += amountDeposited;
        totalWithdrawals += amountWithdrawn;

        //Calculate the monthly interest rate
        double monthlyInterestRate = interestRate / 12 / 100;
        double interest = monthlyInterestRate * endingBalance;
        endingBalance += interest;
        totalInterest += interest;

        //If endingBalance is negative
        if (endingBalance < 0){
            cout << "The account has been closed due to a negative ending balance!" << endl;
            break;
        }

        //Output to file
        outputFile << "Ending balance: " << endingBalance << endl;
        outputFile << "Total amount of deposits: " << totalDeposits << endl;
        outputFile << "Total amount of withdrawals: " << totalWithdrawals << endl;
        outputFile << "Total interest earned: " << totalInterest << endl;

        outputFile.close();

        // Display the results
        if (endingBalance >=0){
            cout << fixed << showpoint << setprecision(2);
            cout << "Ending balance: " << endingBalance << endl;
            cout << "Total amount of deposits: " << totalDeposits << endl;
            cout << "Total amount of withdrawals: " << totalWithdrawals << endl;
            cout << "Total interest earned: " << totalInterest << endl;
        }
    }
        return 0;
}