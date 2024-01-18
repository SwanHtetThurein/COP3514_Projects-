//Description - a C program that calculates the total cost depending on the length of the rental of equipment
//Name - Swan Htet Thurein (U09364833)
#include <stdio.h>

void calculate_cost(int equipment, int days, int hours){
    int hour_rate = 0;
    int day_rate = 0, week_rate = 0, cost = 0;
    //Equipments and their rates
    if (equipment == 1){
        hour_rate = 7;
        day_rate = 10;
        week_rate = 40;
    }
    else if (equipment == 2){
        hour_rate = 27;
        day_rate = 39;
        week_rate = 156;
    }
    else if (equipment == 3){
        hour_rate = 61;
        day_rate = 87;
        week_rate = 348;
    }
    else if (equipment == 4){
        hour_rate = 59;
        day_rate = 84;
        week_rate = 336;
    }
    else{
        printf("Invalid selection. Select from 1 to 4.\n");
        return;
    }
    //calculating weekly rate
    cost += (days / 7) * week_rate;
    days %= 7; //number of days left

    //calculating day rate
    if (days >= 4) {
        cost += week_rate;
    }
    else{
        if (hours <= 4) {
            cost += hour_rate;
        } else {
            cost += day_rate;
        }
        cost += days * day_rate;
    }

    printf("Charge($): %d\n", cost);//printing the total cost
}


int main() {
    int equipment, days, hours;

    //asking equipment selection
    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection: ");
    scanf("%d", &equipment);
    if (equipment <= 0 || equipment > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        scanf("%d", &equipment);
        return 0;
    }

    //asking days and hours of the rental of the selected  equipment
     printf("Enter days: ");
     scanf("%d", &days);
     printf("Enter hours: ");
     scanf("%d", &hours);

     if (hours <= 0  || hours > 23) {
        printf("Invalid hours.");
        return 0;
     }

    calculate_cost(equipment, days, hours);
    return 0;
}

