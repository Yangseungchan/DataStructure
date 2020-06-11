#include <stdio.h>
#include "PriorityQueue.h"

typedef enum menu
{
  ENQUEUE = 1,
  DEQUEUE,
  PRINTHEAP,
  ISEMPTY,
  ISFULL,
  CLEAR
} Menu;

Menu ScanMenu()
{
  Menu menu;

  printf("============<SELECT THE MENU THAT YOU WANT TO DO>============\n\n");

  printf("(1) ENQUEUE             (2) DEQUEUE\n");
  printf("(3) PRINTING HEAP       (4) CHECKING EMPTINESS\n");
  printf("(5) CHECKING FULLNESS   (6) TERMINATE\n\n");

  printf("MENU : "); scanf("%d", &menu);

  while (menu > 6) /* if input menu is out of given menu, menu is scanned continually */
  {
    printf("MENU : "); scanf("%d", &menu);
  }
  printf("\n\n");
  printf("=============================================================\n\n");
  return menu;
}

int main(void)
{
    Menu menu;
    HData data;
    PrQueue Prq;
    InitPrQ(&Prq);

    do
    {
      menu = ScanMenu();
      switch(menu)
      {
        case ENQUEUE:
          if(IsFull(&Prq))
          {
            printf("Priority Queue is full; Failed to enqueue\n\n\n");
          }
          else
          {
            printf("Input the data that you want to enqueue(ONE CHARACTER) : ");
            scanf(" %c", &data);
            Enqueue(&Prq, data);
          }
          printf("\n\n\n");
          break;

        case DEQUEUE:
          if(IsEmpty(&Prq))
          {
            printf("Priority Queue is empty; Failed to dequeue\n\n\n");
          }
          else
          {
            printf("Dequeued data : %c\n\n\n\n", Dequeue(&Prq));
          }
          break;

        case PRINTHEAP:
          PrintPrQ(&Prq);
          printf("\n\n\n");
          break;

        case ISEMPTY:
          if(IsEmpty(&Prq)){
            printf("Queue is empty\n");
          }
          else{
            printf("Queue is not empty\n");
          }
          printf("\n\n\n");
          break;

        case ISFULL:
          if(IsFull(&Prq)){
            printf("Queue is full\n");
          }
          else{
            printf("Queue is not full\n");
          }
          printf("\n\n\n");
          break;

        case CLEAR:
          Clear(&Prq);
          break;
          
        default:
          break;
      }
    }while(menu != 6);


  return 0;
}