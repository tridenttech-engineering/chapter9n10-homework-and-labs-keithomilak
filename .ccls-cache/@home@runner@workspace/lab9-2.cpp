//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Keith Omilak> on <3/23/25>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);

int main()
{
    //declare variables
    int principal = 0;
    double rateCred = 0.0;
    double rateDealer = 0.0;
    int termYears = 0;
    int rebate = 0;
    double credPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Enter the Principal Amoumt: " << endl;
    cin >> principal;
    cout << "Enter the Rebate: " << endl;
    cin >> rebate;
    cout << "Enter the Credit Rate: " << endl;
    cin >> rateCred;
    cout << "Enter the Dealer Rate: " << endl;
    cin >> rateDealer;
    cout << "Enter the Term in Years: " << endl;
    cin >> termYears;

    //call function to calculate payments
    credPayment = getPayment(principal - rebate,
        rateCred / 12, termYears * 12);
    dealerPayment = getPayment(principal, 
        rateDealer / 12, termYears * 12);    //assign values to calculate payments

    //display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit Union Payment: $" 
        << credPayment << endl;
    cout << "Dealer Payment: $"
        << dealerPayment << endl;

    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin,
                  double monthRate, 
                  int months)
{
    //calculates and returns a monthly payment
    double monthPay = 0.0;

    monthPay = prin * monthRate / 
        (1 - pow(monthRate + 1, -months));
    return monthPay;
} //end of getPayment function
