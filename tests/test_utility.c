#include <stdio.h>
#include "utility.h"

void testClearBuffer() {
   printf("Testing clearBuffer function:\n");
   clearBuffer(); // Call the function to test it.
   printf("clearBuffer function executed successfully.\n");
}

int main() {
   testClearBuffer();
   return 0;
}