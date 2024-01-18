//Swan Htet Thurein ( U09364833 )
//a program that calculates the active seconds of an escalator using pointer arithmetic
#include <stdio.h>

int active_seconds(int arrival[],int n){
    int seconds = 0;
    int *p;
    for (p = arrival; p < arrival + n - 1; p++){
        if (*(p+1) - *p > 10){//when the arrival time is greater than 10 seconds
            seconds += 10;
        }
        else if (*(p+1) - *p <= 10){//when the arrival time is less than or equal to 10 seconds
            seconds += *(p+1) - *p;
        }
    }
    return seconds + 10;
}

int main(){
    int people, i;

    printf("Enter number of people: ");
    scanf("%d", &people);

    int arrival_times[people];
    //creating an array of arrival times
    printf("Enter arrival times: ");
    for (i = 0; i < people; i++){
        scanf("%d", &arrival_times[i]);
    }
    //calling the function and printing
    int seconds = active_seconds(&arrival_times, people);
    printf("Active seconds: %d", seconds);
    return 0;
}