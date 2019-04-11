#include <stdio.h>

int main(void){
	int x;
	int y;
	int num;
	char ao;
	printf("Hello This is Calculator\n");
	printf("write to arithmetic operatio\n");
	printf("+ - x /\n");
	scanf("%c", &ao);
	printf("write first num\n");
	scanf("%d", &x);
	printf("write second num\n");
	scanf("%d", &y);

	switch (ao)
	{

		case '+':
			{
				num=x+y;
				printf("%d + %d = %d\n",x,y,num);
				break;
			}

		case '-':
			{
				num=x-y;
				printf("%d - %d = %d\n",x,y,num);
				break;

			}

		case '*':
		{
				num=x*y;
				printf("%d * %d = %d\n",x,y,num);
				break;
			

		}
		
		case '/':

		{
				num=x/y;
				printf("%d / %d = %d\n",x,y,num);
				break;		
		}
	
	}
	

	return(0);
    }
