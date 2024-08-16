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