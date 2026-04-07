#include <stdio.h>

struct Account {
    int accNo;
    int pin;
    float balance;
};

struct Account currentUser;

                              // LOGIN USING FILE
int verify_acc() {
    FILE *fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("No account database found!\n");
        return 0;
    }

    int accNo, pin, attempts = 3;
    struct Account temp;

    while (attempts > 0) {
        printf("Enter Account Number: ");
        scanf("%d", &accNo);

        printf("Enter PIN (%d attempts left): ", attempts);
        scanf("%d", &pin);

        rewind(fp);

        while (fread(&temp, sizeof(temp), 1, fp)) {
            if (temp.accNo == accNo && temp.pin == pin) {
                currentUser = temp;
                fclose(fp);
                printf("Login successful!\n");
                return 1;
            }
        }

        attempts--;
        printf("Invalid credentials!\n");
    }

    fclose(fp);
    printf("Account blocked!\n");
    return 0;
}

                                   // UPDATE ACCOUNT IN FILE
void saveAccount() {
    FILE *fp = fopen("accounts.dat", "rb+");
    struct Account temp;

    while (fread(&temp, sizeof(temp), 1, fp)) {
        if (temp.accNo == currentUser.accNo) {
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fwrite(&currentUser, sizeof(currentUser), 1, fp);
            break;
        }
    }

    fclose(fp);
}

                            // CHECK BALANCE
void checkBalance() {
    printf("Balance: NPR %f\n", currentUser.balance);
}

                            // SAVINGS ACCOUNT
void savingsAccount() {
    int type;
    float amount;

    printf("Savings Account\n");
    printf("Balance: %f\n", currentUser.balance);

    printf("1.Withdraw\n2.Deposit\nChoice: ");
    scanf("%d", &type);

    if (type == 1) {
        printf("Enter amount: ");
        scanf("%f", &amount);

        if (amount <= 0 || currentUser.balance - amount < 1000) {
            printf("Invalid transaction!\n");
        } else {
            currentUser.balance -= amount;
            printf("Withdraw successful!\n");
        }

    } else if (type == 2) {
        printf("Enter amount: ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid amount!\n");
        } else {
            currentUser.balance += amount;
            printf("Deposit successful!\n");
        }
    }

    saveAccount();
}

                                  // CURRENT ACCOUNT
void currentAccount() {
    int type;
    float amount;

    printf("Current Account\n");

    if (currentUser.balance < 5000) {
        printf("Penalty charged!\n");
        currentUser.balance -= 200;
    }

    printf("Balance: %f\n", currentUser.balance);

    printf("1.Withdraw\n2.Deposit\nChoice: ");
    scanf("%d", &type);

    if (type == 1) {
        printf("Enter amount: ");
        scanf("%f", &amount);

        if (amount <= 0 || currentUser.balance - amount < 5000) {
            printf("Invalid transaction!\n");
        } else {
            currentUser.balance -= amount;
            printf("Withdraw successful!\n");
        }

    } else if (type == 2) {
        printf("Enter amount: ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid amount!\n");
        } else {
            currentUser.balance += amount;
            printf("Deposit successful!\n");
        }
    }

    saveAccount();
}

                                          // SALARY ACCOUNT
void salaryAccount() {
    int type;
    float amount;

    printf("Salary Account\n");
    printf("Balance: %f\n", currentUser.balance);

    printf("1.Withdraw\n2.Deposit\nChoice: ");
    scanf("%d", &type);

    if (type == 1) {
        printf("Enter amount: ");
        scanf("%f", &amount);

        if (amount <= 0 || amount > 25000 || amount > currentUser.balance) {
            printf("Invalid transaction!\n");
        } else {
            currentUser.balance =currentUser.balance-amount;
            printf("Withdraw successful!\n");
        }

    } else if (type == 2) {
        printf("Enter amount: ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("Invalid amount!\n");
        } else {
            currentUser.balance += amount;
            printf("Deposit successful!\n");
        }
    }

    saveAccount();
}

int main() {
    int choice;

    printf("------ KDBC ATM SYSTEM ------\n");

   if (verify_acc() == 0) {
    return 0;
}

    printf("\n1.Savings\n2.Current\n3.Salary\n4.Check Balance\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
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
         printf("Invalid choice\n");
    }

    printf("Thank you!\n");
    return 0;
}
