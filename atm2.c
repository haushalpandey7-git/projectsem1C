#include <stdio.h>

float balance = 100000.00;

// PIN VERIFICATION
int verify_acc() {

    int accNo;
    int pin;
    int attempts = 3;

    while (attempts > 0) {

        printf("Enter the account number: ");
        scanf("%d", &accNo);

        printf("Enter your 4-digit PIN (Attempts left: %d): ", attempts);
        scanf("%d", &pin);

        if (accNo == 123456 && pin == 1234) {
            printf("PIN verified successfully!\n");
            return 1;
        } else {
            attempts--;
            if (attempts > 0) {
                printf("Incorrect details. Please try again.\n");
            }
        }
    }

    printf("Card Blocked! Please contact the bank.\n");
    return 0;
}

// TRANSACTION FUNCTION
void transaction() {

    int transactionType;
    float amount;

    printf("\nSelect transaction type:\n");
    printf("1. Withdraw\n");
    printf("2. Deposit\n");
    printf("Enter choice: ");
    scanf("%d", &transactionType);

    if (transactionType == 1) {

        printf("Enter withdrawal amount: NPR ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid amount!\n");
        } 
        else if (balance - amount >= 1000) {
            balance=balance-amount;
            printf("Withdrawal successful!\n");
        } 
        else {
            printf("Minimum balance of NPR 1000 must be maintained.\n");
        }

    } 
    else if (transactionType == 2) {

        printf("Enter deposit amount: NPR ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid amount!\n");
        } 
        else {
            balance=balance+amount;
            printf("Deposit successful!\n");
        }

    } 
    else {
        printf("Invalid transaction type.\n");
    }

    printf("Current Balance: NPR %.2f\n", balance);
}

int main() {

    printf("----------- WELCOME TO KDBC ATM -----------\n");

    if (verify_acc() == 0) {
        return 0;
    }

    printf("Your starting balance: NPR %.2f\n", balance);

    transaction();

    printf("Thank you for using our ATM!\n");

    return 0;
}