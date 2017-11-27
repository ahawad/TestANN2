
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	FILE *datafile, *testing, *training;
	int array [6], i;
	datafile = fopen("datafile.txt", "w");
	training = fopen("trainingfile.txt", "w");
	testing = fopen("testingfile.txt", "w");

	int counter = 1;
	int trainingcounter = 1;
	int testingcounter = 1;

	if(datafile == NULL)
	{
		printf("ERROR");
		exit(1);

	}

// {SourceIP, DestIP, SourcePort, DestPort, TCP/UDP, Deny/Allow}
	int rules[26][6] =
	{
		1, 2, 1, 2, 1, 1,
		1, 2, 3, 2, 1, 0,
		1, 3, 1, 3, 1, 1,
		1, 3, 2, 3, 1, 0,
		1, 4, 1, 3, 1, 1,
		1, 4, 2, 3, 1, 0,
		2, 1, 2, 1, 1, 1,
		2, 1, 2, 3, 1, 0,
		2, 3, 2, 3, 1, 1,
		2, 3, 2, 1, 1, 0,
		2, 4, 2, 3, 1, 1,
		2, 4, 2, 1, 1, 0,
		3, 1, 3, 1, 1, 1,
		3, 1, 3, 2, 1, 0,
		3, 2, 3, 2, 1, 1,
		3, 2, 3, 1, 1, 0,
		3, 4, 3, 3, 1, 1,
		4, 1, 3, 1, 1, 1,
		4, 1, 3, 2, 1, 0,
		4, 2, 3, 1, 1, 0,
		4, 2, 3, 2, 1, 1,
		4, 3, 3, 3, 1, 1,
		1, 2, 1, 2, 2, 1,
		2, 1, 2, 1, 2, 1,
		4, 1, 3, 1, 2, 0,
		4, 2, 3, 2, 2, 0
	};

	fprintf(datafile, "100000 5 1 \n");


	while (counter <= 90000)
	{
		int row = (rand() % 26);
		for (int i = 0; i <= 5; i++)
		{
			fprintf(datafile, "%d ", rules[row][i]);

			if((testingcounter <= 20000) && (counter%6))
				fprintf(testing, "%d ", rules[row][i]);
				
			if((trainingcounter <= 80000) && (counter%3))
				fprintf(training, "%d ", rules[row][i]);
				
		}


		fprintf(datafile, "\n");
		fprintf(training, "\n");
		fprintf(testing, "\n");
		counter++;
		testingcounter++;
		trainingcounter++;
	}
	while(counter <= 100000)
	{
		int IPS = (rand() % 4) + 1; // Source IP
		int IPD = (rand() % 4) + 1; // Dest IP
		int PS = (rand() % 3) + 1; // Source Port
		int PD = (rand() % 3) + 1; // Dest Port
		int Prot = (rand() % 2) + 1; //Protocol
		int Action = (rand() % 2);

		fprintf(datafile, "%d %d %d %d %d %d \n", IPS, IPD, PS, PD, Prot, Action);
		counter ++;

		if(trainingcounter <= 80000)
		{
			fprintf(training, "%d %d %d %d %d %d \n", IPS, IPD, PS, PD, Prot, Action);
			trainingcounter++;
		}

		else if(testingcounter <= 20000)
		{
			fprintf(testing, "%d %d %d %d %d %d \n", IPS, IPD, PS, PD, Prot, Action);
			testingcounter++;
		}
	}

	fclose(datafile);
	fclose(training);
	fclose(testing);

}