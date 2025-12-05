#include<stdio.h>

#define STACK_LEN 5 
int arr[5] = { 0 };
int top = -1;

int IsStackEmpmty()
{
	if (top == -1)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int IsStackFull()
{
	if (top == (STACK_LEN - 1))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void push(int val)
{
	if ((IsStackFull() == -1))
	{
		arr[top + 1] = val;
		top++;
	}      
	else
	{
		printf("\nstack is full\n");
	}
}

void pop()
{
	if ((IsStackEmpmty() == 0))
	{
		printf("\nstack is empty\n");
	}
	else 
	{
		printf("\nvalue poping from stack: %d", arr[top]);
		arr[top] = 0;
		top--;
	}
}

void peek()
{  
	printf("peek = %d", arr[top]);
}

void StackPrint()
{
	int i = 0;
	if (IsStackEmpmty() == 0)
	{
		printf("\nstack is empty\n");
	}
	else
	{
		printf("\nstack element : ");
		for (i = 0; i <= top; i++)
		{
			printf("%d\t", arr[i]);
		}
		printf("\n");
	}
}

void StackSize() 
{
	printf("\nStack Length = %d", (top + 1));
}


int main()
{
	
	char buff[10] = {0};
	int menu=0;
	int val;
	int loop = 1;

	while (loop)
	{
		printf("\n------------------------------------");
		printf("\n-----------STACK MENU---------------");
		printf("\n------------------------------------");
		printf("\n1.print stact\n2.stack size\n3.push element in stack\n4.pop\n5.peek\n6.Exit\n");
		printf("Enter the menu: \n");
		scanf("%d", &menu);
		printf("\n------------------------------------");

		printf("\nYou selected %d", menu);

		switch (menu)
		{
		case 1:
			StackPrint();
			break;

		case 2:
			StackSize();
			break;

		case 3:
			printf("\nEnter value to store in stack:");
			scanf("%d", &val);
			push(val);
			break;

		case 4:
			pop();
			break;

		case 5:
			peek();
			break;

		case 6:
			loop = 0;
			break;

		default:
			printf("Unknown input given");
			break;
		}
	}
	 
	return 0;
}