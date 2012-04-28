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
	long * req[1000];
	long out;
	char bad[] = "Too Bad";

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld\n", &N);
		printf("%ld\n", N);

		req[0] = calloc(N, sizeof(long) * 2);


		for (j = 0; j < N; ++j)
		{
			req[j] = req[0] + 2 * j;
			fscanf(fin, "%ld %ld\n", &req[j][0], &req[j][1]);
			printf("%ld %ld\n", req[j][0], req[j][1]);
		}

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

		free(req[0]);
		
	}

	fclose(fin);
	fclose(fout);


	return 0;
}