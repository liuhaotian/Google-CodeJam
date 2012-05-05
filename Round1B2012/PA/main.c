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
	long i, j, k;
	double out;
	float * P;
	double * E;

	fscanf(fin, "%ld\n", &T);
	char ocase[100];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld %ld\n", &A, &B);
		//printf("%ld %ld\n", A, B);
		//printf("%d\n", (int)sizeof(double));

		P = calloc(A + 1, sizeof(float));
		E = calloc(A + 1, sizeof(double));
		for (j = 1; j < A; ++j)
		{
			fscanf(fin, "%f ", &P[j]);
			//printf("%f\n", P[j]);
		}
		fscanf(fin, "%f\n", &P[j]);
		//printf("%f\n", P[j]);
		
		for (j = 1; j < A; ++j)
		{	
			E[j] = 1;
			for (k = 1; k <= A - j; ++k)
			{
				E[j] *= P[k];
			}
			E[j] = (1 - E[j]);
			//printf("%.7f\n", E[j]);

			E[j] = (B - A + 1) + 2 * j + E[j] * (B + 1);
			//printf("%.7f\n", E[j]);
		}
		
		//keep
		E[0] = 1;
		for (k = 1; k <= A; ++k)
		{
			E[0] *= P[k];
		}
		E[0] = (B - A + 1) + (1 - E[0]) * (B + 1);
		//printf("%.7f\n", E[0]);

		E[A] = B + 2;

		out = B + 2;
		for (j = 0; j <= A; ++j)
		{
			if (E[j] <= out)
			{
				out = E[j];
			}
		}
		//printf("\n");
		//out = 0;

		sprintf(ocase, "Case #%ld: %.6f", i + 1, out);
		//printf("%s\n", ocase);
		
		if (i != T - 1)
		{
			fprintf (fout, "%s\n", ocase);
		}
		else
			fprintf (fout, "%s", ocase);
		

		free(E);
		free(P);
	}

	fclose(fin);
	fclose(fout);


	return 0;
}