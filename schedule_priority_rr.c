#include <stdio.h>
#include "task.h"
#include "list.h"
#include <stdlib.h>
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
//RR
void schedule()
{
	struct node* temp = getByPriority(head);
	while (numTasks > 0)
	{
		Task *tmp = temp->task;
		if (tmp->burst > 10)
		{
			run(tmp, 10);
			tmp->burst = tmp->burst - 10;
			//Get next task based on priority
			//priorityCheck = getByPriority(head);
			temp = RRPriority(head, temp);
			if(temp == NULL)
			{
				return;
			}
			tmp = temp->task;
		}
		else
		{
			int time_Remaining = tmp->burst;
			run(tmp, time_Remaining);
			tmp->burst = tmp->burst - time_Remaining;
			delete(&head, tmp);
			temp = getByPriority(head);
			if(temp == NULL)
			{
				return;
			}
			tmp = temp->task;
			numTasks--;
		}
	}
}
