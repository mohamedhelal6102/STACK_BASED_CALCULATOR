/*
 * main.c
 *
 * Created: 6/14/2023 5:42:33 PM
 *  Author: Mohamed Helal
 */
#include "HKEYPAD_interface.h"
#include "HLCD_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_EXPR_SIZE 100
signed char stack[MAX_EXPR_SIZE];
signed char top = -1;
signed char ch,result;

void push (char ele)
{
	top++;
	stack[top]=ele;
}

int pop(void)
{
	if(top==-1)
	return -1;
	else
	{
		ch=stack[top];
		top--;
	}
	return ch;
}
// Function to return precedence of operators
int precedence(char operator)
{
	switch (operator) {
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

// Function to check if the scanned character
// is an operator
int isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
	|| ch == '^');
}

// Main functio to convert infix expression
// to postfix expression
char* infixToPostfix(char* infix)
{
	int i, j;
	int len = strlen(infix);
	char* postfix = (char*)malloc(sizeof(char) * (len + 2));


	for (i = 0, j = 0; i < len; i++) {
		if (infix[i] == ' ' || infix[i] == '\t')
		continue;

		// If the scanned character is operand
		// add it to the postfix expression
		if (isalnum(infix[i])) {
			postfix[j++] = infix[i];
		}

		// if the scanned character is '('
		// push it in the stack
		else if (infix[i] == '(') {
			stack[++top] = infix[i];
		}

		// if the scanned character is ')'
		// pop the stack and add it to the
		// output string until empty or '(' found
		else if (infix[i] == ')') {
			while (top > -1 && stack[top] != '(')
			postfix[j++] = stack[top--];
			if (top > -1 && stack[top] != '(')
			return "Invalid Expression";
			else
			top--;
		}

		// If the scanned character is an operator
		// push it in the stack
		else if (isOperator(infix[i])) {
			while (top > -1
			&& precedence(stack[top])
			>= precedence(infix[i]))
			postfix[j++] = stack[top--];
			stack[++top] = infix[i];
		}
	}

	// Pop all remaining elements from the stack
	while (top > -1) {
		if (stack[top] == '(') {
			return "Invalid Expression";
		}
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}
void evaluate_infixPostfix(char* postfix)
{
	char ele;
	char i,num1,num2,ans;
	int len = strlen(postfix);
	i=0;
	while(i<=len-1)
	{
		ele=postfix[i];
		if(isalnum(ele))
		{
			push(ele-'0');
		}
		else
		{
			num1=pop();
			num2=pop();
			switch(ele)
			{
				case '+':
				{
					ans=num2+num1;
					break;

				}
				case '-':
				{
					ans=num2-num1;
					break;

				}
				case '*':
				{
					ans=num2*num1;
					break;

				}
				case '/':
				{
					ans=num2/num1;
					break;

				}
			}
			push(ans);
		}
		i++;
	}
	result=pop();
	return result;
}

// Driver code
int main()
{
	char var = 0xff;
	char counter = 0;
	HLCD_enumInit();
	HKEYPAD_voidInit();
	char infix[MAX_EXPR_SIZE] = "";
	// Function call

	while(1)
	{
		HKEYPAD_GetPressedKey(&HKEYPADArrayOfKeypads[HKEYPAD_NUM0], &var);
		if(var=='C')
		{
			counter=0;
			stpcpy(infix, "");
			HLCD_enumClearScreen(HLCD_NUM0);
		}
		if(var=='=')
		{
			char* postfix = infixToPostfix(infix);
			evaluate_infixPostfix(postfix);
			HLCD_enumGoToXY(0, 0, HLCD_NUM0);
			HLCD_enumDisplayString(infix, HLCD_NUM0);
			HLCD_enumGoToXY(1, 0, HLCD_NUM0);
			HLCD_enumDisplayString(postfix, HLCD_NUM0);
			HLCD_enumGoToXY(2, 0, HLCD_NUM0);
			HLCD_enumIntegerToString(result, HLCD_NUM0);
			free(postfix);
			while(var != 'C')
			{
				HKEYPAD_GetPressedKey(&HKEYPADArrayOfKeypads[HKEYPAD_NUM0], &var);
			}
		}
		if(var != 'C' && var != '=' && var != 0xff)
		{
			HLCD_enumWriteData(Data, var, HLCD_NUM0);
			infix[counter]=var;
			counter++;
			var = 0xff;
		}
	}
	return 0;
}
