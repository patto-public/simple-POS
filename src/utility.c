#include <stdio.h>

void clearBuffer() {
    while (getchar() != '\n'); // ล้าง buffer ของ input
}