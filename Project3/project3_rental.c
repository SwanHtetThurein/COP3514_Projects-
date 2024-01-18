//Description - a C program that calculates the total cost depending on the length of the rental of equipment
//Name - Swan Htet Thurein (U09364833)

#include <stdio.h>

void calculate_cost(int equipment, int days, int hours){
    int cost = 0;
    int rates[3];

    //Equipments and their rates
    if (equipment == 1){
        rates[0] = 7; //rates[0] == 4 hour rate
        rates[1] = 10;//rates[1] == day_rate
        rates[2] = 40;//rates[2] == week_rate
    }
    else if (equipment == 2){
        rates[0] = 27;
        rates[1] = 39;
        rates[2] = 156;
    }
    else if (equipment == 3){
        rates[0] = 61;
        rates[1] = 87;
        rates[2] = 348;
    }
    else if (equipment == 4){
        rates[0] = 59;
        rates[1] = 84;
        rates[2] = 336;
    }
    else{
        printf("Invalid selection. Select from 1 to 4.\n");
        return;
    }
    //calculating weekly rate
    cost += (days / 7) * rates[2]; //rates[2] == weekly_rate
    days %= 7; //number of days left

    //calculating day rate
    if (days >= 4) {
        cost += rates[2];
    }
    else{
        if (hours <= 4) {
            cost += rates[0]; //rates[0] == 4hour rate
        } else {
            cost += rates[1]; //rates[1] == day_rate
        }
        cost += days * rates[1];
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


