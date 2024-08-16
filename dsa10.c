// Write a program to declare a structure to represent a rectangle, and then find out the largest rectangle
// from a set of rectangles. Declare an array of structures where every instance of the array is a structure
// containing the length and breadth of a rectangle, where the length and breadth of n rectangles are taken
// as input from the user and stored in this array of structures (n is also taken as user input). Display the
// index number of the rectangle with the largest area as the final output of your program, i.e. if the m
// the entered rectangle is the largest, m should be the final output.
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