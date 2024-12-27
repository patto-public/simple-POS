#include <stdio.h>
#include "product.h"
#include "utility.h"
#include <stdlib.h> // Include for srand() and rand()
#include <string.h> // Include for strcspn
#include <time.h>   // Include for time()

#define MAX_MENUS 100

// Function to initialize dummy data by reading from a file
void initializeDummyData(MenuItem* menus, int* menuCount) {
   FILE *file = fopen("menu.txt", "r");
   if (file == NULL) {
       printf("Error opening menu file!\n");
       return;
   }

   // Read header line (optional)
   char header[100];
   fgets(header, sizeof(header), file);

   // Read menu items from the file
   while (fscanf(file, "%49[^,],%f,%d\n", 
                 menus[*menuCount].name,
                 &menus[*menuCount].price,
                 &menus[*menuCount].sales) == 3) {
       (*menuCount)++;
       if (*menuCount >= MAX_MENUS) {
           break; // Prevent exceeding maximum menu items
       }
   }

   fclose(file);
}

int main() {
   MenuItem menus[MAX_MENUS];
   int menuCount = 0;
   int choice;

   srand(time(NULL)); // Seed the random number generator

   // Initialize dummy data from file
   initializeDummyData(menus, &menuCount);

   do {
       printf("\n--- POS Menu ---\n");
       printf("1. View Menu and Prices\n");
       printf("2. Create Today's Sales Report\n"); 
       printf("3. Check Best-Selling Menu\n"); 
       printf("4. Generate Daily Sales CSV Report\n");
       printf("5. Search for a Menu Item\n");
       printf("6. Filter by Price\n"); 
       printf("7. Exit\n");
       
       printf("Enter your choice: ");
       
       scanf("%d", &choice);
       clearBuffer(); // Clear the input buffer

       switch (choice) {
           case 1:
               displaySales(menus, menuCount); // Show only menu name and price.
               break;
           case 2:
               displayTodaysSales(menus, menuCount); // Show today's sales report.
               break;
           case 3:
               displayBestSelling(menus, menuCount); // Show best-selling items.
               break;
           case 4:
               generateSalesCSV(menus, menuCount); // Generate CSV report.
               break;
           case 5: {
               char searchName[50];
               printf("Enter the name of the menu item to search: ");
               fgets(searchName, sizeof(searchName), stdin);
               searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character

               if (!searchMenu(menus, menuCount, searchName)) {
                   printf("No menu items found containing '%s'.\n", searchName);
               }
               break;
           }
           case 6: { 
               float maxPrice;
               printf("Enter maximum price to filter: ");
               scanf("%f", &maxPrice);
               filterByPrice(menus, menuCount, maxPrice); // Call filter function.
               break;
           }
           case 7:
               printf("Exiting the program.\n");
               break;
           default:
               printf("Invalid choice! Please try again.\n");
       }
       
   } while (choice != 7); // Continue until user chooses to exit.

   return 0;
}