#include <iostream>
using namespace std;

struct Node { // структура узла
    int key;
    Node* left; // левое поддерево
    Node* right; // правое поддерево
    int height;
    Node(int data){
        key=data;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};

int Height(Node* node) { // функция для нахождения высоты
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

void newHeight(Node* node) { // функция для обновления значения высоты
    node->height = 1 + max(Height(node->left), Height(node->right));
}

int Balance(Node* node){ // функция для нахождения баланса
    if (node==nullptr){
        return 0;
    }
    return Height(node->left)-Height(node->right); // разность высот левого и правого поддеревьев
}

Node* rightTurn(Node* node) { // функция для правого поворота
    Node* root = node->left; // левое поддерево становится новым корнем
    node->left = root->right; // правое поддерево уходит влево
    root->right = node; // правому поддереву присваивается текущий узел
    newHeight(node);
    newHeight(root);
    return root;
}

Node* leftTurn(Node* node) { // функция для левого поворота
    Node* root = node->right; // правое поддерево становится новым корнем
    node->right = root->left; // левое поддерево уходит вправо
    root->left = node; // левому поддереву присваивается текущий узел
    newHeight(node);
    newHeight(root);
    return root;
}

Node* to_Balance(Node* node) { // функция для балансировки
    int bal = Balance(node);

        if (bal > 1) { // случай, когда показатель баланса больше 1 (перевес влево)
        if (Height(node->left->left) < Height(node->left->right)) { // перевес правой стороны левого поддерева
            node->left = leftTurn(node->left); // левый поворот у левого поддерева
        }
        return rightTurn(node); // правый поворот текущего узла
    }

    else if (bal< -1) { // случай, когда показатель баланса меньше -1 (перевес вправо)

        if (Height(node->right->left) > Height(node->right->right)) { // перевес левой стороны правого поддерева
            node->right = rightTurn(node->right); // правый поворот у правого поддерева
        }
        return leftTurn(node); // левый поворот текущего узла
    }
    return node;
}


Node* insertion(Node* node, int key) { // вставка значения в дерево
    if (node==nullptr) {
        return new Node(key);
    }

    if (key < node->key) { // если значение меньше текущего
        node->left=insertion(node->left, key); // вставка в левое поддерево
    } else if (key > node->key) { // если значение больше текущего
        node->right=insertion(node->right, key); // вставка в правое поддерево

    } else { // такое значение уже есть
        return node;
    }


    // обновление высоты и баланса узла
    newHeight(node);
    return to_Balance(node);
}

void inOrder(Node* node) { // функция для симметричного обхода дерева
    if (node!=nullptr){
        inOrder(node->left); // проход по левому поддереву
        cout<<node->key<<" ";
        inOrder(node->right); // проход по правому поддереву
    }
}

int main() {
    // пример создания АВЛ-дерева
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

