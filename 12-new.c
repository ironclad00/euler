#include <stdio.h>
#include <stdlib.h>
#define TARGET 500

int makePrimeComponentArray(int **arrayOfComponents, int value);

int main() {
	int termNum=1;
    long termVal=1;
    int found=0;
    int *arrayOfComponents;
    int i,numPrimes,numDivs;
    arrayOfComponents = malloc(100*sizeof(int *));	//100 is an overestimate of how many
    for(i=0;i<100;i++) {							//component primes I will need to calculate
        arrayOfComponents[i]=0;
    }

    while(!found) {
        termNum++;
        termVal+=termNum;
        
        int maxIndex=makePrimeComponentArray(&arrayOfComponents,termVal);
        
        if(getNumDivs(&arrayOfComponents,maxIndex)>TARGET)
            found=1;
        for(i=0;i<maxIndex;i++) {
            arrayOfComponents[i]=0;
        }
    }
    
    printf("The first triangle number to have over %d divisors is term number %d equal to %d.\n",TARGET,termNum,termVal);

    return 0;
}

int makePrimeComponentArray(int **arrayOfComponents, int value) {//sets up the prime components so that divisors can be easily calculated
    int curIndex=0;//odd indexes are primes, even indexes are the number of times the (i-1) prime is repeated
    int i=2;
    
    while(value>1) {
        if(value%i==0) { //if i is a prime component of the number being tested
            value/=i;
            (*arrayOfComponents)[curIndex]=i;
            i=2;
            if(curIndex>1 && (*arrayOfComponents)[curIndex-2]==(*arrayOfComponents)[curIndex]) {
                (*arrayOfComponents)[curIndex]=0;
                (*arrayOfComponents)[curIndex-1]+=1;
            }
            else {
                (*arrayOfComponents)[curIndex+1]+=1;
            	curIndex+=2;
            }
        }
        else {
            i++;
        }
    }
    
    return curIndex;
}

int getNumDivs(int **arrayOfComponents, int maxIndex) {
    int i;
    int divs=1;
    
    for(i=1;i<maxIndex;i+=2) {
        divs*=((*arrayOfComponents)[i]+1);
    }
    
    return divs;
}
