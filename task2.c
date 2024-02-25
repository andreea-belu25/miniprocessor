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
    scanf("%u", &inst);  //  citesc instructiunea de la tastatura
    int n = (int)((inst >> twenty_nine) & seven) + 1;  //  determin n
    //  determin cu cat sa shiftez pt a det sirul de biti pentru operatori
    unsigned int shift = twenty_nine - n*2;
    //  determin sirul de operatori
    unsigned int operators = ((inst >> shift) &  ((1 << (n * 2)) - 1));
    for (int i = n * 2 - 2; i >= 0; i -= 2) {
        //  determin fiecare operator si il adaug intr-un vector
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
    car[k] = '\0';  //  termin vectorul de operatori
    //  cu cat shiftez pentru a determina dimensiunea
    unsigned int shift1 = twenty_five - n * 2;
    //  determin dimensiunea operanzilor
    int dim = (int)((inst >> shift1) & fifteen) + 1;
    //  determin nr de nr citite conform enuntului
    nr_citite = ((n + 1) * dim);
    if (nr_citite % sixteen == 0)
        nr_citite /= sixteen;
    else
        nr_citite = nr_citite / sixteen + 1;
    for (int i = 0; i < nr_citite; i++) {
        scanf("%d", &operand);
        //  determin fiecare operand,
        //  tinand cont ca dim acestora este putere a lui 2
        for (int j = (int)sizeof(__uint16_t) * eight - dim; j >=0; j-=dim) {
            __uint16_t nr_bit = (operand >> j) & ((1 << dim) - 1);
            if (contor <= n + 1)
            //  adaug valorile determinate intr-un vector de valori
                val[contor++] = nr_bit;
        }
    }
    //  initializez expresia cu prima valoare din vectorul de valori
    int exp = val[0];
    for (int i = 0; i < k; i++) {
        // modific valoarea expresiei in functie
        // de urmatorul operator si operand
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
    printf("%d\n", exp);  //  afisez rezultatul expresiei calculate
    return 0;
}
