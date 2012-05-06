#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

long findmin(long* pvalue, long N, long index){
	long i, min, ret;
	min = pvalue[0] + pvalue[1];
	for (i = 0; i < N; ++i)
	{
		if(i == index)continue;
		if (pvalue[i] <= min)
		{
			ret = i;
		}
	}
	return ret;
}

double getout(long* pvalue, long N, long* pmark, long X, long index, double f){
	long i, tempsum=0, tempnum=0;
	double tempout;

	for (i = 0; i < N; ++i)
	{
		if (pvalue[i] <= pvalue[index] + f * X)
		{
			pmark[i] = 1;
			tempsum += pvalue[i];
			tempnum++;
		}
	}
	tempout = ((tempsum + X) * 1.0 / tempnum - pvalue[index]) / X;
	if (tempout <= 0)
	{
		return 0;
	}
	else if(tempout < f){
		return getout(pvalue, N, pmark, X, index, tempout);
	}
	else
		return f;
}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N, num, tempsum;
	long i, j, k, thatindex;
	double out[200];
	long pvalue[200];
	long pmark[200];
	long X;
	char ocase[20];

	fscanf(fin, "%ld\n", &T);


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld ", &N);
		//printf("%ld ", N);

		X = 0;
		memset(pvalue, 0, sizeof(long));
		memset(pmark, 0, sizeof(long));
		memset(out, 0, sizeof(double));
		for (j = 0; j < N - 1; ++j)
		{
			fscanf(fin, "%ld ", &pvalue[j]);
			X += pvalue[j];
			//printf("%ld ", pvalue[j]);
		}
		fscanf(fin, "%ld\n", &pvalue[j]);
		X += pvalue[j];

		for (j = 0; j < N; ++j)
		{
			memset(pmark, 0, sizeof(long));
			out[j] = 100 * getout(pvalue, N, pmark, X, j, 1.0);

		}


		//printf("%ld\n", pvalue[j]);
		//printf("%d\n", (int)sizeof(double));

		
		sprintf(ocase, "Case #%ld: ", i + 1);
		//printf("%s\n", ocase);
		
		if (i != T - 1)
		{
			fprintf (fout, "%s", ocase);
			for (j = 0; j < N - 1; ++j)
			{
				fprintf (fout, "%.6f ", out[j]);
			}
			fprintf (fout, "%.6f\n", out[j]);
		}
		else{
			fprintf (fout, "%s", ocase);
			for (j = 0; j < N - 1; ++j)
			{
				fprintf (fout, "%.6f ", out[j]);
			}
			fprintf (fout, "%.6f", out[j]);
		}
		

	}

	fclose(fin);
	fclose(fout);


	return 0;
}