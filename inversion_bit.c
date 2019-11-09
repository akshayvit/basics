#include <stdio.h>

int getsum(int bit[],int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i-=(i&-i);
	}
	return sum;
}

void update(int bit[],int  i,int val,int n)
{
	//int sum=0;
	while(i<=n)
	{
		bit[i]+=val;
		i+=(i&-i);
	}
}

main()
{
	int arr[]={2,4,1,8,6};
	int max=-1;
	int i;
	for(i=0;i<5;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	int bit[max+1],inv=0;
	for(i=0;i<=max;i++)
	{
		bit[i]=0;
	}
	for(i=4;i>=0;i--)
	{
		inv+=getsum(bit,arr[i]-1);
		update(bit,arr[i],1,max+1);
	}
	for(i=0;i<=max;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n%d\n",inv);
}
