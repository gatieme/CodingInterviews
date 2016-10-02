#include <stdio.h>
#include <stdint.h>

int rich(int n)
{
    return ( (int)( &((uint8_t (*) [n])0)[1+n][0]) ) >> 1;
}

int main() {
    printf("%d\n", rich(10));

    return 0;
}

