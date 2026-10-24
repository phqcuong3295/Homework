#include <stdio.h>
#include <stdint.h>
 
uint8_t xtime(uint8_t a){
    uint8_t check = a & 0x80;
    if (check) {
        return (a<<1 ^ 0x11b);// m(x)= 100011011
    } else {
        return (a<<1);
    }
}
uint8_t nhan(uint8_t a, uint8_t b){
    uint8_t result = 0;
    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            result ^= a;
        }
        b >>= 1;
        a = xtime(a);
    }
    return result;
}
int main() {
    uint8_t a = 0x03; 
    uint8_t b = 0x09; 
    uint8_t result = nhan(a, b);
    printf("Result: %02x", result);
    return 0;
}