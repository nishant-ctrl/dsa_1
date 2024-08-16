// Write a program to declare an array of structures, where each element of the array is a structure
// containing three variables, name, marks, and length, similar to Question no. 3 above. Take the names
// and marks of a class of n students as input from the user (taking n also as input from the user), and then
// store these n sets of data in the array of structures declared earlier, using the variable name to store
// names and the variable marks to store marks. Calculate and store the length of each name in the
// variable length. Display the following as the final output of your program: i) the longest name, ii) the
// shortest name, iii) the highest marks along with the corresponing student’s name, iv) the lowest marks
// along with the corresponding student’s name, v) the average marks of the whole class, and vi) the
// number of students who have passed if pass marks is 40.
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
    int max_len=stud[0].length , max_len_index=0;
    int min_len=stud[0].length , min_len_index=0;
    float highest_marks=stud[0].marks , lowest_marks=stud[0].marks;
    int highest_marks_index=0 , lowest_marks_index=0;
    int passed_student=0;
    float total_marks=0 ,avg_marks=0;
    for(int i=0 ; i<n ; i++)
    {
        if(max_len<=stud[i].length)
        {
            max_len=stud[i].length;
            max_len_index=i;
        }
        if(min_len>=stud[i].length)
        {
            min_len=stud[i].length;
            min_len_index=i;
        }
        if(highest_marks<=stud[i].marks)
        {
            highest_marks=stud[i].marks;
            highest_marks_index=i;
        }
        if(lowest_marks>=stud[i].marks)
        {
            lowest_marks=stud[i].marks;
            lowest_marks_index=i;
        }
        if(stud[i].marks>=40)
        {
            passed_student++;
        }
        total_marks+=stud[i].marks;
    }
    avg_marks=total_marks/n;
    printf("Longest Name: %s\n" ,stud[max_len_index].name);
    printf("Shortest Name: %s\n" ,stud[min_len_index].name);
    printf("Highest marks: %f is of student %s\n" ,highest_marks , stud[highest_marks_index].name);
    printf("Lowest marks: %f is of student %s\n" ,lowest_marks , stud[lowest_marks_index].name);
    printf("Average marks of the whole class : %f\n" ,avg_marks);
    printf("Total number of passed students : %d\n" ,passed_student);
    return 0;
}