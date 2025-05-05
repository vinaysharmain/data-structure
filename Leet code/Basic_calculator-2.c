int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

void process(int *operand, char *operator, int *top1, int *top2) {
    int x = operand[(*top1)--];
    int y = operand[(*top1)--];
    int z;
    char op = operator[(*top2)--];
    switch (op) {
        case '+': z = y + x; break;
        case '*': z = y * x; break;
        case '/': z = y / x; break;
        case '-': z = y - x; break;
    }
    operand[++(*top1)] = z;
}

int calculate(char* s) {
    int len = strlen(s);
    char operator[len];
    int operand[len], top1 = -1, top2 = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            operand[++top1] = num;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top2 != -1 && precedence(ch) <= precedence(operator[top2])) {
                process(operand, operator, &top1, &top2);
            }
            operator[++top2] = ch;
        }
    }

    while (top2 != -1) {
        process(operand, operator, &top1, &top2);
    }
    return operand[top1];
}
