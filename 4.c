#include<stdio.h>
#include<string.h>
#include<ctype.h>
//#include<conio.h>

char in[20], pre[20], stack[20];
int top=-1, j=0;

void push(char);
char pop();
int precedence(char);
int associativity(char);
void reverse(char[]);
void evaluate(char[]);
void push1(int);
int pop1();
int operation(int,int,char);

int main()
{
    int i,n;

    //clrscr();

    printf("Enter Infix Expression: ");
    scanf("%s",in);

    reverse(in);
    n=strlen(in);

    for(i=0;i<n;i++)
    {
        if(in[i]=='(')
            in[i]=')';
        else if(in[i]==')')
            in[i]='(';
    }

    for(i=0;i<n;i++)
    {
        if(isdigit(in[i]))
            pre[j++]=in[i];

        else if(in[i]=='(')
            push(in[i]);

        else if(in[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
                pre[j++]=pop();
            pop();
        }

        else
        {
            while(top!=-1 && stack[top]!='(' &&
                 (precedence(stack[top])>precedence(in[i]) ||
                 (precedence(stack[top])==precedence(in[i]) &&
                  associativity(stack[top]))))
            {
                pre[j++]=pop();
            }
            push(in[i]);
        }
    }

    while(top!=-1)
        pre[j++]=pop();

    pre[j]='\0';
    reverse(pre);

    printf("\nPrefix Expression : %s",pre);

    evaluate(pre);

    //getch();
    return 0;
}

void reverse(char s[])
{
    int i,j;
    char t;

    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
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

void evaluate(char pre[])
{
    int i,a,b,n;

    n=strlen(pre);

    for(i=n-1;i>=0;i--)
    {
        if(isdigit(pre[i]))
        {
            push1(pre[i]-'0');
        }
        else
        {
            a=pop1();
            b=pop1();
            push1(operation(a,b,pre[i]));
        }
    }

    printf("\nPrefix Evaluation : %d",pop1());
}