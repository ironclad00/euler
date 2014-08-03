#include <stdio.h>
#include <math.h>
#define TARGET 600851475143

//SOLVED

int main() {
    double max=0;
    double loop=(double)TARGET;
    double i;
    for(i=1;i<loop;i++) {
        if(fmod((double)TARGET,i)==0)
            if(isPrime(i)) {
                max=i;
                loop=TARGET/max;
            }
    }

    printf("The largest prime factor of %.0f is %.0f.",(double)TARGET,max);

    return 0;
}

int isPrime(double num) {
    if((fmod(num,2)==0 && num!=2) || num==1 || num<=0)
        return 0;

    double i;
    for(i=2;i<num;i++) {
        if(fmod(num,i)==0)
            return 0;
    }
    return 1;
}
