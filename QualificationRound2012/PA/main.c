#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "r");

	int T, i, j;
	char tab[27];
	memset(tab, ' ', 26);
	tab['q'-'a']='z';
	tab['e'-'a']='o';
	tab['y'-'a']='a';
	tab['z'-'a']='q';

	char in[100];
	char out[120];
	char ocase[20];
	int offset;
	char * outp;

	fscanf(fin, "%d", &T);
	fgetc(fin);

	for (i = 0; i < T; ++i)
	{
		fgets(in, 100, fin);
		fgets(out, 120, fout);
		//printf("%s\n", in);
		//printf("%s\n", out);
		sprintf(ocase, "Case #%d: ", T);
		offset = strlen(ocase);
		//printf("tste\n");
		for (j = 0; in[j] != 0; ++j)
		{
			if(in[j] != ' '){
				tab[in[j]-'a']=out[j + offset];
			}
		}
	}

	printf("%s\n", tab);
	//fscanf(fin, "%d", &T);
	//printf("%d\n", T);
	fclose(fin);
	fclose(fout);


	return 0;
}