#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertFirst(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

void insertLast(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int key, int value){
    Node* temp = head;

    while(temp != NULL){
        if (temp->data == key){

            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL){
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    cout << "Data tidak ditemukan\n";
}

void deleteFirst(){
    if (head == NULL) {
        cout<< "List kosong\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void deleteLast(){
    if (head == NULL){
        cout<< "List kosong\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    if (temp->prev != NULL){
        temp->prev->next = NULL;
    } else{
        head = NULL;
    }
    delete temp;
}

void deleteByValue(int value){
    if (head == NULL){
        cout << "List kosong.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != value){
        temp = temp->next;
    }

    if (temp == NULL){
        cout << "Data tidak ditemukan.\n";
        return;
    }
    if (temp == head){
        deleteFirst();
        return;
    }
    if (temp->next == NULL){
        deleteLast();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    cout << "Data berhasil dihapus.\n";
}

void display(){
    if (head == NULL){
        cout << "List kosong.\n";
        return;
    }
    Node* temp = head;

    cout << "Isi Double Linked List:\n";

    while (temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main(){

    insertFirst(14);
    insertFirst(8);
    insertLast(23);
    insertAfter(10,17);

    display();

    deleteByValue(10);

    display();

    return 0;
}

// int main() {

//     insertFirst(10);
//     insertFirst(5);
//     insertLast(20);
//     insertAfter(10, 15);

//     display();

//     deleteByValue(10);

//     display();

//     return 0;
// }