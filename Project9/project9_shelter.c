//Swan Htet Thurein (U09364833)
//A program that reads data about animals from an input file, sorts them using qsort and write the sorted data to an output file 

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 100
#define MAX_ANIMAL 200

struct Animal{
    char name[NAME_LEN + 1];
    char species[NAME_LEN + 1];
    char gender[NAME_LEN + 1];
    int  age;
    double weight; 
};

//Functions to compare animals 
int compare_animals(const void *a, const void *b){
    const struct Animal *animal_a = (const struct Animal *)a;//Typecast a to struct animal
    const struct Animal *animal_b = (const struct Animal *)b;//Typecase b to struct animal 

    //Compare the animals by Species
    int compare_species = strcmp(animal_a->species, animal_b->species);
    if (compare_species != 0){
        return compare_species;
    }
    //Compare by age if Species is the same 
    return animal_a->age - animal_b->age;
}

int main(){
    struct Animal animals[MAX_ANIMAL + 1]; //200 animals wih max length 100 each 
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

    fclose(file);//Close the input file 

    //Open file to write(create one if there isn't one)
    FILE *output_file = fopen("results.txt", "w");
    //Output file validation 
    if (output_file == NULL){
        printf("Error creating output file!\n");
        return 1;
    }
    //q sort function
    qsort(animals, num_animals, sizeof(struct Animal), compare_animals);
    //Write the sorted data to results.txt
    for (int i = 0; i < num_animals; i++){
        fprintf(output_file, "%s ", animals[i].species);
        fprintf(output_file, "%d ", animals[i].age);
        fprintf(output_file, "%s ", animals[i].name);
        fprintf(output_file, "%.2lf ", animals[i].weight);
        fprintf(output_file, "%s\n", animals[i].gender);
    }

    fclose(output_file);//Close the output file
    printf("Output file name: results.txt\n");

    return 0; 
}
