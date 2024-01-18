//A program that calculates the number of seconds the elevator was active
//Swan Htet Thurein (U09364833)
#include <stdio.h>

int active_seconds(int arrival[], int n){
    int i;
    int seconds = 0;
    for (i = 0; i < n-1; i++){
        //when arrival time difference is more than 10 sec
        if ((arrival[i+1] - arrival[i]) > 10){
            seconds += 10;
        }
        //when it's less than equal to 10
        else if (arrival[i+1] - arrival[i] <= 10){
            seconds += arrival[i+1] - arrival[i];
        }
    }
    return seconds + 10;
}
int main(){
    int num_people, final_result;

    //asking number of people
    printf("Enter number of people: ");
    scanf("%d", &num_people);

    //declaring the array after knowing its length
    int arrival_times[num_people];

    //asking for input of array elements, in this case arrival times
    printf("Enter arrival times: ");
    int i;
    for(i = 0; i < num_people; i++){
        scanf("%d", &arrival_times[i]);
    }

    //calling function
    final_result = active_seconds(arrival_times, num_people);
    printf("Active seconds: %d", final_result);
}