#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	int T, N, S, p, t[110];
	int i, j;
	fscanf(fin, "%d\n", &T);

	char in[400];
	char out[400];
	char ocase[20];

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%d ", &N);
		fscanf(fin, "%d ", &S);
		fscanf(fin, "%d ", &p);
		for (j = 0; j < N - 1; ++j)
		{
			fscanf(fin, " %d", &(t[j]));
		}
		fscanf(fin, " %d\n", &(t[j]));
		printf("%s\n", (char *)t);

		//memset(ocase, 0, 20);
		//memset(in, 0, 120);
		//memset(out, 0, 120);
		sprintf(ocase, "Case #%d: ", i+1);
		strcpy(out, ocase);

		/*
		if (i != T -1)
		{
			fprintf (fout, "%s\n", out);
		}
		else
			fprintf (fout, "%s", out);
		*/
	}

	fclose(fin);
	fclose(fout);


	return 0;
}