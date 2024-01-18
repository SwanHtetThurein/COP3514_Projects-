//Swan Htet Thurein (U09364833)
//A C program that checks if the command line argument is in order or not 

#include <stdio.h>
#include <ctype.h>

int inOrder(char *input);

int main(int argc, char *argv[])
{
    //Input Validation
    char *input = argv[1];
    for (int i = 0; input[i] != '\0'; i++){
        if (!isalpha(input[i])){
            printf("invalid input\n");
            return 0;
      }
    }
    if (argc != 2){
      printf("invalid input\n");
      return 0;
    }
    
    //Calling function
    int result = inOrder(argv[1]);
    
    //Print output 
    if (result == 1){
      printf("in order\n");
    }
    else {
      printf("not in order\n");
    }
    return 0;
}

int inOrder(char *input){
  char *p;
  int order = 1;
  for (p = input ; *(p+1) != '\0'; p++){
    if(*p > *(p+1)){//if it's not in order, return order = 0
      order = 0;
  }
  }
  return order;
}