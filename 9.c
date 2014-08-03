#include <stdio.h>
#define TARGET 1000

//SOLVED, but with terrible time efficiency: O(n^3)

int main() {
    int a,b,c;
    for(a=1;a<TARGET;a++) {
        for(b=1;b<TARGET;b++) {
            for(c=1;c<TARGET;c++) {
                if(a+b+c==1000) {
                    if(power(a,2)+power(b,2)==power(c,2)) {
                        printf("The product abc=%d",a*b*c);
                        return 0;
                    }
                }
            }
        }
    }
    printf("Something went wrong. End of program not reached.");
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
