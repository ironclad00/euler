#include <stdio.h>
#define TARGET 100

//SOLVED

int main() {
    int i,diff;
    int sumOfSqu=0;
    int squOfSum=0;
    for(i=1;i<=TARGET;i++) {
        sumOfSqu+=power(i,2);
        squOfSum+=i;
    }
    squOfSum=power(squOfSum,2);
    diff=squOfSum-sumOfSqu;
    printf("%d - %d = %d",squOfSum,sumOfSqu,diff);
    return 0;
}

int power(int num, int pow) {
    int i;
    int ans=1;
    for(i=0;i<pow;i++) {
        ans*=num;
    }
    return ans;
}
