#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
};

/* Five default products */
struct Product products[MAX] =
{
    {101, "Notebook", 10, 50.00},
    {102, "Pen", 20, 10.00},
    {103, "Pencil", 15, 5.00},
    {104, "Eraser", 12, 8.00},
    {105, "SchoolBag", 5, 500.00}
};

int count = 5;

void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void calculateStockValue();

int main()
{
    int choice;

    char username[20] = "admin";
    char password[20] = "1234";
    char enteredUsername[20];
    char enteredPassword[20];

    char *u = username;
    char *p = password;

    /* Welcome Message */
    printf("============================================\n");
    printf(" WELCOME TO INVENTORY MANAGEMENT SOFTWARE\n");
    printf("============================================\n");

    /* Verify Username and Password */
    printf("\nEnter Username: ");
    scanf("%19s", enteredUsername);

    printf("Enter Password: ");
    scanf("%19s", enteredPassword);

    if (strcmp(enteredUsername, u) == 0 &&
        strcmp(enteredPassword, p) == 0)
    {
        printf("\nLogin Successful!\n");
    }
    else
    {
        printf("\nInvalid Username or Password!\n");
        printf("Access denied! Exiting program.\n");
        return 0;
    }

    printf("\nWelcome to the Inventory Management System!\n");
    printf("\nFive default products are loaded.\n");

    /* Continuous Inventory Menu */
    while (1)
    {
        printf("\n========== INVENTORY MENU ==========\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Calculate Stock Value\n");
        printf("7. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Enter a number.\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                deleteProduct();
                break;

            case 6:
                calculateStockValue();
                break;

            case 7:
                printf("\nThank you for using the software!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

/* Add Product */
void addProduct()
{
    int i;

    if (count >= MAX)
    {
        printf("\nInventory is full!\n");
        return;
    }

    printf("\nEnter Product ID: ");
    scanf("%d", &products[count].id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == products[count].id)
        {
            printf("\nProduct ID already exists!\n");
            return;
        }
    }

    printf("Enter Product Name (single word): ");
    scanf("%49s", products[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &products[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &products[count].price);

    count++;

    printf("\nProduct added successfully!\n");
}

/* Display Products */
void displayProducts()
{
    int i;

    if (count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%d\t%-15s\t%d\t\t%.2f\n",
               products[i].id,
               products[i].name,
               products[i].quantity,
               products[i].price);
    }
}

/* Search Product */
void searchProduct()
{
    int id, i;

    printf("\nEnter Product ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("\nProduct Found!\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            return;
        }
    }

    printf("\nProduct not found!\n");
}

/* Update Product */
void updateProduct()
{
    int id, i;

    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("Enter New Product Name: ");
            scanf("%49s", products[i].name);

            printf("Enter New Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter New Price: ");
            scanf("%f", &products[i].price);

            printf("\nProduct updated successfully!\n");
            return;
        }
    }

    printf("\nProduct not found!\n");
}

/* Delete Product */
void deleteProduct()
{
    int id, i, j;

    printf("\nEnter Product ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            for (j = i; j < count - 1; j++)
            {
                products[j] = products[j + 1];
            }

            count--;

            printf("\nProduct deleted successfully!\n");
            return;
        }
    }

    printf("\nProduct not found!\n");
}

/* Calculate Total Stock Value */
void calculateStockValue()
{
    int i;
    float total = 0;

    for (i = 0; i < count; i++)
    {
        total += products[i].quantity * products[i].price;
    }

    printf("\nTotal Inventory Value = %.2f\n", total);
}





