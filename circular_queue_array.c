#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void search(int key) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        if (queue[i] == key) {
            printf("Element %d found at index %d\n", key, i);
            return;
        }

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("Element not found\n");
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
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
