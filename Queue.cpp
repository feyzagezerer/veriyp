#include "Queue.h"
#include<iostream>
using namespace std;

bool Queue::isFull() {//kuyruk dolu mu?
    return (rear + 1) % size == front ? true : false;
}

char Queue::dequeue() {//dequeue fonksiyonunun 'char' olarak döner
                       //.dönen değerin 'NULL' olup olmadığını kontrol etmek için.
    if (isEmpty()) {//kuyruk boş ise null değer döner.
        return NULL;
    } else if (front == rear) {//kuyruktaki son eleman mı?
        char c = queueArray[front];
        rear = front = -1;
        return c;
    } else {//boş değil ve son eleman değil.en öndeki değeri döner ve o elemanı kuyruktan çıkarır
        char c = queueArray[front];
        front = (front + 1) % size;
        return c;
    }
}

void Queue::enqueue(int i) {
    if (isFull()) {//kuyruk dolu yeni eleman eklenemez.
        cout << "Hata:Kuyruk dolu!!\n";
        return;
    }
    if (isEmpty()) {//boş ise front ve rear değerleri aynı.yani kuyruğa giren ilk değer olacak.
        front = rear = 0;
    } else {//kuyrukta başka değerler var.yeni değeri en sona ekle
        rear = (rear + 1) % size;
    }
    queueArray[rear] = i;
}

bool Queue::isEmpty() {
    return (front == -1 && rear == -1);
}

int Queue::getSize() {
    return size;
}

Queue::Queue(int size) {//constructor.kuyrukta hiç eleman yok.kuyruğun büyüklüğü size kadar olacak.
    queueArray = new int[size];
    front = -1;
    rear = -1;
    this->size = size;
}

Queue::~Queue() {
    delete []queueArray;
}
