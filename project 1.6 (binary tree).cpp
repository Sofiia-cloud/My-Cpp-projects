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


bool search(Node* root, int value) { // ������� ��� ������ ����������� �������� � ������
    if (root==nullptr) { // ������, ����� ������ ������
        return false;
    }
    if (root->data==value) {
        return true;
    }
    if (value < root->data) {
        return search(root->left, value); // ����� � ����� ��������� ����� ��������
    }
    else {
        return search(root->right, value); // ����� � ������ ��������� ����� ��������
    }
}



Node* pop(Node* root, int value) { // ������� ��� �������� ������������� ���� � ������
    if (root== nullptr) {
        return root; // ������ ������� ������
    }

    if (value < root->data) { // ���� ���� � ����� ���������
        root->left=pop(root->left, value);
    }
    else if (value > root->data) { // ���� ���� � ������ ���������
        root->right=pop(root->right, value);
    }
    else { // ���� ���� ������
        if (root->left==nullptr) { // ���� � ���� ��� ������ ���������
            Node* temp= root->right; // ���������� ������� ���������

            return temp;
        }
        else if (root->right==nullptr) { // ���� � ���� ��� ������� ���������
            Node* temp = root->left; // ���������� ������ ���������

            return temp;
        }

    }

    return root; // ������� ���� ����� ��������
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

    int elem;
    cout << "Input a value to search: " << endl;
    cin >> elem;
    cout << "Value " << elem;
    if (search(root, elem)){
        cout<<" is found"<< endl;
    }
    else {
        cout<< " is not found" << endl;
    }

    int val;
    cout << "Input a value to delete: "<< endl;
    cin >> val;
    root = pop(root, val);

    cout << "Tree after deletion:" << endl;
    preorder(root);
    cout << endl;

    return 0;
}
