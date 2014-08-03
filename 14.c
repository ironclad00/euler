#include <stdio.h>
#define TARGET 1000000

int main() {
	long count;
    long iter;
    long value;
    long maxCount=1;
    long maxCountAt=0;	

    for(iter=2; iter<TARGET; iter++) {
        value=iter;
        count=1;
        
        while(value>1) {
            if(value%2==0) { //if even
                value/=2;
            } else {		 //if odd
                value=3*value+1;
            }
            count++;
        }
        
        if(count>maxCount) {
            printf("new max %d at %d\n",maxCount,maxCountAt);
            maxCount=count;
            maxCountAt=iter;
        }
    }
    
    printf("The longest sequence chain is %d terms long and occurs when starting at %d.\n",maxCount,maxCountAt);

    return 0;
}