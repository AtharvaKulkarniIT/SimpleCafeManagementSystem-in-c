#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    char foodname[50];
    float price;
    struct node* next;
};

struct node* heada = NULL;  // Head pointer for admin menu
struct node* headc = NULL;  // Head pointer for customer order

void adminmenu() {
    // Display the admin menu options
    printf("\n\t\t\t\t\t\t\t***** ADMIN MENU *****\n\n");
    printf("\t\t\t\t\t\t\t1. Total Sales\n");
    printf("\t\t\t\t\t\t\t2. Add Item\n");
    printf("\t\t\t\t\t\t\t3. Delete Item\n");
    printf("\t\t\t\t\t\t\t4. View Items\n");
    printf("\t\t\t\t\t\t\t5. Exit\n\n");
}

void customermenu() {
    // Display the customer menu options
    printf("\n\t\t\t\t\t\t\t***** CUSTOMER MENU *****\n\n");
    printf("\t\t\t\t\t\t\t1. Order Menu\n");
    printf("\t\t\t\t\t\t\t2. View Order\n");
    printf("\t\t\t\t\t\t\t3. Delete Item from Order\n");
    printf("\t\t\t\t\t\t\t4. Total Bill\n");
    printf("\t\t\t\t\t\t\t5. Exit\n\n");
}

struct node* createadmin(struct node* head, int data, char foodname[], float price) {
    // Create a new menu item and add it to the admin menu
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    strcpy(temp->foodname, foodname);
    temp->price = price;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    return head;
}

struct node* deleteadmin(struct node* head, int data) {
    // Delete a menu item from the admin menu
    if (head == NULL) {
        printf("\n\t\t\t\t\t\t\tNo items found!\n");
    } else {
        struct node* prev = NULL;
        struct node* curr = head;

        while (curr != NULL && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("\n\t\t\t\t\t\t\tItem deleted from menu successfully!\n");
        } else {
            printf("\n\t\t\t\t\t\t\tItem not found in menu!\n");
        }
    }

    return head;
}

struct node* createcustomer(struct node* head, int data, char foodname[], float price) {
    // Add a menu item to the customer's order
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    strcpy(temp->foodname, foodname);
    temp->price = price;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    return head;
}

struct node* deletecustomer(struct node* head, int data) {
    // Delete a menu item from the customer's order
    if (head == NULL) {
        printf("\n\t\t\t\t\t\t\tNo items found!\n");
    } else {
        struct node* prev = NULL;
        struct node* curr = head;

        while (curr != NULL && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("\n\t\t\t\t\t\t\tItem deleted from order successfully!\n");
        } else {
            printf("\n\t\t\t\t\t\t\tItem not found in order!\n");
        }
    }

    return head;
}

void view(struct node* head) {
    // Display the items in a menu
    if (head == NULL) {
        printf("\n\t\t\t\t\t\t\tNo items found!\n");
    } else {
        printf("\n\t\t\t\t\t\t\tID\tFood Name\t\tPrice\n");
        struct node* ptr = head;
        while (ptr != NULL) {
            printf("\n\t\t\t\t\t\t\t%d\t%s\t\tRs. %.2f\n", ptr->data, ptr->foodname, ptr->price);
            ptr = ptr->next;
        }
    }
}

void ordermenu() {
    // Display the menu for ordering
    printf("\n\t\t\t\t\t\t\t***** MENU *****\n\n");
    printf("\t\t\t\t\t\t\tID\tFood Name\t\tPrice\n");
    struct node* ptr = heada;
    while (ptr != NULL) {
        printf("\n\t\t\t\t\t\t\t%d\t%s\t\tRs. %.2f\n", ptr->data, ptr->foodname, ptr->price);
        ptr = ptr->next;
    }
    printf("\n\t\t\t\t\t\t\tEnter food ID to add to order (0 to exit): ");
}

float calculateTotalBill() {
    // Calculate the total bill for the customer's order
    struct node* ptr = headc;
    float totalBill = 0.0;

    while (ptr != NULL) {
        totalBill += ptr->price;
        ptr = ptr->next;
    }

    return totalBill;
}

