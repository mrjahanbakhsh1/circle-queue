// Circular Queue
#include <iostream>
#include <conio.h>
using namespace std;
 
struct Queue
{
    int *a;
    int rear;
	int front;
    int size;
    
    Queue(int s)
    {
       a = new int[s];
	   front =-1;
	   rear = -1;
       size = s;
    }
 
    void  add(int item);
    void   deleted();
    void  show();
};
 
void Queue::add(int item)
{
    if ((front == 0 && rear == size-1) || (rear == front-1))
    {
        cout<<"\nFull";
        return;
    }
 
    else if (front == -1)    // Insert First Element 
    {
        front =0; 
		rear  = 0;
        a[rear] = item;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        a[rear] = item;
    }
 
    else
    {
        rear++;
        a[rear] = item;
    }
}
 
void Queue::deleted()
{
    if (front == -1)
    {
        cout<<"\n Empty";
    }
 
    int item = a[front];
    a[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
 
    cout << endl << "deleted : " << item << endl; 
}
 
void Queue::show()
{
    if (front == -1) { cout<<"\nEmpty"; return; }
    
	cout<<"\nElements : ";
    if (front<=rear)
    {
        for (int i = front; i <= rear; i++)
            cout<<a[i]<<"\t";
    }
    else
    {
        for (int i = front; i <=size-1; i++)
            cout<< a[i]<<"\t";
 
        for (int i = 0; i <= rear; i++)
            cout<< a[i]<<"\t";
    }
}
  
int main()
{
   Queue  q(5);
   
   q.add(25);
   q.add(14);
   q.add(42);
   
   q.show();
   
   q.deleted();
   
   q.show();
  
   q.add(9);
   q.add(10);
   q.add(35);

   q.show();

   q.add(19);
   q.show();

   getch();
}
