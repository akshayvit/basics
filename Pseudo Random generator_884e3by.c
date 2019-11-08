#include <stdio.h>
#include <math.h>

double generate(double k,int seed,double a,double m,double  c)
{
	double ran=k;
	int i;
	for(i=0;i<=seed;i++)
	{
	    ran=(double)fmod((a*ran+c),m);
	}
	return ran;
}

main()
{
	int seed;
	scanf("%d",&seed);
	int sum=0.0;
	int n=seed;
	int i;
	for(i=0;i<=seed;i++)
	{
		sum+=i;
	}
	double mean=(double)sum/(seed);
	double var;
	sum=0;
	for(i=0;i<n;i++)
	{
		sum+=(i-mean)*(i-mean);
	}
	var=(double)sum/seed;
	int L=1;
	double cl=(double)(1.5*L+5)/(1.0-sum);
	printf("%d",(int)fabs(generate(0.0,seed,mean,var,cl)));
	
}