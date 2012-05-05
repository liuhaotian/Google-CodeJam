#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b)
{
	long c;
	while(1)
	{
		c = a % b;
		if(c == 0)
			return b;
		a = b;
		b = c;
	}
}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N;
	long i, j, k;
	char** tab;
	double score[100];
	long winloss[100][2];
	double wp[100];
	double owp[100];
	long out;

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld\n", &N);
		//printf("%ld\n", N);
		memset(wp, 0, 100*sizeof(double));
		memset(score, 0, 100*sizeof(double));
		memset(owp, 0, 100*sizeof(double));

		tab = malloc(sizeof(char*)*N);
		for (j = 0; j < N; ++j)
		{
			tab[j] = malloc(sizeof(char)*N);
			fscanf(fin, "%s\n", tab[j]);
		}

		/*
		for (j = 0; j < N; ++j)
		{
			printf("%s\n", tab[j]);
		}
		*/

		for (j = 0; j < N; ++j)
		{
			winloss[j][0] = 0;
			winloss[j][1] = 0;
			for (k = 0; k < N; ++k)
			{
				if (tab[j][k] == '1')
				{
					winloss[j][0]++;
				}
				else if (tab[j][k] == '0')
				{
					winloss[j][1]++;
				}
			}
			//printf("%ld:w:%ld,l:%ld\n", N, winloss[j][0], winloss[j][1]);
			wp[j] = 1.0 * winloss[j][0] / winloss[j][1];
		}

		for (j = 0; j < N; ++j)
		{
			owp[j] = 0;
			for (k = 0; k < N; ++k)
			{
				if(k == j)continue;
				owp[j] += 
			}
		}

		
		//out = mintime(time_string);
		//out = calc(N, PD, PG);

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