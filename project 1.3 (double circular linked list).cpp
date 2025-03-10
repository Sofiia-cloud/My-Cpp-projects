#include <iostream>
using namespace std;

struct Node { // ��������� Node
    int data;
    Node* next;
    Node* prev;

    Node(int new_data){ // ����������� ��� �������� ������ � ����� ����
        data=new_data;
        next=nullptr;
        prev=nullptr;
    }
};

class CircledList { // ����� ��� ����������� ���������� ������
private:
    Node* head;
    Node* tail;

public:
    CircledList(){ // ����������� ��� �������� ���������� ������
        head=nullptr;
        tail=nullptr;
    }

    void append(int new_data) { // ����� ��� ���������� ������ ���� � ����� ������
        Node* new_node=new Node(new_data);
        if (head==nullptr) { // ������, ����� ������ ������
            head=new_node;
            tail=new_node; // ����� ���� ���������� ������������ ������� � ������
            head->next=head; // �������������� ������
            head->prev=head; // �������������� ������
        }
        else { // ������, ����� ������ ��������
            tail->next=new_node; // ��������� ����� �������� ����� ����� ����
            new_node->prev=tail; // ������� ����� ���������� ���������� ��������� ��� ������ ����
            new_node->next=head; // �������������� ������ (��������� �� ������)
            head->prev=new_node; // ����� ���� ���������� ���������� ��������� ������
            tail=new_node; // ����� ���� ���������� ������
        }
    }


    void remove(int new_data) { // ����� ��� �������� ���� �� ��������
        if (head==nullptr){ // ������, ����� ������ ������
            cout<<"The list is empty"<<endl;
            return;
        }
        Node* current=head; // ������� ��������� ���������� ������ ������
        do {
            if (current->data == new_data) {
                if (current==head && current==tail) { // ������ �������� ������������� �������� � ������
                    // �����(���������) ������ � �����
                    head=nullptr;
                    tail=nullptr;
                }
                else {
                    if (current==head) { // �������� ���������� ���� ������
                        head= current->next; // ������� ������ �� ��������� �������
                        tail->next= head; // ���������� ���������� ���� ����� ����� �� ����� ������
                        head->prev= tail; // ���������� ����������� ���� ������ ������ �� ����� ������
                    }
                    else if (current==tail) { // �������� ���������� ���� ������
                        tail= current->prev; // ������� ����� �� ���������� �������
                        tail->next= head;
                        head->prev=tail;
                    }
                    else { // �������� ������ ������� ����
                        current->prev->next=current->next; // �������� ����������� �������� �� ���������
                        current->next->prev=current->prev; // �������� ���������� �������� �� ����������
                    }

                }
                return;
            }
            current =current->next; // ������� � ���������� �������� ������
        } while (current!=head);
        cout << "Value " << new_data << " not found in the list"<<endl;
    }


    void display() { // ����� ��� ������ ��������� ������
        if (head==nullptr) { // ������, ����� ������ ������
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

    bool check() { // ��������, �������� �� ������ ���������
        return head != nullptr && head->next != nullptr && head->prev != nullptr && head->next != head && head->prev != head;
    }
};

int main() {
    CircledList list; // ������� ������ ������

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

    list.remove(40); // ������� ������� �������������� �������

    return 0;
}
