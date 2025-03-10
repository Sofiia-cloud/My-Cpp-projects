#include <iostream>
#include <vector>
using namespace std;

struct Node { // структура узла дерева отрезков
    int KeyMin;
    int KeyMax;
    Node* Left; // левое поддерево
    Node* Right; // правое поддерево

    Node(int min, int max) { // конструктор для передачи данных в новый узел
        KeyMin=min;
        KeyMax=max;
        Left=nullptr;
        Right=nullptr;
    }
};

Node* root= nullptr;

Node* buildTree(vector<pair<int, int>>& intervals, int l, int r) { // функция для построения дерева отрезков
    if (l > r) { // случай, когда отрезок введен некорректно
        return nullptr;
    }


    Node* node=new Node(intervals[l].first, intervals[r].second);  // узел с минимальным и максимальным значениями отрезка

    if (l==r) { // случай, когда отрезок состоит из 1 точки
        return node;
    }
    int middle =(l+r) / 2; // середина отрезка


    node->Left=buildTree(intervals, l, middle); // построение левого поддерева
    node->Right=buildTree(intervals, middle + 1, r); // построение правого поддерева

    return node;
}


int searchX(Node* node, int x) { // функция для подсчета количества интервалов дерева содержащих точку X
    if (node==nullptr) { // случай, когда дошли до конца дерева
        return 0;
    }

    if (x >=node->KeyMin && x <= node->KeyMax) { // случай, когда Х входит в отрезок
        return 1 + searchX(node->Left, x) + searchX(node->Right, x); // кол-во интервалов: 1(найденный отрезок) + коли-во подходящих отрезков в поддеревьях узла
    }


    if (x< node->KeyMin) { // случай, когда X меньше левой границы отрезка
        return searchX(node->Left, x); // поиск в левом поддереве
    }

    // случай, когда X больше правой границы отрезка
    return searchX(node->Right, x);  // поиск в правом поддереве
}


void preorder(Node* node) { // прямой обход дерева
    if (node==nullptr) { // случай, когда узел пустой
        return;
    }
    cout << "[" << node->KeyMin << ", " << node->KeyMax << "] ";
    preorder(node->Left); // обход левого дерева
    preorder(node->Right);  // обход правого дерева
}


void preOrder() { // функция для вывода прямого обхода дерева
    cout << "Direct traversal of the segment tree: ";
    preorder(root);
    cout << endl;
}

int main() {
    int n;
    cout<<"Input the number of intervals: ";
    cin>> n;

    vector<pair<int, int>> intervals;

    for (int i=0; i<n; i++){
        int l,r;
	cout<<"Input the beginning and the end of the interval: "<< endl;
        cin>>l>>r;
        intervals.push_back({l,r});
    }


    root = buildTree(intervals, 0, intervals.size() - 1);


    preOrder();


    int x;
    cout << "Input X: ";
    cin >> x;


    int count=searchX(root, x);
    cout << "Number of intervals containing " << x << ": " << count << endl;

    return 0;
}
