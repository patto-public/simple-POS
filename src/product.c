#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // Include this header for rand()
#include "product.h"

// Function to generate a CSV file with dummy sales data
void generateSalesCSV(const MenuItem* menus, int count) {
    FILE *file = fopen("sales_report.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Write header
    fprintf(file, "Date,Menu Item,Price,Sales Quantity\n");

    // Generate dummy sales data for 60 days
    time_t t = time(NULL);
    struct tm *tm_info;

    for (int day = 0; day < 60; day++) {
        tm_info = localtime(&t);
        tm_info->tm_mday -= day; // Subtract days for past dates
        mktime(tm_info); // Normalize the structure

        char date[11]; // Format: YYYY-MM-DD
        strftime(date, sizeof(date), "%Y-%m-%d", tm_info);

        for (int i = 0; i < count; i++) {
            int salesQuantity = rand() % 10; // Random sales quantity between 0-9
            fprintf(file, "%s,%s,%.2f,%d\n", date, menus[i].name, menus[i].price, salesQuantity);
        }
    }

    fclose(file);
    printf("Sales report generated: sales_report.csv\n");
}

// Function to add a new menu item
void addMenu(MenuItem* menus, int* count, const char* name, float price) {
    if (*count < MAX_MENUS) {
        strcpy(menus[*count].name, name);
        menus[*count].price = price;
        menus[*count].sales = 0; // Initialize sales to 0
        (*count)++;
    } else {
        printf("Error: Maximum menu limit reached.\n");
    }
}

// Function to display the menu items (only name and price)
void displaySales(const MenuItem* menus, int count) {
    printf("\nMenu Items:\n");
    for (int i = 0; i < count; i++) {
        printf("Menu: %s | Price: %.2f\n", 
               menus[i].name, menus[i].price);
    }
}

// Function to display today's sales report
void displayTodaysSales(const MenuItem* menus, int count) {
    printf("\nToday's Sales Report:\n");
    for (int i = 0; i < count; i++) {
        printf("Menu: %s | Price: %.2f | Sales: %d\n", 
               menus[i].name, menus[i].price, menus[i].sales);
    }
}

// Function to display best-selling menu items
void displayBestSelling(const MenuItem* menus, int count) {
    printf("\nBest-Selling Menu:\n");

    // Sort by sales in descending order before displaying best-sellers.
    MenuItem sortedMenus[MAX_MENUS];
    memcpy(sortedMenus, menus, sizeof(MenuItem) * count); // Copy original data to sort

    sortBestSelling(sortedMenus, count); // Sort the copied array

    // Display top 3 best-selling items as an example.
    printf("Top 3 Best-Selling Items:\n");
    for (int i = 0; i < count && i < 3; i++) {
        printf("Menu: %s | Price: %.2f | Sales: %d\n", 
               sortedMenus[i].name, sortedMenus[i].price, sortedMenus[i].sales);
    }
}

//Function to sort best-selling menu items in descending order
void sortBestSelling(MenuItem* menus, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (menus[i].sales < menus[j].sales) {
                MenuItem temp = menus[i];
                menus[i] = menus[j];
                menus[j] = temp;
            }
        }
    }
}

// void sortBestSelling(MenuItem* menus, int count) {
//     for (int i = 0; i < count - 1; i++) {
//         for (int j = i + 1; j < count; j++) {
//             if (menus[i].sales < menus[j].sales) {
//                 // Swap without temp
//                 menus[i].sales = menus[i].sales + menus[j].sales;
//                 menus[j].sales = menus[i].sales - menus[j].sales;
//                 menus[i].sales = menus[i].sales - menus[j].sales;

//                 // Swap the entire MenuItem structure
//                 MenuItem temp = menus[i];
//                 menus[i] = menus[j];
//                 menus[j] = temp;
//             }
//         }
//     }
// }

// Function to search for menu items by name
int searchMenu(const MenuItem* menus, int count, const char* name) {
    int found = 0; // Flag to check if any matches were found
    printf("Matching menu items:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(menus[i].name, name) != NULL) { // Check if the menu item's name contains the search string
            printf("Menu: %s | Price: %.2f\n", 
                   menus[i].name, menus[i].price);
            found = 1; // Set flag to true if a match is found
        }
    }
    return found; // Return whether any matches were found
}

// Function to filter menu items by maximum price
void filterByPrice(const MenuItem* menus, int count, float maxPrice) {
    int found = 0; // Flag to check if any matches were found
    printf("Menu items with price not exceeding %.2f:\n", maxPrice);
    for (int i = 0; i < count; i++) {
        if (menus[i].price <= maxPrice) {
            printf("Menu: %s | Price: %.2f\n", 
                   menus[i].name, menus[i].price);
            found = 1; // Set flag to true if a match is found
        }
    }
    if (!found) {
        printf("No menu items found with price not exceeding %.2f.\n", maxPrice);
    }
}