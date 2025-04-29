#include <stdio.h>
#include <string.h>

#define SIZE 5

struct Order {
    int id;
    char name[30];
};

struct Order queue[SIZE];
int front = -1, rear = -1;
int idCounter = 1;

void enqueue() {
    if (rear == SIZE - 1) {
        printf("Queue full! Cannot take more orders.\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;

    printf("Enter customer name: ");
    scanf("%s", queue[rear].name);
    queue[rear].id = idCounter++;

    printf("Order added: ID %d for %s\n", queue[rear].id, queue[rear].name);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("No orders to process.\n");
        return;
    }
    printf("Processing order ID %d for %s\n", queue[front].id, queue[front].name);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("No pending orders.\n");
        return;
    }
    printf("Pending orders:\n");
    for (int i = front; i <= rear; i++) {
        printf("ID %d - %s\n", queue[i].id, queue[i].name);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Place Order\n2. Process Order\n3. Show Orders\n4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) enqueue();
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) break;
        else printf("Invalid choice.\n");
    }
    return 0;
}
