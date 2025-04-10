#include <iostream>
using namespace std;


struct Node { // структура узла двоичного дерева
    int data;  // данные узла
    Node* left; // указатель на левое поддерево
    Node* right; // указатель на правое поддерево
    Node* parent;
    char color;
};


Node* createNode (int value){ // функция для создания нового узла
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left=nullptr;
    newNode->right=nullptr;
    newNode->parent=nullptr;
    newNode->color='R';
    return newNode;
}


Node* insert(Node* root, int value){ // функция для добавления элемента в дерево
    if (root==nullptr){
        return createNode(value); // если дерево пустое, то создаем корень
    }
    if (value<root->data){
        root->left=insert(root->left, value); // вставка в левое поддерево (через рекурсию)
        root->left->parent=root;
    }
    else{
        root->right=insert(root->right, value); // вставка в правое поддерево (через рекурсию)
        root->right->parent=root;
    }
    return root;
}



int height(Node* root) { // функция для вычисления высоты дерева
    if (root==nullptr) {
        return 0; // если дерево пустое, то возвращаем 0
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

void preorder(Node* root){ // прямой обход дерева
    if (root){
        cout<<root->data<<""; // посетить корень
        if (root->color=='R'){
            cout<<"(RED) ";
        }
        else {
            cout<<"(BLACK) ";
        }
        preorder(root->left); // обход левого поддерева
        preorder(root->right); // обход правого поддерева
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
