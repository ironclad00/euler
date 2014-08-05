#include <stdio.h>
#include <stdlib.h>
#define TARGET 500

//test program that iteratively calculates and displays the value, list of prime components, and number of
//divisors for each of the first 1000 triangle numbers

int makePrimeComponents(int **arrayOfComponents, int value);
int getUniqueSubsets(int **arrayOfComponents,int numPrimes);
int getNumDivs(int termVal);

int main() {
	int termNum=1;
    long termVal=1;
    int found=0;
    int *arrayOfComponents;
    int i,numPrimes,numDivs;
    arrayOfComponents = malloc(100*sizeof(int *));
    for(i=0;i<100;i++) {
        arrayOfComponents[i]=-1;
    }
    printf("1) 1: (total=0)\n");
    
    while(termNum<1000) {
    //while(!found) {
        termNum++;
        termVal+=termNum;
        
        printf("%d) %d: ",termNum,termVal);
        numPrimes=makePrimeComponents(&arrayOfComponents,termVal);
        numDivs=getNumDivs(termVal);
        //if(getNumDivs(&arrayOfComponents,numPrimes)>500)
        //    found=1;
        for(i=0;i<numPrimes;i++) {
            printf("%d,",arrayOfComponents[i]);
        }
        printf(" (total=%d with %d divisors)\n",numPrimes,numDivs);
    }
    
    //printf("The first triangle number to have over %d divisors is term number %d equal to %d.\n",TARGET,termNum,termVal);

    return 0;
}

int makePrimeComponents(int **arrayOfComponents, int value) {
    int curIndex=0;
    int i=2;
    
    while(value>1) {
        if(value%i==0) {
            value/=i;
            (*arrayOfComponents)[curIndex]=i;
            i=2;
            curIndex++;
        }
        else {
            i++;
        }
    }
    
    return curIndex;
}

int getUniqueSubsets(int **arrayOfComponents,int numPrimes) {
    return 0;
}

int getNumDivs(int value) {
    int i;
    int sum=2;
    for(i=2;i<value;i++) {
        if(value%i==0) {
            sum++;
        }
    }
    
    return sum;
}
