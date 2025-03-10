#include <iostream>
using namespace std;

struct Node { // структура узла
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Test { // класс для проверки на наличие проскока или перескока
private:
    Node* head;
public:
    Test(){
        head=nullptr;
    }

    void set_head(Node* new_head) { // метод для установки головы списка
        head=new_head;
    }

    bool check() { // метод для проверки на наличие проскока или перескока
        Node* first=head;
        Node* second=head;

        while (second!=nullptr && second->next!=nullptr) { // пока не дойдет до конца списка
            first=first->next; // передвигаем на 1 узел вперед
            second=second->next->next; // передвигаем на 2 узла вперед

            if (first==second) { // если указатели совпали
                return true; // есть проскок
            }
        }

        return false;
    }
};

int main() {
    Test list; // пример списка с проскоком
    Node* head=new Node(11);
    head->next=new Node(32);
    head->next->next=new Node(63);
    head->next->next->next=new Node(49);
    head->next->next->next->next=new Node(50);
    head->next->next=head->next; // проскок

    list.set_head(head);

    if (list.check()) {
        cout << "There is a skip or an overshoot in the list" << endl;
    }
    else {
        cout << "There is no skip or overshoot" << endl;
    }

    return 0;
}
