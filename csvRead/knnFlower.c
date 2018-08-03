/* Michael Delaney ~ Simple K-Nearest Neighbors Algorithm Implementation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "csvRead.h"
#include "knnFlower.h"

//d(a,b) = sqrt( (a1-b1)^2 + (a2-b2)^2 + (a3-b3)^2 + (a4-b4)^2 )

vector_t *nearestNeighbors(vector_t *flower){
	
	int comparisons;
	printf("\nEnter the desired number of comparisons to nearby neighbors: ");
	scanf("%d", &comparisons);

	int i, maximum = 0, setosaCount = 0, versicolorCount = 0, virginicaCount = 0;
	char *flowerEstimate;
	for(i = 0; i < comparisons; i++){

	//	printf("Neighbor #%d\tClass: %s\tVector Length %lf\n", i+1, flower[i].type, flower[i].vectorLength/1000);
	
		if(strcmp(flower[i].type, "Iris-setosa") == 0){
			
			setosaCount++;	
	
		}else if(strcmp(flower[i].type, "Iris-virginica") == 0){
			virginicaCount++;
	
		}else if(strcmp(flower[i].type, "Iris-versicolor") == 0){
			versicolorCount++;

		}else{

			fprintf(stderr, "NO SPECIFIED CLASS");
		}

		if(setosaCount > maximum){
			flowerEstimate = flower[i].type;
			maximum = setosaCount;
			
		}else if(versicolorCount > maximum){
			
			flowerEstimate = flower[i].type;
			maximum = versicolorCount;

		}else if(virginicaCount > maximum){

			flowerEstimate = flower[i].type;
			maximum = virginicaCount;
			
		}else{
			printf("no new maximum");
		//	fprintf(stderr, "Nearest Neighbor cannot be found");
		}
	}

	printf("Out of %d nearest neighbors, the most likely classification for the input flower is type %s\n.", i+1, flowerEstimate);
	return flower;
}

vector_t *evaluateDistance(flower_t *flowerData, flower_t inputFlower, int arrElements){

	vector_t *flower = (vector_t *) calloc(150, sizeof(vector_t));
	
	for(int i = 0; i < arrElements; i++){
	
		float d_sL = (inputFlower.sL-flowerData[i].sL);
		float d_sW = (inputFlower.sW-flowerData[i].sW);
		float d_pL = (inputFlower.pL-flowerData[i].pL);
		float d_pW = (inputFlower.pW-flowerData[i].pW);
	
		if(flower == NULL){
			printf("The given node cannot be NULL"); 
			return 0; 
		}else{
		
			flower[i].type = flowerData[i].fClass;
			flower[i].vectorLength = (sqrt(d_sL*d_sL + d_sW*d_sW + d_pL*d_pL + d_pW*d_pW)*1000); //multiplying by 1000 because sorting function returns type int.	
		
		printf("Neighbor #%d\tClass: %s\tVector Length %lf\n", i+1, flower[i].type, flower[i].vectorLength/1000);
		}
	}
		
	// void qsort(base, num, size, comp);
	qsort(flower, arrElements, sizeof(*flower), sortFlowers);
	
	return flower;

}

flower_t readUserInput(){

	flower_t userData;
	int comparisons;

	printf("Flower Type Classifier. Enter the requested information in order to classify a type.\n");

	printf("Enter the length of the sepals: ");
	scanf("%f", &userData.sL);
	printf("\nEnter the width of the sepals: ");
	scanf("%f", &userData.sW);
	printf("\nEnter the length of the petals: ");
	scanf("%f", &userData.pL);
	printf("\nEnter the width of the petals: ");
	scanf("%f", &userData.pW);

//	printf("\nYou entered: %f, %f, %f, %f\n", userData.sL, userData.sW, userData.pL, userData.pW);
	
	return userData;

}


int sortFlowers(const void*  x, const void* y){

	int l = (int)((vector_t*)x)->vectorLength;
	int r = (int)((vector_t*)y)->vectorLength;	
	
	return(l-r);
}			


