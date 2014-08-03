#include <stdio.h>
#define TARGET 2000000

int ceiling(float value);

int main() {
    double sum=17;
    int term;
    
    for(term=9;term<TARGET;term+=2) {
        if(isPrime(term)) {
            sum+=term;
        }
    }
    
    printf("The sum of all primes below %d equals %.0f.\n",TARGET,sum);

    return 0;
}

int isPrime(int value) {
    int i;
    
    for(i=3;i<=ceiling((float)value/i);i++) {
        if(value%i==0) {
            return 0;
        }
    }
    
    return 1;
}

int ceiling(float value) {
    if((int)value<value)
        return ((int)value)+1;
    else
    	return (int)value;
}
