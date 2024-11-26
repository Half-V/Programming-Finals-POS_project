#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Hardcoded credentials
#define ADMIN_PASSWORD "admin123"
#define USER_PASSWORD "user123"

//Outside functions
#include "ASCII_ARTS.c"

char password[50];


// PRODUCTS

// Define a structure for products
typedef struct {
    char name[50];
    int price;
    int stock;
    int cart;
} Product;

// Global product list
Product products[5] = {
    {"Chocolate Chips", 10, 25, 0},
    {"Milk", 80, 30, 0},
    {"Bread", 60, 20, 0},
    {"Butter", 50, 15, 0},
    {"Eggs", 70, 50, 0},
};

// Total number of products
int totalProducts = 5;


// -- MAIN PROGRAM --
int main() {
	
	system("COLOR 03");
	
	int choice;
	while(choice!=3){
		TITLE_ASCII();
        printf("\n\t\t\t\t\t  VEN&BEN Store POS System\n\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] LOG IN                |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] ABOUT THE PROGRAM     |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] EXIT                  |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tSelect your number: "); 
        scanf("%i", &choice); 

        switch (choice) {
            case 1: system("cls"); logIn(); break;
            case 2: system("cls"); aboutProgram(); break;
            case 3: system("cls"); break;
            default: printf("\n\t\t\t\t\t    !!! INVALID INPUT !!!\n"); getch(); system("cls");
            }
        } 
        
    }

// LOG-IN SYSTEM
int logIn() {
	
	int choice;
	while(choice!=3) {
	LOGIN_SCREEN();
	printf("\n\t\t\t\t\t\t  LOG IN AS:\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] Admin                 |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] Non-Admin		    |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] BACK                  |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tSelect your number: "); 
        scanf("%i", &choice); 
        switch(choice) {
        	case 1: adminLogin(); break;
        	case 2: userLogin(); break;
        	case 3: system("cls"); break;
        	default: printf("\n\t\t\t\t\t    !!! INVALID INPUT !!!\n"); getch(); system("cls");
			}	
	}
}

// SYSTEM ACCOUNTS
void adminLogin() {
    printf("\n\t\t\t\t\tEnter Admin Password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASSWORD) == 0) {
        printf("Admin Login Successful! Welcome, Admin.\n");
        system("cls"); isAdmin();
    } else {
        printf("\n\t\t\t\t\tIncorrect password. Access denied.\n");
        getch(); system("cls");
    }
}
void userLogin() {
    printf("\n\t\t\t\t\tEnter User Password: ");
    scanf("%s", password);

    if (strcmp(password, USER_PASSWORD) == 0) {
        printf("User Login Successful! Welcome, User.\n");
    } else {
        printf("\n\t\t\t\t\tIncorrect password. Access denied.\n");
        getch();  system("cls");
    }
}


//ABOUT PROGRAM OPTION
int aboutProgram() {
	TITLE_ASCII();
	printf("\n\t\t\t\t     VEN&BEN Store POS System Version 1.0"
			"\n\n\t\t\t        VEN&BEN is a Point-of-sale System that process"
			"\n\t\t\t        payments, manage sales and inventory. Designed"
			" \n\t\t\t        to empower technopreneurship for every business.\n");
	printf("\n\n\t\t\t\t\t-- Press Anything to Exit --");
	getch(); 
	system("cls");
}

// ADMIN AND NON-ADMIN MAIN MENU

int isAdmin() {
	
	int choice;
	while(choice!=5) {
	
	WELCOME_ADMIN();
	printf("\n\t\t\tHi, Welcome to VEN&BEN Store POS System, How can I be of service?\n\n"
               "\t\t\t\t\t     LOGGED IN AS: ADMIN\n\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] Sales Transaction     |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] Product Management    |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] Inventory Managment   |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [4] User Management       |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [5] Logout                |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tSelect your number: ");
	scanf("%i", &choice); 
			
            	switch (choice) {
                case 1: system("cls"); salesProcessing(); break;
                case 2: system("cls"); productManagement(); break;
                case 3: system("cls"); inventoryManagement(); break;
                case 4: system("cls"); userManagement(); break;
                case 5: system("cls"); break;
                default: system("cls"); printf("\n\t\t\t\t\t    !!! INVALID INPUT !!!\n");
            	}
        } 	
    }

int isNonAdmin() {
	
	int choice;
    system("cls");
	printf("\n\t\t\tHi, Welcome to VEN&BEN Store POS System, How can I be of service?\n\n"
               "\t\t\t\t\t   LOGGED IN AS: NON-ADMIN\n\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] Sales Processing      |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] View Inventory        |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] Logout                |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tInput your number: ");
               scanf("%i", &choice);
} 

// SUB-MENU 

int productManagement() {
	printf("You have accessed product management!");
	scanf("%i");
}

int inventoryManagement() {
	printf("You have accessed inventory management!");
	scanf("%i");
}

int userManagement() {
	printf("You have accessed user management!");
	scanf("%i");
}
 

// --- SALES PROCESSING ---

// Function prototypes

