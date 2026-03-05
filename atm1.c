#include <stdio.h>

float balance = 100000.00;

// PIN VERIFICATION OR ACCOUNT VERIFICATION

int verify_acc(){

    int accNo;
    int pin;
    int attempts = 3;
    
    while(attempts > 0){
        
        printf("Enter the account number:" );
        scanf("%d",&accNo);
        
        printf("Enter your 4-digit PIN (Attempts left: %d): ", attempts);
        scanf("%d", &pin);
        
        if(accNo == 123456 && pin == 1234){
            printf("PIN verified successfully!\n");
            return 1;
        }else{
            attempts--;
            if(attempts > 0){
                printf("Incorrect PIN. Please try again.\n");
            }
        }
    }
    
    printf("Card Blocked! Please contact the bank.\n");
    return 0;
}

//CHECK BALANCE

void checkBalance(){
    {
        printf("Your Current Balance: NPR%f\n", balance);
        
    }
}

// SAVINGS ACCOUNT

void savingsAccount(){
    int transactionType;
    float amount;
    
    printf("Savings Account\n");
    printf("Your Current Balance: NPR%f\n", balance);
    
    printf("Select transaction type:\n");
    printf("1.Withdraw\n");
    printf("2.Deposit\n");
    printf("Enter choice: ");
    scanf("%d", &transactionType);
    
//WITHDRAW
    
    if(transactionType == 1){ 
        printf("Enter withdrawal amount: NPR");
        scanf("%f", &amount);
        
        if(amount <= 0){
            printf("Invalid amount!\n");
            return;
        }else if(balance - amount >= 1000){
            balance=balance-amount;
            printf("Withdrawal successful!\n");
            printf("New balance: NPR%f\n", balance);
        }else{
            printf("Withdrawal failed! Minimum balance of ₹1000 must be maintained.\n");
            printf("Current balance: NPR%f\n", balance);
        }
        
//DEPOSIT 
        
    }else if(transactionType == 2){
        printf("Enter deposit amount: NPR");
        scanf("%f", &amount);
        
        if(amount <= 0){
            printf("Invalid amount!\n");
            return;
        }
        
        balance=balance+amount;
        printf("Deposit successful!\n");
        printf("New balance: NPR%f\n", balance);
        
    }else{
        printf("Invalid transaction type.\n");
    }
}

//CURRENT ACCOUNT 

void currentAccount(){
    int transactionType;
    float amount;
    
    printf("Current Account\n");
    printf("Your Current Balance: NPR%f\n", balance);
    
//PENALTY 

    if(balance < 5000){
        printf("Penalty of NPR 200 charged for low balance.\n");
        balance= balance-200;
        printf("Balance after penalty: NPR%f\n", balance);
    }
    
    printf("Select transaction type:\n");
    printf("1.Withdraw\n");
    printf("2.Deposit\n");
    printf("Enter choice: ");
    scanf("%d", &transactionType);
    
//WITHDRAW 
    
    if(transactionType == 1){
        printf("Enter withdrawal amount: NPR");
        scanf("%f", &amount);
        
        if (amount <= 0) {
            printf("Invalid amount!\n");
            return;
        }
        
        if(balance - amount >= 5000){
            balance=balance-amount;
            printf("Withdrawal successful!\n");
            printf("New balance: NPR%f\n", balance);
        }else{
            printf("Withdrawal failed! Minimum balance of ₹5000 must be maintained.\n");
            printf("Current balance: NPR%f\n", balance);
        }
        
//DEPOSIT 
        
    }else if(transactionType == 2){
        printf("Enter deposit amount: NPR");
        scanf("%f", &amount);
        
        if(amount <= 0){
            printf("Invalid amount!\n");
            return;
        }
        
        balance=balance+amount;
        printf("Deposit successful!\n");
        printf("New balance: NPR%f\n", balance);
        
    }else{
        printf("Invalid transaction type.\n");
    }
}

//SALARY ACCOUNT

void salaryAccount(){
    int transactionType;
    float amount;
    
    printf("Salary Account\n");
    printf("Your Current Balance: NPR%f\n", balance);
    
    printf("Select transaction type:\n");
    printf("1.Withdraw\n");
    printf("2.Deposit\n");
    printf("Enter choice: ");
    scanf("%d", &transactionType);
    
//WITHDRAW
    
    if(transactionType == 1){ 
        printf("Enter withdrawal amount: NPR");
        scanf("%f", &amount);
        
        if(amount <= 0){
            printf("Invalid amount!\n");
            return;
        }
        
        if(amount > 25000.00){
            printf("Withdrawal failed! Maximum withdrawal limit per transaction: NPR25,000.\n");
        }else if(amount > balance){
            printf("Withdrawal failed!.\n");
            printf("Current balance: NPR%f\n", balance);
        }else{
            balance=balance-amount;
            printf("Withdrawal successful!\n");
            printf("New balance: NPR%f\n", balance);
        }
        
//DEPOSIT
        
    }else if(transactionType == 2){
        printf("Enter deposit amount: NPR");
        scanf("%f", &amount);
        
        if(amount <= 0){
            printf("Invalid amount!\n");
            return;
        }
        
        balance=balance+amount;
        printf("Deposit successful!\n");
        printf("New balance: NPR%f\n", balance);
        
    }else{
        printf("Invalid transaction type.\n");
    }
}

int main(){
    int accountType;
    
    printf("------------------WELCOME TO KDBC ATM------------------\n");
    
//PIN VERIFICATION 

    if(verify_acc() == 0){
        return 0;
    }
    
//BALANCE     
    
    printf("\nYour starting balance is: NPR%f\n", balance);
    
//ACCOUNT SELECTION

    printf("Select Account Type:\n");
    printf("1.Savings Account\n");
    printf("2.Current Account\n");
    printf("3.Salary Account\n");
    printf("4.Check Balance\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &accountType);
    
//ACCOUNT TYPE

    switch(accountType) {
        case 1:
            savingsAccount();
            break;
        case 2:
            currentAccount();
            break;
        case 3:
            salaryAccount();
            break;
        case 4:
            checkBalance();
            break;
        default:
            printf("Invalid account type.\n");
            break;
    }
    
    printf("Thank you for using our ATM!\n");
    return 0;
}
bishalchhetri2730@gmail.com
9866
9840