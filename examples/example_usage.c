#include <stdio.h>
#include "product.h"
#include "utility.h"

#define MAX_MENUS 100

int main() {
    MenuItem menus[MAX_MENUS];
    int menuCount = 0;

    addMenu(menus, &menuCount, "Example Pad Thai", 50.00);
    
    printf("Example Menu Item:\n");
    displaySales(menus, menuCount);

    return 0;
}