#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

struct node {
    int data;
    struct node* next;
    node(int _data) :data(_data), next(nullptr) {
    }
};
struct node* init() {
    node* head = new node(1);
    node* node1 = new node(2);
    node* node2 = new node(3);
    node* node3 = new node(4);
    node* node4 = new node(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
    return head;
}
void destroy(node* head){
    while(head != nullptr){
        node* tmp = head->next;
        delete head;
        head = tmp;
    }
}
void print(node* list){
    while(list != nullptr){
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}
node* reverse(node* head){
    node* prev = nullptr;
    node* curr = head;
    
    while(curr != nullptr){
        node* next = curr->next;
        
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//for practice
node* reverse2(node* head){
    node* prev = nullptr;
    node* curr = head;
    while(curr != nullptr){
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    auto head = init();
    head = reverse(head);
    print(head);
    destroy(head);
    return 0;
}

