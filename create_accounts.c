#include <stdio.h>

struct Account {
    int accNo;
    int pin;
    float balance;
    int isLocked;
};

int main() {
    FILE *fp = fopen("accounts.dat", "wb");

    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    struct Account a1 = {123456, 1234, 100000.0, 0};
    struct Account a2 = {111111, 1111, 50000.0, 0};
    struct Account a3 = {222222, 2222, 75000.0, 0};

    fwrite(&a1, sizeof(a1), 1, fp);
    fwrite(&a2, sizeof(a2), 1, fp);
    fwrite(&a3, sizeof(a3), 1, fp);

    fclose(fp);

    printf("accounts.dat file created successfully!\n");
    return 0;
}