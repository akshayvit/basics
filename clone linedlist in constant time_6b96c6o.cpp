#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
    int data;
    node* next;
    node* arbit;
    node(int d){
        data=d;
        next=NULL;
    }
};
node* copylist(node* start);
/*{
    node* copy=start;
    node* c=copy;
    while(start!=null)
    {
        node* temp=start->next;
        node* del=next;
        start->next=copy;
        copy->next=temp;
        node->del=NULL;
        copy=start;
        start=start->next;
    }
    return c;
}*/
void arrange(node* m);
node* arrange_again(node* m);
int main()
{
    node* n=new node(3);
    node* n1=new node(5);
    node* n2=new node(7);
    node* n3=new node(2);
    node* n4=new node(1);
    n->next=n1;
    n->next->arbit=n;
    n->next->next=n2;
    n2->arbit=n;
    n->next->next->next=n3;
    n3->arbit=n1;
    n->next->next->next->next=n4;
    n4->arbit=n2;
    node* cpy=copylist(n);
    arrange(cpy);
    node* copy=arrange_again(n);
    std::cout<<"Values:"<<"\n";
    while(copy!=NULL)
    {
        std::cout<<" "<<copy->data<<"-->"<<" ";
        copy=copy->next;
    }
    return 0;
}
node* copylist(node* start)
{
    node* copy=start;
    node* c=copy;
    while(start!=NULL)
    {
        node* temp=start->next;
        start->next=NULL;
        start->next=copy;
        copy->next=temp;
        copy=start;
        start=start->next;
    }
    return c;
}
void arrange(node* m){
    while(m!=NULL)
    {
        node* temp=m;
        node* nt=temp->next;
        node* rd=nt->arbit;
        node* s=nt;
        nt=rd;
        rd=s;
        m=m->next;
    }
}
node* arrange_again(node* m)
{
    while(m!=NULL)
    {
        node* temp=m->next;
        m->next=m->next->next;
        temp= NULL;
        m=m->next;
    }
    return m;
}