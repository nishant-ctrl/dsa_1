// Write a program to take the names and roll numbers of n students as input from the user (taking n also
// as input from the user), and then ask the user to enter a roll number so that your program fetches the
// corresponding name of the student. First create the database of the students, and then accept the query
// from the user. The result of the query, i.e. the name of the student queried for, will be the final output of
// the program. Do not use any structures.
#include<stdio.h>
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
    char name[100][100];
    int roll[100];
    int search;
    printf("Enter how many details of students you want to enter: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        getchar();
        printf("Enter the name of student %d: " ,i+1);
        fgets(name[i] , 100 , stdin);
        remove_newline_character(name[i]);
        printf("Enter the roll number of student %d: " ,i+1);
        scanf("%d" ,&roll[i]);
    }
    printf("Enter the roll number of student to search: ");
    scanf("%d" ,&search);
    for(int i=0 ; i<n ; i++)
    {
        if(roll[i]==search)
        {
            printf("Name of the student: %s and Roll-%d" ,name[i] ,roll[i]);
            return 0;
        }
    }
    printf("Student not found in the database.");
    return 0;
}