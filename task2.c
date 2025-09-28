#include<stdio.h>
#define NMAX 105
#define twenty_nine 29
#define seven 7
#define twenty_five 25
#define fifteen 15
#define sixteen 16
#define eight 8

int main() {
    unsigned int inst = 0;
    int operand = 0, val[NMAX];
    int k = 0, contor = 0;
    unsigned int nr_citite = 0;
    char car[NMAX];
    
    scanf("%u", &inst);
    
    int n = (int)((inst >> twenty_nine) & seven) + 1;
    unsigned int shift = twenty_nine - n*2;
    unsigned int operators = ((inst >> shift) &  ((1 << (n * 2)) - 1));
    
    for (int i = n * 2 - 2; i >= 0; i -= 2) {
        unsigned int op = operators >> i;
        op = op & 3;
        
        if (op == 0) {
            car[k++] = '+';
            continue;
        }
        
        if (op == 1) {
            car[k++] = '-';
            continue;
        }
        
        if (op == 2) {
            car[k++] = '*';
            continue;
        }
        
        if (op == 3) {
            car[k++] = '/';
            continue;
        }
    }

    car[k] = '\0';
    
    unsigned int shift1 = twenty_five - n * 2;
    int dim = (int)((inst >> shift1) & fifteen) + 1;
    nr_citite = ((n + 1) * dim);
    
    if (nr_citite % sixteen == 0) {
        nr_citite /= sixteen;
    } else {
        nr_citite = nr_citite / sixteen + 1;
    }
    
    for (int i = 0; i < nr_citite; i++) {
        scanf("%d", &operand);
       
        for (int j = (int)sizeof(__uint16_t) * eight - dim; j >=0; j-=dim) {
            __uint16_t nr_bit = (operand >> j) & ((1 << dim) - 1);
            if (contor <= n + 1)
                val[contor++] = nr_bit;
        }
    }
    
    int exp = val[0];
    
    for (int i = 0; i < k; i++) {
    
        if (car[i] == '+') {
             exp += val[i + 1];
             continue;
        }
        
        if (car[i] == '*') {
             exp *= val[i + 1];
             continue;
        }
        
        if (car[i] == '/') {
             exp /= val[i + 1];
             continue;
        }
        
        if (car[i] == '-') {
             exp -= val[i + 1];
             continue;
        }
        
    }
    
    printf("%d\n", exp);
    
    return 0;
}