void mainmenu() {
    // Display the main menu and handle user choices
    int choice;

    printf("\n\t\t\t\t\t\t\t***** CAFE MANAGEMENT SYSTEM *****\n\n");
    printf("\t\t\t\t\t\t\t1. Admin\n");
    printf("\t\t\t\t\t\t\t2. Customer\n");
    printf("\t\t\t\t\t\t\t3. Exit\n\n");
    printf("\t\t\t\t\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char username[20], password[20];

        printf("\n\t\t\t\t\t\t\tEnter username: ");
        scanf("%s", username);
        printf("\t\t\t\t\t\t\tEnter password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin@cafe") == 0) {
            int choice;

            while (1) {
                adminmenu();
                printf("\t\t\t\t\t\t\tEnter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        // Calculate, display total sales
                        printf("\n\t\t\t\t\t\t\tTotal Sales: Rs. %.2f\n", calculateTotalBill());
                        break;
                    case 2: {
                        int data;
                        char foodname[50];
                        float price;

                        printf("\n\t\t\t\t\t\t\tEnter food ID: ");
                        scanf("%d", &data);
                        printf("\t\t\t\t\t\t\tEnter food name: ");
                        scanf("%s", foodname);
                        printf("\t\t\t\t\t\t\tEnter price: ");
                        scanf("%f", &price);

                        heada = createadmin(heada, data, foodname, price);
                        printf("\n\t\t\t\t\t\t\tItem added to menu successfully!\n");
                        break;
                    }
                    case 3: {
                        int data;

                        printf("\n\t\t\t\t\t\t\tEnter food ID to delete: ");
                        scanf("%d", &data);

                        heada = deleteadmin(heada, data);
                        break;
                    }
                    case 4:
                        view(heada);
                        break;
                    case 5:
                        return;
                    default:
                        printf("\n\t\t\t\t\t\t\tInvalid choice! Please try again.\n");
                        break;
                }
            }
        } else {
            printf("\n\t\t\t\t\t\t\tInvalid username or password!\n");
        }
    } else if (choice == 2) {
        int choice;

        while (1) {
            customermenu();
            printf("\t\t\t\t\t\t\tEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    int data;
                    printf("\n");
                    ordermenu();
                    scanf("%d", &data);

                    if (data == 0) {
                        break;
                    }

                    struct node* ptr = heada;
                    while (ptr != NULL && ptr->data != data) {
                        ptr = ptr->next;
                    }

                    if (ptr != NULL) {
                        headc = createcustomer(headc, ptr->data, ptr->foodname, ptr->price);
                        printf("\n\t\t\t\t\t\t\tItem added to order successfully!\n");
                    } else {
                        printf("\n\t\t\t\t\t\t\tItem not found in menu!\n");
                    }

                    break;
                }
                case 2:
                    view(headc);
                    break;
                case 3: {
                    int data;

                    printf("\n\t\t\t\t\t\t\tEnter food ID to delete from order: ");
                    scanf("%d", &data);

                    headc = deletecustomer(headc, data);
                    break;
                }
                case 4:
                    printf("\n\t\t\t\t\t\t\tTotal Bill: Rs. %.2f\n", calculateTotalBill());
                    break;
                case 5:
                    return;
                default:
                    printf("\n\t\t\t\t\t\t\tInvalid choice! Please try again.\n");
                    break;
            }
        }
    } else if (choice == 3) {
        exit(0);
    } else {
        printf("\n\t\t\t\t\t\t\tInvalid choice! Please try again.\n");
    }
}

int main() {
    // Default items in the admin menu
    heada = createadmin(heada, 1, "Dosa", 100);
    heada = createadmin(heada, 2, "Samosa", 20);
    heada = createadmin(heada, 3, "Softie", 15);
    heada = createadmin(heada, 4, "Fried Rice", 80);
    heada = createadmin(heada, 5, "Noodles", 80);

    while (1) {
        mainmenu();
    }

    return 0;
}
