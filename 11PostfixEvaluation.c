#include<stdio.h>

#define MAX 40

typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;

char EXPR[MAX];

int stack[20];

int top=-1;

precedence get_token(char *symbol,int *n){

 *symbol=EXPR[(*n)++];

 switch(*symbol)

 {

 case '(':return lparen;

 case ')':return rparen;

 case '+':return plus;

 case '-':return minus;

 case '*':return times;

 case '/':return divide;

 case '%':return mod;

 case '\0':return eos;

 default:return operand;

 }

}

void push(int num){

 stack[++top]=num;

}

int pop(){

 return stack[top--];

}

int eval(){

 precedence token;

 char symbol;
int op1,op2,n=0;

 token=get_token(&symbol,&n);

 while(token!=eos)

 {

 if(token==operand)

 push(symbol-'0');

 else

 {

 op2=pop();

 op1=pop();

 switch(token)

 {

 case plus:

 push(op1+op2);

 break;

 case minus:

 push(op1-op2);

 break;

 case times:

 push(op1*op2);

 break;

 case divide:

 push(op1/op2);

 break;

 case mod:

 push(op1%op2);

 break;

 }

 }

 token=get_token(&symbol,&n);

 }
return pop();

}

void main(){

 int res;

 printf("\nEnter the postfix expression\n");

 scanf("%s",EXPR);

 res=eval();

 printf("\nAfter evaluation:\t%d",res);

}
