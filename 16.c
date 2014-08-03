#include <stdio.h>
#define TARGET 1000

int main() {
	int i;
    double big=2.0;
    
    for(i=2;i<=TARGET;i++) {
        big*=2;
    }
    
    while(big>1) {
        double unit=big/10;
        unit=big-10*unit;
    }
    
    printf("2^1000 equals %.0f",big);

    return 0;
}