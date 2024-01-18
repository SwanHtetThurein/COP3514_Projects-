#include <stdio.h>
#include <string.h>

void decode(char words[][101], int num_words, char *result);

int main(){
    char file_name[101];
    char decoded_file_name[101];
    char words[1001][101];
    int num_words = 0;

    //Ask input file name 
    printf("Enter the file name: ");
    scanf("%100s", file_name); 

    FILE *file = fopen(file_name, "r");
    //Input file name validation and Closing
    if (file == NULL){
        printf("Error opening the file. \n");
        return 1; //Give an error if the file doesn't exist 
    }
    //Read every word in the input file
    while (fscanf(file, "%100s", words[num_words]) == 1){
        num_words++;
    }
    fclose(file);

    //Call function that puts each word into an array and put decoded_ in front of the new file
    decode(words, num_words, decoded_file_name);
    
    FILE *decoded_file = fopen(decoded_file_name, "w");
    //Decoded file name validation
    if (decoded_file == NULL){
        printf("Error making the output file. \n");
        return 1;
    }

    //Write the first letter of every word to the new file
    for (int i = 0; i < num_words; i++){
        fprintf(decoded_file, "%c", words[i][0]);
    }

    //Close the decoded file
    fclose(decoded_file);
    printf("Output file name: %s\n",decoded_file_name);

    return 0;
}

void decode(char words[][101], int num_words, char *result){
    strcpy(result, "decoded_");
    strcat(result, file_name);
}