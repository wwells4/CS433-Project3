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
	struct node* temp = head;
	while (numTasks > 0)
	{
		Task *tmp = temp->task;
		if (tmp->burst > 10)
		{
			run(tmp, 10);
			tmp->burst = tmp->burst - 10;
			temp = temp->next;
			if (temp != NULL)
			{
				tmp = temp->task;
			}
			else
			{
				temp = head;
				if (temp == NULL)
				{
					return;
				}
				else
				{
					tmp = temp->task;
				}
			}
		}
		else
		{
			int time_Remaining = tmp->burst;
			run(tmp, time_Remaining);
			tmp->burst = tmp->burst - time_Remaining;
			temp = temp->next;
			delete(&head, tmp);
			if (temp != NULL)
			{
				tmp = temp->task;
			}
			else
			{
				temp = head;
				if (temp == NULL)
				{
					return;
				}
				else
				{
					tmp = temp->task;
				}
			}
		}
	}
}

