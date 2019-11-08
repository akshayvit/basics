#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
vector<int> find(int n);
void getfact(int n);
bool isprime(int n);
int main()
{
    //cout << "Hello World!" << endl;
    int n;
    std::cin>>n;
    std::cout<<isprime(2)<<" "<<isprime(97)<<" "<<isprime(1004)<<" "<<isprime(101)<<"\n";
    getfact(n);
    return 0;
}
vector<int> find(int n){
    bool temp[n+1];
    vector<int> v;
    memset(temp,false,n+1);
    for(int i=0;i<n+1;i++){
        if(i%2==0){
            temp[i]=true;
        }
        else if(i%3==0){
            temp[i]=true;
        }
        else if(i%5==0){
            temp[i]=true;
        }
    }
    for(int i=2;i<n+1;i++){
        if(temp[i]==false){
            v.push_back(i);
        }
    }
    return v;
}
bool isprime(int n){
    if(n==2 || n==3){
        return true;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void getfact(int n){
    if(n>2 && n%2==0){
    vector<int> v=find(n);
    for(int i=0;i<v.size();i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<"\n";
    for(int i=0;v[i]<=n/2;i++){
        if(isprime(n-v[i])){
            std::cout<<v[i]<<"+"<<n-v[i]<<"\n";
        }
    }
    }
    else{
        std::cout<<"No"<<"\n";
        return;
    }
}