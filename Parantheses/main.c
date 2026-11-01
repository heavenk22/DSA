#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

// Infix to Postfix Conversion
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isdigit(c))
            postfix[j++] = c;

        else if (c == ',')
            continue;

        else if (c == '(')
            push(c);

        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            pop();
        }

        else
        {
            while (top != -1 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(c) ||
                  (precedence(stack[top]) == precedence(c) &&
                   c != '^')))
            {
                postfix[j++] = pop();
            }

            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Postfix Evaluation
int evaluatePostfix(char postfix[])
{
    int s[MAX], t = -1;
    int a, b, result;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];

        if (isdigit(c))
            s[++t] = c - '0';

        else
        {
            b = s[t--];
            a = s[t--];

            switch (c)
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero!\n");
                        return 0;
                    }
                    result = a / b;
                    break;

                case '^':
                    result = (int)pow(a, b);
                    break;
            }

            s[++t] = result;
        }
    }

    return s[t];
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
