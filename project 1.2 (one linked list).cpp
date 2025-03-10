#include <iostream>
using namespace std;


struct Node { // структура узла
    int data;
    Node* next;
};


class OneLinkedList { // класс для создания односвязного списка
    Node* head;

public:
    OneLinkedList() {
        this->head=NULL;
    }

    void pushback(int value) { // функция для вставки нового узла в конец списка
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head==NULL) { // если список пустой, то переносим головой списка становится новый узел
            head = newNode;
            return;
        }

        // переход к следующему узлу
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }


        temp->next = newNode;
    }


    // функция для печати списка
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

    void split(int x, OneLinkedList& less, OneLinkedList& more){ // функция для разделения списка на 2 новых
        Node* current = head;
        while (current!=NULL){
            Node* nextNode = current->next; // Сохраняем следующий узел
            current->next = NULL;
            if (current->data < x) {
                less.pushback(current->data);
            } else {
               more.pushback(current->data);
            }
            current = nextNode; // Переходим к следующему узлу
            }
    }
};

int main() {
    // создаем пример списка
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
