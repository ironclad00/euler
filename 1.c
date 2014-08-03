#include <stdio.h>
#define target 1000

//SOLVED

int main() {
    int i;
	int sum=0;

	for(i=0; i<target; i++)
		if(i%3==0 || i%5==0)
			sum+=i;

    printf("Sum=%d",sum);

	return 0;
}
