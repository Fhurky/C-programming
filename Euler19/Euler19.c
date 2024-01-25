#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year){
    if(year % 4 != 0){
        return 0; // Not a leap year
    }else if(year % 100 != 0){
        return 1; // Leap year
    }else if(year % 400 != 0){
        return 0; // Not a leap year
    }else{
        return 1; // Leap year
    }
}

// Function to count Sundays on the first day of the month
int countSundaysOnFirstOfMonth(){
    int sundaysCount = 0;
    int year, month;
    // January 1, 1901 was a Tuesday (days since Sunday: 2)
    int daysSinceSunday = 2;

    for(year = 1901; year<=2000; year++){
        for(month = 1; month <= 12; month++){
            // Check if the first day of the month is a Sunday
            if (daysSinceSunday % 7 == 0){
                sundaysCount++;
            }
            // Update days since Sunday for the next month
            switch (month){
                case 4:
                case 6:
                case 9:
                case 11:
                    daysSinceSunday += 30;
                    break;
                case 2:
                    daysSinceSunday += isLeapYear(year) ? 29 : 28;
                    break;
                default:
                    daysSinceSunday += 31;
                    break;
            }
        }
    }

    return sundaysCount;
}

int main(){
    int result = countSundaysOnFirstOfMonth();
    printf("Number of Sundays falling on the first day of the month: %d\n", result);

    return 0;
}

