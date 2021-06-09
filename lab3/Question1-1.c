#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define STACKSIZE 5
// stack with push pop and empty functions, regular
struct stack
 {
 int items[STACKSIZE];
 int top;  // Keeps the last free index, whenever we insert data to the stack we increas it by one. ex. when top = 4, we have 5 elements in the stack
 } ;
void push(struct stack * ,int);
int pop(struct stack *);
void main(void)
{
struct stack s;
int xx;
char optype;
s.top=-1;
do
{
 printf("Enter Operation type \n");
 scanf("\n%c",&optype);
 switch (optype)
 {
 case 'I':{
 printf("ENTER input Number \n");
 scanf("%d",&xx);
 push(&s,xx);
 break;
 }
 case 'D':{
 printf("%d %s",pop(&s)," is deleted \n");
 break;
 }
 default :printf("%s","Illegal Oparation code \n");
 }
 }while (optype!='E');
 }
 
int pop(struct stack *ps) {
	int x;
 	if (ps->top==-1) {
		printf("%s","stack underflow");
		exit(1);
	} else {
 		x=ps->items[ps->top];
	 	ps->top=ps->top - 1;
 	}
	return x;
}

void push(struct stack *ps, int x) {
	if (ps->top == STACKSIZE-1) {
		printf("%s","stack overflow ");
		exit(1);
	} else {
		ps->top=ps->top + 1; // ++(ps->top)
 		ps->items[ps->top]=x;
 	}
}
