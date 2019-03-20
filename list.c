/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(struct node **head, Task *newTask) {
    // add the new task to the list 
    struct node *newNode = malloc(sizeof(struct node));

    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;
}

struct node *RRPriority(struct node *head, struct node *currentPriority)
{
	struct node *temp;
	struct node *priority = malloc(sizeof(struct node));
	temp = head;
	priority = currentPriority;
	struct node *lastPriority = currentPriority;
	while (temp != NULL)
	{
		if (temp->task->priority >= priority->task->priority)
		{
			if (strcmp(temp->task->name, lastPriority->task->name) != 0) //Make sure the order doesn't affect the switch
			{
				priority = temp;
				temp = temp->next;
			}
			else
			{
				temp = temp->next;
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	return priority;
}



struct node* getByPriority(struct node *head)
{
	struct node *temp = head;
	struct node *priority = malloc(sizeof(struct node));
	priority = head;
	while(temp != NULL)
	{
		if(temp->task->priority > priority->task->priority)
		{
			priority = temp;
			temp = temp->next;
		}
		else
		{
			temp = temp->next;
		}
	}
return priority;
}

struct node* getSmallestBurst(struct node *head)
{
	struct node *temp = head;
	struct node *smallest = malloc(sizeof(struct node));
	smallest = head;
	while(temp != NULL)
	{
		if(temp->task->burst < smallest->task->burst)
		{
			smallest = temp;
			temp = temp->next;
		}
		else
		{
			temp = temp->next;
		}
	}
return smallest;
}

// delete the selected task from the list
void delete(struct node **head, Task *task) {
    struct node *temp;
    struct node *prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node *head) {
    struct node *temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}
