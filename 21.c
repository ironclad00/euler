#include <stdio.h>
#define TARGET 10000

int main() {
	int sum=0;
    int i;
    
    for(i=0;i<TARGET;i++) {
        int num1=d(i);		//284=d(220)
        int num2=d(num1);	//220=d(284)
        
        if(num2==i && i!=num1) {
            sum+=i;
        }
    }
    
    printf("The sum of all amicable numbers under %d is %d.\n",TARGET,sum);

    return 0;
}

int d(int number) {
    int sum=1;
    int i;
    
    for(i=2;i<number;i++) {
        if(number%i==0) {
            sum+=i;
        }
    }
    
    return sum;
}