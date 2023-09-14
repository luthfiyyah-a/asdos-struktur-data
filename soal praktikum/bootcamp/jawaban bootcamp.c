/*

- soal 2 modul 1 struktur data
program ini menggunakan priority queue

dibuat dan ditulis oleh luthfiyyah hanifah amari
--- tanggal 26 maret 2021. 

catatan lain :
    banyak source code yang copas dari source code modul github
    
direvisi oleh luthfiyyah hanifah amari
--- tanggal 5 maret 2022
untuk penyelesaian soal praktikum modul 1
kelas struktur data C 2022 genap

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_OUTPUT 30


// struct pqueque node
typedef struct pqueueNode_t {
    int data_urgensi1;
    int data_urgensi2;
    int data_id;
    struct pqueueNode_t *next;
} PQueueNode;

// struct priority queue
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* prototype fungsi */
void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int id, int urgensi1, int urgensi2);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);


/* fungsi */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

int b;
void pqueue_push(PriorityQueue *pqueue, int id, int urgensi1, int urgensi2)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data_id = id;
    newNode->data_urgensi1 = urgensi1;
    newNode->data_urgensi2 = urgensi2;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (urgensi1 > pqueue->_top->data_urgensi1) 
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else if(urgensi1 == pqueue->_top->data_urgensi1 && urgensi2 > pqueue->_top->data_urgensi2)
    {
            newNode->next = pqueue->_top;
            pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                temp->next->data_urgensi1 > urgensi1)
        {
             temp = temp->next;
        }
        
        
        if(temp->next != NULL && temp->next->data_urgensi1 == urgensi1)
        {
            while(temp->next != NULL && 
                  temp->next->data_urgensi2 > urgensi2 && 
                  temp->next->data_urgensi1 == urgensi1)
            {
                temp = temp->next;
            }
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data_id;
    else return 0;
}

void pqueue_print(PriorityQueue *pqueue){
    PQueueNode *temp = pqueue->_top;
    while(temp != NULL){
        printf("%d ", temp->data_id);
        temp = temp->next;
    }
}


int main()
{
    char input[10];
    int temp_id, temp_urgensi1, temp_urgensi2;
    int output;
    PQueueNode daftar;
    int Q, i;

    pqueue_init(&daftar);
    
    scanf("%d", &Q);
    b = 0;
    
    for(i=0; i<Q; i++) {
        scanf("%s", &input);
        if(strcmp(input, "DAFTAR") == 0){
            scanf("%d %d %d", &temp_id, &temp_urgensi1, &temp_urgensi2);

            pqueue_push(&daftar, temp_id, temp_urgensi1, temp_urgensi2);
        }
        
        if(strcmp(input, "DIBUKA") == 0){
            
            int n;
            scanf("%d", &n);
            int j;
            for(j=0; j<n; j++){
                pqueue_pop(&daftar);
            }
        }
    }
    
    
    while(!pqueue_isEmpty(&daftar)){
        printf("%d ", pqueue_top(&daftar));
        pqueue_pop(&daftar);
    }
    return 0;
}

