#include<stdlib.h>
#include <stdio.h>
#include <string.h>
// single linear linkedlist
struct node {
    char info[10];
    struct node *n;
};

int main() {
    typedef struct node *NODEPTR;
    char a[10];
    int cnt=0;
    NODEPTR x , y , save , head , p , q;
    x = (NODEPTR)malloc(sizeof(struct node));
    y = (NODEPTR)malloc(sizeof(struct node));

    head = x;
    x->n=y;
    y->n=NULL;
    strcpy(x->info,"cemal");
    strcpy(y->info,"mert");

    do {
        puts("Enter Name information");
        gets(a);
        cnt++;
        q=NULL;

        // descencing order
        for(p=head; p!=NULL && strcmp(a,p->info)<0; p=p->n)
            q = p;

        if (q == NULL) {
            p=(NODEPTR)malloc(sizeof(struct node));
            strcpy(p->info,a);
            p->n = head;
            head=p;
        } else {
            save=p;
            p=(NODEPTR)malloc(sizeof(struct node));
            strcpy(p->info,a);
            p->n=save;
            q->n=p;
        }
    } while (cnt!=2);

    for(save=head;save!=NULL;save=save->n)
        printf("Traverse Node = %s\n",save->info);

    printf("Who to delete: ");
    scanf("%s", a);
    int found = 0;
    for(save=head;save!=NULL;save=save->n) {
        if(strcmp(a, save->info) == 0) {
            found = 1;
            if(save ==  head) {
                head = head->n;
            } else {
                NODEPTR ptr, prev;
                for(ptr=head; ptr->n==save; ptr=ptr->n);
                ptr->n = save->n;
            }
            printf("%s deleted!\n", save->info);
            break;
        }
    }
    if(!found) {
        printf("name you entered not found!\n");
    }

    for(save=head;save!=NULL;save=save->n)
        printf("Traverse Node after deletion = %s\n",save->info);

    return 0;
}
