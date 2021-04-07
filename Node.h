#ifndef NODE_H
#define NODE_H
#include "Queue.h"

class Node//bu sınıf ağaca eklenecek olan nesnedir.
{
        Queue *key_value;//node'un tutacağı Queue nesnesi
        int value;
    public:
        Node(Queue *q);
        void printValue();//queue nesnesinin toplam değerini yazdırır.
        void setValue();//queue nesnesinin toplam değerini hesaplar.
        int getValue();//queue nesnesinin toplam değerini döner.
        Node *left;//node'un solundaki node.
        Node *right;//node'un sağındaki node.
};


#endif /* NODE_H */

