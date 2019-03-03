#include<iostream>
using namespace std;

struct node{
	char value;
	struct node *next;
};

// 链表打印 
void print(struct node *head){
	if(head != NULL){
		cout << head->value << endl;
		print(head->next);
	}
}

// 链表转置 
struct node * reverse (struct node *head){
	struct node *headn = NULL , *ptr;
	while(head != NULL){
		ptr = head;
		head = head -> next;
		ptr -> next = headn;
		headn = ptr;
	}
	return headn;
}

// 初始化链表，元素为A、B、C、D、E 
struct node *init(){
    char vs[] = {'A','B','C','D','E'};
    struct node *head=NULL,*ptr;

	for(int i = sizeof(vs)-1;i >= 0;i--){
		ptr = new struct node;
		ptr->value = vs[i];
		ptr->next = head;
		head = ptr;
    }
	return head;	
}

// 删除C节点 
void remove(struct node * head){
    struct node *ptr=head;
	while(ptr->next != NULL){
		if(ptr->next->value == 'C'){
			struct node *p = ptr->next;
			ptr->next = ptr->next->next;
			delete p;
			break;
		}
		ptr = ptr->next;
	}
}
// D节点前增加X节点 
void insert(struct node * head){
    struct node *ptr=head;
	while(ptr->next != NULL){
		if(ptr->next->value == 'D'){
			struct node *p = new struct node;
			p->value = 'X';
			p->next = ptr->next;
			ptr->next = p;
			break;
		}
		ptr = ptr->next;
	}
}

int main(int argc, char *argv[])
{
    struct node *head,*ptr;
    
	head = init();
	print(head);
	cout << "-------------------" << endl;

	remove(head);
	print(head);
	cout << "-------------------" << endl;
	
	insert(head);
	print(head);
	cout << "-------------------" << endl;
	
	system("pause");
	return 0;
}
