#include <stdio.h>
#include <math.h>

int generate(int i,int seed,double a,double c,double  m)
{
	if(i==seed)
	{
		return fmod((a*i+c),m);
	}
	return generate(i+1,seed,a,c,m);
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
	printf("%d",generate(0,seed,mean,var,cl));
	
}
