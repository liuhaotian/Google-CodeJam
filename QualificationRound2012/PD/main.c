#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#define U_L 100000000b
#define U_M	010000000b
#define U_R 001000000b
#define M_L 000100000b
#define M_M	000010000b
#define M_R 000001000b
#define D_L 000000100b
#define D_M	000000010b
#define D_R 000000001b
*/

//when X' been touch, it become a Y, that don't reflect anything, it absorb everything

typedef struct
{
	long long int H, W, D;
	char* map;
	long long int Xx, Xy;
} mirrorobj;

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long long int T, H, W, D;
	long long int i;
	long long int j, k;
	mirrorobj mirrorhall;

	fscanf(fin, "%lld\n", &T);

	long long int out;
	char ocase[40];

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%lld ", &H);
		//printf("%lld\n", H);
		fscanf(fin, "%lld ", &W);
		//printf("%lld\n", W);
		fscanf(fin, "%lld\n", &D);
		//printf("%lld\n", D);

		out = 0;

		//readMirror(fin, mirrorhall);
		mirrorhall.map = calloc(H * W + 1, sizeof(char));
		for (j = 0; j < H; ++j)
		{
			fscanf(fin, "%s\n", mirrorhall.map + W * j );
		}
		//printf("%s", mirrorhall.map);
		//mirTheWall(mirrorhall);
		//mirTheNode();
		//travTheHall();





		sprintf(ocase, "Case #%lld: %lld", i + 1, out);
		//printf("%s\n", ocase);
		/*
		if (i != T - 1)
		{
			fprintf (fout, "%s\n", ocase);
		}
		else
			fprintf (fout, "%s", ocase);
		*/
	}

	fclose(fin);
	fclose(fout);


	return 0;
}