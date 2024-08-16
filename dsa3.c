// Write a program to declare a structure, with the tag student, which contains three variables: i) name,
// which can store a string, ii) marks, which can store a fraction, and iii) length, which can store an
// integer. Take the values of name and marks from the user, and then calculate the length of name and
// store it in length. Display all three values as the final output of your program.
#include <stdio.h>
struct student
{
    char name[100];
    float marks;
    int length;
};
int len_name(char name[])
{
    int size=0;
    for(int i=0 ; name[i]!='\0' ; i++)
    {
        size++;
    }
    return size;
}
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
    printf("Enter how many names of students you want to enter: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        getchar();
        printf("Enter the name of student %d: " ,i+1);
        fgets(stud[i].name , 100 , stdin);
        remove_newline_character(stud[i].name);
        printf("Enter the marks of student %d : " ,i+1);
        scanf("%f" ,&stud[i].marks);
        stud[i].length=len_name(stud[i].name);
    }
    for(int i=0 ; i<n ; i++)
    {
        printf("Name: %s , Marks: %f , Length: %d\n" ,stud[i].name , stud[i].marks , stud[i].length);
    }
    return 0;
}