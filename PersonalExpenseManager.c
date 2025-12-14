#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure
typedef struct {
    char category[50];
    float amount;
} Expense;

void addExpense() {
    FILE *fp = fopen("expenses.txt", "a"); // Opens file in append mode
    Expense e;

    printf("Enter Category (example like: Food, Transport..): ");
    scanf("%s", e.category);
    printf("Enter Amount: ");
    scanf("%f", &e.amount);

    // Save to file in a simple format: Category Amount
    fprintf(fp, "%s %.2f\n", e.category, e.amount);
    fclose(fp);
    printf("Expense saved!\n");
}

void viewExpenses() {
    FILE *fp = fopen("expenses.txt", "r");
    char cat[50];
    float amt;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Expense History ---\n");
    // Scan the file until the end
    while (fscanf(fp, "%s %f", cat, &amt) != EOF) {
        printf("Category: %-15s | Cost: $%.2f\n", cat, amt);
    }
    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Add Expense\n2. View Expenses\n3. Exit\nChoose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
