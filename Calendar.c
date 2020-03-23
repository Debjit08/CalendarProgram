#include <stdio.h>
int Months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char* Days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int WeekDay(int,int,int,int);
int IsLeapYear(int);
void PrintCalendar(int,int,int);

int main()
{
    int d,m,y=2020,day_index;
    char ch;
    printf("Enter ur DOB(dd-mm) : ");
    scanf("%d-%d",&d,&m);
    if(IsLeapYear(y))
        Months[1]=29;
    while(1)
    {
        printf("enter its weekday: ");
        scanf("%d",&day_index);
        printf("ok..\nIt is a %s.(y/n)",Days[day_index]);
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
            break;
    }
    //printf("\n%d",day_index);
    day_index +=770000;
    //printf("\n%d",day_index);
    day_index=WeekDay(d,m-1,y,day_index);
    printf("It's a %s",Days[day_index]);
    
    


    return 0;
}

// correction for leap year
int IsLeapYear(int y)
{
    if (y%4==0&&(y%100!=0||y%400==0))
        return 1;
    else
        return 0;
}

int WeekDay(int day,int month,int year,int day_index)
{
    int i,row;
    day_index =day_index -(day-1);
    for(i=(month-1);i>=0;i--)
    {
        day_index = day_index -Months[i];
    }
    Months[1]=28;
    printf("Enter the date where u want to jump(dd-mm-yyyy): ");
    scanf("%d-%d-%d",&day,&month,&year);
    if(year>2020)
    {
        for(i=2020;i<year;i++)
        {
            if(IsLeapYear(i))
                day_index = day_index + 366;
            else
                day_index = day_index + 365;
            
        }
    }
    else if(year<2020)
    {
        for(i=2020-1;i>=year;i--)
        {
            if(IsLeapYear(i))
                day_index = day_index - 366;
            else
                day_index = day_index - 365;
            
        }

    }
    if(IsLeapYear(year))
        Months[1]=29;
    for(i=0;i<month-1;i++)
        day_index=day_index+Months[i];
    row = (Months[month-1]+(day_index)%7+6) / 7;
    //printf("\nNo. of rows needed: %d.\n",row);
    PrintCalendar(day_index%7,month,row);
    day_index= day_index + (day-1);
    day_index = day_index % 7;
    return (day_index);    
}

void PrintCalendar(int index,int month,int row)
{
    int i,j,k=1;
    char M[12][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    printf("\nAnd the month is: %s.",M[month-1]);
    printf("\n-----------------------------------------------------------------\n\t");
    for(i=0;i<7;i++)
        printf("%s ",Days[i]);
    printf("\n-----------------------------------------------------------------\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<7;j++)
        {
            if(k>Months[month-1]||(i==0&j<index))
                printf(" \t");
            else
                printf("\t%d",k++);
        }
        printf("\n");
    }
    printf("\n-----------------------------------------------------------------\n");

}