#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T;
	long i;
	long out;

	fscanf(fin, "%lld\n", &T);
	char ocase[40];

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%lld ", &H);
		mirrorhall.H = H;
		//printf("%lld\n", H);
		




		sprintf(ocase, "Case #%lld: %lld", i + 1, out);
		printf("%s\n", ocase);
		
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