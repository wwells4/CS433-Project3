#include <stdlib.h>
#include <stdio.h>
#include "task.h"
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

struct node *head;
int numTasks = 0;

void add(char *name, int priority, int burst)
{
	Task *tmp = malloc(sizeof(struct node));
	tmp->name = name;
	tmp->priority = priority;
	tmp->burst = burst;
	insert(&head, tmp);
	numTasks++;
}

void schedule()
{
	//SJF
	while(numTasks > 0)
	{
		struct node *smallest = getSmallestBurst(head);
		Task *tmp = smallest->task;
		run(tmp, tmp->burst);
		delete(&head, tmp);
		numTasks--;
	}
} 
