#include <iostream>
#include <vector>
using namespace std;

struct Node { // ��������� ���� ������ ��������
    int KeyMin;
    int KeyMax;
    Node* Left; // ����� ���������
    Node* Right; // ������ ���������

    Node(int min, int max) { // ����������� ��� �������� ������ � ����� ����
        KeyMin=min;
        KeyMax=max;
        Left=nullptr;
        Right=nullptr;
    }
};

Node* root= nullptr;

Node* buildTree(vector<pair<int, int>>& intervals, int l, int r) { // ������� ��� ���������� ������ ��������
    if (l > r) { // ������, ����� ������� ������ �����������
        return nullptr;
    }


    Node* node=new Node(intervals[l].first, intervals[r].second);  // ���� � ����������� � ������������ ���������� �������

    if (l==r) { // ������, ����� ������� ������� �� 1 �����
        return node;
    }
    int middle =(l+r) / 2; // �������� �������


    node->Left=buildTree(intervals, l, middle); // ���������� ������ ���������
    node->Right=buildTree(intervals, middle + 1, r); // ���������� ������� ���������

    return node;
}


int searchX(Node* node, int x) { // ������� ��� �������� ���������� ���������� ������ ���������� ����� X
    if (node==nullptr) { // ������, ����� ����� �� ����� ������
        return 0;
    }

    if (x >=node->KeyMin && x <= node->KeyMax) { // ������, ����� � ������ � �������
        return 1 + searchX(node->Left, x) + searchX(node->Right, x); // ���-�� ����������: 1(��������� �������) + ����-�� ���������� �������� � ����������� ����
    }


    if (x< node->KeyMin) { // ������, ����� X ������ ����� ������� �������
        return searchX(node->Left, x); // ����� � ����� ���������
    }

    // ������, ����� X ������ ������ ������� �������
    return searchX(node->Right, x);  // ����� � ������ ���������
}


void preorder(Node* node) { // ������ ����� ������
    if (node==nullptr) { // ������, ����� ���� ������
        return;
    }
    cout << "[" << node->KeyMin << ", " << node->KeyMax << "] ";
    preorder(node->Left); // ����� ������ ������
    preorder(node->Right);  // ����� ������� ������
}


void preOrder() { // ������� ��� ������ ������� ������ ������
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
