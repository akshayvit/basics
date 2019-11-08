#include <iostream>
using namespace std;
int main()
{
    int* a=new int[5];
    for(int i=0;i<5;i+=1){
        *(a+i)=i;
    }
    std::cout<<a[3]<<"\n"<<4[a]<<"\n"<<*(a+3);
    return 0;
}
