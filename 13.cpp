#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

double power(int num, int power);

int main() {
    string line[100];
    ifstream textFile;
    textFile.open("13input.txt");

    int i,j,k;
    if(textFile.is_open()) {
        for(i=0;i<100;i++)
            getline(textFile,line[i]);
    }
    else
        printf("A file-related error occurred.\n");
    textFile.close();

    double numArray[100][5];
    for(i=0;i<100;i++) //initialize
        for(j=0;j<5;j++)
            numArray[i][j]=0;
    for(i=0;i<100;i++) { //breaks each number into a series of 5 10-digit numbers
        for(j=0;j<5;j++) {
            for(k=0;k<10;k++) {
                numArray[i][j]+= ((int)line[i][k+(j*10)]-48) * power(10,(9-k));
            }
        }
    }

    double sum=0;
    for(i=4;i>=0;i--) {
        for(j=0;j<100;j++)
            sum+=numArray[j][i];
        if(i>0)
            sum=floor(sum/10000000000);
    }
    while(sum>9999999999) {
        sum=floor(sum/10);
    }

    printf("The first 10 digits of the sum of the input equals %.0f\n",sum);

    return 0;
}

double power(int num, int power) {
        int i;
        double ans=1;
        for(i=0;i<power;i++) {
                ans*=num;
        }
        return ans;
}
