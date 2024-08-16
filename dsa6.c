// Write a program to take an array of strings as input from the user, and then modify the array such that
// all the strings in the array are reversed, without using any second array, i.e. you may use only one two-
// dimensional array in your program. Display the modified array of strings as the final output of your
// program. Reversing the string means to rearrange the characters of a string in the reverse order
// compared to the original string, i.e. reversing the string “computer” gives the resultant string as
// “retupmoc”.
#include <stdio.h>
void rev_str(char name[])
{
    char temp;
    int count=0;
    for(int i=0 ; name[i]!='\0' ; i++)
    {
        count++;
    }
    for(int j=0 ; j<=(count-1)/2 ; j++)
    {
        temp=name[j];
        name[j]=name[count-1-j];
        name[count-1-j]=temp;
    }
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
    char name[100][100];
    printf("How many details of students you want to enter: ");
    scanf("%d" ,&n);
    getchar();
    for(int i=0 ; i<n ; i++)
    {
        printf("Enter the name of student %d: " ,i+1);
        fgets(name[i] , 100 , stdin);
        remove_newline_character(name[i]);
    }
    printf("Original Array of strings: \n");
    for(int i=0 ; i<n ; i++)
    {
        printf("%s\n" ,name[i]);
    }
    for(int i=0 ; i<n ; i++)
    {
        rev_str(name[i]);
    }
    printf("Modified Array of strings: \n");
    for(int i=0 ; i<n ; i++)
    {
        printf("%s\n" ,name[i]);
    }
    return 0;
}