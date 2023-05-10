// What day is today ?
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// convert day in string to number
int dayToNum(char* day) {
    if (strcmp(day, "Monday")==0) {
        return 1;
    }
    else if (strcmp(day, "Tuesday")==0) {
        return 2;
    }
    else if (strcmp(day, "Wednesday")==0) {
        return 3;
    }
    else if (strcmp(day, "Thirsday")==0) {
        return 4;
    }
    else if (strcmp(day, "Friday")==0) {
        return 5;
    }
    else if (strcmp(day, "Saturday")==0) {
        return 6;
    }
    else
        return 7;
    
}

// convert day in number to day in string
char* numToDay(int day) {
    if (day == 1) {
        return "Monday";
    }
    else if (day == 2) {
        return "Tuesday";
    }
    else if (day == 3) {
        return "Wednesday";
    } 
    else if (day == 4) {
        return "Thursday";
    }
    else if (day == 5) {
        return "Friday";
    }
    else if (day == 6) {
        return "Saturday";
    }
    else {
        return "Sunday";
    }
    
}

int main()
{
    int y = 0, d = 0;
    char* dString;
    dString = (char*)malloc(sizeof(char)*100);

    int leap_year = 0; // 0: not leap_year, 1: leap_year
    int numbers_of_data = 0;
    int flag = 0; // 0: input is not wrong, 1: input is wrong
    int month = 0, date = 0;
    int days;
    printf("Input the year and the first day of the year:\n");

    printf("Year: ");
    scanf("%d", &y);
    printf("First day of the year(ex: Monday, Tuesday or ...): ");
    scanf("%s", dString);
    d = dayToNum(dString);

    // leap_year or not
    if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
    {
        leap_year = 1; // leap year
    }

    // input numbers of data
    printf("Input the numbers of data: ");
    scanf("%d", &numbers_of_data);

    // calculate every inpute line
    for (int i = 0; i < numbers_of_data; i++)
    {
        flag = 0; // flag initialization
        days = 0; // days initialization

        // Relatively input the month and date
        printf("Input the month and date:\n");
        printf("Month: ");
        scanf("%d", &month);
        printf("Date: ");
        scanf("%d", &date);
        days = date; // give input date to variable days

        // Prevent the user to input the wrong data
        // if user input wrong date or month, assigned 1 to flag
        if (month < 1 || month > 12)
        {
            printf("month is wrong\n");
            flag = 1;
        }

        if (date < 1)
        {
            printf("date is wrong\n");
            flag = 1;
        }
        else
        {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (date > 31)
                {
                    printf("date is wrong\n");
                    flag = 1;
                }
                break;
            case 2:
                if ((leap_year == 1 && date > 29) ||
                    (leap_year == 0 && date > 28))
                {
                    printf("date is wrong\n");
                    flag = 1;
                }
                break;
            default:
                if (date > 30)
                {
                    printf("date is wrong\n");
                    flag = 1;
                }
            } // end of switch
        }// end of else

        // calculate the input data
        for (int m = 1; m < month; m++)
        {
            switch (m)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                days += 31;
                break;
            case 2:
                if (leap_year == 1)
                {
                    days += 29;
                }
                else
                {
                    days += 28;
                }
                break;
            default:
                days += 30;
            } // end of switch
        }     // end of for loop

        days += d - 1; // plus the first "day" with days, and print the final answer

        // print the day
        if (flag != 1)
        {
            int holder = days % 7;
            char* result = (char*)malloc(sizeof(char)*100);
            result = numToDay(holder);
        
            printf("Case #%d: %s\n", i + 1, result);
        }

    } // end of for loop which calculate every input line

    return 0;

} // end of main