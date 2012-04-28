#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, A, B;
	long i, j;
	double out;
	float * P;

	fscanf(fin, "%ld\n", &T);
	char ocase[100];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld %ld\n", &A, &B);
		//printf("%ld %ld\n", A, B);
		//printf("%d\n", (int)sizeof(double));

		P = calloc(A, sizeof(float));
		for (j = 0; j < A - 1; ++j)
		{
			fscanf(fin, "%f ", &P[j]);
			//printf("%f\n", P[j]);
		}
		fscanf(fin, "%f\n", &P[j]);
		//printf("%f\n", P[j]);
		
		//out = mintime(time_string);
		out = 0;

		sprintf(ocase, "Case #%ld: %.6f", i + 1, out);
		//printf("%s\n", ocase);
		
		if (i != T - 1)
		{
			fprintf (fout, "%s\n", ocase);
		}
		else
			fprintf (fout, "%s", ocase);
		


		free(P);
	}

	fclose(fin);
	fclose(fout);


	return 0;
}