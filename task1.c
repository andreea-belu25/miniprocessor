#include<stdio.h>
#define twenty_nine 29
#define seven 7
#define twenty_five 25
#define fifteen 15

int main() {
    unsigned int inst = 0;
    
    scanf("%u", &inst);
    
    int n = (int)((inst >> twenty_nine) & seven) + 1;
    unsigned int shift = twenty_nine - n*2;
    
    unsigned int operators = ((inst >> shift) &  ((1 << (n * 2)) - 1));
    
    for (int i = n * 2 - 2; i >= 0; i -= 2) {
        unsigned int op = operators >> i;
        op = op & 3;
        
        if (op == 0) {
            printf("%c ", '+');
            continue;
        }
        
        if (op == 1) {
            printf("%c ", '-');
            continue;
        }
        
        if (op == 2) {
            printf("%c ", '*');
            continue;
        }
        
        if (op == 3) {
            printf("%c ", '/');
            continue;
        }
    }
    
    unsigned int shift1 = twenty_five - n * 2;
    unsigned int dim = ((inst >> shift1) & fifteen) + 1;
    
    printf("%u\n", dim);
    
    return 0;
}
