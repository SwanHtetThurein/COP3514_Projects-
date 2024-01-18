//Swan Htet Thurein U09364833
//A guest-management program that adds, prints and/or clear the guests' data(using linked lists and dynamic memory allocation)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30
#define PHONE_LEN 20

struct guest{
	char phone[PHONE_LEN+1];
	char last[NAME_LEN+1];
	char first[NAME_LEN+1];
	int party_size;
	struct guest *next;
};


struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);


int main(void)
{
  char code;

  struct guest *new_list = NULL;  
  printf("Operation Code: a for adding to the list at the end, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = add_guest(new_list);
                break;
      case 'p': print_list(new_list);
                break;
      case 'q': clear_list(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct guest *add_guest(struct guest *list)
{
    struct guest *new_guest = malloc(sizeof(struct guest));//Dynamically allocate memory for the new guest 
    
    printf("Enter phone number: ");//Ask phone number 
    scanf("%s", new_guest-> phone);
    
    //Guest phone number already exists 
    for (struct guest *p = list; p != NULL; p = p -> next)
    {
        if (strcmp(p->phone, new_guest->phone) == 0){ 
            printf("guest already exists.");
            free(new_guest);//Free the allocated memory 
            return list; //Return list without adding anything new 
        }
    }
    printf("Enter guest's last name: ");
    scanf("%s", new_guest->last);

    printf("Enter guest's first name: ");
    scanf("%s", new_guest->first);

    printf("Enter party size: ");
    scanf("%d", &(new_guest->party_size));
   
    //Make new guest the last node 
    new_guest->next = NULL;
    if (list == NULL){
         //If the list is empty, make new_guest the only node
        return new_guest;
    }
    else{
        //Otherwise, add the guest to the end of the linked list and return the pointer to the linked list
        struct guest *last = list; 
        while(last->next != NULL){
            last = last->next;
        } 
        last->next = new_guest;
        return list; 
    }
}


void print_list(struct guest *list)
{
    while (list != NULL) {
        printf("%-15s%-20s%-20s%5d\n", list->phone, list->last, list->first, list->party_size);
        list = list->next;
    }
}

void clear_list(struct guest *list)
{
    struct guest *p;
    while (list != NULL){
        p= list; //Assign current node to "p"(temporary variable)
        list = list -> next; //Update list to the next node before freeing it
        free(p);
    }
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
