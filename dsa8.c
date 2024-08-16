#include <stdio.h>
struct emp
{
    char name[100];
    int age;
    float salary;
};
int main()
{
    int n;
    struct emp x[100];
    printf("How many employes to enter: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        getchar();
        printf("Enter name of employe %d : " ,i+1);
        fgets(x[i].name , 100 , stdin);
        printf("Enter age of employe %d : " ,i+1);
        
        scanf("%d" ,&x[i].age);
        printf("Enter salary of employe %d : " ,i+1);
        scanf("%f" ,&x[i].salary);
    }
    for(int i=0 ; i<n ; i++)
    {
        if(x[i].age>30 && x[i].salary>50000)
        {
            printf("Details of employe.\n");
            printf("Name: %s" ,x[i].name);
            printf("Age: %d\n" ,x[i].age);
            printf("Salary: %f\n" ,x[i].salary);
        }
    }
    return 0;
}    