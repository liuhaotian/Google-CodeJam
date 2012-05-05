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

struct tab
{
	long nwin;
	long nloss;
} ptab[101];

long calc(long N, long PD, long PG){
	long ret = 0;
	long D, G;

	if (N < ptab[PD].nwin + ptab[PD].nloss)
	{
		return 0;
	}
	if (PG == 100 && PD != 100)
	{
		return 0;
	}
	if (PG == 0 && PD != 0)
	{
		return 0;
	}

	return 1;

}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N, PD, PG;
	long i;
	long out;
	char out_true[] = "Possible";
	char out_false[] = "Broken";

	fscanf(fin, "%ld\n", &T);
	char ocase[40];

	for (i = 1; i < 100; ++i)
	{
		ptab[i].nwin = i / gcd(i, 100 - i);
		ptab[i].nloss = (100 - i) / gcd(i, 100 - i);
	}
	ptab[0].nwin = 0;
	ptab[0].nloss = 1;

	ptab[100].nwin = 1;
	ptab[100].nloss = 0;

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