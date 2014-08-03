/* QUESTION:
In the 20x20 grid given in 11.jpg, four numbers along a diagonal line have been marked in red.
The product of these numbers is 26 x 63 x 78 x 14 = 1788696. (Starting at row 7 column 9)
What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20x20 grid?
*/

#include <iostream>
#include <fstream>
#include <string>
#define GRID 20
#define TARGET 4
using namespace std;

int removeSpaces(string &aString);

// This program accepts input in the form of a grid of numbers from a text file.
// Expected input format:
// * input file is called "11input.txt"
// * the grid is size nxn where each row n occupies its own individual line
// * each number x is in the range 0 <= x < 100
// * there is one space between each number
// * each number occupies two spaces, regardless of whether or not the number is less than 10 (example: 8 would be written in the file as 08)

int main() {
    int i,j,k,piece,numArray[GRID][GRID];
    char temp;
    string line[GRID];
    ifstream textFile;
    textFile.open("11input.txt");

    if(textFile.is_open()) {
        for(i=0;i<GRID;i++) {
            getline(textFile,line[i]);
            if(!removeSpaces(line[i])) {
                printf("Invalid input format. Each number must be expressed as exactly two digits and the grid must be size %dx%d.\n",GRID,GRID);
                return 0;
            }
            for(j=0;j<GRID;j++) {
                temp=line[i][0];
                piece=10*((int)temp-48);
                temp=line[i][1];
                piece+=(int)temp-48;
                line[i].erase(0,2);
                numArray[i][j]=piece;
            }
        }
        printf("Input successful.\n");
    }
    else {
        printf("Error opening file.\n");
        return 0;
    }
    textFile.close();
    /* end array prep */

    double prodArray[8]; // 0-3 correspond to NESW, respectively. 4-7 correspond to NE,SE,SW,NW, respectively
    double maxProdArray[TARGET];
    for(i=0;i<8;i++)
        prodArray[i]=1;
    for(i=0;i<TARGET;i++)
        maxProdArray[i]=1;
    double maxProd=1;
    int maxRow=0;
    int maxCol=0;
    int dirInt=-1;
    string direction="placeholder";
    for(i=0;i<GRID;i++) {
        for(j=0;j<GRID;j++) {
            if(i>=TARGET-1) { //checks North
                for(k=0;k<TARGET;k++)
                    prodArray[0]*=numArray[i-k][j];
            }
            if(j<=GRID-TARGET) { //checks East
                for(k=0;k<TARGET;k++)
                    prodArray[1]*=numArray[i][j+k];
            }
            if(i<=GRID-TARGET) { //checks South
                for(k=0;k<TARGET;k++)
                    prodArray[2]*=numArray[i+k][j];
            }
            if(j>=TARGET-1) { //checks West
                for(k=0;k<TARGET;k++)
                    prodArray[3]*=numArray[i][j-k];
            }
            if(i>=TARGET-1 && j<=GRID-TARGET) { //check North AND East
                for(k=0;k<TARGET;k++)
                    prodArray[4]*=numArray[i-k][j+k];
            }
            if(i<=GRID-TARGET && j<=GRID-TARGET) { //checks South AND East
                for(k=0;k<TARGET;k++)
                    prodArray[5]*=numArray[i+k][j+k];
            }
            if(i<=GRID-TARGET && j>=TARGET-1) { //checks South AND West
                for(k=0;k<TARGET;k++)
                    prodArray[6]*=numArray[i+k][j-k];
            }
            if(i>=TARGET-1 && j>=TARGET-1) { //checks North AND West
                for(k=0;k<TARGET;k++)
                    prodArray[7]*=numArray[i-k][j-k];
            }
            // end multiplying in each direction

            for(k=0;k<8;k++) { //check to see if there's a new maximum product
                if(prodArray[k]>maxProd) {
                    maxProd=prodArray[k];
                    maxRow=i+1;
                    maxCol=j+1;
                    dirInt=k;
                }
                prodArray[k]=1;
            }
        }
    }

    switch(dirInt) {
        case(0):
            direction="northern";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1-k][maxCol-1];
            break;
        case(1):
            direction="eastern";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1][maxCol-1+k];
            break;
        case(2):
            direction="southern";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1+k][maxCol-1];
            break;
        case(3):
            direction="western";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1][maxCol-1-k];
            break;
        case(4):
            direction="northeastern";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1-k][maxCol-1+k];
            break;
        case(5):
            direction="southeastern";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1+k][maxCol-1+k];
            break;
        case(6):
            direction="southwestern";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1+k][maxCol-1-k];
            break;
        case(7):
            direction="northwestern";
            for(k=0;k<TARGET;k++)
                maxProdArray[k]=numArray[maxRow-1-k][maxCol-1-k];
            break;
        default:
            direction="[Error: cannot determine the vector of maximum product]";
    }

    cout<<"The largest product of any "<<TARGET<<" adjacent numbers from the given input is ";
    printf("%.0f",maxProd);
    cout<<"\nbeginning at row "<<maxRow<<", column "<<maxCol<<" in the "<<direction<<" direction.\n";
    cout<<"The components of this product are ";
    for(k=0;k<TARGET;k++) {
        cout<<maxProdArray[k];
        if(k<TARGET-1)
            cout<<"x";
    }
    cout<<".\n";

    return 0;
}

int removeSpaces(string &aString) {
    int i;
    int strSize = aString.length();
    for(i=0;i<strSize;i++)
        if((int)aString[i]==32)
            aString.erase(i,1);

    if(aString.length()==(2*GRID))
        return 1;
    else
        return 0;
}
