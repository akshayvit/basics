#include <stdio.h>
#include <string.h>


int main()
{
//    printf("Hello World!\n");
    char text[]="akshaychatterjee";
    char patt[]="tter";
    int len=strlen(patt),lenm=strlen(text);
    int lps[len];
    lps[0]=0;
    int i=0,j=1,k=1;
    while(k<len)
    {
        if(patt[i]==patt[j])
        {
            lps[k]=lps[i]+1;
            i++;
            j++;
        }
        else
        {
            lps[k]=0;
            i=lps[i-1];
        }
        k++;
    }
    int index=0;
    i=0;
    int find=-1,cnt=0;;
    while(i<len && index<lenm)
    {
        if(text[index]==patt[i])
        {
            cnt++;
            if(cnt==1)
            {
                find=index;
            }
            index++;
            i++;
        }
        else
        {
            cnt=0;
            index++;
            i=lps[i];
        }
    }
    printf("%d",find);
    return 0;
}