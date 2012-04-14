#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	int T;
	long int A, B;
	int i, j;
	fscanf(fin, "%d\n", &T);

	char in[40];
	unsigned long long out;
	char ocase[40];

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%lu ", &A);
		//printf("%lu\n", A);
		fscanf(fin, "%lu", &B);
		//printf("%lu\n", B);

		sprintf(ocase, "Case #%d: %llu", i+1, out);
		
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