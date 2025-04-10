#include <iostream>
using namespace std;

struct Node { // ��������� ����
    int key;
    Node* left; // ����� ���������
    Node* right; // ������ ���������
    int height;
    Node(int data){
        key=data;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};

int Height(Node* node) { // ������� ��� ���������� ������
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

void newHeight(Node* node) { // ������� ��� ���������� �������� ������
    node->height = 1 + max(Height(node->left), Height(node->right));
}

int Balance(Node* node){ // ������� ��� ���������� �������
    if (node==nullptr){
        return 0;
    }
    return Height(node->left)-Height(node->right); // �������� ����� ������ � ������� �����������
}

Node* rightTurn(Node* node) { // ������� ��� ������� ��������
    Node* root = node->left; // ����� ��������� ���������� ����� ������
    node->left = root->right; // ������ ��������� ������ �����
    root->right = node; // ������� ��������� ������������� ������� ����
    newHeight(node);
    newHeight(root);
    return root;
}

Node* leftTurn(Node* node) { // ������� ��� ������ ��������
    Node* root = node->right; // ������ ��������� ���������� ����� ������
    node->right = root->left; // ����� ��������� ������ ������
    root->left = node; // ������ ��������� ������������� ������� ����
    newHeight(node);
    newHeight(root);
    return root;
}

Node* to_Balance(Node* node) { // ������� ��� ������������
    int bal = Balance(node);

        if (bal > 1) { // ������, ����� ���������� ������� ������ 1 (������� �����)
        if (Height(node->left->left) < Height(node->left->right)) { // ������� ������ ������� ������ ���������
            node->left = leftTurn(node->left); // ����� ������� � ������ ���������
        }
        return rightTurn(node); // ������ ������� �������� ����
    }

    else if (bal< -1) { // ������, ����� ���������� ������� ������ -1 (������� ������)

        if (Height(node->right->left) > Height(node->right->right)) { // ������� ����� ������� ������� ���������
            node->right = rightTurn(node->right); // ������ ������� � ������� ���������
        }
        return leftTurn(node); // ����� ������� �������� ����
    }
    return node;
}


Node* insertion(Node* node, int key) { // ������� �������� � ������
    if (node==nullptr) {
        return new Node(key);
    }

    if (key < node->key) { // ���� �������� ������ ��������
        node->left=insertion(node->left, key); // ������� � ����� ���������
    } else if (key > node->key) { // ���� �������� ������ ��������
        node->right=insertion(node->right, key); // ������� � ������ ���������

    } else { // ����� �������� ��� ����
        return node;
    }


    // ���������� ������ � ������� ����
    newHeight(node);
    return to_Balance(node);
}

void inOrder(Node* node) { // ������� ��� ������������� ������ ������
    if (node!=nullptr){
        inOrder(node->left); // ������ �� ������ ���������
        cout<<node->key<<" ";
        inOrder(node->right); // ������ �� ������� ���������
    }
}

int main() {
    // ������ �������� ���-������
    Node* root=nullptr;

    int n;
    cout << "Input the number of elements: " << endl;
    cin>>n;
    cout << "Input elements of the tree: " << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root=insertion(root, value);
    }


    cout << "Sorted elements of the tree: ";
    inOrder(root);

    return 0;
}

