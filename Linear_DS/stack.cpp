#include<iostream>
using namespace std;
class QNode
{
    public:
    int key;
    QNode *next;
    QNode(int data)
    {   
        this->key=data;
        this->next=NULL;
    }
};
class Stack 
{ 
	public:
    QNode *top;
    int size;
    Stack()
    {
        this->top=NULL;
    }
    void push(int val)
    {
        QNode* node=new QNode(val);
        QNode* temp=NULL;
        node->next=nullptr;
        if(top==nullptr)
        {
            top=node;
            top->next=nullptr;
        }
        else
        {
            temp=top;
            top=node;
            top->next=temp;
        }
        size++;
        //cout<<"poped sucessfully"<<endl;
    }
    void print()
    {
        QNode *temp=top;
        while(temp!=NULL)
        {
            cout<<temp->key<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    ~Stack()
    {
        QNode *node;
        while(top!=NULL)
        {
            node=top;
            //cout<<"hii"<<endl;
            top=top->next;
            delete node;
        }
        top=NULL;
    }
    QNode *pop()
    {
        if(top==NULL)
            return NULL;
        else
        {
            QNode* node=top;
            top=top->next;
            size--;
            //cout<<"poped sucessfully"<<endl;
            return node;
        }
    }
    int size1()
    {
        return size;
    }

}; 
int main()
{
    Stack q1;
    q1.push(5);
    q1.push(8);
    QNode *n=q1.pop();
    cout<<"dequeue = "<<n->key<<endl;
    n=q1.pop();
    cout<<"dequeue = "<<n->key<<endl;
    q1.push(1);
    q1.push(30);
    q1.print();
    
    return 0;
}