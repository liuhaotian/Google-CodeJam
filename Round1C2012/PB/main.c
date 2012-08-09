#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double t, d, v, a;
double D;
double car[2000][2];
double acc[250];

double deltaT(){
	return (sqrt(v * v - 2 * a * (d - D)) - v) / a;
}

long update(long j){
	double dt = car[j][0] - car[j - 1][0];
	//printf("%lf\n", dt);
	double vcar = (car[j][1] - car[j-1][1]) / dt;
	double dmine = v*dt + 0.5*a*dt*dt + d;

	if (dmine > car[j][1])
	{
		dmine = car[j][1];
		d = car[j][1];
		v = sqrt(v*v + 2*a*(car[j][1] - car[j-1][1]));
		t = car[j][0];
		return 1;
	}
	else{
		
		if (car[j][1] == D)
		{
			t = t + deltaT();
			d = D;
			
			return 1;
		}
		return 1;
	}
	return 1;
}

long gcd(long a,long b){long c;while(1){c = a % b;if(c == 0)return b;a = b;b = c;}}

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	long T, N, A;
	//double D;

	long i, j, k;
	double out[250];

	fscanf(fin, "%ld\n", &T);
	char ocase[40];


	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%lf %ld %ld\n", &D, &N, &A);
		//printf("%lf %ld %ld\n", D, N, A);

		memset(car, 0, 2000*2*sizeof(double));
		memset(acc, 0, 250*sizeof(double));
		memset(out, 0, 250*sizeof(double));

		for (j = 0; j < N; ++j)
		{
			fscanf(fin, "%lf %lf\n", &car[j][0], &car[j][1]);
			//printf("%lf %lf\n", car[j][0], car[j][1]);
		}

		for (j = 0; j < N; ++j)
		{
			if (car[j][1] >= D)
			{
				N = j + 1;
				break;
			}
		}

		for (j = 0; j < A - 1; ++j)
		{
			fscanf(fin, "%lf ", &acc[j]);
			//printf("%lf ", acc[j]);
		}
		fscanf(fin, "%lf ", &acc[j]);
		//printf("%lf\n", acc[j]);

		for (j = 0; j < A; ++j)
		{
			d = 0;
			t = 0;
			v = 0;
			a = acc[j];
			out[j] = 0;
			double wait = 0;

			if (N == 1)
			{
				out[j] = deltaT();
				continue;
			}
			else if (car[N - 1][1] > D)
			{
				car[N - 1][0] = (D - car[N - 2][1]) / (car[N - 1][1] - car[N - 2][1]) * (car[N - 1][0] - car[N - 2][0]) + car[N - 2][0];
				car[N - 1][1] = D;
			}

			for (k = 0; k < N; ++k)
			{
				if(sqrt(car[k][1] * 2 / a) + wait < car[k][0]){
					wait = car[k][0] - sqrt(car[k][1] * 2 / a);
				}
			}
			out[j] = wait + sqrt(D * 2 / a);
		}



		sprintf(ocase, "Case #%ld:", i + 1);
		//printf("%s\n", ocase);
		
		if (i != T - 1)
		{
			fprintf (fout, "%s\n", ocase);
			for (j = 0; j < A; ++j)
			{
				fprintf (fout, "%.7lf\n", out[j]);
			}
		}
		else{
			fprintf (fout, "%s\n", ocase);
			for (j = 0; j < A - 1; ++j)
			{
				fprintf (fout, "%.7lf\n", out[j]);
			}
			fprintf (fout, "%.7lf", out[j]);
		}
			//fprintf (fout, "%s", ocase);
		
	}

	fclose(fin);
	fclose(fout);


	return 0;
}