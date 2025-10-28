#include<stdio.h>
int total_expense = 0;
int n;
int expense1[100];
char category[100][50];
int income1;
int income()
{   
    printf("Enter your monthly income:");
    scanf("%d",&income1);
    return income1;
}

int expense()
{
    printf("Enter the number of expense categories: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the category of your expense: ");
        scanf("%s", category[i]);
        printf("Enter the amount spent in %s: ", category[i]);
        scanf("%d", &expense1[i]);
        total_expense += expense1[i];
    }
    return total_expense;
    
}
int display()
{   printf("--------------------Financial Tracker--------------------\n");
    printf("Total Income: %d\n", income1);
    printf("Total Expense: %d\n", total_expense);
    printf("Remaining Balance: %d\n", income1 - total_expense);
}
int display1()
{    printf("--------------------Financial Summary--------------------\n");
    printf("Category\tExpense\n");
    for(int i=0;i<n;i++)
    {

        printf("%s\t\t%d\n",category[i],expense1[i]);
    }
}
int graph()
{   printf("---------------------Graph---------------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t",category[i]);
        printf("|");
        if (expense1[i]>=10000)
        {
        for(int j=0;j<expense1[i]/1000;j++)
        {  
            printf("#");
           
        }
        printf(" %d",expense1[i]);
        printf("\n");
    }
    else
    {for(int j=0;j<expense1[i]/1000;j++)
        {  
            printf("#");
           
        }
        printf(" %d",expense1[i]);
        printf("\n");}
    }
}
int main()
{
    printf("====================== Peronsal Finance Tracker =====================\n");
    income();
    expense();
    display();
    display1();
    graph();

    return 0;
}