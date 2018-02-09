#include <iostream>
#include <stdlib.h>
using namespace std;

class MyQueue
{
public:
    MyQueue(int queueCapacity); //创建队列
    virtual ~MyQueue();         //销毁队列
    void ClearQueue();          //清空队列
    bool QueueEmpty()const;     //判空队列
    bool QueueFull()const;      //判满队列
    int QueueLength()const;     //队列长度
    bool EnQueue(int element);  //新元素入队
    bool DeQueue(int &element);  //首元素出队
    void QueueTraverse();       //遍历队列
private:
    int *m_pQueue;              //队列数组指针
    int m_iQueueLen;            //队列元素个数
    int m_iQueueCapacity;       //队列数组容量
    int m_iHead;                //队列头
    int m_iTail;                //队列尾
};

MyQueue::MyQueue(int queueCapacity)
{
    m_iQueueCapacity = queueCapacity;
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLen = 0;
    m_pQueue = new int[m_iQueueCapacity];

}

MyQueue::~MyQueue()
{
    delete []m_pQueue;
    m_pQueue = NULL;
}

void MyQueue::ClearQueue()
{
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty()const
{
    if(m_iQueueLen==0)
    {
        return true;

    }
    else
    {
        return false;
    }
}

int MyQueue::QueueLength()const
{
    return m_iQueueLen;
}

bool MyQueue::QueueFull()const
{
    if(m_iQueueLen == m_iQueueCapacity)
    {
        return true;
    }
    return false;
}

bool MyQueue::EnQueue(int element)
{
    if(QueueFull())
    {
        return false;
    }
    else
    {
        m_pQueue[m_iTail] = element;
        m_iTail++;
        m_iTail = m_iTail % m_iQueueCapacity;
        m_iQueueLen++;
    }
}

bool MyQueue::DeQueue(int &element)
{
    if(QueueEmpty())
    {
        return false;
    }
    else
    {
        element = m_pQueue[m_iHead];
        m_iHead++;
        m_iHead = m_iHead % m_iQueueCapacity;
        m_iQueueLen--;
        return true;
    }

}

void MyQueue::QueueTraverse()
{
    for(int i = m_iHead;i<m_iQueueLen+m_iHead;i++)
    {
        cout<<m_pQueue[i%m_iQueueCapacity]<<endl;
    }
    cout<<endl;
}

int main(void)
{
    MyQueue *p = new MyQueue(4);

    p->EnQueue(10);
    p->EnQueue(12);
    p->EnQueue(16);
    p->EnQueue(18);
    p->EnQueue(20);
    p->QueueTraverse();
    int e = 0;
    p->DeQueue(e);
    cout<<endl;
    cout<<e<<endl;

    p->DeQueue(e);
    cout<<endl;
    cout<<e<<endl;

    cout<<endl;
    p->QueueTraverse();

    cout<<endl;
    p->ClearQueue();

    cout<<endl;
    p->EnQueue(20);
    p->EnQueue(30);
    p->QueueTraverse();

    delete p;
    p = NULL;

    system("pause");
    return 0;
}
