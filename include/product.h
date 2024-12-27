#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_MENUS 100 // Define MAX_MENUS here

typedef struct {
    char name[50];  // ชื่อเมนู
    float price;    // ราคาเมนู
    int sales;      // จำนวนยอดขาย
} MenuItem;

void addMenu(MenuItem* menus, int* count, const char* name, float price);
void displaySales(const MenuItem* menus, int count);
void sortBestSelling(MenuItem* menus, int count); // Keep this as non-const if it modifies the data
int searchMenu(const MenuItem* menus, int count, const char* name);
void generateSalesCSV(const MenuItem* menus, int count);
void filterByPrice(const MenuItem* menus, int count, float maxPrice);
void displayTodaysSales(const MenuItem* menus, int count); // Declaration for today's sales report
void displayBestSelling(const MenuItem* menus, int count); // Declaration for best-selling items

#endif // PRODUCT_H