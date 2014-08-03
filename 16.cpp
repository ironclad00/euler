#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	int i;
    int sum=0;
    double big=2.0;
    
    for(i=2;i<=1000;i++) {
        big*=2;
    }
    
    ifstream inputFile;
    inputFile.open("16io.txt");
    if(inputFile.is_open())
        inputFile << big;
    else
        printf("A file-related error occurred.\n");
    inputFile.close();
    
    string number;
    ofstream outputFile;
    outputFile.open("16io.txt");
    if(outputFile.is_open())
        getline(outputFile,number);
    else
        printf("A file-related error occurred.\n");
    outputFile.close();
    
    for(i=0;i<string.length();i++) {
    	sum+=(int)number[i]-48;
    }
    
    printf("The sum of the digits that compose the number 2^1000 is %d.\n",sum);

    return 0;
}