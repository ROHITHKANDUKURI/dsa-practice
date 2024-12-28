#include<iostream>

using namespace std;
struct Node{
    int value;
    Node* next;
};

class Queue {

    Node* head;
    Node* tail;
    int length;
    public:
        Queue() {
            this->head = this->tail = NULL;
            this->length = 0;
        }

        void enqueue(int value) {
            this->length++;
            Node* newNode = new Node(); // Dynamically allocate memory for new node
            newNode->value = value;
            newNode->next = nullptr;

            if (!this->tail) {
                this->tail = this->head = newNode;
            } else {
                this->tail->next = newNode;
                this->tail = newNode;
            }
        }

        int deque() {
            if(!this->head) {
                return -1;
            }

            this->length--;
            Node* head = this->head;
            this->head = this->head->next;
            return head->value;
        }

        int peek() {
            if(!this->head) {
                return -1;
            }

            return this->head->value;
        }
};

int main() {
    Queue queue1;

    queue1.enqueue(7);
    queue1.enqueue(6);
    queue1.enqueue(5);
    
    cout << queue1.peek() << endl;
    
    cout << queue1.deque() << endl;
    cout << queue1.deque() << endl;
    cout << queue1.deque() << endl;
}