#include <stdio.h>
int add_odds(int odd[100] , int n)
{
    if(n>=0)
    {
        if(odd[n-1]%2!=0)
        {
            return odd[n-1] + add_odds(odd,n-1);
        }
        else
        {
            return 0 + add_odds(odd,n-1);
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    int odd[100];
    printf("How many numbers to enter: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        printf("Enter element %d: " ,i+1);
        scanf("%d" ,&odd[i]);
    }
    int sum=add_odds(odd,n);
    printf("Sum of all odds: %d" ,sum);
    return 0;
}