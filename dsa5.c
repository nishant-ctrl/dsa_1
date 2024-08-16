// Solve the same problem given in Question no. 2 above, but by using an array of structures where each
// instance of the structure will contain the name and roll number of a student. As in Question no. 2, the
// name of the student queried for will be the final output of the program.
#include<stdio.h>
struct student
{
    char name[100];
    int roll;
};
void remove_newline_character(char name[])
{
    for(int i=0 ; name[i]!='\0' ; i++)
    {
        if(name[i]=='\n')
        {
            name[i]=name[i+1];
            break;
        }
    }
}
int main()
{
    int n;
    struct student stud[100];
    int search;
    printf("Enter how many details of students you want to enter: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        getchar();
        printf("Enter the name of student %d: " ,i+1);
        fgets(stud[i].name , 100 , stdin);
        remove_newline_character(stud[i].name);
        printf("Enter the roll number of student %d: " ,i+1);
        scanf("%d" ,&stud[i].roll);
    }
    printf("Enter the roll number of student to search: ");
    scanf("%d" ,&search);
    for(int i=0 ; i<n ; i++)
    {
        if(stud[i].roll==search)
        {
            printf("Name of the student: %s and Roll-%d" ,stud[i].name ,stud[i].roll);
            return 0;
        }
    }
    printf("Student not found in the database.");
    return 0;
}