/* Michael Delaney - kNNFlower.h */

#ifndef KNNFLOWER_h
#define KNNFLOWER_h

enum flowerClass{ setosa = 0, versicolor = 1, virginica = 2};


typedef struct vector_t{

	double vectorLength;
	char* type;

} vector_t;

vector_t *evaluateDistance(flower_t*, flower_t, int);
vector_t *nearestNeighbors(vector_t*);
flower_t readUserInput();
int sortFlowers(const void*, const void*);



#endif
