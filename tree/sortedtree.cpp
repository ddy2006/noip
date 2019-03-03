#include <bits/stdc++.h>
using namespace std;
//定义节点
struct Node{
    char val;
    struct Node *left, *right;
};
//构造二叉树
void add(Node* &p, char val){
    if(p==NULL){
        Node *ptr = new Node;
        ptr->left = ptr->right = NULL;
        ptr->val = val;
        p = ptr;
    } else if (p->val > val){
        add(p->left,val);
    } else {
        add(p->right,val);
    }
}
//中序遍历输出
void print(Node *p){
    if(p!=NULL){
        print(p->left);
        putchar(p->val);
        print(p->right);
    }
}

int main(){
    char line[300];
    gets(line);     //整行输入
    struct Node *root = NULL;
    for(int i=0;i<strlen(line);i++){
        char ch=line[i];
        if(!isalnum(ch)){   //错误即输出“ERROR”
            cout<<"ERROR"<<endl;
            return 1;
        }
        add(root,ch);
    }
    print(root);
    putchar('\n');
    // printf("%s\n",line);
    return 0;
}
