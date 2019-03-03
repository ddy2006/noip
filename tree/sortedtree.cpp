#include <bits/stdc++.h>
using namespace std;
struct Node{
    char val;
    struct Node *left, *right;
};

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
void print(Node *p){
    if(p!=NULL){
        print(p->left);
        putchar(p->val);
        print(p->right);
    }
}

int main(){
    char line[300];
    gets(line);
    struct Node *root = NULL;
    for(int i=0;i<strlen(line);i++){
        char ch=line[i];
        if(!isalnum(ch)){
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
