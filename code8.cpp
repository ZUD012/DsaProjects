#include<iostream>
#include<vector>
using namespace std;
class Node{
    public : 
   int data ;
   Node* next ;
   Node(int val){
   data = val ;
}
};
class list{
    public:
    Node* head ;
    Node* tail ;
    list(){
        head = tail = NULL ;
    }
    void push_front(int val){
    Node* NewNode = new  Node(val) ; 
        if(head == tail){
            head = tail = NewNode ;
        }
        else{
        NewNode->next = head ;
        head  = NewNode ; 
    }
  }
  void pop_back(){
    if(head == NULL){
        cout<<"The List is Empty "<<endl ; 
    }
    else{
    Node* temp = head ;
    head = head->next ; 
    temp->next = NULL ;
    delete temp ;   
}

  }
void top(){
 if(top == NULL){
    cout<<"The list is Empty";
 }
 else{
    cout<<head->data;
 }
  }
};




int main(){

return 0;
}