#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Expense {
    char category[50];
    int amount;
};

struct FinanceData {
    int income;
    int totalExpense;
    int n; 
    struct Expense expenses[100];
};


void data(struct FinanceData *fd);
void filesaving(struct FinanceData *fd);
void Income(struct FinanceData *fd);
void expenses(struct FinanceData *fd);
void display(struct FinanceData *fd);
void display1(struct FinanceData *fd);
void graph(struct FinanceData *fd);


void data(struct FinanceData *fd) {
    FILE *fp;
   
    fp = fopen("Finance.txt", "r+");
    if (fp == NULL) {
       
        fd->income = 0;
        fd->totalExpense = 0;
        fd->n = 0;
        printf("No previous data found. Starting fresh.\n");
        return;
    }

  
    fscanf(fp, "%d %d", &fd->income, &fd->n);

    fd->totalExpense = 0;
    for (int i = 0; i < fd->n; i++) {
        fscanf(fp, "%s %d", fd->expenses[i].category, &fd->expenses[i].amount);
        fd->totalExpense += fd->expenses[i].amount;
    }

    fclose(fp);
    printf("Data loaded successfully from file.\n");
}


void filesaving(struct FinanceData *fd) {
    FILE *fp = fopen("Finance.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open file for saving.\n");
        return;
    }

   
    fprintf(fp, "%d %d\n", fd->income, fd->n);

   
    for (int i = 0; i < fd->n; i++) {
        fprintf(fp, "%s %d\n", fd->expenses[i].category, fd->expenses[i].amount);
    }

    fclose(fp);
    printf("Data saved successfully to file.\n");
}


void Income(struct FinanceData *fd) {
    printf("Enter your monthly income: ");
    scanf("%d", &fd->income);
    printf("Income updated.\n");
}


void expenses(struct FinanceData *fd) {
    int more;
    do {
        if (fd->n >= 100) {
            printf("Maximum number of expenses reached.\n");
            return;
        }

        printf("Enter expense category name (no spaces): ");
        scanf("%s", fd->expenses[fd->n].category);

        printf("Enter amount spent in %s: ", fd->expenses[fd->n].category);
        scanf("%d", &fd->expenses[fd->n].amount);
        fd->totalExpense += fd->expenses[fd->n].amount;
        fd->n++;
        printf("Add another expense? (1 = Yes, 0 = No): ");
        scanf("%d", &more);
    } while (more == 1);
}


void display(struct FinanceData *fd) {
    printf("\n-------------------- Financial display --------------------\n");
    printf("Total Income        : %d\n", fd->income);
    printf("Total Expense       : %d\n", fd->totalExpense);
    printf("Remaining Balance   : %d\n", fd->income - fd->totalExpense);

    if (fd->income > 0) {
        float expensePercent = (fd->totalExpense * 100.0) / fd->income;
        printf("Expense %% of Income : %.2f%%\n", expensePercent);
        if (fd->totalExpense > fd->income) {
            printf("Warning: You have spent more than your income!\n");
        }
    }
}


void display1(struct FinanceData *fd) {
    printf("\n-------------------- Expense Details --------------------\n");
    if (fd->n == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("Category\tAmount\n");
    printf("-----------------------------\n");
    for (int i = 0; i < fd->n; i++) {
        printf("%-10s\t%d\n", fd->expenses[i].category, fd->expenses[i].amount);
    }
}


void graph(struct FinanceData *fd) {
    printf("\n-------------------- Expense Graph --------------------\n");
    if (fd->n == 0) {
        printf("No expenses to display.\n");
        return;
    }


    int max = 0;
    for (int i = 0; i < fd->n; i++) {
        if (fd->expenses[i].amount > max)
            max = fd->expenses[i].amount;
    }
    if (max == 0) {
        printf("All expenses are zero.\n");
        return;
    }

    for (int i = 0; i < fd->n; i++) {
        printf("%-10s | ", fd->expenses[i].category);

        int barLength = (fd->expenses[i].amount * 50) / max; // scaled to max 50 '#'
        if (barLength == 0 && fd->expenses[i].amount > 0)
            barLength = 1; 

        for (int j = 0; j < barLength; j++) {
            printf("#");
        }
        printf(" (%d)\n", fd->expenses[i].amount);
    }
}

int main() {
    struct FinanceData fd;
    int choice;

    printf("====================== Personal Finance Tracker =====================\n");

    
    data(&fd);

    while (1) {
        printf("\n-------------------------- MENU --------------------------\n");
        printf("1. Set / Update Income\n");
        printf("2. Add Expenses\n");
        printf("3. Show display\n");
        printf("4. Show Expense Details\n");
        printf("5. Show Graph\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Income(&fd);
                break;
            case 2:
                expenses(&fd);
                break;
            case 3:
                display(&fd);
                break;
            case 4:
                display1(&fd);
                break;
            case 5:
                graph(&fd);
                break;
            case 6:
                filesaving(&fd);
                printf("Exiting program.\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}