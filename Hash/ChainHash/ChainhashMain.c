#include <string.h>
#include <stdio.h>
#include "Chainhash.h"
#include "Member.h"

typedef enum menu
{
  ADD_NODE = 1,
  DELETE_NODE,
  SEARCH,
  PRINT_TABLE,
  TERMINATE
} Menu;

Menu ScanMenu()
{
  int menu;
  printf("============<SELECT THE MENU THAT YOU WANT TO DO>============\n");
  printf("(1) ADDING NEW NODE     (2) DELETING NODE\n");
  printf("(3) SEARCHING THE NODE  (4) PRINTING HASHTABLE\n");
  printf("(5) TERMINATE PROGRAM\n");
  printf("MENU : ");
  scanf("%d", &menu);
  while (menu > 5)
  {
    printf("MENU : ");
    scanf("%d", &menu);
  }
  printf("=============================================================\n\n");
  return menu;
}

int main(void)
{
  Menu menu;         /* menu enum integer */
  Member new_member; /* member */
  ChainHash ch;      /* ChainHash */
  char name[20];
  int size;   /* integer that contains the size of the hashtable */
  int status; /* status value that contains the result value of add, delete function */

  printf("Input the size of HashTable : ");
  scanf("%d", &size);
  Initialize(&ch, size); /* Initializing the hashtable using the input size */
  printf("Initializing the HashTable is complete!\n");
  printf("\n\n");

  /* selecting the menu that you want to do */
  do
  {
    menu = ScanMenu();
    switch (menu)
    {
    case ADD_NODE:
      new_member = ScanMember("ADD", MEMBER_NAME | MEMBER_NO);
      status = Add(&ch, new_member);
      if (status)
      {
        printf("TRYING TO ADD NODE IS FAILURE; TRY AGAIN\n\n");
      }
      break;
    case DELETE_NODE:
      new_member = ScanMember("DELETE", MEMBER_NAME);
      status = Delete(&ch, new_member.name);
      if (status)
      {
        printf("DELETE PROCESS IS FAILED; THE NAME YOU INPUT DOES NOT EXIST\n\n");
      }
      else
      {
        printf("DELETE PROCESS IS DONE!\n\n");
      }
      break;
    case SEARCH:
      new_member = ScanMember("DELETE", MEMBER_NAME);
      status = Search(&ch, new_member.name);
      if (status >= 0)
      {
        printf("THIS MEMBER EXISTS AT KEY #%d\n\n", status);
      }
      else
      {
        printf("SEARCH IS FAILED; THE NAME YOU INPUT DOES NOT EXIST\n\n");
      }
      break;
    case PRINT_TABLE:
      PrintHash(&ch);
      break;
    case TERMINATE:
      Terminate(&ch);
      printf("The Chain HashTable is removed\n\n");
      break;
    default:
      break;
    }
  } while (menu != TERMINATE);

  return 0;
}
