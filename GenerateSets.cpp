#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() 
{
	FILE *training, *testing, *data;
	data = fopen("datafile.txt");
	training = fopen("trainingfile.txt", "w");
	testing = fopen("testingfile.txt", "w");

	if((data == NULL ) || (testing == NULL) || (training == NULL))
	{
		printf("ERROR");
		exit(1);
	}

	int traincounter, testcounter, linecounter, row; // trainingcounter, testing counter, counter for the file. 
	traincounter = testcounter = linecounter = 1;
	char buffer [200]; 

	while(traincounter <= 80000)
	{
		row = (rand() % 100000) + 1;
		printf(fgets(buffer, 200, data));
		fprintf(training, "%s\n", buffer);
		traincounter++;
	}





}