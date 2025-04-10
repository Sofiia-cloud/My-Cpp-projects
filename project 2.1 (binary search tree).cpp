#include <iostream>
using namespace std;


struct Node { // структура узла двоичного дерева
    int data;  // данные узла
    Node* left; // указатель на левое поддерево
    Node* right; // указатель на правое поддерево
};


Node* createNode (int value){ // функция для создания нового узла
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
}


Node* insert(Node* root, int value){ // функция для добавления элемента в дерево
    if (root==nullptr){
        return createNode(value); // если дерево пустое, то создаем корень
    }
    if (value<root->data){
        root->left=insert(root->left, value); // вставка в левое поддерево (через рекурсию)
    }
    else{
        root->right=insert(root->right, value); // вставка в правое поддерево (через рекурсию)
    }
    return root;
}


void preorder(Node* root){ // прямой обход дерева
    if (root){
        cout<<root->data<<" "; // посетить корень
        preorder(root->left); // обход левого поддерева
        preorder(root->right); // обход правого поддерева
    }
}


int height(Node* root) { // функция для вычисления высоты дерева
    if (root==nullptr) {
        return 0; // если дерево пустое, то возвращаем 0
    }
    return 1 + max(height(root->left), height(root->right));
}

void balance(Node* root){ // функция для вычисления баланса узла
    if (root==nullptr){ // случай, когда дерево пустое
        return;
    }
    int left_h=height(root->left); // высота левого поддерева
    int right_h=height(root->right); // высота правого поддерева
    int bal=left_h-right_h; // вычисление баланса (разница высот левого и правого поддеревьев)
    cout<<root->data<<"("<<bal<<")"<<endl;
    balance(root->left); // проход по левому поддереву
    balance(root->right); // проход по правому поддереву
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
