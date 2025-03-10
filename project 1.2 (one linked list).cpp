#include <iostream>
using namespace std;


struct Node { // ��������� ����
    int data;
    Node* next;
};


class OneLinkedList { // ����� ��� �������� ������������ ������
    Node* head;

public:
    OneLinkedList() {
        this->head=NULL;
    }

    void pushback(int value) { // ������� ��� ������� ������ ���� � ����� ������
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head==NULL) { // ���� ������ ������, �� ��������� ������� ������ ���������� ����� ����
            head = newNode;
            return;
        }

        // ������� � ���������� ����
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }


        temp->next = newNode;
    }


    // ������� ��� ������ ������
    void show() {
        if (head==NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp!=NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void split(int x, OneLinkedList& less, OneLinkedList& more){ // ������� ��� ���������� ������ �� 2 �����
        Node* current = head;
        while (current!=NULL){
            Node* nextNode = current->next; // ��������� ��������� ����
            current->next = NULL;
            if (current->data < x) {
                less.pushback(current->data);
            } else {
               more.pushback(current->data);
            }
            current = nextNode; // ��������� � ���������� ����
            }
    }
};

int main() {
    // ������� ������ ������
    OneLinkedList list1;


    list1.pushback(1);
    list1.pushback(4);
    list1.pushback(3);
    list1.pushback(7);
    list1.pushback(2);


    cout << "Linked list at the beginning: ";
    list1.show();

    int x;
    std::cout << "Input X: ";
    std::cin >> x;

    OneLinkedList less;
    OneLinkedList more;

    list1.split(x, less, more);

    std::cout << "less values " << x << ": ";
    less.show();

    std::cout << "more and equals values " << x << ": ";
    more.show();



    return 0;
}
