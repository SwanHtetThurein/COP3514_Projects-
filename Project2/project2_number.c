#include <stdio.h>

int main(void){
    int number;
    printf("Enter input: ");
    scanf("%d", &number);

   //check if the number contains 3
   int i = number;
   int contains_3 = 0;
    for (i = number; i > 0; i /= 10) {
        int digit = i % 10;
        if (digit == 3) {
            contains_3 = 1;  // Set to true if a 3 is found
            break;
        }
    }
   /*
    while (i > 0) {
        int digit = i % 10;
        if (digit == 3) {
            contains_3 = 1;  // Set to true if a 3 is found
            break;
        }
        i /= 10;
    }
   */
    if (number % 3 == 0 && contains_3 == 1 ){
        printf("yes");
        return 0;
    }
    else{
        printf("no");
        return 0;
    }
}
