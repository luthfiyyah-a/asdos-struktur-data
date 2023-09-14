/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 *
 * Dimodifikasi oleh luthfiyyah hanifah amari
 * -- tanggal 6 maret 2022
 * untuk penyelesaian problem "Pembukaan" pada praktikum modul 1
 * kelas struktur data C 2022
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack tumpukan1;
    Stack tumpukan2;
    Stack tumpukan3;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&tumpukan1);
    stack_init(&tumpukan2);
    stack_init(&tumpukan3);

	int Q, i, jumlah, j;
	char perintah[20];
	int b=1;
    scanf("%d", &Q);
    for(i=0; i<Q; i++)
	{
    	scanf("%s", &perintah);
    	scanf("%d", &jumlah);
    	if(strcmp(perintah, "CETAK") == 0)
    	{
    		for(j=0; j<jumlah; j++)
    		{
    			stack_push(&tumpukan1, b++);
			}
		}
		else if(strcmp(perintah, "TTD") == 0)
		{
			for(j=0; j<jumlah; j++)
			{
				stack_push(&tumpukan2, stack_top(&tumpukan1));
				stack_pop(&tumpukan1);
			}
		}
		else if(strcmp(perintah, "SAMPUL") == 0)
		{
			for(j=0; j<jumlah; j++)
			{
				stack_push(&tumpukan3, stack_top(&tumpukan2));
				stack_pop(&tumpukan2);
			}
		}	
	}
	
	Stack tumpukanTemp;
	stack_init(&tumpukanTemp);
    // cetak isi stack
    printf("tumpukan 1: ");
    while (!stack_isEmpty(&tumpukan1)) {
    	stack_push(&tumpukanTemp, stack_top(&tumpukan1));
        stack_pop(&tumpukan1);
    }
    while (!stack_isEmpty(&tumpukanTemp)) {
        printf("%d ", stack_top(&tumpukanTemp));
        stack_pop(&tumpukanTemp);
    }
    printf("\n");
    
    printf("tumpukan 2: ");
    while (!stack_isEmpty(&tumpukan2)) {
        stack_push(&tumpukanTemp, stack_top(&tumpukan2));
        stack_pop(&tumpukan2);
    }
    while (!stack_isEmpty(&tumpukanTemp)) {
        printf("%d ", stack_top(&tumpukanTemp));
        stack_pop(&tumpukanTemp);
    }
    printf("\n");
    
    printf("tumpukan 3: ");
    while (!stack_isEmpty(&tumpukan3)) {
        stack_push(&tumpukanTemp, stack_top(&tumpukan3));
        stack_pop(&tumpukan3);
    }
    while (!stack_isEmpty(&tumpukanTemp)) {
        printf("%d ", stack_top(&tumpukanTemp));
        stack_pop(&tumpukanTemp);
    }
    printf("\n");
    
    return 0;
}
