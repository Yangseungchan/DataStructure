#include <stdio.h>
#include <string.h>
#include "Member.h"

void PrintMember(const Member *m)
{
  printf("[#%3d / %s]", m->no, m->name);
}
void PrintMemberln(const Member *m)
{
  printf("[#%3d / %s]\n", m->no, m->name);
}

int cmpMemberName(const Member *m1, const Member *m2)
{
  return strcmp(m1->name, m2->name);
}

int cmpMemberNo(const Member *m1, const Member *m2)
{
  return m1->no == m2->no ? 0 : -1;
}

Member ScanMember(char *message, int sw)
{
  Member temp;
  printf("Input member's information to %s\n", message);
  if (sw & MEMBER_NAME)
  {
    printf("NAME : ");
    scanf("%s", temp.name);
  }
  if (sw & MEMBER_NO)
  {
    printf("NO : ");
    scanf("%d", &temp.no);
  }
  printf("\n");
  return temp;
}