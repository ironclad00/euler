#include <stdio.h>
#define MAX 4000000
#define firstTerm 1
#define secondTerm 2

//SOLVED

int main() {
	int sum = 2;
	int curr = 0;
	int prev = secondTerm;
	int prev2 = firstTerm;

	while(curr<=MAX)
	{
		curr = prev + prev2;
		if(curr%2==0)
			sum+=curr;
		prev2 = prev;
		prev = curr;
	}

	printf("Sum=%d\n",sum);

	return 0;
}
