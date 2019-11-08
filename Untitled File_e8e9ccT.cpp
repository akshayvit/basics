#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void printn(char* s);
void set(char **buf);
char arr[5]={'0','1','2','3','4'};
int n=5;
int main()
{
    //printf("Hello World!\n");
    const char* ss=(char*)'a';
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("%d\t",n);
    //int test[]={1,4,5,6,8,9};
    //printf("%d\n%d\n%d",test==test[0],test,*&test[0]);
    char *str=(char*)malloc(5*sizeof(char));;
    set(&str);
    puts(str);
    return 0;
}
void printn(char* s){
    printf("%d\n%c",n,s);
}
void set(char **buf)
{
    
    // 1. don't assign the other string, copy it to the pointer, to avoid memory leaks, using string literal etc.
    // 2. you need to allocate a byte for the null terminator as well
    strcpy(*buf, "test");
}