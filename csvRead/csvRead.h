/* Michael Delaney - csvRead.h */

#ifndef CSVREAD_h
#define CSVREAD_h

#define BUFFER_SIZE 1024
#define FIRSTLINE 0

typedef struct{

	float sL;
	float sW;
	float pL;
	float pW;
	char fClass[16];

}flower_t;

flower_t *readCSV(flower_t *csvData);

#endif
