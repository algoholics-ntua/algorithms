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
struct Queue 
{ 
	QNode *front, *rear;
    	int size=0;
    Queue()
    {
        this->front=NULL;
        this->rear=NULL;
    }
    void enqueue(int val)
    {
        QNode* node=new QNode(val);
        node->next=NULL;
        if(front==NULL)
        {
            front=rear=node;
            rear->next=NULL;
        }
        else
        {
            rear->next=node;
            rear=node;
            rear->next=NULL;
        }
        size++;
        cout<<"enqueued sucessfully"<<endl;
    }
    void print()
    {
        QNode *temp=front;
        int t=0;
        while(t<size)
        {
            cout<<temp->key<<" ";
            temp=temp->next;
            t++;
        }
        cout<<endl;
    }
    ~Queue()
    {
        QNode *node;
        while(front!=NULL)
        {
            node=front;
            //cout<<"hii"<<endl;
            front=front->next;
            delete node;
        }
        front=rear=NULL;
    }
    QNode *dequeue()
    {
        if(front==NULL)
            return NULL;
        else
        {
            QNode* node=front;
            front=front->next;
            size--;
             cout<<"dequeued sucessfully"<<endl;
            //delete node;
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
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(8);
    QNode *n=q1.dequeue();
    cout<<"dequeue = "<<n->key<<endl;
    n=q1.dequeue();
    cout<<"dequeue = "<<n->key<<endl;
    q1.enqueue(1);
    q1.enqueue(30);
    q1.print();
    
    return 0;
}
