#include<stdio.h>
#define NMAX 105
#define twenty_nine 29
#define seven 7
#define twenty_five 25
#define fifteen 15
#define thirty_two 32
#define s 16
int main() {
    unsigned int inst = 0;
    int operand = 0, val[NMAX];
    int k = 0, contor = 0;
    unsigned int nr_citite = 0;
    char car[NMAX];
    //  aceleasi comentarii ca la task-ul 3
    // pana la portiunea unde incep sa calculez rezultatul expresiei cerute
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
    if (nr_citite % s == 0)
        nr_citite /= s;
    else
        nr_citite = nr_citite / s + 1;

    int ok = 0, m = 0;
    int operand1 = 0, temp = 0;
    unsigned int count = 0;
    for (int i = 0 ; i < nr_citite; i++) {
        scanf("%d", &operand);
        if (ok == 0) {  // nu mai am biti suplimentari
            operand1 = (operand >> (s - dim)) & ((1 << dim) - 1);
            // determin prima grupare de dim biti
            val[m++] = operand1;  //  adaug valoarearea gasita in vector
            count = dim;  // am folosit dim biti
        } else {
            temp = temp + (operand >> (thirty_two - dim - count));
            // temp = restul de biti din nr anterior neutilizati
            // temp = expresie = > determin o noua grupare din bitii
            // ramasi anterior si un nr de biti din nr curent
            val[m++] = temp;  // adaug val gasita in vector
            count = dim - s + count;  // cati biti am folosit acum
        }
        while (s - count >= 0) {
            if (s - count >= dim) {
                operand1 = (operand >> (s - count - dim)) & ((1 << dim) - 1);
                val[m++] = operand1;
                count = count + dim;
            } else {
                temp = operand & ((1 << (s - count)) - 1);
                temp = temp << (dim - s + count);
                ok = 1;  //  mai am nevoie de biti
                break;
            }
        }
    }

    int  k1 = 0, t = 0, i = 0;
    int res[NMAX];
    char op[NMAX];
    int exp = 0, valgasita = 0, gasit = 0;
    ok = 0;
     for (i = 0; i < m - 1; i++) {
            exp = val[i];
            // am intalnit plus =>
            // adaug nr asa cum e la res si + la vectorul de operatori
            if (car[i] == '+') {
                 op[t++] = '+';
                 res[k1++] = exp;
            }
            if (car[i] == '-') {  //  analog pentru minus
                op[t++] = '-';
                res[k1++] = exp;
            }
            while (car[i] == '*' || car[i] == '/') {
                //  daca am * sau / consecutive calculez valoarea
                //  expresiei si apoi o adaug in vector
                if (car[i] == '*')
                     exp *= val[i+1];
                if (car[i] == '/')
                    exp /= val[i+1];
                i++;  //  mai inaintez o data pentru a intalni
                //  primul operator + sau - pe care il
                //  adaug ulterior in vectorul de operatori
                ok = 1;
            }
            if (ok == 1) {
                  res[k1++] = exp;
                  op[t++] = car[i];
                  ok = 0;
            }
        }
    op[t] = '\0';  // op = sirul operatorilor ramasi
    if (car[k-1] == '+' || car[k-1] == '-') {
        for (int i = m - 1 ; i >= 0 && gasit != 1; i--)
            if (val[i] != 0) {
                gasit = 1;
                valgasita = val[i];
            }
            //  adaug in vectorul de rezultate ultima valoare nenula gasita
          res[k1++] = valgasita;
    }

    exp = res[0];
    for (i = 0; i < t ; i++) {
        // calculez rezultatul expresiei,
        // adunand sau scazand rezultatele intre ele, dupa caz
        if (op[i] == '+')
            exp = exp + res[i+1];
        if (op[i] == '-')
            exp = exp - res[i+1];
    }

    printf("%d\n", exp);
    return 0;
}