int salesProcessing() {

    int choice;
    do {
        // Display the product list
        displayProducts(products, 5);
        printf("\n"
               "\t\t\t\t\t      SALES TRANSACTION\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] Add to cart           |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] Remove to cart        |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] View Cart / Checkout  |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [0] EXIT                  |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tInput your number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls"); addToCart(products, 5);
                break;
            case 2:
                system("cls"); removeFromCart(products, 5);
                break;
            case 3:
                system("cls"); checkout(products, 5);
                break;
            case 0:
                system("cls");
                break;
            default:
                printf("\n\t\t\t\t\tInvalid choice. Please try again.\n");
                getch(); system("cls");
        }
    } while (choice != 0);

    return 0;
}

// Function to display products and their stock
void displayProducts() {
    int i; 
    printf("\n\t\t\t\t    Products available:\n");
    for (i = 0; i < totalProducts; i++) {
        printf("\t\t\t\t    [STOCK: %d] %d. %s (PHP %d)\n", products[i].stock , i+1, products[i].name, products[i].price);
    }
}


// Function to add items to the cart
void addToCart() {
    int productNumber, amount;
    while (1) {
        displayProducts();
        printf("\n\t\t\tEnter product number to add to cart (\"0\" TO RETURN TO MENU): ");
        scanf("%d", &productNumber);

        if (productNumber == 0) {
        	system("cls");
            break;
		}
        if (productNumber < 1 || productNumber > totalProducts) {
            printf("\n\t\t\t\t  Invalid product number. Please try again.\n");
            getch();
            system("cls");
            continue;
        }

        printf("\n\t\t\tEnter quantity to add: ");
        scanf("%d", &amount);

        if (amount > products[productNumber - 1].stock) {
            printf("\n\t\t\t\t  Not enough stock available. Please try again.\n");
            getch();
            system("cls");
        } else if (amount <= 0) {
            printf("\n\t\t\t\t  Invalid amount. Please try again.\n");
            getch();
            system("cls");
        } else {
            products[productNumber - 1].cart += amount;
            products[productNumber - 1].stock -= amount;
            system("cls");
            printf("\n\t\t\t\t  Added %d %s to cart.\n", amount, products[productNumber - 1].name);
        }
    }
}

// Function to remove items from the cart
void removeFromCart(Product products[], int size) {
    int productNumber, amount;
    while (1) {
        displayProducts(products, size);
        printf("\n\t\t\tEnter product number to remove from cart (\"0\" TO RETURN TO MENU): ");
        scanf("%d", &productNumber);

        if (productNumber == 0) {
        	system("cls");
            break;
    	} 

        if (productNumber < 1 || productNumber > size) {
            printf("\n\t\t\t\t  Invalid product number. Please try again.\n");
            getch();
            system("cls");
            continue;
        }

        printf("\n\t\t\tEnter quantity to remove: ");
        scanf("%d", &amount);

        if (amount > products[productNumber - 1].cart) {
            printf("\n\t\t\t\t  Not enough items in cart. Please try again.\n");
            getch();
            system("cls");
        } else if (amount <= 0) {
            printf("\n\t\t\t\t  Invalid amount. Please try again.\n");
            getch();
            system("cls");
        } else {
            products[productNumber - 1].cart -= amount;
            products[productNumber - 1].stock += amount;
            system("cls");
            printf("\n\t\t\t\t  Removed %d %s from cart.\n", amount, products[productNumber - 1].name);
        }
    }
}

// Function to check out and display the cart summary
void checkout(Product products[], int size) {
    printf("\n\t\t\t\t\tCheckout Summary:\n");
    int hasItems = 0;
	float sumAmount=0.00, totalPrice, payment, change;
	char choice[1];
	
    for (int i = 0; i < size; i++) {
    	
    	sumAmount += products[i].price * products[i].cart;
    	totalPrice += sumAmount;
        if (products[i].cart > 0) {
            printf("\n\t\t\t\t\tPHP %.2f - %s: %d\n", sumAmount, products[i].name, products[i].cart);
            hasItems = 1;
            sumAmount = 0;
        }
    }

    if (!hasItems) {
        printf("\n\t\t\t\t\tYour cart is empty...\n");
        getch();
        system("cls");
    } 
	
	else {
    	printf("\n\t\t\t\t\tYOUR TOTAL AMOUNT IS: PHP %.2f\n", totalPrice);
    	printf("\n\t\t\t\t\tDo you want to checkout now? (Y or N): "); scanf("%s", &choice);
    	
		if ((strcmp(choice, "Y")==0)||(strcmp(choice,"y")==0)){
    		 printf("\n\t\t\t\t\tENTER AMOUNT PAID: PHP "); scanf("%f", &payment);
    		if (payment>=totalPrice) {
    			change = payment - totalPrice;
				printf("\t\t\t\t\tYOUR CHANGE IS: PHP %.2f\n", change); 
				printf("\n\t\t\t\t\tThank you for your purchase!\n");
				THANK_YOU();
        		getch();
        		system("cls");
			}
			else {
				printf("\n\t\t\t\t\tINSUFFICIENT BALANCE");
				getch();
				system("cls");
			}	
		}
    	else {
    		system("cls");
		}
	}	
        // Reset cart after checkout
        for (int i = 0; i < size; i++) {
            products[i].cart = 0;
        }
    }

