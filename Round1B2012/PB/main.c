#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

long getsub(long* pvalue, long N, long sum, long index){
	long i, ret = sum,last;
	if (index = -1)
	{
		return -1;
	}

	for (int i = index; i >= 0; ++i)
	{
		if (pvalue[i] <= ret)
		{
			ret -= pvalue[i];
			last = i;
		}
	}
	if (ret != 0)
	{
		return getsub(pvalue, N, sum, index - 1);
	}
	else
		return last;
}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N;
	long i, j, k, l, m, n, o, p, q, r, s, t, u;
	long out;
	long pvalue[500];

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld ", &N);
		//printf("%ld ", N);

		for (j = 0; j < N - 1; ++j)
		{
			fscanf(fin, "%ld ", &pvalue[j]);
			//printf("%ld ", pvalue[j]);
		}
		fscanf(fin, "%ld\n", &pvalue[j]);
		//printf("%ld\n", pvalue[j]);
		for (j = 0; j < N; ++j)
		{
			for (k = j + 1; k < N; ++k)
			{
				
			}
		}
		//out = mintime(time_string);

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