# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include <ctype.h>
#define N 100
char stack[N];
int top = -1;

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
        return 1;
    }
    return 0;
}

// defining the precedence of the operator
int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

char* infixTopostfix(char* infix){
    int len = strlen(infix);
    // new postfix expression
    char* postfix = (char *) malloc(sizeof(char) * (len+2));
    int i, j;

    // start loop from first char to last char of infix
    for(i=0, j=0; i<len; i++){
        // continue those part which have spacees
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        //char is an operand
         if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // if there is any Opening Parenthesis '(' add to stack
        else if(infix[i] == '('){
            stack[++top] = infix[i];
        }

        // if there is any Closing Parenthessis')' pop the operators from the stack and add it to the postfix expression
        else if(infix[i] == ')'){
            while(top>-1 && stack[top] != '('){ // adding the operators till we get an Opening Expression
                postfix[j++] = stack[top--]; 
            }
            if(top>-1 && stack[top] != '('){ // if there is any extra '(' opeining parenthesis
                printf("Error: mismatched parenthesis\n");
            }
            else{ // decrement the top to pop the opening parenthesis without adding it.
                top--; 
            }
        }

        // if there is any Operator add it to the postfix expression
        else if(isOperator(infix[i])){
            // check the precedence of curr char with the top stack operator
            while(top>-1 && precedence(stack[top]) >= precedence(infix[i])){ 
                postfix[j++] = stack[top--];  // poping the char from the stack and adding it.
            }
            // now adding the curr char
            stack[++top] = infix[i];
        }
    }
    // if there is any remaining operator in the stack than add it to the postfix expression
    while(top>-1){
        if (stack[top] == '(') { // if there is any extra openening parenthesis '('
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char infix[N] = "a+b*(c^d-e)^(f+g*h)-i";

    // Function call
    char* postfix = infixTopostfix(infix);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}