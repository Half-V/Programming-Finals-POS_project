#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//Hardcoded credentials
#define ADMIN_PASSWORD "admin123"
#define USER_PASSWORD "user123"
char password[50];

//Outside functions
#include "ASCII_ARTS.c"

//ASCII Functions
void TITLE_ASCII();
void LOGIN_SCREEN();
void WELCOME_ADMIN();
void WELCOME_USER();
void THANK_YOU();

// -- Function prototypes --
// main_menu
void logIn();
void adminLogin();
void userLogin();
void aboutProgram();
void isAdmin();
void isNonAdmin();

// sales_processing
void salesProcessing();
void displayProducts();
void displayCart();
void addToCart();
void removeFromCart();
void checkout();

// inventory_management
void inventoryManagement();
void changePrice();
void changeStock(); 


// PRODUCTS
// Define a structure for products
typedef struct {
    char name[50];
    int price;
    int stock;
    int cart;
} Product;

// Total number of products
int totalProducts = 15;
// Product list
Product products[15] = {
    {"1KG Rice", 55, 25, 0},
    {"Cooking Oil", 10, 30, 0},
    {"Eggs", 10, 90, 0},
    {"Bread", 65, 40, 0},
    {"Canned Tuna", 35, 20, 0},
    {"Canned Sardines", 25, 20, 0},
    {"Canned Corned Beef", 76, 20, 0},
    {"Chocolate Candy", 2, 20, 0},
    {"Choco Mallows", 40, 20, 0},
    {"Biscuit", 15, 15, 0},
    {"Crackers", 10, 30, 0},
    {"Potato Chips", 18, 50, 0},
    {"Pancit Canton", 15, 50, 0},
    {"Instant Cup Noodles", 22, 50, 0},
    {"1L Coke Soft Drink", 60, 20, 0},
    
};



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
void logIn() {
	
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
        system("cls"); isNonAdmin();
    } else {
        printf("\n\t\t\t\t\tIncorrect password. Access denied.\n");
        getch();  system("cls");
    }
}


//ABOUT PROGRAM OPTION
void aboutProgram() {
	TITLE_ASCII();
	printf("\n\t\t\t\t     VEN&BEN Store POS System Version 1.1.5"
			"\n\n\t\t\t        VEN&BEN is a Point-of-sale System that process"
			"\n\t\t\t        payments, manage sales and inventory. Designed"
			" \n\t\t\t        to empower technopreneurship for every business.\n");
	printf("\n\n\t\t\t\t\t-- Press Anything to Exit --");
	getch(); 
	system("cls");
}

// ADMIN AND NON-ADMIN MAIN MENU

void isAdmin() {
	
	int choice;
	while(choice!=3) {
	
	WELCOME_ADMIN();
	printf("\n\t\t\tHi, Welcome to VEN&BEN Store POS System, How can I be of service?\n\n"
               "\t\t\t\t\t     LOGGED IN AS: ADMIN\n\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] Sales Transaction     |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] Manage Inventory      |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] Logout                |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tSelect your number: ");
	scanf("%i", &choice); 
			
            	switch (choice) {
                	case 1: system("cls"); salesProcessing(); break;
                	case 2: system("cls"); inventoryManagement(); break;
                	case 3: system("cls"); break;
                	default: system("cls"); printf("\n\t\t\t\t\t    !!! INVALID INPUT !!!\n");
            	}
        } 	
    }

void isNonAdmin() {
	
	int choice;
	while (choice!=3) {
		
    WELCOME_USER();
	printf("\n\t\t\tHi, Welcome to VEN&BEN Store POS System, How can I be of service?\n\n"
               "\t\t\t\t\t     LOGGED IN AS: USER\n\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] Sales Transaction     |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] View Inventory        |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] Logout                |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tInput your number: ");
    scanf("%i", &choice);
    
    			switch (choice) {
    				case 1: system("cls"); salesProcessing(); break;
    				case 2: 
						system("cls"); 
						displayProducts();
						printf("\n\t\t\t\t\t-- Press Anything to Exit --");
						getch();
						system("cls");
						break;
    				case 3: system("cls"); break;
    				default: system("cls"); printf("\n\t\t\t\t\t    !!! INVALID INPUT !!!\n");
				}
	} 
}
// SUB-MENU 

// --- SALES PROCESSING ---

void salesProcessing() {

    int choice;
    while (choice != 0) {
        // Display the product list
        displayProducts();
        displayCart();
        printf("\n\n"
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
                system("cls"); addToCart(products, totalProducts);
                break;
            case 2:
                system("cls"); removeFromCart(products, totalProducts);
                break;
            case 3:
                system("cls"); checkout(products, totalProducts);
                break;
            case 0:
                system("cls");
                break;
            default:
                printf("\n\t\t\t\t\tInvalid choice. Please try again.\n");
                getch(); system("cls");
        }
    } 
}

// Function to display products and their stock
void displayProducts() {
    int i; 
    printf("\n\t\t\t\t    Products available:\n");
    for (i = 0; i < totalProducts; i++) {
    	if (products[i].stock <= 5) {
    		printf("\t\t\t\t!!! [STOCK: %d] %d. %s (PHP %d)\n", products[i].stock , i+1, products[i].name, products[i].price);
		}
		else {
			printf("\t\t\t\t    [STOCK: %d] %d. %s (PHP %d)\n", products[i].stock , i+1, products[i].name, products[i].price);
		}
        
    }
}

