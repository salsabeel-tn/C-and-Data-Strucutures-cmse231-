#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXELEMENTS 20
#define TRUE 1
#define FALSE 0
// queue of structures, insertin and deletion ops
struct person {
    int empNo;
    char name[12];
    int age;
    char gender[2];/* M=male, F=Female */
};

struct queue {
    struct person allperson[15];
    int front , rear;
};

void cqinsert(struct queue *, struct person p);
struct person cqdelete(struct queue *);
int empty(struct queue *);
void print(struct person p);

int main() {
    struct person tenPerson[10] = {
        123,"Ahmet", 21, "M",
        234,"Sevgi", 26, "F",
        128,"Osman", 18, "M",
        432,"Mert", 27, "M",
        287,"Ayse", 34, "F" ,
        423,"Kemal",21, "M",
        634,"Lale", 16, "F",
        828,"Sefer",15,"M",
        252,"Meral",27,"F",
        887,"Demet",34,"F"
    };

    char operation;
    struct person p;
    struct queue q;
    struct queue qm, qf;
    int qmSize=0, qfSize=0;
    q.front = q.rear = MAXELEMENTS - 1;
    qm.front = qm.rear = MAXELEMENTS -1;
    qf.front = qf.rear = MAXELEMENTS -1;
    do {
        printf("%s\n","I for Insert\nD for delete\nE for End");
        printf("1. Create a Circular queue using tenPerson array structure.\n");
        printf("2. Delete all the elements and show them\n");
        printf("3. Create two new circular queues for both genders\n");
        printf("4. List the gender diverged queues\n");
        printf("Enter your choice: ");

        scanf("\n%c",&operation);
        int i;
        switch (operation) {
          case '1':
            for( i=0; i<10; i++) {
                cqinsert(&q, tenPerson[i]);
            }
            break;
          case '2':
            for( i=0; i<10; i++) {
                cqdelete(&q);
            }
            break;
          case '3':
            for( i=0; i<10; i++) {
                if(strcmp(tenPerson[i].gender, "M") == 0 || strcmp(tenPerson[i].gender, "m") == 0) {
                    cqinsert(&qm, tenPerson[i]);
                    qmSize++;
                } else {
                    cqinsert(&qf, tenPerson[i]);
                    qfSize++;
                }
            }
            break;
          case '4':
            printf("Male:\n");
            for( i=0; i<qmSize; i++)
                cqdelete(&qm);
            printf("\nFemale:\n");
            for( i=0; i<qfSize; i++)
                cqdelete(&qf);
            break;
          case 'I':
            printf("empNo: ");
            scanf("%d", &p.empNo);
            printf("name: ");
            scanf("%s", p.name);
            printf("age: ");
            scanf("%d", &p.age);
            printf("gender: ");
            char temp;
            scanf("%c%s", &temp, p.gender);
            cqinsert(&q , p);
            break;
          case 'D':
            p = cqdelete(&q);
            break;
      }
    } while (operation != 'E');

    return 0;
}

int empty(struct queue *pq)
{
    return((pq->front == pq->rear) ? TRUE : FALSE);
}

struct person cqdelete(struct queue *pq)
{
  if (empty(pq)) {
    printf("Queue underflow ");
    exit(1);
  }
  if (pq->front == MAXELEMENTS - 1)
    pq->front = 0;
  else
    (pq->front)++;

  print(pq->allperson[pq->front]);
  printf("is deleted from the location point %p.\n\n", &pq->allperson[pq->front]);
  return(pq->allperson[pq->front]);
}

void cqinsert(struct queue *pq , struct person p)
{
  /* make room for new element */
  if (pq->rear == MAXELEMENTS - 1)
    pq->rear = 0;
  else
    (pq->rear)++;
  if (pq->rear == pq->front) {
    printf("Queue overflow");
    getchar(); getchar();
    exit(1);
  }
  pq->allperson[pq->rear] = p;
  print(pq->allperson[pq->rear]);
  printf("inserted in the %p location point.\n\n", &pq->allperson[pq->rear]);
}

void print(struct person p) {
    printf("Person {\n  empNo: %d\n  name: %s\n  age: %d\n  gender: %s\n}\n", p.empNo, p.name, p.age, p.gender);
}
