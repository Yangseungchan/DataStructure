#ifndef __MEMBER_H__
#define __MEMBER_H__

#define MEMBER_NAME 1
#define MEMBER_NO 2

typedef struct _member{
  char name[20];
  int no;  
}Member;


void PrintMember(const Member *m);

void PrintMemberln(const Member *m);

int cmpMemberName(const Member *m1, const Member *m2);

int cmpMemberNo(const Member *m1, const Member *m2);

Member ScanMember(char *message, int sw);

#endif __MEMBER_H__