void displayCart() {
	int i;
	int noCart=1;
	printf("\n\t\t\t\t    Items currently in cart:");
	for (i = 0; i < totalProducts; i++) {
		if (products[i].cart > 0) {
			printf("\n\t\t\t\t    %d. %s [QTY: %d]", i+1, products[i].name, products[i].cart);
			noCart=0;
		}
	}
	if (noCart==1) {
			printf("\n\t\t\t\t    !! NONE !!");
		}	
}


// Function to add items to the cart
void addToCart(Product products[], int size) {
    int productNumber, amount;
    while (1) {
        displayProducts();
        displayCart();
        printf("\n\n\t\t\tEnter product number to add to cart (\"0\" TO RETURN TO MENU): ");
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
            printf("\n\t\t\t\t    Added %d %s to cart.\n", amount, products[productNumber - 1].name);
        }
    }
}

// Function to remove items from the cart
void removeFromCart(Product products[], int size) {
    int productNumber, amount;
    while (1) {
        displayProducts();
        displayCart();
        printf("\n\n\t\t\tEnter product number to remove from cart (\"0\" TO RETURN TO MENU): ");
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
        	printf("\t\t\t\t\t_____________________________________\n");
            printf("\n\t\t\t\t\tPHP %.2f - %s [QTY: %d]\n", sumAmount, products[i].name, products[i].cart);
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
		printf("\t\t\t\t\t_____________________________________\n");
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
				printf("\n\t\t\t\t\tINSUFFICIENT BALANCE, TRY AGAIN.");
				getch();
				system("cls");
			}	
		}
    	else {
    		system("cls");
		}
	}	
        // Reset cart after checkout
        if (payment>=totalPrice) {
        	for (int i = 0; i < size; i++) {
            products[i].cart = 0;
        	}
		}
        
    }

// -- INVENTORY MANAGEMENT --
void inventoryManagement() {
	int choice;
	while (choice != 0) {
    	displayProducts();
    	printf("\n\n"
               "\t\t\t\t\t    Inventory Management\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [1] Change product price  |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [2] Add to stock          |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [3] Remove from stock     |\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t ---------------------------\n"
			   "\t\t\t\t\t| [0] EXIT                  |\n"
			   "\t\t\t\t\t ---------------------------\n"
               "\n\t\t\t\t\tInput your number: ");
        scanf("%d", &choice);
    	
    	switch(choice) {
    		case 1: 
				system("cls"); changePrice(products, totalProducts);
				break;
    	
    		case 2: 
				system("cls"); changeStock(products, totalProducts, 1);
				break;
    		case 3: 
				system("cls"); changeStock(products, totalProducts, 2);
				break;
			case 0:
				system("cls"); break;
			default:
				printf("\n\t\t\t\t\tInvalid choice. Please try again.\n");
                getch(); system("cls"); 
		}
        		
	}
    	
}	

void changePrice(Product products[], int size) {
	int productNumber;
	while (1) {
		displayProducts();
		printf("\n\t\t\t    Select product number to change (\"0\" TO RETURN TO MENU): "); scanf("%d", &productNumber);
		if (productNumber==0) {
    		system("cls");
    		break;
		}
		if (productNumber < 0 || productNumber > size) {
			printf("\n\t\t\t\t    Invalid product number. Please try again.\n");
            getch();
            system("cls");
            continue;
		}
		
		else {
			printf("\n\t\t\t    Insert new price: PHP ");
			scanf("%d", &products[productNumber - 1].price);
			system("cls");
			printf("\n\t\t\t\t  Changed \"%s\" Price to: PHP %d\n", products[productNumber - 1].name, products[productNumber -1 ].price);
		}
	}
}

void changeStock(Product products[], int size, int select) {
	int productNumber, appendStocks;
	while (1) {
		displayProducts();
		if (select==1) {
			printf("\n\t\t\t    Select product number to add stocks (\"0\" TO RETURN TO MENU): "); 
			scanf("%d", &productNumber);
			
			if (productNumber==0) {
    			system("cls");
    			break;
			}
			
			if (productNumber < 0 || productNumber > size) {
				printf("\n\t\t\t\t    Invalid product number. Please try again.\n");
            	getch();
            	system("cls");
            	continue;
			}
		
			else {
				printf("\n\t\t\t    Insert amount to add: ");
				scanf("%d", &appendStocks);
				products[productNumber - 1].stock += appendStocks;
				system("cls");
				printf("\n\t\t\t\t  Added %d stocks to \"%s\"\n", appendStocks, products[productNumber -1 ].name);
			}
		}
		
		else if (select==2) {
			printf("\n\t\t\t    Select product number to remove stocks (\"0\" TO RETURN TO MENU): "); 
			scanf("%d", &productNumber);
			
			if (productNumber==0) {
    			system("cls");
    			break;
			}
			
			if (productNumber < 0 || productNumber > size) {
				printf("\n\t\t\t\t    Invalid product number. Please try again.\n");
            	getch();
            	system("cls");
            	continue;
			}
		
			else {
				printf("\n\t\t\t    Insert amount to remove: ");
				scanf("%d", &appendStocks);
				if (appendStocks > products[productNumber - 1].stock) {
					printf("\n\t\t\t\t    Cannot remove more than available stock!");
					getch();
					system("cls");
				}
				else {
					products[productNumber - 1].stock -= appendStocks;
					system("cls");
					printf("\n\t\t\t\t  Removed %d stocks from \"%s\"\n", appendStocks, products[productNumber -1 ].name);
				}

			}
		}
		
	}
}
