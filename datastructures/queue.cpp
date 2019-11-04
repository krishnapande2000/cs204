#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int key;
    node* next;
};

class queu
{
public:
    node* start;
    node* rear;

};
node* newnode(int k)
{
    node* temp= new node();
    temp->key=k;
    temp->next=NULL;
    return temp;
}
queu* create()
{
    queu* q= new queu();
    q->start=NULL;
    q->rear=NULL;
    return q;
}

void enqueue(queu* q,int k)
{
    node *temp=newnode(k);

    if(q->rear==NULL)
    {
        q->start=temp;
        q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
    return;

}
node* dequeue(queu* q)
{
    if(q->start==NULL)
        return NULL;
    node* temp=q->start;


    q->start=q->start->next;
    if(q->start==NULL)
        q->rear=NULL;
    return temp;
}

int main()
{
    queu* q=create();
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int a;
        cin>>a;
        enqueue(q,a);
    }

    node* t=dequeue(q);
    node* k=dequeue(q);
    cout<< t->key <<" "<< k->key << endl;
    return 0;
}