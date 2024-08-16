#include <stdio.h>
int main()
{
    int a,b;
    int mat[100][100];
    printf("Enter the size of Matrix in the form a x b : ");
    scanf("%d%d" ,&a, &b);
    for(int i=0 ; i<a ; i++)
    {
        for(int j=0 ; j<b ; j++)
        {
            printf("Enter element at [%d][%d] : " ,i+1,j+1);
            scanf("%d" ,&mat[i][j]);
        }
    }
    int sum=0;
    for(int i=0 ; i<a ; i++)
    {
        for(int j=0 ; j<b ; j++)
        {
            sum=sum+mat[i][j];
        }
    }
    printf("Sum of all elements : %d" ,sum);
    return 0;
}