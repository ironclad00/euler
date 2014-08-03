#include <stdio.h>
#define MAX 999

//SOLVED

int main() {
    int i,j,test;
    int max=0;
    int iMax=0;
    int jMax=0;
    for(i=2;i<=MAX;i++)
        for(j=2;j<=MAX;j++) {
            test=i*j;
            if(isPalindrome(test))
                if(test>max) {
                    max=test;
                    iMax=i;
                    jMax=j;
                }
        }

    printf("The largest palindrome possible is %d*%d=%d\n",iMax,jMax,max);

    return 0;
}

int isPalindrome(int num) {
    int i,j;
    int temp=num;
    int length=1;
    while(temp>9) {
        temp/=10;
        length++;
    }
    if(length%2!=0)
        return 0;
    else {
        int array[length];
        for(i=0; i<length; i++) {
            array[i]=num/power(10,(length-i-1));
            num-=array[i]*power(10,(length-i-1));
        }
        for(j=0; j<(length/2); j++) {
            if(array[j]!=array[length-j-1])
                return 0;
        }
        return 1;
    }
}

int power(int num, int pow) {
    int i;
    int ans=1;
    for(i=0;i<pow;i++) {
        ans*=num;
    }
    return ans;
}
