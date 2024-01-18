//Swan Htet Thurein U09364833
//Macros definition, struct definitions and prototypes of functions 

#ifndef GUEST
#define GUEST

//Define Macros
#define NAME_LEN 30
#define PHONE_LEN 20

//Define the struct guest 
struct guest
{
  char phone[PHONE_LEN + 1];
  char last[NAME_LEN + 1];
  char first[NAME_LEN + 1];
  int party_size;
  struct guest *next;
};

//Function Prototypes
struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);
struct guest *remove_guest(struct guest *list);

#endif