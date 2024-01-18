// Swan Htet Thurein U09364833
// A guest-management program that adds, removes, prints and/or clear the guests' data(using linked lists and dynamic memory allocation)

#include "guest.h"
#include "read_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char code;
  struct guest *new_list = NULL;
  printf("Operation Code: a for adding to the list at the end, r for removing from the list, p for printing the list; q for quit.\n");
  for (;;)
  {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n') /* skips to end of line */
      ;
    switch (code)
    {
    case 'a':
      new_list = add_guest(new_list);
      break;
    case 'r':
      new_list = remove_guest(new_list);
      break;
    case 'p':
      print_list(new_list);
      break;
    case 'q':
      clear_list(new_list);
      return 0;
    default:
      printf("Illegal code\n");
    }
    printf("\n");
  }
}
