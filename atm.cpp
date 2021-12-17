#include <iostream>
#include <Windows.h>
using namespace std;

// Variables declared globally
double balance = 100;
int amount, pin, choice;
int continuedTransaction = 1;
char y,Y, n, N;

// Function to display the MENU and its content
void showMenu()
{
   cout << "\t*****MENU*****" << endl;
   cout << "\t1.Check Balance" << endl;
   cout << "\t2.Deposit" << endl;
   cout << "\t3.Withdrawal" << endl;
   cout << "\t4.Exit" << endl;
   cout << "\t**************" << endl;
}

// Function to check balance
int checkBalance()
{

   cout << "Your balance is: "
        << " $" << balance << endl;
   return balance;
}

// Function to deposit money
int deposit()
{
   cout << "Please make your deposit" << endl;
   cin >> amount;
   balance += amount;
   cout << "Your have deposited "
        << " $" << amount << endl;
   cout << "Your new balance is "
        << " $" << balance << endl;
   return balance;
}

// Function to withdraw money
int withdrawal()
{
   cout << "Please enter withdrawal amount" << endl;
   cin >> amount;
   if (balance >= amount)
   {
      balance -= amount;
      cout << "You have withdrawn "
           << " $" << amount << endl;
      cout << "Your new balance is "
           << " $" << balance << endl;
   }
   else
   {
      cout << "You do not have enough funds..please enter an amount lesser than " << balance << endl;
      withdrawal();
   }
   return amount;
}

int main()
{
   cout << "Welcome, Please enter your PIN: " << endl;
   int trial = 2;
   do
   {
      // The correct PIN code is 2416
      cin >> pin;
      if (pin == 2416)
      {
         showMenu();
         cout << "Please select from the menu: " << endl;
         cin >> choice;
         switch (choice)
         {
         case 1:
            checkBalance();
            break;
         
         case 2:
            deposit();
            break;
         
         case 3:
            withdrawal();
            break;
         
         case 4:
            exit(1);
            break;
         
         default:
            cout << "Invalid Input";
            break;
         }
      }
      else
      {
         cout << "Invalid PIN...you have " << trial << " trial(s) left" << endl;
         if (trial == 0 && pin != 2416)
            cout << "You have been blocked...please contact customer care!";
         Beep(610, 500);
      }

      trial--;

   } while (trial >= 0 && pin != 2416);

   return 0;
}
