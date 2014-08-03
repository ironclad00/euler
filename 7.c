#include <stdio.h>
#define TARGET 10001

//SOLVED

int main() {
    int index=1;
    int attempt=1;
    int found=0;
    while(!found) {
        attempt++;
        if(isPrime(attempt))
            if(index==TARGET)
                found=1;
            else
                index++;
    }
    printf("The %dst prime number is: %d",TARGET,attempt);
    return 0;
}

int isPrime(int num) {
    if((num%2==0 && num!=2) || num==1 || num<=0)
        return 0;
    int i;
    for(i=2;i<num;i++) {
        if(num%i==0)
            return 0;
    }
    return 1;
}
