#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 6

int cq[MAX];
int front = -1, rear = -1;

bool is_full() {
    return (rear + 1) % MAX == front;
}

bool is_empty() {
    return front == -1 && rear == -1;
}

void insert(int item) {
    if (is_full()) {
        printf("Overflow: Circular queue is full.\n");
        // Handle overflow appropriately, e.g., return without enqueueing
        return;
    }
   
    if (is_empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
   
    cq[rear] = item;
    printf("Enqueued: %d\n", item);
}

int dequeue() {
    if (is_empty()) {
        printf("Underflow: Circular queue is empty.\n");
        return -1;
    }

    int deletedItem = cq[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("Dequeued: %d\n", deletedItem);
    return deletedItem;
}

int main() {
    int n, ele;
    do {
        printf("\n1. Insert\n2. Delete\n3. Exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert(ele);
                break;
            case 2:
                {
                    int deletedItem = dequeue();
                    if (deletedItem != -1) {
                        printf("The element %d is removed.\n", deletedItem);
                    }
                }
                break;
            case 3:
                printf("Thanks\n");
                break;
            default:
                printf("Please enter the right option.\n");
        }
    } while (n != 3);

    return 0;
}
