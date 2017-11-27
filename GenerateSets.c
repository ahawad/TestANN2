#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() 
{
	FILE *training, *testing, *data;
	data = fopen("datafile.txt", "w");
	training = fopen("trainingfile.txt", "w");
	//testing = fopen("testingfile.txt", "w");

	if((data == NULL ) )
	{
		printf("ERROR \n");
		exit(1);
	}

	int traincounter, testcounter, linecounter, row; // trainingcounter, testing counter, counter for the file. 
	traincounter = testcounter = linecounter = 1;
	char buffer [200]; 

	printf("%s", fgets(buffer, 200, data));

/*	while(traincounter <= 80000)
	{
		row = (rand() % 100000) + 1;

		printf("%s", fgets(buffer, 200, data));
		fprintf(training, "%s\n", buffer);
		traincounter++;
	}


*/


}