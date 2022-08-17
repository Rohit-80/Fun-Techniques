#include <bits/stdc++.h>
using namespace std;


// implementing Queue using Array [ 2 pointer approch ]
class Queue {
public :
	int size;
	int front;
	int rear;
	int *q;

	Queue(int size) {
		this->size = size;
		front = -1;
		rear = -1;
		q = new int[size];
	}


	void push(int x) {
		if (rear == size - 1) {
			cout << "Queue is Full\n";
		} else {
			rear++;
			q[rear] = x;
		}
	}

	int pop() {

		int x = -1;
		if (front == rear) {
			cout << "Queue is Empty\n";
		} else {
			front++;
			x = q[front];
		}

		return x;
	}

	bool isEmpty() {
		return front == rear;
	}

	bool isFull() {
		return rear == size - 1;
	}
	int frontp() {
		if (front == -1 || front == rear) return -1;
		return q[front];
	}

	void display() {
		for (int i = front + 1; i <= rear; i++) {
			cout << q[i] << " ";
		}
	}
};

/* but there are 3 major Problem of 2 pointer approch .....

   1. we can't use deleted memory space
   2. we can use each space only once
   3. if rear is at size - 1 th postition and front is at rear
      then both will true queue is empty as well as full . its a lol!

   solution can be
       1 . resetling pointer
       2. circular queue

       With Resetling Pointer
       if front is at rear move both to -1.
       but that won't work every time . if there's one element in queue then queue
       isn't empty but still there alot space free behind front that's a brawback
       of resetling pointers.

       but with circular queue every thing working fine .
       here's queue would be n-1 length .

   */


class CircularQueue {
public :
	int size;
	int front;
	int rear;
	int *q;

	CircularQueue(int size) {
		this->size = size;
		front = 0;
		rear = 0;
		q = new int[size];
	}


	void push(int x) {
		if ((rear + 1) % size == front) {
			cout << "Queue is Full\n";
		} else {
			rear = (rear + 1) % size;
			// cout<<rear<<endl;
			q[rear] = x;
		}
	}

	int pop() {

		int x = -1;
		if (front == rear) {
			cout << "Queue is Empty\n";
		} else {
			front = (front + 1) % size;
			x = q[front];
		}

		return x;
	}

	bool isEmpty() {
		return front == rear;
	}

	bool isFull() {
		return (rear + 1) % size == front;
	}
	int frontp() {
		return q[(front + 1) % size];
	}

	void display() {

		int i = front + 1;

		do {
			cout << q[i] << " ";
			i = (i + 1) % size;
		} while (i != (rear + 1) % size);

	}
};


struct node {
	int data;
	node* next;
};

class QueueUsingLinkedList {

public :
	node * front = NULL;
	node * rear = NULL;

	void push(int x) {

		node * t = new node;
		if (t == NULL) {
			cout << "Queue is Full\n";
		} else {
			t->data = x;
			t->next = NULL;


			// if only one node is in queue front and rear both sould be pointed to this node;
			if (front == NULL) {

				front = rear = t;
			} else {
				rear->next = t;
				rear = t;
			}
		}
	}


	int pop() {
		int x = -1;
		node *p;
		if (front == NULL ) {
			cout << "Queue is Empty";
		} else {
			p = front;
			front = front->next;
			x = p->data;
			free(p);
		}

		return x;
	}

	bool isEmpty() {
		return front == NULL;
	}

	bool isFull() {
		node *t = new node;
		return t == NULL;
	}


	int frontp() {
		return front != NULL ? front->data : -1;
	}

	void display() {

		node* temp = front;

		for (temp; temp->next != NULL; temp = temp->next) {
			// cout<<"work";
			cout << temp->data << " ";
		}

		cout << temp->data << " ";
	}
};

// Deque
// Priority_Queue
// Queue using 2 Stack

class QueueUsing2Stack {
public :

	stack<int> s1, s2;
	void push(int x) {
		s1.push(x);

	}

	int pop() {
		int x = -1;
		if (s2.empty() && s1.empty()) {
			cout << "Queue is empty";
			return -1;
		}
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		x = s2.top();
		s2.pop();
		return x;
	}

	void display() {
		auto s = s2;

		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}

		auto s22 = s1;
		while (!s22.empty()) {
			s.push(s22.top());
			s22.pop();
		}

		while (!s22.empty()) {
			cout << s22.top() << " ";
			s22.pop();
		}

	}
};


int main() {

	QueueUsingLinkedList q;

	// q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);



	q.pop();
	// q.pop();
	// q.pop();
	// q.pop();
	// q.pop();
	// q.pop();



	q.display();

	return 0;
}