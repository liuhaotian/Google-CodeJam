#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long class[1000][1000];
long classnum[1000];
long mark[1000];
long N;

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

long addmark(long index){
	long i, ret = 0;
	for (i = 0; i < classnum[index]; ++i)
	{
		mark[class[index][i] - 1]++;
		if(mark[class[index][i] - 1] > 1)return 1;
		ret = addmark(class[index][i] - 1);
		if(ret == 1)return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T;
	long i, j, k;
	long out;
	char ocase[20];

	fscanf(fin, "%ld\n", &T);


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%ld\n", &N);
		//printf("start:%ld\n", N);

		memset(class, -1, 1000*1000*sizeof(long));
		memset(classnum, -1, 1000*sizeof(long));


		for (j = 0; j < N; ++j)
		{
			fscanf(fin, "%ld ", &classnum[j]);
			//printf("%ld ", classnum[j]);
			if(classnum[j] == 0)continue;
			for (k = 0; k < classnum[j] - 1; ++k)
			{
				fscanf(fin, "%ld ", &class[j][k]);
				//printf("%ld ", class[j][k]);
			}
			fscanf(fin, "%ld\n", &class[j][k]);
			//printf("%ld end\n", class[j][k]);
		}

		out = 0;
		for (j = 0; j < N; ++j)
		{
			memset(mark, 0, 1000*sizeof(long));
			out += addmark(j);
			if(out > 0)break;
		}

		//printf("%ld\n", pvalue[j]);
		//printf("%d\n", (int)sizeof(double));

		
		sprintf(ocase, "Case #%ld: %s", i + 1, out?"Yes":"No");
		//printf("%s\n", ocase);
		
		if (i != T - 1)
		{
			fprintf (fout, "%s\n", ocase);
		}
		else{
			fprintf (fout, "%s", ocase);
		}
		

	}

	fclose(fin);
	fclose(fout);


	return 0;
}