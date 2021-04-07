#include <cstdlib>
#include <fstream>
#include <string>
#include<iostream>
#include "Queue.h"
#include "BinarySearchTree.h"
using namespace std;

Node* createNode(string line);
int findLength(string line);

int main(int argc, char** argv) {
    
  BinarySearchTree *tree = new BinarySearchTree();
  string line;
  ifstream myfile ("sayilar.txt");
  if (myfile.is_open())
  {
    while (getline (myfile,line) )//dosyadaki ilk satırı oku.
    {
        cout<<line<<endl;
        tree->insert(createNode(line));//okunan satırdan diğer metodları kullanarak node oluşturup ağaca ekle.
    }
    //dosya okuma bitti.şimdi ağaç gezilebilir.
    tree->inOrder();
    cout<<endl;
    tree->preOrder();
    cout<<endl;
    tree->postOrder();
    myfile.close();
  }

  else cout << "Unable to open file"; 
    return 0;
}
Node* createNode(string line){//gelen stringdeki sayılar 'boşluk' karakterine göre parse edilip kuyruğa atılacak.
                              //kuyruğun son haliuyle bir node oluşturulup dönülecek.
    Queue *q = new Queue(findLength(line));//kuyruğu oluştur.henuz kuyruk boş
    //bundan sonraki kısmın algoritması şu şekilde.
    //ilk boşluğa kadar olan karakteri al ve int'e çevir.
    //sonra kuyruğa at.
    //sonra bu karakteri 'substr()' metoduyla stringden at.
    //stringde boşluk kalmayana kadar döngüye devam et.
    //boşluk yoksa son sayı da kuyruğa atılmıştır.
    string intValue = line.substr(0,line.find(" "));
    int i = atoi(intValue.c_str());
    q->enqueue(i);
    while(line.find(" ")!=-1){
        line = line.substr(line.find(" ")+1);
        intValue = line.substr(0,line.find(" "));
        i = atoi(intValue.c_str());
        q->enqueue(i);
    }
    Node *n = new Node(q);
    return n;
}
int findLength(string line){//satırda kaç tane sayı var.Queue nesnesinin büyüklüğü için lazım.
    int count = 0;          //kaç tane sayıu olduğunu bulmak için stringdeki boşluk karakterlerinin sayısı bulunur.
                            //boşluk sayyısının 1 fazlası kaç tane sayı olduğunu gösterir.
    size_t n = line.find(" ", 0);//
    while(n != string::npos)
    {
        count++;
        n = line.find(" ", n+1);//
    }
    return count+1;
}



