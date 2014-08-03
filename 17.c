#include <stdio.h>

int main() {
    int i;
    long sum=0;
    int array[91];
    for(i=0;i<91;i++) {
    	array[i]=-30000;
    }
    array[0]=0;
    array[1]=3;
    array[2]=3;
    array[3]=5;
    array[4]=4;
    array[5]=4;
    array[6]=3;
    array[7]=5;
    array[8]=5;
    array[9]=4;
    array[10]=3;
    array[11]=6;
    array[12]=6;
    array[13]=8;
    array[14]=8;
    array[15]=7;
    array[16]=7;
    array[17]=9;
    array[18]=8;
    array[19]=8;
    array[20]=6;
    array[30]=6;
    array[40]=5;
    array[50]=5;
    array[60]=5;
    array[70]=7;
    array[80]=6;
    array[90]=6;
    
    for(i=1;i<1000;i++) {
        int temp;
        if(i>=100) {
            sum+=7;						 		//"hundred"
            sum+=array[(int)(i/100)]; 	 		//how many hundreds
	        temp=i-100*(int)(i/100);			//tens part of the number
            if(!(i%100==0)) {
                sum+=3;						 	//"and"
                if(temp<=20 || temp%10==0) {
                    sum+=array[temp];
                } else {
                    sum+=array[(int)(temp/10)]; //tens
                    sum+=array[temp%10];		//units
                }
            }
        } else {
            if(i<=20 || i%10==0) {
                sum+=array[i];
            } else {
                sum+=array[(int)(i/10)]; 		//tens
                sum+=array[i%10];				//units
            }
        }
    }
    sum+=11;									//"one thousand"
    
    printf("The sum of the number of letters in the numbers [1,1000] is %d.\n",sum);

    return 0;
}