/* Michael Delaney - CSV File Reading Library - csvRead.c */
#include "csvRead.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Program notes: last two printed values are duplicates
 * 
 * 
 * floats - 2400 bytes 
 * Setosa - 11 bytes
 * Versicolor - 15 bytes
 * Virginica - 14 bytes
 * 
 * Number of bytes in csvData ~ 4500
 * 
*/

flower_t *readCSV(flower_t *csvData) {
  int counter = 0;
 	
  //csvData = malloc(((counter+1) * (4*sizeof(float))) + (counter * (15*sizeof(char))));

  csvData = malloc(5000);
  FILE *irisCsv = fopen("iris.csv", "r");

  if (!irisCsv) {

    printf("File could not be found\n");
    exit(EXIT_FAILURE);
  }

  while (!feof(irisCsv)) {
  	if(fscanf(irisCsv, "%f,%f,%f,%f,%s\n", &csvData[counter].sL, &csvData[counter].sW, &csvData[counter].pL, &csvData[counter].pW, csvData[counter].fClass) != 0){


      }else{ 
 
	    printf("scan failed.\n");
            exit(EXIT_FAILURE);
      
      } ++counter;

  }
  fclose(irisCsv);
  return csvData;

}

