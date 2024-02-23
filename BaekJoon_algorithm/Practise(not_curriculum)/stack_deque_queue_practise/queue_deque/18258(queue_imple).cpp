/*
#include <iostream>
#include <string>
#define endl '\n'


using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Queue
{
	private:
		Node *front;
		Node *rear;
		int size = 0;
	public:
		Queue();
		int ReturnSize();
		bool Empty();
		int Front();
		int Back();
		void Push(int x);
		int Pop();
};



Queue::Queue()
{
	this->front = NULL;
	this->rear = NULL;
};

void Queue::Push(int x)
{
	//cout<<"insize"<<"   ";
	Node *temp = new Node;
	temp->data = x;
	
	if(front == NULL)
	{
		front = temp;
		rear =temp;
		size ++;
		//cout<<"input data = "<<front->data<<'\n';
	}
	
	else
	{
		rear->next = temp; //뒤에서 두 번째 자료가 가장 끝을 가리키도록 지정
		rear = temp;	   //rear 가 가장 마지막 자료를 가리키도록 지정
		size++;
		//cout<<"input data = "<<rear->data<<'\n';
	}
}

int Queue::Pop()
{
	if(size == 0)
		return -1;

	else
	{
		int result = front->data;
		if(size == 1)
		{
			delete front; 
			front = NULL;
			rear = NULL;
			size --;
		}
		else
		{
			Node*temp = front->next;
			delete front;
			front = temp;
			size--;
		}
		return result;
	}
}

int Queue::Front()
{
	if(size == 0)
		return -1;
	else
		return front->data;
}

int Queue::Back()
{
	if(size == 0)
		return -1;
	else
		return rear->data;
}

int Queue::ReturnSize()
{
	return this->size;
}

bool Queue::Empty()
{
	if(size == 0)
		return 1;
	else
		return 0;
	
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string input;
	//Queue myq = Queue();
	Queue myq;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		if(input == "push")
		{
			//cout<<"push  ";
			int temp;
			cin>>temp;
			myq.Push(temp);
			continue;
		}
		
		else if(input == "pop")
		{
			//cout<<"pop  ";
			cout <<myq.Pop()<<'\n';
			continue;
		}
		
		else if(input == "front")
		{
			//cout<<"front  ";
			cout << myq.Front()<<'\n';
			continue;
		}
		
		else if(input == "back")
		{
			//cout<<"back  ";
			cout<< myq.Back()<<'\n';
			continue;
		}
		
		else if(input == "empty")
		{
			//cout<<"empty  ";
			cout<< myq.Empty()<<'\n';
			continue;
		}
		
		else if(input == "size")
		{
			//cout<<"size  ";
			cout << myq.ReturnSize()<<'\n';
			continue;
		}
	}
}

*/