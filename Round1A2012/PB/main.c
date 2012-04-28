#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

long findmaxb(long * req, long N){
	long i;
	long max = 0, imax;
	for (i = 0; i < N; i++)
	{
		if (req[2*i + 1] >= max)
		{
			max = req[2*i + 1] ;
			imax = i;
		}
	}
	return imax;
}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N;
	long i, j;
	long req[2000];
	long out;
	long nstar;
	char bad[] = "Too Bad";

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld\n", &N);
		//printf("%ld\n", N);

		for (j = 0; j < N; ++j)
		{
			fscanf(fin, "%ld %ld\n", &req[2*j], &req[2*j+1]);
			printf("%ld %ld\n", req[2*j], req[2*j+1]);
		}
		printf("%ld\n", findmaxb(req, N));

		//out = mintime(time_string);
		out = 0;

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