//Swan Htet Thurein(U09364833)
//A program that compresses the user's string using only pointer arithmetic, not array subscripting

#include <stdio.h>

void compress (char *input, char *output);

int main (){
  char input[1001];
  char output[1001];

  printf ("Enter message: ");
  scanf ("%s", input);

  //Call function and print the result 
  compress (input, output);
  printf ("Output: %s\n", output);

  return 0;
}

void compress (char *input, char *output){
  char *p, *q;
  p = input;
  q = output;
  int counter = 1;
  for (; *p != '\0'; p++){
      if (*p == *(p+1)){//Keep track of the number of times a character repeats 
          counter ++; 
      }
      else{
        if (counter > 2){ 
            *q++ = '0' + counter;//Convert the "int" value of counter to "char"
         }
         else if (counter == 2){ //Case where compression is useless 
             *q++ = *p;
         }
         *q++ = *p; //Assign each character to the output variable 
         counter = 1;//Reset counter for later characters 
      }
  }
  *q = '\0';
}