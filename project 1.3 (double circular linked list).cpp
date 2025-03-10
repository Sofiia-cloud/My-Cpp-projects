#include <iostream>
using namespace std;

struct Node { // стурктура Node
    int data;
    Node* next;
    Node* prev;

    Node(int new_data){ // конструктор для передачи данных в новый узел
        data=new_data;
        next=nullptr;
        prev=nullptr;
    }
};

class CircledList { // класс для двусвязного кольцевого списка
private:
    Node* head;
    Node* tail;

public:
    CircledList(){ // конструктор для создания начального списка
        head=nullptr;
        tail=nullptr;
    }

    void append(int new_data) { // метод для добавления нового узла в конец списка
        Node* new_node=new Node(new_data);
        if (head==nullptr) { // случай, когда список пустой
            head=new_node;
            tail=new_node; // новый узел становится одновременно началом и концом
            head->next=head; // закольцовываем список
            head->prev=head; // закольцовываем список
        }
        else { // случай, когда список непустой
            tail->next=new_node; // добавляем после текущего конца новый узел
            new_node->prev=tail; // текущий хвост становится предыдущим элементом для нового узла
            new_node->next=head; // закольцовываем список (указатель на начало)
            head->prev=new_node; // новый узел становится предыдущим элементом начала
            tail=new_node; // новый узел становится концом
        }
    }


    void remove(int new_data) { // метод для удаления узла по значению
        if (head==nullptr){ // случай, когда список пустой
            cout<<"The list is empty"<<endl;
            return;
        }
        Node* current=head; // текущим элементом становится начало списка
        do {
            if (current->data == new_data) {
                if (current==head && current==tail) { // случай удаления единственного элемента в списке
                    // сброс(обнуление) начала и конца
                    head=nullptr;
                    tail=nullptr;
                }
                else {
                    if (current==head) { // удаление начального узла списка
                        head= current->next; // перенос начала на следующий элемент
                        tail->next= head; // обновление следующего узла после конца на новое начало
                        head->prev= tail; // обновление предыдущего узла нового начала на конец списка
                    }
                    else if (current==tail) { // удаления последнего узла списка
                        tail= current->prev; // перенос конца на предыдущий элемент
                        tail->next= head;
                        head->prev=tail;
                    }
                    else { // удаление любого другого узла
                        current->prev->next=current->next; // указание предыдущего элемента на следующий
                        current->next->prev=current->prev; // указание следующего элемента на предыдущий
                    }

                }
                return;
            }
            current =current->next; // переход к следующему элемента списка
        } while (current!=head);
        cout << "Value " << new_data << " not found in the list"<<endl;
    }


    void display() { // метод для вывода элементов кольца
        if (head==nullptr) { // случай, когда список пустой
            cout << "The list is empty" <<endl;
            return;
        }
        Node* current=head;
        do {
            cout << current->data << " ";
            current =current->next;
        } while (current!=head);
        cout << endl;
    }

    bool check() { // проверка, является ли список кольцевым
        return head != nullptr && head->next != nullptr && head->prev != nullptr && head->next != head && head->prev != head;
    }
};

int main() {
    CircledList list; // создаем пример списка

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "The list after adding the elements: ";
    list.display();

    cout << "Circle check: ";
    if (list.check()) {
        cout << "Yes" << endl;
    }
    else {
        cout<< "No" << endl;
    }

    list.remove(20);
    cout << "The list after deleting the value 20: ";
    list.display();

    cout << "Circle check: ";
    if (list.check()) {
        cout << "Yes" << endl;
    }
    else {
        cout<< "No" << endl;
    }

    list.remove(40); // пробуем удалить несуществующий элемент

    return 0;
}
