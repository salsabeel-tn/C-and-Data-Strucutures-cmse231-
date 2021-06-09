#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
// stack, pushing elemnts to stack till'*' then pop the last element
typedef struct
{
 char home[35];
 int top;
} My_stack;

void push(My_stack *, char); /* prototypes (declarations) of functions in use */
void pop(My_stack *); /* they implement standard operations on stack */
int is_empty(My_stack *);

int main() {
	My_stack st;
	char input[50]; /* input sequence for processing */
	int i = 0;
	st.top = -1;
	
	/* previous assignment indicates that stack is empty from the beginning */
	printf("Enter the sequence (length is limited!): ");
	gets(input);
	
	printf("RESULT (after performing pop operation): ");
	while(input[i] != '\0') /* while end of line is not reached */
	{
		if(isalpha(input[i]))
			push(& st, input[i]); /* push character onto the stack */
		else {
			if(input[i] == '*')
				pop(&st);
			else {
		 		printf("ERROR: Wrong input symbol – program terminates!\n");
		 		exit(1);
			}
		}
		i++;
	}
	return 0;
}

void push(My_stack * s, char c) // push (insert) operation
{ // assume there is enough space for pushing next element!
	s -> top ++;
	s -> home[s -> top] = c;
}

void pop(My_stack * s) // pop (remove) operation
{
	if(is_empty(s))
	{
		printf("ERROR: Nothing to pop - program terminates\n");
		exit(1);
	}
	printf("%c", s ->home[s ->top --]); 
}

int is_empty(My_stack * s) // checking whether stack is empty or not
{
	return(s -> top < 0 ? 1 : 0);
}
