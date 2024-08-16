#include <stdio.h>
struct rectangle
{
    float length;
    float breadth;
};
int main()
{
    int n;
    struct rectangle x[100];
    printf("How many rectangles to enter: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        printf("Enter length of rectangle %d : " ,i+1);
        scanf("%f" ,&x[i].length);
        printf("Enter breadth of rectangle %d : " ,i+1);
        scanf("%f" ,&x[i].breadth);
    }
    float area=0;
    int count=0;
    for(int i=0 ; i<n ; i++)
    {
        if(x[i].length * x[i].breadth >=area)
        {
            area=x[i].length * x[i].breadth;
            count=i+1;
        }
    }
    printf("Largest area is %f and is at position %d." ,area,count);
    return 0;
}