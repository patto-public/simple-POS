#include <stdio.h>
#include "product.h"

void testAddMenu() {
    MenuItem menus[MAX_MENUS];
    int count = 0;

    addMenu(menus, &count, "Test Product", 9.99);
    
    if (count == 1 && strcmp(menus[0].name, "Test Product") == 0 && 
        menus[0].price == 9.99 && menus[0].sales == 0) {
        printf("testAddMenu passed!\n");
    } else {
        printf("testAddMenu failed!\n");
    }
}

int main() {
    testAddMenu();
    return 0;
}