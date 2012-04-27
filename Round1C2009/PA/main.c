#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long mintime(char* const time_string){
	long i;
	long base[256];
	memset(base, -1, 256 * sizeof(long));
	long basenum = 0;
	long ret = 0;

	for (i = 0; i < strlen(time_string); ++i)
	{
		if(base[time_string[i]] == -1){
			//printf("%c\n", time_string[i]);
			if (basenum == 0)
			{
				base[time_string[i]] = 1;
			}
			else if (basenum == 1)
			{
				base[time_string[i]] = 0;
			}
			else
				base[time_string[i]] = basenum;
			basenum++;
		}
			
	}
	if(basenum == 1) basenum = 2;

	//printf("%ld\n", basenum);

	for (i = 0; i < strlen(time_string); ++i)
	{
		ret = base[time_string[i]] + ret * basenum;
		//printf("%ld\n", ret);
	}



	return ret;
}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T;
	char time_string[80];
	long i;
	long out;

	fscanf(fin, "%ld\n", &T);
	char ocase[40];

	for (i = 0; i < T; ++i)
	{
		memset(time_string, 0, 80);
		fscanf(fin, "%s\n", time_string);
		//printf("%s\n", time_string);
		
		out = mintime(time_string);

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