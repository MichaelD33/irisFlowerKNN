/* Michael Delaney - this program reads data from a csv file */
#include <stdio.h>
#include <stdlib.h>
#include "csvRead.h"

int main(){
		
	flower_t flower1;

	flower1 = readCSV(flower1);
	
	printf("%f, %f, %f, %f, %s\n", flower1.sL, flower1.sW, flower1.pL, flower1.pW, flower1.fClass);

	return 0;
}
