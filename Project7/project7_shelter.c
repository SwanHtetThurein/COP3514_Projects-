//Swan Htet Thurein (U09364833)
//A program that reads data about animals from an input file, filters animals by user-specified species and gender, and saves matching animals in an output file.

#include <stdio.h> 
#include <string.h>

#define NAME_LEN 100
#define MAX_ANIMAL 200

struct Animal{
    char name[NAME_LEN + 1];
    char species[NAME_LEN + 1];
    char gender[NAME_LEN + 1];
    int  age;
    double weight; 
};

int main(){
    struct Animal animals[MAX_ANIMAL + 1]; //200 animals wih max length 100 each 
    struct Animal user_animal; //store user's input
    int num_animals = 0;

    FILE *file = fopen("animals.txt", "r");

    //File open validation 
    if(file == NULL){
       printf("Error opening the file!\n");
       return 1;
    }

    //Read each line as an animal 
    while(num_animals < MAX_ANIMAL && 
        fscanf(file, "%s %s %s %d %lf", animals[num_animals].name, 
                animals[num_animals].species, animals[num_animals].gender, 
                &animals[num_animals].age, &animals[num_animals].weight) == 5){
        num_animals++;
    }

    fclose(file);

    //Ask user input 
    printf("Enter species: ");
    scanf("%s", user_animal.species);
    printf("Enter gender: ");
    scanf("%s", user_animal.gender);

    //Open file to write(create one if there isn't one)
    FILE *output_file = fopen("results.txt", "w");
    //Output file validation 
    if (output_file == NULL){
        printf("Error creating output file!\n");
        return 1;
    }
    
    //Compare user input to file content and writing the matching ones to output file
    for (int i = 0; i < MAX_ANIMAL; i++){
        if(strcmp(user_animal.species, animals[i].species) == 0 && 
            strcmp(user_animal.gender, animals[i].gender) == 0){
            fprintf(output_file, "%s %d %.2lf\n", animals[i].name, animals[i].age, animals[i].weight);
        }
    }

    fclose(output_file);
    printf("Output file name: results.txt\n");

    return 0; 
}

