/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

// insert and delete operations.
void insert(struct node **head, Task *task);
struct node *RRPriority(struct node *head, struct node *currentPriority);
struct node *getByPriority(struct node *head);
struct node *getSmallestBurst(struct node *head);
void delete(struct node **head, Task *task);
void traverse(struct node *head);
