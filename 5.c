#include <stdio.h>
#define MAX 20

//SOLVED

int main() {
    int i;
    int found=0;
    int attempt=MAX;
    while(!found) {
        found=1;
        for(i=1;i<=MAX;i++) {
            if(attempt%i!=0) {
                found=0;
            }
        }
        if(!found)
            attempt++;
    }

    printf("Largest number that is divisible by numbers 1-20 is %d.",attempt);

    return 0;
}
