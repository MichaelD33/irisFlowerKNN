/* Michael Delaney - CSV File Reading Library - csvRead.c */
#include "csvRead.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Program notes: last two printed values are duplicates
 *
*/

flower_t readCSV(flower_t csvData) {

  char buffer[BUFFER_SIZE];
  int lineCount = 0;

  printf("buffer size: %lu\n", sizeof(buffer));

  FILE *irisCsv = fopen("iris.csv", "r");

  if (!irisCsv) {

    printf("File could not be found\n");
    exit(EXIT_FAILURE);
  }

  while (!feof(irisCsv)) {

    while (fgets(buffer, sizeof(buffer), irisCsv) != NULL) {
      	if(sscanf(buffer, "%f, %f, %f, %f, %s", &csvData.sL, &csvData.sW, &csvData.pL, &csvData.pW, csvData.fClass) == 0){

            printf("%s\n", buffer); 
	    printf("scan failed.\n");
            exit(EXIT_FAILURE);

      }else{

	      printf("%f, %f, %f, %f, %s\n", csvData.sL, csvData.sW, csvData.pL, csvData.pW, csvData.fClass);

	      for(int i = 0; i<sizeof(buffer); i++){
			      
		if(buffer[i] == '\n') lineCount++;
      	      
		}
	      break;
    	}
     }	
  }

     printf("Line count: %d\n", lineCount);
     return csvData;

}

