//Swan Htet Thurein(U09364833)
//A program that determines if a string a user inputted is in order or not

#include <stdio.h>
#include <ctype.h>

char curr_char, prev_char, input;
int valid_input = 1;

//function that returns true or false depending on the order of the characters
int in_order(char curr_char){
    if (prev_char != '0' && prev_char > curr_char){
        valid_input = 0;
    }
    prev_char = curr_char;
    return valid_input;
}
int main(void){
    prev_char = '\0';
    printf("Enter input: ");
    //converting to lower case
    while ( (input = getchar()) != '\n'){//going through every character until the new line
        curr_char = tolower(input); //converting to lower case so that comparison is easier
        //input validation
        if (!isalpha(curr_char)){
            printf("invalid input");
            return 0; //exiting the program when the input contains a digit
        }
        in_order(curr_char); //calling function after input validation
    }
    //printing the result according to the function
    if (in_order(curr_char)){
        printf("in order\n");
    }
    else{
        printf("not in order\n");
    }
    return 0;
}
