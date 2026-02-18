#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) 
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
    }
}

void search(int key) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        if (queue[i] == key) {
            printf("Element %d found at position %d\n", key, i);
            return;
        }
    }

    printf("Element %d not found\n", key);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Search 4.Display 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

