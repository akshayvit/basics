#include <bits/stdc++.h>
using namespace std;

char st[1000000],t[1000000],z[1000000];

void changer(int length,char s[])
{
    //cout<<s<<"\n";
    int p=0;
    if(length==1)
		{
		    if(s[0]=='9')
		    printf("11\n");
		    else{
		    s[0]+=1;
		   cout<<s<<"\n";}
		}
		else{
    if(length%2==0)
		{
			for(int i=length-1;i>=length/2;i--)
			{
				s[i]=s[length-i-1];
			}
			if(strcmp(s,t)>0)
			{
				
			}
			else
			{
				if(s[(length/2)-1]!='9' && s[length/2]!='9'){
				s[(length/2)-1]++;
				s[length/2]++;
				}
				else
				{
					if(s[length/2]=='9' && s[(length/2)-1]!='9')
					{
						s[(length/2)-1]++;
						s[length/2]='0';
					}
					else
					{
						s[length/2]='0';
				    int carry=1,i=1;
				    while(carry>0 && (length/2)-i>=0)
				    {
				        
				        if(s[(length/2)-(i)]<'9')
				        {
				            s[(length/2)-(i)]+=carry;
				            carry=0;
				        }
				        else
				        {
				            s[(length/2)-(i)]='0';
				        }
				        i++;
				    }
				    //cout<<s<<"\n";
				    char ar[length+2];
				    if((length/2)-i+1==p && carry==1)
				    {
				        for(int j=length;j>p;j--)
				        {   
				            ar[j]=s[j-1];
				        }
				    
				    ar[0]='1';
				    ar[length+1]='\0';
				     for(int i=length;i>=(length+1)/2;i--)
			{
				ar[i]=ar[length-i];
			}
				    strcpy(s,ar);
				    }
				    else
				    {
				        
		for(int i=length-1;i>=length/2;i--)
			{
				s[i]=s[length-i-1];
			}
				    }
					}
				}
			}
		}
		else
		{
			for(int i=length-1;i>=length/2;i--)
			{
				s[i]=s[length-i-1];
			}
			if(strcmp(s,t)>0)
			{
			}
			else
			{
				if(s[(length/2)]!='9')
				{
				s[length/2]++;
				}
				else
				{
				    s[length/2]='0';
				    int carry=1,i=1;
				    while(carry>0 && (length/2)-i>=0)
				    {
				        
				        if(s[(length/2)-(i)]<'9')
				        {
				            s[(length/2)-(i)]+=carry;
				            carry=0;
				        }
				        else
				        {
				            s[(length/2)-(i)]='0';
				        }
				        i++;
				    }
				    char ar[length+2];
				    if((length/2)-i+1==p && carry==1)
				    {
				        for(int j=length;j>p;j--)
				        {   
				            ar[j]=s[j-1];
				        }
				    
				    ar[0]='1';
				    ar[length+1]='\0';
				     for(int i=length;i>=(length+1)/2;i--)
			{
				ar[i]=ar[length-i];
			}
				    strcpy(s,ar);
				    }
				    else
				    {
				        for(int i=length-1;i>=length/2;i--)
			{
				s[i]=s[length-i-1];
			}
				    }
				}
			}
		}
		cout<<s<<"\n";
		}
}

int main() {
	
	// your code here
	int n;
	std::cin>>n;
	while(n--)
	{
		scanf("%s",st);
		int length=strlen(st);
		if(length==0)
		  continue;
		else{
		        int p=0;
		        if(st[0]=='0')
		        {
		            
		            int j;
		            for(j=0;st[j]=='0';j++);
		            if(j>length-1)
		            {
		                printf("1\n");
		            }
		            else{
		            int k=-1;
		            while(st[j]!='\0')
		            {
		                z[++k]=st[j++];
		            }
		            z[++k]='\0';
		           // printf("Z: %s\n",z);
		          //  strcpy(s,z);
		          strcpy(t,z);
		          changer(strlen(z),z);
		            }
		        }
		      else
		      {
		          
		          strcpy(t,st);
		          changer(strlen(st),st);
		      }
		
		}
	}
	return 0;
}