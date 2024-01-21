#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int data);
int pop();
int isFull(void);
int isEmpty();
void prime_fact(int num);

int main(void)
{
    int number;

    printf("ENTER THE NUMBER TO FIND ITS PRIME FACTORS: ");
    scanf("%d", &number);

    prime_fact(number);

    return (0);
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack overflow\n");
        return;
    }
    top += 1;
    stack[top] = data;
}

int pop()
{
    int element;

    if (isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    element = stack[top];
    top -= 1;

    return (element);
}

int isFull(void)
{
    if (top == MAX - 1)
        return (1);
    else
        return (0);
}

int isEmpty(void)
{
    if (top == -1)
        return (1);
    else
        return (0);
}

void prime_fact(int num)
{
    int i = 2;

    while (num != 1)
    {
        while (num % i == 0)
        {
            push(i);
            num = num / i;
        }
        i++;
    }

    while (top != -1)
    {
        printf("%d ", pop());
    }
    printf("\n");
}