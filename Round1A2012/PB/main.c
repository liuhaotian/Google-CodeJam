#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

long nstar;

long findmaxb(long * req, long N){
	long i;
	long max = 0, imax = -1;
	for (i = 0; i < N; i++)
	{
		if (req[4*i + 1] >= max && req[4*i + 1] <= nstar)
		{
			if (req[4*i+3] != 0)
			{
				continue;
			}
			max = req[4*i + 1] ;
			imax = i;
		}
	}
	return imax;
}

long findmina(long * req, long N){
	long i;
	long min = 2001, imin = -1;
	for (i = 0; i < N; i++)
	{
		if (req[4*i] <= min && req[4*i] <= nstar)
		{
			if (req[4*i+2] != 0)
			{
				continue;
			}
			min = req[4*i] ;
			imin = i;
		}
	}
	return imin;
}

long find2(long * req, long N){
	long i;
	long max = 0, imax = -1;
	for (i = 0; i < N; i++)
	{
		if (req[4*i + 1] >= max && req[4*i + 1] <= nstar)
		{
			if (req[4*i+3] != 0 || req[4*i+2] != 0)
			{
				continue;
			}
			max = req[4*i + 1] ;
			imax = i;
		}
	}
	return imax;
}

long find1(long * req, long N){
	long i;
	long max = 0, imax = -1;
	for (i = 0; i < N; i++)
	{
		if (req[4*i + 1] >= max && req[4*i] <= nstar)
		{
			if (req[4*i+3] != 0 || req[4*i+2] != 0)
			{
				continue;
			}
			max = req[4*i + 1] ;
			imax = i;
		}
	}
	return imax;
}

long getstar(long *req, long index){
	if (index%4 == 0)
	{
		req[index + 2] = 1;
		return 1;
	}
	else{
		if (req[index + 1] == 1)
		{
			req[index + 2] = 1;
			return 1;
		}
		else{
			req[index + 2] = 1;
			req[index + 1] = 1;
			return 2;
		}
	}
}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N;
	long i, j;
	long req[4000];
	long star[2000];
	long out;

	char bad[] = "Too Bad";
	long tempi;

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld\n", &N);
		//printf("%ld\n", N);

		memset(req, 0, sizeof(long)*4000);
		out = 0;
		nstar = 0;
		for (j = 0; j < N; ++j)
		{
			fscanf(fin, "%ld %ld\n", &req[4*j], &req[4*j+1]);
			printf("%ld %ld\n", req[4*j], req[4*j+1]);
		}
		//printf("%ld\n", findmaxb(req, N));

		while(1){
			tempi = find2(req, N);
			if (tempi != -1 && req[4*tempi + 1] <= nstar)
			{
				nstar += getstar(req, 4*tempi + 1);
				printf("2 step:%ld star:%ld\n", tempi, nstar);
				out++;
				continue;
			}
			tempi = findmaxb(req, N);
			if (tempi != -1 && req[4*tempi + 1] <= nstar)
			{
				nstar += getstar(req, 4*tempi + 1);
				printf("b step:%ld star:%ld\n", tempi, nstar);
				out++;
				continue;
			}
			tempi = findmina(req, N);
			if (tempi != -1 && req[4*tempi] <= nstar)
			{
				nstar += getstar(req, 4*tempi);
				printf("a step:%ld star:%ld\n", tempi, nstar);
				out++;
				continue;
			}
			break;
		}

		//out = mintime(time_string);
		if (out == 0)
			sprintf(ocase, "Case #%ld: %s", i + 1, bad);
		else
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