#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNumber;
    char name[50];
    float balance;
};

struct Account accounts[100];
int totalAccounts = 0;

// Function Prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayAccounts();
void menu();

int main() {
    menu();
    return 0;
}

// Menu Function
void menu() {
    int choice;
    while (1) {
        printf("\n\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAccounts();
                break;
            case 6:
                printf("Exiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to create an account
void createAccount() {
    struct Account acc;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", acc.name);
    acc.balance = 0;
    
    accounts[totalAccounts++] = acc;
    printf("Account created successfully!\n");
}

// Function to deposit money
void depositMoney() {
    int accNum, i;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (i = 0; i < totalAccounts; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Amount Deposited Successfully!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    int accNum, i;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (i = 0; i < totalAccounts; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal Successful!\n");
            } else {
                printf("Insufficient Balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to check balance
void checkBalance() {
    int accNum, i;
    printf("\nEnter Account Number: ");
    scanf("%d", &accNum);

    for (i = 0; i < totalAccounts; i++) {
        if (accounts[i].accNumber == accNum) {
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to display all accounts
void displayAccounts() {
    int i;
    if (totalAccounts == 0) {
        printf("\nNo accounts available!\n");
        return;
    }

    printf("\nAccount Details:\n");
    printf("-------------------------------------------------\n");
    printf("Acc Number\tHolder Name\tBalance\n");
    printf("-------------------------------------------------\n");

    for (i = 0; i < totalAccounts; i++) {
        printf("%d\t\t%s\t\t%.2f\n", accounts[i].accNumber, accounts[i].name, accounts[i].balance);
    }
    printf("-------------------------------------------------\n");
}