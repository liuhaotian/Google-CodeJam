#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N, A;
	double D;
	double car[2000][2];
	double acc[250];
	long i, j;
	long out;

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%f %ld %ld\n", &D, &N, &A);
		printf("%f %ld %ld\n", D, N, A);

		memset(car, 0, 2000*2*sizeof(double));
		memset(acc, 0, 250*sizeof(double));

		for (j = 0; j < N; ++j)
		{
			fscanf(fin, "%f %f\n", &car[j][0], &car[j][1]);
			printf("%f %f\n", car[j][0], car[j][1]);
		}

		for (j = 0; j < A - 1; ++j)
		{
			fscanf(fin, "%f ", &acc[j]);
			printf("%f ", acc[j]);
		}
		fscanf(fin, "%f ", &acc[j]);
		printf("%f\n", acc[j]);



		sprintf(ocase, "Case #%ld: %ld", i + 1, out);
		//printf("%s\n", ocase);
		
		if (i != T - 1)
		{
			fprintf (fout, "%s\n", ocase);
		}
		else
			fprintf (fout, "%s", ocase);
		
	}

	fclose(fin);
	fclose(fout);


	return 0;
}