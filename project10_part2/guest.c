#include "guest.h"
#include "read_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Add a new guest
struct guest *add_guest(struct guest *list)
{
  struct guest *new_guest = malloc(sizeof(struct guest)); // Dynamically allocate memory for the new guest

  printf("Enter phone number: "); // Ask phone number
  scanf("%s", new_guest->phone);

  // Guest phone number already exists
  for (struct guest *p = list; p != NULL; p = p->next)
  {
    if (strcmp(p->phone, new_guest->phone) == 0)
    {
      printf("guest already exists.");
      free(new_guest); // Free the allocated memory
      return list;     // Return list without adding anything new
    }
  }
  printf("Enter guest's last name: ");
  scanf("%s", new_guest->last);

  printf("Enter guest's first name: ");
  scanf("%s", new_guest->first);

  printf("Enter party size: ");
  scanf("%d", &(new_guest->party_size));

  // Make new guest the last node
  new_guest->next = NULL;
  if (list == NULL)
  {
    // If the list is empty, make new_guest the only node
    return new_guest;
  }
  else
  {
    // Otherwise, add the guest to the end of the linked list and return the pointer to the linked list
    struct guest *last = list;
    while (last->next != NULL)
    {
      last = last->next;
    }
    last->next = new_guest;
    return list;
  }
}

//Print all the guests from the list
void print_list(struct guest *list)
{
  while (list != NULL)
  {
    printf("%-15s%-20s%-20s%5d\n", list->phone, list->last, list->first, list->party_size);
    list = list->next;
  }
}

//Clear the whole guest list
void clear_list(struct guest *list)
{
  struct guest *p;
  while (list != NULL)
  {
    p = list;          // Assign current node to "p"(temporary variable)
    list = list->next; // Update list to the next node before freeing it
    free(p);
  }
}

//Remove a certain guest from the list 
struct guest *remove_guest(struct guest *list)
{
  char phone[PHONE_LEN + 1];
  char first[NAME_LEN + 1];
  char last[NAME_LEN + 1];

  //Ask User Input 
  printf("Enter phone number: ");
  scanf("%s", phone);
  printf("Enter guest's last name: ");
  scanf("%s", last);
  printf("Enter guest's first name: ");
  scanf("%s", first);

  struct guest *q = NULL;
  // Compare the user-inputted node with our node
  for (struct guest *p = list; p != NULL; q = p, p = p->next)
  {
    // Locate the node to be removed
    if (strcmp(p->phone,phone) == 0 &&
        strcmp(p->last,last) == 0 &&
        strcmp(p->first,first) == 0)
    {
      // Alter the previous node to bypass the removed node
      if (q == NULL)
      {
        return p->next;
      }
      else
      {
        q->next = p->next;
        return list;
      }
    }
  }

  // When guest does not exist
  printf("guest does not exist.");
  return list;
}
