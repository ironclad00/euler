#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i,tens;
    long sum=0;
    int array[91];
    char **testArray;
    
    //initialize array and testArray, including indexes which will only be accessed if an error occurs
    for(i=0;i<91;i++) {
    	array[i]=-30000;
    }
    array[0]=0;		//0 letters
    array[1]=3;		//"one"
    array[2]=3;		//"two"
    array[3]=5;		//"three"
    array[4]=4;		//"four"
    array[5]=4;		//"five"
    array[6]=3;		//"six"
    array[7]=5;		//"seven"
    array[8]=5;		//"eight"
    array[9]=4;		//"nine"
    array[10]=3;	//"ten"
    array[11]=6;	//"eleven"
    array[12]=6;	//"twelve"
    array[13]=8;	//"thirteen"
    array[14]=8;	//"fourteen"
    array[15]=7;	//"fifteen"
    array[16]=7;	//"sixteen"
    array[17]=9;	//"seventeen"
    array[18]=8;	//"eighteen"
    array[19]=8;	//"nineteen"
    array[20]=6;	//"twenty"
    array[30]=6;	//"thirty"
    array[40]=5;	//"forty"
    array[50]=5;	//"fifty"
    array[60]=5;	//"sixty"
    array[70]=7;	//"seventy"
    array[80]=6;	//"eighty"
    array[90]=6;	//"ninety"
    
    testArray = malloc(91*sizeof(int *));
    for(i=0;i<91;i++) {
        testArray[i] = malloc(array[i]*sizeof(int));
    }
    testArray[1]="one";
    testArray[2]="two";
    testArray[3]="three";
    testArray[4]="four";
    testArray[5]="five";
    testArray[6]="six";
    testArray[7]="seven";
    testArray[8]="eight";
    testArray[9]="nine";
    testArray[10]="ten";
    testArray[11]="eleven";
    testArray[12]="twelve";
    testArray[13]="thirteen";
    testArray[14]="fourteen";
    testArray[15]="fifteen";
    testArray[16]="sixteen";
    testArray[17]="seventeen";
    testArray[18]="eighteen";
    testArray[19]="nineteen";
    testArray[20]="twenty";
    testArray[30]="thirty";
    testArray[40]="forty";
    testArray[50]="fifty";
    testArray[60]="sixty";
    testArray[70]="seventy";
    testArray[80]="eighty";
    testArray[90]="ninety";
    
    for(i=1;i<1000;i++) {
        if(i>=100) {
            sum+=7;						 			//"hundred"
            sum+=array[(int)(i/100)]; 	 			//how many hundreds
	        tens=i-100*(int)(i/100);				//tens part of the number
            printf("%s hundred ",testArray[(int)(i/100)]);
            if(!(i%100==0)) {						//if the number is not a multiple of 100
                sum+=3;						 		//"and"
                printf("and ");
                if(tens<=20 || tens%10==0) {
                    sum+=array[tens];
                    printf("%s",testArray[tens]);
                } else {
                    sum+=array[(int)(tens/10)*10];	//tens
                    sum+=array[tens%10];			//units
                    printf("%s-%s",testArray[(int)(tens/10)*10],testArray[tens%10]);
                }
            }
        } else { //for all numbers less than 100
            if(i<=20 || i%10==0) {
                sum+=array[i];
                printf("%s",testArray[i]);
            } else {
                sum+=array[(int)(i/10)*10]; 		//tens
                sum+=array[i%10];					//units
                printf("%s-%s",testArray[(int)(i/10)*10],testArray[i%10]);
            }
        }
        printf("\n");
    }
    sum+=11;										//"one thousand"
    printf("one thousand\n");
    
    printf("The sum of the number of letters in the numbers [1,1000] is %d.\n",sum);

    return 0;
}