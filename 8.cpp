#include <iostream>
#include <fstream>
#include <string>
#define TARGET 13
using namespace std;

// This program accepts input in the form of a number stored inside of a text file.
// There cannot be any breaks, spaces, or non-numerical characters in said file.

string makeStringOf(string filename);

int main() {
    string charArray=makeStringOf("8input.txt");
    int numSize=charArray.length();
    int numArray[numSize];
    int numIter=numSize-TARGET;
    int components[TARGET];
    int i,j;
    int maxIndex=0;
    float prod;
    float maxProd=1;
    for(i=0;i<numSize;i++)
        numArray[i]=(int)charArray[i]-48;


    for(i=0;i<=numIter;i++) {
        prod=1;
        for(j=i;j<TARGET+i;j++) {
            prod*=numArray[j];
        }
        if(prod>maxProd) {
            maxProd=prod;
            maxIndex=i;
        }
    }
    for(i=0;i<TARGET;i++)
        components[i]=numArray[maxIndex+i];

    printf("The largest product of any %d adjacent digits in the given input is\n%.0f at index %d.\nThe component numbers are ",TARGET,maxProd,maxIndex);
    for(i=0;i<TARGET;i++) {
        printf("%d",components[i]);
        if(i!=TARGET-1)
            printf("x");
        else
            printf(".\n");
    }

    return 0;
}

string makeStringOf(string fileName) {
    string line;
    ifstream textFile;
    textFile.open(fileName);

    if(textFile.is_open())
        getline(textFile,line);
    else
        printf("A file-related error occurred.\n");
    textFile.close();

    return line;
}
