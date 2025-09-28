#include<stdio.h>
#define NMAX 105
#define twenty_nine 29
#define seven 7
#define twenty_five 25
#define fifteen 15
#define s 16
#define thirty_two 32

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
    unsigned int dim = ((inst >> shift1) & fifteen) + 1;
    nr_citite = ((n + 1) * dim);
    
    if (nr_citite % s == 0) {
        nr_citite /= s;
    } else {
        nr_citite = nr_citite / s + 1;
    }
    
    int ok = 0, m = 0;
    int operand1 = 0, temp = 0;
    unsigned int count = 0;
    
    for (int i = 0 ; i < nr_citite; i++) {
        scanf("%d", &operand);
        
        if (ok == 0) {
            operand1 = (operand >> (s - dim)) & ((1 << dim) - 1);
            val[m++] = operand1;
            count = dim;
        } else {
            temp = temp + (operand >> (thirty_two - dim - count));
            val[m++] = temp;
            count = dim - s + count;
        }
        
        while (s - count >= 0) {
            if (s - count >= dim) {
                operand1 = (operand >> (s - count - dim)) & ((1 << dim) - 1);
                val[m++] = operand1;
                count = count + dim;
            } else {
                temp = operand & ((1 << (s - count)) - 1);
                temp = temp << (dim - s + count);
                ok = 1;
                break;
            }
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

