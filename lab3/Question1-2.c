#include<string.h>
#include<stdio.h>
#define STACKSIZE 5
// stack filled with person structure, push and pop are a bit different than normal
struct person {
	int empnr;
	char name[12];
	int age;
};

struct stack {
	struct person items[STACKSIZE];
	int top;
};

void push(struct stack * s, int emp,char na[],int a)  { 
	s -> top ++;
	s -> items[s->top].empnr=emp;
	s -> items[s->top].age=a;
	strcpy(s -> items[s->top].name,na);
}

int is_empty(struct stack * s) // checking whether stack is empty or not
{
	return(s -> top < 0 ? 1 : 0);
}

void pop(struct stack * s) // pop (remove) operation
{
	
	if(is_empty(s)) {
		printf("ERROR: Nothing to pop - program terminates\n");
		exit(1);
	}
	printf("%d %s %d", s -> items[s -> top ].empnr,s -> items[s -> top ].name,s -> items[s -> top ].age);
	s -> top--;
}

void create(struct stack*s)
{
	s->top=-1;
}

int main()
{
	struct stack s;
	int stdID;
	char name[12];
	int age;
	char optype;

	create(&s);
	
	do{
		printf("Enter Operation type \n");
		scanf("\n%c",&optype);
		switch (optype) {
			case 'I':{
				printf("ENTER std Number \n");
				scanf("%d",&stdID);
				getchar();
				printf("ENTER name\n");
				gets(name);
				printf("ENTER age\n");
				scanf("%d",&age);
				push(&s,stdID, name, age);
				break;
			}
			case 'D':{
				pop(&s);
				printf(" is deleted \n");
				break;
			}
			default :printf("%s","Illegal Oparation code \n");
		}
	} while (optype!='E');
	push(&s,25,"imen",27);
	pop(&s);
	return 0;
}

