#include <iostream>
using namespace std;


struct Node { // ��������� ���� ��������� ������
    int data;  // ������ ����
    Node* left; // ��������� �� ����� ���������
    Node* right; // ��������� �� ������ ���������
    Node* parent;
    char color;
};


Node* createNode (int value){ // ������� ��� �������� ������ ����
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left=nullptr;
    newNode->right=nullptr;
    newNode->parent=nullptr;
    newNode->color='R';
    return newNode;
}


Node* insert(Node* root, int value){ // ������� ��� ���������� �������� � ������
    if (root==nullptr){
        return createNode(value); // ���� ������ ������, �� ������� ������
    }
    if (value<root->data){
        root->left=insert(root->left, value); // ������� � ����� ��������� (����� ��������)
        root->left->parent=root;
    }
    else{
        root->right=insert(root->right, value); // ������� � ������ ��������� (����� ��������)
        root->right->parent=root;
    }
    return root;
}



int height(Node* root) { // ������� ��� ���������� ������ ������
    if (root==nullptr) {
        return 0; // ���� ������ ������, �� ���������� 0
    }
    return 1 + max(height(root->left), height(root->right));
}

bool features(Node* root, int& black_c1, int& black_c2){
    if (root==nullptr){
        if (black_c1==-1){
            black_c1=black_c2;
        }
        return black_c1==black_c2;
    }
    if (root->color=='R'){
        if ((root->left && root->left->color=='R')||(root->right && root->right->color=='R')){
            return false;
        }
    }

    if (root->color=='B'){
        black_c2++;
    }

    return features(root->left, black_c1, black_c2)&&features(root->right, black_c1, black_c2);
}

bool check(Node* root){
    int black_c1=-1;
    int black_c2=0;
    return features(root, black_c1, black_c2)&&(root==nullptr || root->color=='B');
}

void preorder(Node* root){ // ������ ����� ������
    if (root){
        cout<<root->data<<""; // �������� ������
        if (root->color=='R'){
            cout<<"(RED) ";
        }
        else {
            cout<<"(BLACK) ";
        }
        preorder(root->left); // ����� ������ ���������
        preorder(root->right); // ����� ������� ���������
    }
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

    if (check(root)){
        cout<<"The tree has necessary features"<< endl;
    }
    else{
        cout<<"The tree doesn't have necessary features"<< endl;
    }
    return 0;
}
