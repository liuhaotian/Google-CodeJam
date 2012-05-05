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
	
	long T, N, PD, PG;
	long i;
	long out;

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld %ld %ld\n", &N, &PD, &PG);
		//printf("%ld %ld %ld\n", N, PD, PG);
		
		//out = mintime(time_string);
		out = calc(N, PD, PG);

		sprintf(ocase, "Case #%ld: %s", i + 1, out?out_true:out_false);
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