#include<stdio.h>
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
    char name[100][100];
    printf("Enter how many names of students you want to enter: ");
    scanf("%d" ,&n);
    getchar();
    for(int i=0 ; i<n ; i++)
    {
        
        printf("Enter the name of student %d: " ,i+1);
        fgets(name[i] , 100 , stdin);
        remove_newline_character(name[i]);
    }
    for(int i=0 ; i<n ; i++)
    {
        printf("%s : %d\n" , name[i] ,len_name(name[i]));
    }
    return 0;
}