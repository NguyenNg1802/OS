#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
    for (int i=0; i < 10; i++) {
        if ( q->proc[i] == NULL && q->size <= 10 ) {
            q->proc[i] = proc;
            q->size++;
            break;
        }
    }
    return;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
    uint32_t max = 0;
    int position = 0;
    struct pcb_t *result = NULL;
    if ( q->size != 0 ) {
        for (int i = 0; i < 10; i++) {
            if ( q->proc[i]!=NULL ) {
                if ( q->proc[i]->priority >= max ) {
                    max = q->proc[i]->priority;
                    position = i;
                }
            }
        }
        result = q->proc[position];
        q->proc[position] = NULL;
        q->size--;
    }
	return result;
}

