/*
 * Swan Htet Thurein (U09364833)
 * A program that creates exclusive elements from two arrays, merges them into an array and printing them
 * using a function that uses pointer arithmetic
 */
#include <stdio.h>

void exclusive_or(int *a, int n1,  int *b, int n2, int *c, int *size){
    int *p, *q;
    *size = 0;
    //Check the first array for common elements
    for (p = a; p < a + n1; p++){
        int found = 0;
        for (q = b; q < b + n2; q++){
            if (*p == *q){
                found = 1;
                break;
            }
        }
        //Add the exclusive elements to array c, simultaneously increasing its size
        if (found == 0){
            *c++ = *p;
            (*size)++;
        }
    }

    //Check the second array for common elements
    for (q = b; q < b + n2; q++){
        int found = 0;
        for (p = a; p < a + n1; p++){
            if (*q == *p){
                found = 1;
                break;
            }
        }
        if (found == 0) {
            *c++ = *q;
            (*size)++;
        }
    }
}

int main(){
    int n1;
    printf("Enter length of array #1: ");
    scanf("%d", &n1);

    int array1[n1];
    printf("Enter array elements: ");
    for (int i = 0; i < n1; i++){
        scanf("%d", &array1[i]);
    }

    int n2;
    printf("Enter length of array #2: ");
    scanf("%d", &n2);

    int array2[n2];
    printf("Enter array elements: ");
    for (int i = 0; i < n2; i++){
        scanf("%d", &array2[i]);
    }

    int size = n1 + n2;//Size of array 3 is the total of the other two
    int array3[size];

    //Call the void function(no need to assign variables)
    exclusive_or(array1, n1, array2, n2, array3, &size);


    printf("Output: ");
    for (int i = 0; i < size; i++) {
        printf(" %d", array3[i]);
    }
    return 0;
}
