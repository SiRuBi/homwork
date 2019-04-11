#include <stdio.h>
int result(char ao,int a,int b)
{
	int rnum;
	switch(ao) {
		case '+':
			rnum= a + b;
			break;
		case '-':
			rnum= a - b;
			break;
		case '*':
			rnum= a * b;
			break;
		case '/':
			rnum= a / b;
			break;
	}
	return(rnum);
};
int main(void){
	int x;
	int y;
	
	char ao;
	printf("Hello This is Calculator\n");
	printf("write to arithmetic operatio\n");
	printf("+ - x /\n");
	scanf("%c", &ao);
	printf("write first num\n");
	scanf("%d", &x);
	printf("write second num\n");
	scanf("%d", &y);
	printf("result %d\n",result(ao,x,y));	
	return(0);
    }
