//
// Created by cy on 2015/10/26.
//

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <iomanip>
#include <queue>
#include <android/log.h>
using namespace std;

struct Node {
    Node(const Node *t) : data(t->data), lChild(NULL), rChild(NULL) { }

    Node(int d) : data(d), lChild(NULL), rChild(NULL) { }

    struct Node *lChild;
    struct Node *rChild;
    int data;
};

void visit(Node *t) {
//    cout << setw(3) << t->data << " ";
//    __android_log_write(ANDROID_LOG_WARN, "jni log", t->data+" "+5);
    __android_log_print(ANDROID_LOG_WARN, "SomeTag", "%d", t->data);
//    printf("%d",t->data);
}

void PreOrder(Node *root, void (*visit)(Node *)) {
    if (root == NULL) return;
    stack<Node *> s;
    Node *cur;
    s.push(root);

    while (!s.empty()) {
        cur = s.top();
        visit(cur);
        s.pop();
        if (cur->rChild != NULL) s.push(cur->rChild);
        if (cur->lChild != NULL) s.push(cur->lChild);
    }
}

void InOrder(Node *root, void (*visit)(Node *)) {
    stack<Node *> s;
    Node *cur = root;

    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->lChild;
        }

        cur = s.top();
        visit(cur);
        s.pop();

        if (cur->rChild == NULL)
            cur = NULL; // no current node. must pop.
        else
            cur = cur->rChild;
    }
}

void PostOrder(Node *root, void (*visit)(Node *)) {
    stack<Node *> s;
    Node *cur = root;
    Node *visited = NULL;

    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->lChild;
        }

        cur = s.top();  // check but no visit.

        if (cur->rChild == visited || cur->rChild == NULL) {
            visit(cur);
            s.pop();
            visited = cur;
            cur = NULL; // no current node, must pop.
        }
        else
            cur = cur->rChild;
    }
}

/***************************************
* 层序遍历：跟先序遍历很像。是二叉树的广度优先搜索。
* 所以要用队列实现。
***************************************/
void LevelOrderTraverse(Node *t, void (*visit)(Node *)) {
    if (NULL == t)
        return;
    queue<Node *> q;
    Node *e;
    q.push(t);
    while (!q.empty()) {
        visit(e = q.front());
        q.pop();
        if (NULL != e->lChild) q.push(e->lChild);
        if (NULL != e->rChild) q.push(e->rChild);
    }
}

//插入节点的函数
void insert(Node *&root, Node *t) {
    if (root == NULL)
        root = new Node(t);
    else if (t->data > root->data)
        insert(root->rChild, t);
    else if (t->data < root->data)
        insert(root->lChild, t);
    else;
}

//使用数组创建二叉树
 Node * createTree(vector<int> &a) {
    if (0 == a.size())
        return NULL;

    Node *root = new Node(a[0]);
    vector<int>::const_iterator iter = a.begin();
    iter++;
    for (; iter != a.end(); ++iter) {
        Node *t = new Node(*iter);
        insert(root, t);
    }
    return root;
}

int main()
{
    vector<int> a;
    for (int i = 0 ; i < 10 ; ++i )
    {
        int temp = rand() % 31;//随便取了几个随机数
        a.push_back(temp);

    }

    Node* root = createTree( a );
    __android_log_print(ANDROID_LOG_INFO, "SomeTag", "PreOrder");
    PreOrder(root, visit);
    __android_log_print(ANDROID_LOG_INFO, "SomeTag", "InOrder");
    InOrder(root, visit);
    __android_log_print(ANDROID_LOG_INFO, "SomeTag", "PostOrder");
    PostOrder(root, visit);

}