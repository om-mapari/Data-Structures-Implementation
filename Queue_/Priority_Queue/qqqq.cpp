#include <iostream>
using namespace std;
class queue1;
class patient
{
	char name[50];
	int id;
	int priority;

public:
	friend class queue1;
	patient get();
};

class queue1
{
	int front, rear;

public:
	queue1()
	{
		front = -1;
		rear = -1;
	}
	void insertq(patient p[], int, patient);
	void deleteq(patient p[]);
	void display(patient p[]);
};

void queue1 ::insertq(patient p[], int n, patient a)
{
	if (rear == n - 1)
	{
		cout << "Overflow";
	}
	else
	{
		if (front == -1)
		{
			front = 0;
			rear = 0;
			p[rear] = a;
		}
		else
		{
			rear = rear + 1;
			p[rear] = a;
		}
		int j = rear - 1;
		while (p[j].priority > a.priority && j >= front)
		{
			p[j + 1] = p[j];
			j = j - 1;
		}
		p[j + 1] = a;
	}
}

void queue1 ::deleteq(patient p[])
{
	if ((front == -1) || (front == rear + 1))
	{
		cout << "Queue empty";
	}
	else
	{
		front = front + 1;
	}
}

void queue1 ::display(patient p[])
{
	for (int i = front; i <= rear; i++)
	{
		cout << "Name : " << p[i].name << endl;
		cout << "Id : " << p[i].id << endl;
		cout << "Priority : " << p[i].priority << endl;
	}
}

patient patient ::get()
{
	patient p;
	cout << "Enter name ";
	cin >> p.name;
	cout << "Enter id ";
	cin >> p.id;
	cout << "Enter priority ";
	cin >> p.priority;
	return p;
}

int main()
{
	int n, k, c;
	queue1 q1;
	patient a, p1;
	k = 1;
	cout << "No of patients ";
	cin >> n;
	patient *p = new patient[n];
	do
	{
		cout << "1) Insert"
			 << "\n2) Delete"
			 << "\n3) Display"
			 << "\n4) Stop \n";
		cin >> c;
		switch (c)
		{
		case 1:
		{
			a = p1.get();
			q1.insertq(p, n, a);
			break;
		}
		case 2:
		{
			q1.deleteq(p);
			break;
		}
		case 3:
		{
			q1.display(p);
			break;
		}
		case 4:
		{
			k = 0;
			cout << "Exited Successfully!!";
		}
		}
	} while (k != 0);
	return 0;
}