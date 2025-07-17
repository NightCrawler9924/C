#include <stdio.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 50
#define FILE_NAME "inventory.txt"

// Structure for item
struct Item {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
};

// Function prototypes
void addItem(struct Item inventory[], int *n);
void displayInventory(struct Item inventory[], int n);
void searchItem(struct Item inventory[], int n);
void updateItem(struct Item inventory[], int n);
void deleteItem(struct Item inventory[], int *n);
void menu(struct Item inventory[], int *n);

// File I/O
void loadFromFile(struct Item inventory[], int *n);
void saveToFile(struct Item inventory[], int n);

int main() {
    struct Item inventory[MAX];
    int count = 0;

    loadFromFile(inventory, &count); // Load data on startup
    menu(inventory, &count);         // Show menu
    saveToFile(inventory, count);    // Save before exit
    return 0;
}

void menu(struct Item inventory[], int *n) {
    int choice;
    do {
        printf("\n==== Inventory Menu ====\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(inventory, n); break;
            case 2: displayInventory(inventory, *n); break;
            case 3: searchItem(inventory, *n); break;
            case 4: updateItem(inventory, *n); break;
            case 5: deleteItem(inventory, n); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 0);
}

void addItem(struct Item inventory[], int *n) {
    if (*n >= MAX) {  //this means that if we add a 51st item, it won't work
        printf("Inventory full!\n");
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &inventory[*n].id);

    while (getchar() != '\n');
    printf("Enter Item Name: ");
    fgets(inventory[*n].name, sizeof(inventory[*n].name), stdin);
    inventory[*n].name[strcspn(inventory[*n].name, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &inventory[*n].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory[*n].price);

    (*n)++; // increase item count
    saveToFile(inventory, *n); // Save immediately
    printf("Item added successfully.\n");
}

void displayInventory(struct Item inventory[], int n) {
    if (n == 0) {
        printf("Inventory Empty :(\n");
        return;
    }

    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n\n", inventory[i].price);
    }
}

void searchItem(struct Item inventory[], int n) {
    int target_id, found = 0;
    printf("Enter Item ID to search: ");
    scanf("%d", &target_id);

    for (int i = 0; i < n; i++) {
        if (inventory[i].id == target_id) {
            printf("\nItem found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

void updateItem(struct Item inventory[], int n) {
    int target_id, found = 0;
    printf("Enter Item ID to update: ");
    scanf("%d", &target_id);

    for (int i = 0; i < n; i++) {
        if (inventory[i].id == target_id) {
            while (getchar() != '\n'); // flush input
            printf("Enter new name: ");
            fgets(inventory[i].name, sizeof(inventory[i].name), stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = '\0';

            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);

            saveToFile(inventory, n); // Save after update
            printf("Item updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

void deleteItem(struct Item inventory[], int *n) {
    int target_id, found = 0;
    printf("Enter Item ID to delete: ");
    scanf("%d", &target_id);

    for (int i = 0; i < *n; i++) {
        if (inventory[i].id == target_id) {
            // Shift remaining elements to the left
            for (int j = i; j < *n - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*n)--; // Reduce count
            found = 1;
            saveToFile(inventory, *n); // Save after delete
            printf("Item deleted.\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

// Load inventory from file on startup
void loadFromFile(struct Item inventory[], int *n) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("No saved inventory found. Starting fresh.\n");
        return;
    }

    while (fscanf(fp, "%d %s %d %f",
                  &inventory[*n].id,
                  inventory[*n].name,
                  &inventory[*n].quantity,
                  &inventory[*n].price) == 4) { //== 4 ensures that all 4 values (id, name, quantity, price) are successfully read from the file before adding the item to inventory
        (*n)++;
    }

    fclose(fp);
}

// Save inventory to file after every change
void saveToFile(struct Item inventory[], int n) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error writing to file.\n");
        return;
    }


    for(int i = 0; i<n; i++)
    {
        fprintf(fp, "%d %s %d %.2f\n",inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    fclose(fp);
}


// Always write down what exactly the program should do.
// Make sure all the edge cases are taken care of.
// This is done like if the file doesn't exist then what to do, or if inventory is empty.
// You'll eventually make the logic and the program :)