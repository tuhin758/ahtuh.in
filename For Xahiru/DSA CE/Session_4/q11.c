#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100

int mainStack[MAX_SIZE];
int minStack[MAX_SIZE];
int top = -1;
int min_Top = -1;

void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    top++;
    mainStack[top] = element;
    if (min_Top == -1 || element <= minStack[min_Top]) {
        min_Top++;
        minStack[min_Top] = element;
    }
}
int pop() {
    if (top < 0) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    int element = mainStack[top];
    top--;
    if (element == minStack[min_Top]) {
        min_Top--;
    }

    return element;
}
int getMin() {
    if (min_Top < 0) {
        printf("Stack is empty\n");
        return INT_MIN;
    }

    return minStack[min_Top];
}
void printstack(int *stack) {
    printf("Current stack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}

int main() {
    push(9);
    push(2);
    push(4);
    push(2);
    push(4);
    printstack(mainStack);
    printf("\nMinimum element: %d\n", getMin()); 
    pop();
    pop();
    printf("\nAfter removing two elements:\n");
    printstack(mainStack);
    printf("\nMinimum element: %d\n", getMin());  
    push(1);
    printf("\nAfter adding one element:\n");
    printstack(mainStack);
    printf("\nMinimum element: %d\n", getMin());      
    return 0;
}