#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
// checks if string after'*' is the inverse of the string before '*', stack
typedef struct
{
 char home[35];
 int top;
} My_stack;

void push(My_stack * s, char c) // push (insert) operation
{ // assume there is enough space for pushing next element!
	s -> top ++;
	s -> home[s -> top] = c;
}

int pop(My_stack * s) // pop (remove) operation
{
	if(is_empty(s)) {
		printf("ERROR: Nothing to pop - program terminates\n");
		exit(1);
	}
	return (s ->home[s ->top --]);
}

int is_empty(My_stack * s) // checking whether stack is empty or not
{
	return(s -> top < 0 ? 1 : 0);
}
	
int main(){
	char ch[25];
	int i,l;
	My_stack stack;
	printf("give the string");
	scanf("%s",ch);
	l=strlen(ch);
	i=0;	
	while(ch[i]!='\0') {
		if(ch[i]!='A'&&ch[i]!='B'&& ch[i]!='*') {
			printf("the string is not accepted allowed caracters are A,B and * ");
			exit(0);
		}
		i++;
	}	
	i=0;	
	while(ch[i] != '*') {
		push(&stack, ch[i]);
		i++;
	}
	i++; // one step forward to pass '*
	while(ch[i] != '\0') {
		if(ch[i] != pop(&stack)) {
			printf("the string is not valid");
			exit(0);
		}
		i++;
	}
	printf("the string is valid");			
	return 0;
}
