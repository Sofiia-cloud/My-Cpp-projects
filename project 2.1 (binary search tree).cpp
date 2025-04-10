#include <iostream>
using namespace std;


struct Node { // ��������� ���� ��������� ������
    int data;  // ������ ����
    Node* left; // ��������� �� ����� ���������
    Node* right; // ��������� �� ������ ���������
};


Node* createNode (int value){ // ������� ��� �������� ������ ����
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
}


Node* insert(Node* root, int value){ // ������� ��� ���������� �������� � ������
    if (root==nullptr){
        return createNode(value); // ���� ������ ������, �� ������� ������
    }
    if (value<root->data){
        root->left=insert(root->left, value); // ������� � ����� ��������� (����� ��������)
    }
    else{
        root->right=insert(root->right, value); // ������� � ������ ��������� (����� ��������)
    }
    return root;
}


void preorder(Node* root){ // ������ ����� ������
    if (root){
        cout<<root->data<<" "; // �������� ������
        preorder(root->left); // ����� ������ ���������
        preorder(root->right); // ����� ������� ���������
    }
}


int height(Node* root) { // ������� ��� ���������� ������ ������
    if (root==nullptr) {
        return 0; // ���� ������ ������, �� ���������� 0
    }
    return 1 + max(height(root->left), height(root->right));
}

void balance(Node* root){ // ������� ��� ���������� ������� ����
    if (root==nullptr){ // ������, ����� ������ ������
        return;
    }
    int left_h=height(root->left); // ������ ������ ���������
    int right_h=height(root->right); // ������ ������� ���������
    int bal=left_h-right_h; // ���������� ������� (������� ����� ������ � ������� �����������)
    cout<<root->data<<"("<<bal<<")"<<endl;
    balance(root->left); // ������ �� ������ ���������
    balance(root->right); // ������ �� ������� ���������
}

int main() {
    Node* root=nullptr;
    int n;

    cout << "Input the number of elements: "<< endl;
    cin >> n;

    cout << "Input elements of the tree: " << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root=insert(root, value);
    }

    cout << "The straight way:" << endl;
    preorder(root);
    cout << endl;

    cout << "Height of the tree: " << height(root) << endl;

    cout<<"Balance of the each node:"<< endl;
    balance(root);

    return 0;
}
