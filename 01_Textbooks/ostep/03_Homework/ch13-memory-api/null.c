#include <stdio.h>
#include <stddef.h>

int main() {
    int* p = NULL;
    int val = *p;
    printf("%d\n", val);
    return 0;
}