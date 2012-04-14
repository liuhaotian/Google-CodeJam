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

void mirTheWall(mirrorobj* mirrorhall);

void printMap(mirrorobj* mirrorhall);

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
		mirrorhall.H = H;
		//printf("%lld\n", H);
		fscanf(fin, "%lld ", &W);
		mirrorhall.W = W;
		//printf("%lld\n", W);
		fscanf(fin, "%lld\n", &D);
		mirrorhall.D = D;
		//printf("%lld\n", D);

		out = 0;

		//readMirror(fin, mirrorhall);
		mirrorhall.map = calloc(H * W + 1, sizeof(char));
		for (j = 0; j < H; ++j)
		{
			fscanf(fin, "%s\n", mirrorhall.map + W * j );
		}
		for (j = 0; j < W; ++j)
		{
			for (k = 0; k < H; ++k)
			{
				if (mirrorhall.map[j + W * k] == 'X')
				{
					mirrorhall.Xx = j;
					mirrorhall.Xy = k;
				}
			}
		}
		//printf("%s", mirrorhall.map);
		//printMap(&mirrorhall);

		//mirTheWall(mirrorhall);
		
		while(
				((mirrorhall.Xx + 0.5 - 1) * 2 <= mirrorhall.D) ||
				((mirrorhall.Xy + 0.5 - 1) * 2 <= mirrorhall.D) ||
				(((mirrorhall.W - mirrorhall.Xx - 0.5 - 1)) * 2 <= mirrorhall.D) ||
				(((mirrorhall.H - mirrorhall.Xy - 0.5 - 1)) * 2 <= mirrorhall.D)
				){
			mirTheWall(&mirrorhall);
		}
		//mirTheWall(&mirrorhall);


		printMap(&mirrorhall);

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

void mirTheWall(mirrorobj* mirrorhall){
	long long int W = (*mirrorhall).W;
	long long int H = (*mirrorhall).H;
	long long int D = (*mirrorhall).D;
	long long int newW = 3 * W - 4;
	long long int newH = 3 * H - 4;

	long long int i, X0, Y0;
	long long int j, k, newi, newj, oldi, oldj;
	long long int Xx, Xy;
	Xx = (*mirrorhall).Xx + W - 2;
	Xy = (*mirrorhall).Xy + H - 2;

	char* newmap = calloc(newH * newW + 1, sizeof(char));
	memset(newmap, 'U', newW * newH);

	// copy to the main
	for (i = 0; i < W; ++i)
	{
		oldi = i;
		newi = W - 2 + i;

		for (j = 0; j < H; ++j)
		{
			oldj = j;
			newj = H - 2 + j;

			newmap[newi + newW * newj] = (*mirrorhall).map[i + j * W];
		}
	}

	// copy to the left
	X0 = W * 2 - 3;
	for (i = 0; i < W - 1; ++i)
	{
		oldi = i + W - 1;
		newi = X0 - oldi;
		for (j = 0; j < newH; ++j)
		{
			oldj = j;
			newj = j;
			newmap[newi + newW * newj] = newmap[oldi + newW * oldj];
		}
	}

	// copy to the right
	//X0 = W * 2 - 1;
	for (i = 0; i < W - 1; ++i)
	{
		oldi = i;
		newi = newW - oldi - 1;
		for (j = 0; j < H; ++j)
		{
			oldj = j;
			newj = H - 2 + j;
			newmap[newi + newW * newj] = (*mirrorhall).map[oldi + W * oldj];
		}
	}

	// copy to the up
	Y0 = H * 2 - 3;
	for (i = 0; i < newW; ++i)
	{
		oldi = i;
		newi = i;
		for (j = 0; j < H - 1; ++j)
		{
			oldj = j + H - 1;
			newj = Y0 - oldj;
			newmap[newi + newW * newj] = newmap[oldi + newW * oldj];
		}
	}

	// copy to the up
	Y0 = H * 4 - 7;
	for (i = 0; i < newW; ++i)
	{
		oldi = i;
		newi = i;
		for (j = 0; j < H - 1; ++j)
		{
			oldj = j + H - 1;
			newj = Y0 - oldj;
			newmap[newi + newW * newj] = newmap[oldi + newW * oldj];
		}
		newmap[newi + newW * (newH - 1)] = '#';
	}

	free((*mirrorhall).map);
	(*mirrorhall).map = newmap;
	(*mirrorhall).W = newW;
	(*mirrorhall).H = newH;
	(*mirrorhall).Xx = Xx;
	(*mirrorhall).Xy = Xy;

	//printf("%c\n", newmap[Xx + newW * Xy]);
}

void printMap(mirrorobj* mirrorhall){
	long long int W = (*mirrorhall).W;
	long long int H = (*mirrorhall).H;
	long long int D = (*mirrorhall).D;
	char* map = (*mirrorhall).map;

	char* tmpline = calloc(W + 1, sizeof(char));

	long long int i;

	//printf("%lld %lld %lld\n", H, W, D);
	//printf("%s\n", map);
	for (i = 0; i < H; ++i)
	{
		memcpy(tmpline, map + W * i, W);
		tmpline[W] = 0;
		printf("%s\n", tmpline);
	}
	//printf("%s\n", map);
	printf("\n");

	free(tmpline);
}