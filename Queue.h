#ifndef QUEUE_H
#define QUEUE_H
class Queue
{
	int* queueArray;
	int front;
	int rear;
        int size;
public:
	Queue(int size);
	~Queue();
	void enqueue(int i);//lkuyruga eleman ekler
        int getSize();//kuyruğun büyüklüğünü döner
	char dequeue();//kuyruktan ilk elemanı çıkartır ve o elemanı char olarak döner
	bool isEmpty();//kuyruk boş mu 
	bool isFull();//kuyruk dolu mu
};


#endif /* QUEUE_H */


