#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
	int i,bigLength;
    int sum=0;
    double big=2.0;

    for(i=2;i<=1000;i++) {
        big*=2;
    }

    ofstream inputFile;
    inputFile.open("16io.txt");
    if(inputFile.is_open()) {
        inputFile << fixed << showpoint;  //this line and the next prevent 'big' from
        inputFile << setprecision(1);     //being written out in scientific notation
        inputFile << big;
    }
    else
        printf("A file-related error occurred.\n");
    inputFile.close();

    string number;
    ifstream outputFile;
    outputFile.open("16io.txt");
    if(outputFile.is_open())
        getline(outputFile,number);
    else
        printf("A file-related error occurred.\n");
    outputFile.close();

    bigLength=number.length()-2;		//the last two items in the array are '.0'
    for(i=0;i<bigLength;i++) {
    	sum+=(int)number[i]-48;
    }

    printf("The sum of the digits that compose the number 2^1000 is %d.\n",sum);

    return 0;
}
