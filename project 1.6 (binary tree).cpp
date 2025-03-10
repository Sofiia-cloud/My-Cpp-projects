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


bool search(Node* root, int value) { // функция для поиска конкретного элемента в дереве
    if (root==nullptr) { // случай, когда дерево пустое
        return false;
    }
    if (root->data==value) {
        return true;
    }
    if (value < root->data) {
        return search(root->left, value); // поиск в левом поддереве через рекурсию
    }
    else {
        return search(root->right, value); // поиск в правом поддереве через рекурсию
    }
}



Node* pop(Node* root, int value) { // функция для удаления определенного узла в дереве
    if (root== nullptr) {
        return root; // случай пустого дерева
    }

    if (value < root->data) { // если узел в левом поддереве
        root->left=pop(root->left, value);
    }
    else if (value > root->data) { // если узел в правом поддереве
        root->right=pop(root->right, value);
    }
    else { // если узел найден
        if (root->left==nullptr) { // если у узла нет левого поддерева
            Node* temp= root->right; // сохранение правого поддерева

            return temp;
        }
        else if (root->right==nullptr) { // если у узла нет правого поддерева
            Node* temp = root->left; // сохранение левого поддерева

            return temp;
        }

    }

    return root; // текущий узел после удаления
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
