
#### 9. `docs/API.md`

```markdown
# API Documentation

## Product Management

### `addMenu(MenuItem* menus, int* count, const char* name, float price)`
- Adds a new menu item.

### `displaySales(const MenuItem* menus, int count)`
- Displays sales report for all menu items.

### `sortBestSelling(MenuItem* menus, int count)`
- Sorts the menu items by sales in descending order.

### `searchMenu(const MenuItem* menus, int count, const char* name)`
- Searches for a menu item by name.

### `generateSalesCSV(const MenuItem* menus, int count)`
- Generates a CSV file with daily sales data over the last 60 days.