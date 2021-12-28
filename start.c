#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
  int pin = 1234;
  int option;
  int enteredPin;
  int count = 0;
  int amount = 1;
  float balance = 5000;
  int continueTransaction = 1;

  time_t now;
  time(&now);
  printf("\n");
  printf("\t\t\t\t\t        %s", ctime(&now));
  printf("\n\t\t\t================*Welcome to Hez projects ATM*================");

  while (pin != enteredPin)
  {
    printf("\nPlease enter your Pin: ");
    scanf("%d", &enteredPin);
    if (enteredPin != pin)
    {
      Beep(610, 500);
      printf("Invalid pin!!");
    }
    count++;
    if (count == 3 && pin != enteredPin)
    {
      exit(0);
    }
  }

  while (continueTransaction != 0)
  {
    printf("\n\t\t\t================*Available Transactions*=================");
    printf("\n\n\t\t1.Withdrawal");
    printf("\n\t\t2.Deposit");
    printf("\n\t\t3.Check Balance");
    printf("\n\n\tPlease select the option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      while (amount % 500 != 0)
      {
        printf("\n\t\tEnter the amount: ");
        scanf("%d", &amount);
        if (amount % 500 != 0)
          printf("\n\t The amount should be a multiple of 500");
      }
      if (balance < amount)
      {
        printf("\n\t Sorry insufficient funds");
        amount = 1;
        break;
      }
      else
      {
        balance -= amount;
        printf("\n\t\t You have withdrawn CHF.%d. Your new balance is CHF.%.2f", amount, balance);
        amount = 1;
        break;
      }
    case 2:
      printf("\n\t\t Please enter the amount: ");
      scanf("%d", &amount);
      balance += amount;

      printf("\n\t\t You have deposited CHF.%d. Your new balance is %.2f", amount, balance);
      printf("\n\t\t\t============Thank you for banking with Us===========");

      amount = 1;
      break;
    case 3:
      printf("\n\t\tYour balance is CHF.%.2f", balance);
      break;

    default:
      Beep(610, 500);
      printf("\n\t\tInvalid Option!!");
    }
    printf("\n\t\tDo you want to perform another transaction? Press 1 then ENTER to continue OR Press 0 then ENTER to exit\n\t\t");
    scanf("%d", &continueTransaction);
    printf("\n\t\t\t=============*GoodBye*==============\n\n");
  }

  return 0;
}
