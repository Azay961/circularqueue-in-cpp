#include<iostream>
using namespace std;
class circularqueue
{
	private:
		int *data, qsize, front, rear, element;
	public:
		circularqueue()
		{
		}
		circularqueue(int n)
		{
			front=0;
			rear=0;			
			qsize=n;
            data= new int[qsize]; 
		}
		~ circularqueue()
		{
			delete []data;
		}
		bool isfull()
		{
			if (front == 0 && rear == qsize-1)
			  {
			  	return true;
			  }
			else if (front == rear+1)
			  {
			  	return true;
			  }
			else 
			  return false;
		}
		bool isempty()
		{
			if(front==rear)
			   {
			   
				return true;   	
			   }
			
			else
			    return false;	
		}
		void enqueue()
		{

			if (isfull())
			   cout<<"The queue is full. "<<endl;
			else
			  {
			    cout<<"Enter the element to be inserted "<<endl;
			    cin>>element;			  	
			  	rear=(rear+1)%qsize;
			  	data[rear]=element;
			  	cout<<element<<" is inserted in "<<rear<<endl;
			  }
		}
		void dequeue()
		{
			if (isempty())
			{
				cout<<"The queue is empty."<<endl;
			}
			else if (front==rear)
			{
				front=0;
				rear=0;
			}
			else
			{
				front=(front+1)%qsize;
				cout<<"Deleted element is "<<data[front]<<endl;
			}
		}
		void display()
		{
			cout<<"#############################################"<<endl;
			if (isempty())
			{
				cout<<"The queue is empty. "<<endl;
			}
			else
			{
				cout<<" Rear -> "<<rear<<endl;
				cout << "Front -> " << front<<endl;	
				cout<<"Datas inserted are "<<endl;
				for (int i=front;i!=rear;i=(i+1)%qsize)
				{
					int j=(i+1)%qsize;
					cout<<data[j]<<endl;
				}
			     
			}
		   cout<<"#############################################"<<endl;	
		}
};
int main()
{
	cout<<"Enter the size of queue "<<endl;
	int n;
	cin>>n;
	
	circularqueue q(n);
	q.dequeue();//to check if queue is empty or not
	
   for(int i=0;i<n;i++)//filling elements in queue
     {
     	q.enqueue();
	 }
	    q.display();

	 q.dequeue();//for removing elements
       q.display();
       
       q.enqueue();//adding elements
       q.display();
       
       q.enqueue();//checking if we can put elements without removing or not
	
	return 0;
}
//sample output

