#include <stddef.h>
#include<iostream>
using namespace std;
#include "Node.h"

void Node::printValue() {
    cout<<value<<" ";
}

Node::Node(Queue* q) {//node'u oluştur.solu ve sağı null olacak.'value' değeri gelen kuyruktaki elemanların toplamı olacak. 
    key_value = q;
    left = NULL;
    right = NULL;
    setValue();
}

void Node::setValue() {//queue nesnesinin toplam değerini hesapla ve value değerine eşitle.
    int sum = 0;
    while (true) {//döngüye gir.
        char c = key_value->dequeue();//kuyruktan ilk elemanı çıkar.
        if(c == NULL){//çıkan eleman var mı?NULL ise kuyrukta eleman yok.
            break;//döngüden çık
        }
        sum += (int)c;//kuyruktan bir eleman çıktı.char olarak çıktığı için int'e cast edildi.
    }
    value = sum;//toplam değeri hesapla.
}

int Node::getValue() {//toplam değerini dön.
    return value;
}



