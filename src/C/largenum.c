#include "largenum.h"


BigInt load(char* num) {
    BigInt temp;
    int i = 0, j = 0, k;
    int len = strlen(num);
    
    while (num[i] == '0')       // skipping leading 0s
        i++;
    
    if (i == len) {             // if we scanned only 0s, we return 0
        temp.digits[0] = '0';
        temp.len = 1;
        return temp;
    }
    
    // otherwise we are copying remaining chars (note: number's digits are written backwards!)
    
    for (k = len-1; k >= i; k--, j++)
        temp.digits[j] = num[k];
    
    temp.len = j;               // saving length
    
    return temp;
}

BigInt fload(FILE *file) {
    char num[LARGENUM_MAX_DIGITS];
    
    fscanf(file, "%s", num);
    
    return load(num);
}

BigInt sfload(char *filename) {
    FILE *f = fopen(filename, "r");
    
    if (f == NULL) {
        fprintf(stderr, "fopen() error. File \"%s\" not found!\n", filename);
        BigInt tmp;
        tmp.digits[0] = '\0';
        tmp.len = 0;
        return tmp;             // undefined behaviour
    }
    
    return fload(f);
}

int cmp(BigInt op1, BigInt op2) {
    
    // if operands have different lengths, bigger is one with bigger length
    
    if (op1.len > op2.len)
        return 1;
    if (op2.len > op1.len)
        return -1;
    
    // if they are equal, we compare digit by digit from the end, since number digits are written backwards!
    
    int i;
    for (i = op1.len-1; i >= 0; i--)
        if (op1.digits[i] > op2.digits[i])
            return 1;
        else 
            if (op1.digits[i] < op2.digits[i])
                 return -1;
    
    return 0;               // numbers are equal if we made it here
}

int digit_sum(BigInt num) {
    int i, sum = 0;
    
    for (i = 0; i < num.len; i++)
        sum += num.digits[i] - '0';
    
    return sum;
}

BigInt add(BigInt op1, BigInt op2) {
    BigInt res;
    int i;
    char carry = 0;
    
    if (op1.len < op2.len)
        res.len = op1.len;
    else
        res.len = op2.len;
    
    for (i = 0; i < res.len; i++) {
        char tmp = op1.digits[i] - '0' + op2.digits[i] + carry;
        if (tmp <= '9') {
            res.digits[i] = tmp;
            carry = 0;
        }
        else {
            res.digits[i] = tmp - 10;
            carry = 1;
        }
    }
    
    for (; i < op1.len; i++) {
        char tmp = op1.digits[i] + carry;
        if (tmp <= '9') {
            res.digits[i] = tmp;
            carry = 0;
        }
        else {
            res.digits[i] = tmp - 10;
            carry = 1;
        }
    }
    
    for (; i < op2.len; i++) {
        char tmp = op2.digits[i] + carry;
        if (tmp <= '9') {
            res.digits[i] = tmp;
            carry = 0;
        }
        else {
            res.digits[i] = tmp - 10;
            carry = 1;
        }
    }
    
    if (carry)
        res.digits[i++] = '1';
    
    res.len = i;
    
    return res;
}

BigInt add_(BigInt a, BigInt b) {
    int i = a.len, j = b.len, k;
    int carry = 0;
    BigInt c;
    
    if (i > j) 
        k = i;
    else 
        k = j;
    
    c.len = k;
    k--; i--; j--;
    
    while (i >= 0 && j >= 0) {
        char tmp = a.digits[i] - '0' + b.digits[j] + carry;
        if (tmp <= '9') {
            c.digits[k] = tmp;
            carry = 0;
        }
        else {
            c.digits[k] = tmp - 10;
            carry = 1;
        }
        i--; j--; k--;
    }
    
    while (i >= 0) {
        char tmp = a.digits[i] + carry;
        if (tmp <= '9') {
            c.digits[k] = tmp;
            carry = 0;
        }
        else {
            c.digits[k] = tmp - 10;
            carry = 1;
        }
        i--; k--;
    }
    
    while (j >= 0) {
        char tmp = b.digits[j] + carry;
        if (tmp <= '9') {
            c.digits[k] = tmp;
            carry = 0;
        }
        else {
            c.digits[k] = tmp - 10;
            carry = 1;
        }
        j--; k--;
    }
    
    if (carry != 0) {
        for (i = c.len; i > 0; i--)
            c.digits[i] = c.digits[i-1];
        c.len++;
        c.digits[0] = carry + '0';
    }
    
    return c;
}

