/* Michael Delaney - this program reads data from a csv file */
#include <stdio.h>
#include <stdlib.h>
#include "csvRead.h"
#include "knnFlower.h"

//access using dataStream[x].sL
int main(){

	int lineCount = 0;	
	flower_t *dataStream = readCSV(dataStream);
	
	flower_t inputData = readUserInput();	

	for(; lineCount < 150; lineCount++){
//		printf("\nLine count: %d\n", lineCount+1);	
//		printf("Class: %s\n", dataStream[lineCount].fClass);
//		printf("sL: %f\n", dataStream[lineCount].sL);
//		printf("sW: %f\n", dataStream[lineCount].sW);
//		printf("pL: %f\n", dataStream[lineCount].pL);
//		printf("pW: %f\n", dataStream[lineCount].pW);
	}
	
	vector_t *flowerHead = evaluateDistance(dataStream, inputData, lineCount);
	
//	flowerHead = nearestNeighbors(flowerHead);

	for(int j = 0; j < lineCount; j++){
		flowerHead[j].vectorLength /= 1000; //divide by 1000 to return the original (correct) vector length	
		printf("Class: %s\t - \tVector Length: %lf\n", flowerHead[j].type, flowerHead[j].vectorLength); 

	}

	free(dataStream);
	free(flowerHead);
	
	return 0;


}

