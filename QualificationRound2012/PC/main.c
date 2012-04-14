#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	int T;
	unsigned long int A, B;
	int i;
	long int j, k;
	fscanf(fin, "%d\n", &T);

	char in[40];
	unsigned long long out;
	char ocase[40];
	char * tab;
	unsigned long int tmp;
	unsigned long int A0;

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%lu ", &A);
		//printf("%lu\n", A);
		fscanf(fin, "%lu", &B);
		//printf("%lu\n", B);
		out = 0;

		for (A0 = 1; A/A0 > 10; A0 *= 10)
		{
			;
		}
		//printf("%ld\n", A0);

		tab = calloc(B, sizeof(char));
		for (j = A; j <= B; ++j)
		{
			for (k = 10; k <= A0; ++k)
			{
				tmp = j / k + (j % k) * (A0 / k) * 10;
				if(tmp < A)continue;
				if(tmp > B)continue;
				tab[ tmp ] = 1;
			}
		}
		for (j = A; j <= B; ++j)
		{
			out += tab[i];
		}
		free(tab);

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