BigInt shift_left(BigInt op) {
    int i;
    
    for (i = op.len; i >= 0; i--)
        op.digits[i] = op.digits[i-1];
    
    op.digits[0] = '0';
    
    op.len++;
    return op;
}

BigInt turn(BigInt num) {
    int i, l = num.len - 1, limit = num.len / 2;
    
    for (i = 0; i < limit; i++) {
        char tmp = num.digits[i];
        num.digits[i] = num.digits[l-i];
        num.digits[l-i] = tmp;
    }
    
    return num;
}

BigInt digit_mul(BigInt op1, char digit) {
    BigInt result;
    int carry = 0, i;
    
    result.len = op1.len;
    
    for (i = 0; i < op1.len; i++) {
        char tmp = (op1.digits[i] - '0') * digit + carry;
        result.digits[i] = tmp % 10 + '0';
        carry = tmp / 10;
    }
    
    if (carry) {
        result.digits[i] = carry + '0';
        result.len++;
    }
    
    return result;
}

BigInt digit_mul_(BigInt b, char k)  {
    int carry = 0, i;
    BigInt c;
    c.len = b.len;
    
    for (i = b.len-1; i >= 0; i--)  {
        char tmp = (b.digits[i] - '0')*k + carry;
        c.digits[i] = tmp % 10 + '0';
        carry = tmp / 10;
    }
    
    if (carry != 0) {
        for(i = c.len; i > 0; i--)
            c.digits[i] = c.digits[i-1];
        c.len++;
        c.digits[0] = carry + '0';
    }
    
    return c;
}

BigInt mul_slow(BigInt op1, BigInt op2) {
    BigInt result = load("0");
    int i;
    
    if (op1.digits[op1.len-1] == '0' || op2.digits[op2.len-1] == '0')
        return result;
    
    for (i = 0; i < op2.len; i++) {
        BigInt tmp = digit_mul(op1, op2.digits[i] - '0');
        int j;
        
        for (j = 0; j < i; j++)
            tmp = shift_left(tmp);
        
        result = add(result, tmp);
    }
    
    return result;
}

BigInt mul(BigInt a, BigInt b) {
    BigInt c, d;
    int j, i;
    
    if (a.digits[a.len-1] == '0' || b.digits[b.len-1] == '0')
        return load("0");
    
    a = turn(a);
    b = turn(b);
    c.len = 0;
    
    for (j = b.len-1; j >= 0; j--) {
        d = digit_mul_(a, b.digits[j] - '0');
        for (i = d.len; i < d.len + (b.len - j-1); i++)
            d.digits[i] = '0';
        d.len = d.len + (b.len - j-1);
        c = add_(c, d);
    }
    
    return turn(c);
}

void printnum(BigInt num) {
    int i;
    
    for (i = num.len-1; i >= 0; i--)
        putchar(num.digits[i]);
    putchar('\n');
}

void fprintnum(FILE *file, BigInt num) {
    int i;
    
    for (i = num.len-1; i >= 0; i--)
        fputc(num.digits[i], file);
    fputc('\n', file);
}

void sfprintnum(char *filename, BigInt num) {
    FILE *f = fopen(filename, "w");
    
    if (f == NULL) {
        fprintf(stderr, "fopen() error. File \"%s\" not found!\n", filename);
        return;
    }
    
    fprintnum(f, num);
}
