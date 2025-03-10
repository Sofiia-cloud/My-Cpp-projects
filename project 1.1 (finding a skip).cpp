#include <iostream>
using namespace std;

struct Node { // ��������� ����
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Test { // ����� ��� �������� �� ������� �������� ��� ���������
private:
    Node* head;
public:
    Test(){
        head=nullptr;
    }

    void set_head(Node* new_head) { // ����� ��� ��������� ������ ������
        head=new_head;
    }

    bool check() { // ����� ��� �������� �� ������� �������� ��� ���������
        Node* first=head;
        Node* second=head;

        while (second!=nullptr && second->next!=nullptr) { // ���� �� ������ �� ����� ������
            first=first->next; // ����������� �� 1 ���� ������
            second=second->next->next; // ����������� �� 2 ���� ������

            if (first==second) { // ���� ��������� �������
                return true; // ���� �������
            }
        }

        return false;
    }
};

int main() {
    Test list; // ������ ������ � ���������
    Node* head=new Node(11);
    head->next=new Node(32);
    head->next->next=new Node(63);
    head->next->next->next=new Node(49);
    head->next->next->next->next=new Node(50);
    head->next->next=head->next; // �������

    list.set_head(head);

    if (list.check()) {
        cout << "There is a skip or an overshoot in the list" << endl;
    }
    else {
        cout << "There is no skip or overshoot" << endl;
    }

    return 0;
}
