
#include <stdio.h>

int main(){
	int n, a=0,b=1, sig;
	printf("Dime cuantos terminos quieres:");
	scanf("%d", &n);
	printf("Fibonacci: \n");

	for (int i=0; i<n; i++){
		printf("%d ", a);
		sig= a+b;
		a=b;
		b=sig;
	}
	printf("\n");
	return 0;

}
