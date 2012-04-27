#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N, PD, PG;
	long i;
	bool out;
	char out_true = "Possible";
	char out_false = "Broken";

	fscanf(fin, "%ld\n", &T);
	char ocase[40];

	for (i = 0; i < T; ++i)
	{
		memset(time_string, 0, 80);
		fscanf(fin, "%s\n", time_string);
		//printf("%s\n", time_string);
		
		//out = mintime(time_string);

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