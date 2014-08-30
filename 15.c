#include <stdio.h>
#include <stdlib.h>
#define TARGET 3

//this algorithm only runs adequately on TARGET<=16

void transverse(int ***gridArray, int i, int j, double *numPaths);

int main() {
	int i,j;
    double numPaths=0;
    int **gridArray;					//0: down only, 1: right only, 2: both, 3: end of grid
    
    //initialize grid
    gridArray = malloc((TARGET+1)*sizeof(int *));
    for(i=0;i<(TARGET+1);i++) {
        gridArray[i] = malloc((TARGET+1)*sizeof(int));
    }
    for(i=0;i<(TARGET+1);i++) {
        for(j=0;j<(TARGET+1);j++) {
            if(i==TARGET) {				//initializing the bottom of grid
                gridArray[i][j]=1;
            }
            else if(j==TARGET) {		//initializing the right of grid
                gridArray[i][j]=0;
            }
            else {
            	gridArray[i][j]=2;		//initializing all other points on the grid
            }
        }
    }
    gridArray[TARGET][TARGET]=3;		//initializing the bottom-right corner
    
    transverse(&gridArray,0,0,&numPaths);
    printf("There are a total of %.0f paths in a %dx%d grid.\n",numPaths,TARGET,TARGET);

    return 0;
}

void  transverse(int ***gridArray, int i, int j, double *numPaths) {
    if((*gridArray)[i][j]==0) {
        transverse(gridArray,(i+1),j,numPaths);	//traverse down only
    }
    else if((*gridArray)[i][j]==1) {
        transverse(gridArray,i,(j+1),numPaths);	//traverse right only
    }
    else if((*gridArray)[i][j]==2) {
        transverse(gridArray,i,(j+1),numPaths);	//traverse both right
        transverse(gridArray,(i+1),j,numPaths);	//and down
    }
    else {
        *numPaths+=1.0;							//if end is reached, increase path count
    }
}
