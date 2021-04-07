#include <stddef.h>
#include <iostream>
using namespace std;
#include "BinarySearchTree.h"
#include "Node.h"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {

}

void BinarySearchTree::insert(Node* value) {//ağaca eleman ekle.root null ise gelen node root olacak.
if(root!=NULL)
    insert(value, root);
  else
  {
    root=value;
  }
}

void BinarySearchTree::destroy_tree() {
    destroy_tree(root);
}

void BinarySearchTree::destroy_tree(Node* leaf) {
if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void BinarySearchTree::insert(Node* value, Node* leaf) {//gelen value değerini leaf'in sağına yada soluna ekle
if(value->getValue()< leaf->getValue())//eklenecek node un değeri leaf'in değerinden küçük.
  {                                    //o halde leaf node'unun sol tarafına eklenecek.
    if(leaf->left!=NULL)//leaf'in solunda başka bir node var.leaf'in solundaki node'a göre ekleme yap.
     insert(value, leaf->left);
    else//leaf'in solu boş.value node'unu direk sola at.
    {
      leaf->left= value; 
    }  
  }
else if(value->getValue()>=leaf->getValue())//eklenecek node un değeri leaf'in değerinden büyük.
  {                                          //o halde leaf node'unun sağ tarafına eklenecek.
    if(leaf->right!=NULL)//leaf'in sağında başka bir node var.leaf'in sağındaki node'a göre ekleme yap.
      insert(value, leaf->right);
    else//leaf'in sağı boş.value node'unu direk sağa at.
    {
      leaf->right=value;
    }
  }
}

void BinarySearchTree::inOrder() {
    cout<<"inorder :"<<endl;
    inOrder(root);
}

void BinarySearchTree::postOrder() {
    cout<<"postorder :"<<endl;
    postOrder(root);
}

void BinarySearchTree::preOrder() {
    cout<<"preorder :"<<endl;
    preOrder(root);
}

//recursive metodlar.daha kolay çünkü.
void BinarySearchTree::preOrder(Node* leaf) {//preorder gez.sıralama-->root,sol ve sağ
    if(leaf!=NULL){
        leaf->printValue();
        preOrder(leaf->left);
        preOrder(leaf->right);
    }
}

void BinarySearchTree::inOrder(Node* leaf) {//inoreder gez.sıralama-->sol,root ve sağ
    if(leaf!=NULL){
        inOrder(leaf->left);
        leaf->printValue();
        inOrder(leaf->right);
    }
}

void BinarySearchTree::postOrder(Node* leaf) {//postorder gez.sıralama-->sol,sağ ve root
    if(leaf!=NULL){
        postOrder(leaf->left);
        postOrder(leaf->right);
        leaf->printValue();
    }
}

