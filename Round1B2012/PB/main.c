#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N;
	long i, j;
	long out;
	long pvalue[500];

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld ", &N);
		//printf("%ld ", N);

		for (j = 0; j < N - 1; ++j)
		{
			fscanf(fin, "%ld ", &pvalue[j]);
			printf("%ld ", pvalue[j]);
		}
		fscanf(fin, "%ld\n", &pvalue[j]);
		printf("%ld ", pvalue[j]);

		//out = mintime(time_string);

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