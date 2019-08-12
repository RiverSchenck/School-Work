#include <stdlib.h>
#include <stdio.h>

typedef enum {
	false, true
} bool;

typedef char valueT;

typedef struct _nodeT {
	valueT value;
	struct _nodeT *next;
} nodeT;

typedef struct {
	nodeT *head;
} stackT;

stackT *NewStack(void) {
	stackT* temp = (stackT*)malloc(sizeof(stackT));
	temp->head = NULL;
	return temp;
}

void Push(stackT *stack, valueT value) {
	nodeT *tmp = (nodeT*)malloc(sizeof(nodeT));
	tmp->value = value;
	if (stack->head == NULL) {
		tmp->next = NULL;
	}
	else {
		tmp->next = stack->head;
	}
	stack->head = tmp;

	tmp = NULL;
	free(tmp);
}

valueT Pop(stackT *stack) {

	nodeT *tmp = stack->head;

	if (stack->head != NULL) {
		if (stack->head->next != NULL) {
			stack->head = stack->head->next;
		}
		else {
			stack->head = NULL;
		}
	}
	else {
		printf("Pop: Stack empty!\n");
		return 0;
	}
    char hold = tmp->value;
    free(tmp);
    return hold;
}
void EmptyStack(stackT *stack) {
	nodeT *tmp = stack->head;

	while (stack->head != NULL) {
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}

	tmp = NULL;
}
void FreeStack(stackT *stack) {
    if(stack->head != NULL)
    {
        printf("Stack isnt empty yet!\n");
      
    }
    else
    {
        free(stack);
    }

}
bool IsEmpty(stackT *stack) {
	if (stack->head == NULL) {
		printf("IsEmpty: Stack is empty\n");
		return 1;
	}
    else {
	    return 0;
    }
}


