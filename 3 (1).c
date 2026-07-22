#include<stdio.h>
#include<string.h>
#include<ctype.h>
//#include<conio.h>

char in[20], post[20], stack[20];
int top=-1, j=0;

void push(char);
char pop();
int precedence(char);
int associativity(char);
void evaluate(char[]);
void push1(int);
int pop1();
int operation(int,int,char);
int main()
{
    int i;

    //clrscr();

    printf("Enter Infix Expression: ");
    scanf("%s", in);

    for(i=0; in[i]!='\0'; i++)
    {
        if(isdigit(in[i]))
            post[j++]=in[i];

        else if(in[i]=='(')
            push(in[i]);

        else if(in[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
                post[j++]=pop();
            pop();
        }

        else
        {
            while(top!=-1 && stack[top]!='(' &&
                 (precedence(stack[top])>precedence(in[i]) ||
                 (precedence(stack[top])==precedence(in[i]) &&
                  associativity(in[i]))))
            {
                post[j++]=pop();
            }
            push(in[i]);
        }
    }

    while(top!=-1)
        post[j++]=pop();

    post[j]='\0';

    printf("\nPostfix Expression : %s", post);

    evaluate(post);

    //getch();
    return 0;
}

void push(char ch)
{
    stack[++top]=ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    switch(ch)
    {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

int associativity(char ch)
{
    if(ch=='^')
        return 0;
    return 1;
}
int st[20], t=-1;

void push1(int x)
{
    st[++t]=x;
}

int pop1()
{
    return st[t--];
}

int operation(int a,int b,char op)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;

        case '^':
        {
            int i,r=1;
            for(i=1;i<=b;i++)
                r*=a;
            return r;
        }
    }
    return 0;
}

void evaluate(char post[])
{
    int i,a,b;

    for(i=0; post[i]!='\0'; i++)
    {
        if(isdigit(post[i]))
        {
            push1(post[i]-'0');
        }
        else
        {
            b=pop1();
            a=pop1();
            push1(operation(a,b,post[i]));
        }
    }

    printf("\nPostfix Evaluation : %d", pop1());
}