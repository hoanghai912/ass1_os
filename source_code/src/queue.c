#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if (q->size == 0)
	{
		q->proc[q->size] = proc;
		q->size++;
	}
	else
	{
		q->proc[q->size] = proc;
		q->size++;
		for (int i = 0; i<q->size; i++)
		{
			for (int j = i+1; j<q->size; j++)
			{
				if (q->proc[j]->priority <= q->proc[i]->priority)
				{
					struct pcb_t * tmp = q->proc[i];
					q->proc[i] = q->proc[j];
					q->proc[j] = tmp;
				}
			}
		}
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */

	struct pcb_t * proc = NULL;
	if (!empty(q))
	{
		proc = q->proc[q->size - 1];
		q->proc[q->size - 1] = NULL;
		q->size--;
	}
	return proc;
}

