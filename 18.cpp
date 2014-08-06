#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string temp;		//stores individual lines read in through .txt file
    string pref;		//stores the user's decision to run 18 or 67 in STRING form
    int choice;			//stores the user's decision to run 18 or 67 in INT form
    int i,j;
    int dig1,dig2;		//temporary storage used when converting string numbers to ints
    int TARGET;			//stores how many lines are read in from .txt file
    int userInput=0;	//tracks whether or not the user has entered appropriate input
    ifstream textFile;
    
    while(!userInput) { //allows user to choose between running prob18 and prob67
    	cout<<"Use input from problem 18 (small) or problem 67 (large)? Enter desired problem number and press enter: ";
    	cin>>pref;
        if(pref.length()==2) {
        	dig1 = (int)pref[0]-48;
        	dig2 = (int)pref[1]-48;
        }
        else {
            cout<<"\nInvalid input. Please try again.\n";
        }
        choice=dig1*10+dig2;
        
        if(choice==18) {
            TARGET=15;
    		textFile.open("18input.txt");
            userInput=1;
        }
        else if(choice==67) {
            TARGET=100;
    		textFile.open("67input.txt");
            userInput=1;
        }
        else {
            cout<<"\nInvalid input. Please try again.\n";
        }
    }

    //reading input from file and storing in string form
	string line[TARGET];  //stores the entire .txt input in string form
    if(textFile.is_open())
        for(i=0;i<TARGET;i++) {
        	getline(textFile,temp);
        	line[i]=temp;
    	}
    else
        printf("A file-related error occurred.\n");
    textFile.close();
    //end read

	//formatting string input to int array    
    int triangle[TARGET][TARGET];
    for(i=0;i<TARGET;i++) {
        for(j=0;j<TARGET;j++) {
            triangle[i][j]=-1; //unused indecies initialized to -1 for debugging purposes
        }
    }
    for(i=0;i<TARGET;i++) {
        int k=0;
        for(j=0;j<=i;j++) {
            int dig1=((int)line[i][k]-48)*10;
            int dig2=(int)line[i][k+1]-48;
            int num=dig1+dig2;
            triangle[i][j]=num;
            k+=3;
        }
    }//end format
    
    //algorithm begins
    for(i=TARGET-1;i>=0;i--) {
        for(j=0;j<i;j++) {
            if(triangle[i][j]>triangle[i][j+1]) {
                triangle[i-1][j]+=triangle[i][j];
            }
            else {
                triangle[i-1][j]+=triangle[i][j+1];
            }
        }
    }//end algorithm
    
    cout<<"The maximum total from top to bottom of the triangle with "<<TARGET<<" lines is "<<triangle[0][0]<<".\n";

    return 0;
}