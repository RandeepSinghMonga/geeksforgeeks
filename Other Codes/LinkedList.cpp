#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int value;
    node* next;
};

void append(node **head,node *x){
    if(*head == NULL){
        *head = x;
    }
    else{
        node *curr = new node;
        curr = *head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = x;
    }
}

void insertAfter(node **head,node *x,int pos){
    if(pos == 0){
        x->next = (*head);
        (*head) = x;
    }
    else{
        node *curr = new node;
        curr = *head;
        for(int i=0;i<pos-1;i++){
            curr = curr->next;
        }
        x->next = curr->next;
        curr->next = x;
    }
}

void affix(node **head,node *x){
    x->next = (*head);
    *head = x;
}


node *createNode(int x){
    node* element = new node;
    element->value = x;
    element->next = NULL;
    return element;
}

void print(node *head){
    node *curr = new node;
    curr = head;
    while(curr != NULL){
        cout<<curr->value<<"->";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}

int LengthI(node *head){
    node *curr = new node;
    curr = head;
    int count = 0;
    while(curr != NULL){
        count ++ ;
        curr = curr->next;
    }
    return count;
}

int LengthR(node *head){
    if(head == NULL){
        return 0;
    }
    return 1+LengthR(head->next);
}

void deleteNode(node **head, int x){
    if((*head)->value == x){
        (*head) = (*head)->next;
        return;
    }
    node *curr = new node;
    curr = *head;
    while(curr->next != NULL && (curr->next)->value != x){
        curr = curr->next;
    }
    if(curr->next == NULL){
        cout<<"No such value"<<endl;
    }
    else{
        curr->next = curr->next->next;
    }
}

void searchI(node *head,int x){
    node *curr = new node;
    curr = head;
    int flag = 0;
    while(curr!=NULL){
        if(curr->value == x){
            flag = 1;
            break;
        }
        curr = curr->next;
    }
    if(flag)cout<<"Found !"<<endl;
    else cout<<"Not Found !"<<endl;
}

void searchR(node *head,int x){
    if(head == NULL){
        cout<<"Not Found !"<<endl;
        return;
    }
    else if(head->value == x){
        cout<<"Found !"<<endl;
        return;
    }
    else{
        searchR(head->next,x);
    }
}

node *getNth(node *head,int pos){
    node *curr = new node;
    curr = head;
    for(int i=0;i<pos-1;i++){
        curr = curr->next;
    }
    return curr;
}

node *getNthFromEnd(node *head,int pos){
    if(pos > LengthI(head)){
        return NULL;
    }
            node *x,*y;
    x=head,y=head;
    for(int i=0;i<pos;i++){
        y = y->next;
    }
    while(y!=NULL){
        x = x->next;
        y = y->next;
    }
    return x;
}

node *middle(node *head){
    node *fast = new node;
    node *slow = new node;
    fast = head, slow = head;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void deleteList(node **head){
    while((*head)!=NULL){
        node *del = *head;
        *head = (*head)->next;
        free(del);
    }
}

int countInts(node *head,int x){
    node *curr = head;
    int i = 0;
    while(curr != NULL){
        if(curr->value == x){
            i++;
        }
        curr = curr->next;
    }
    return i;
}

void reverseI(node **head){
    node *x,*y,*z;
    x = NULL;
    y = *head;
    z = (*head)->next;
    while(z!=NULL){
        y->next = x;
        x = y;
        y = z;
        z = z->next;
    }
    y->next = x;
    *head = y;
}

void reverseR(node **head){
    if((*head)->next == NULL){
        return;
    }
    else{
        node *rest;
        rest = (*head)->next;
        reverseR(&rest);
        (*head)->next->next = *head;
        *head = rest;
    }
}

void reversePrint(node *head){
    if(head == NULL){
        return;
    }
    reversePrint(head->next);
    cout<<head->value<<"->";
}

void DetectLoop(node *head){
    node *fast, *slow;
    fast = head->next;
    slow = head;
    while(fast != slow && fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast == slow){
        cout<<"Loop Detected"<<endl;
    }
    else{
        cout<<"No Loop"<<endl;
    }
}

void checkPalindrome(node *head){
	node *mid = middle(head);
	reverseI(&mid);
	node *i, *j;
	i = head;
	j = mid;
	int flag = 0;
	while(i!=NULL && j!= NULL){
		if(i->value != j->value){
			flag=1;
			break;
		}
		i=i->next;
		j=j->next;
	}
	if(flag == 1){
		cout<<"Not Palindrome"<<endl;
	}
	else{
		cout<<"Palindrome"<<endl;
	}
}

void checkIntersection(node *head,node *head1){
	int len = LengthI(head);
	int len1 = LengthI(head1);
	node *ntemp;
	int itemp;
	if(len1 > len){
		itemp =  len1;
		len1 = len;
		len = itemp;

		ntemp = head;
		head = head1;
		head1 = ntemp;
	}
	node *i,*j;
	i = head;
	j = head1;
	for(int k=0;k<len - len1;k++){
		i = i->next;
	}
	while(i!=NULL && j!=NULL){
		if(i->value == j->value){
			cout<<"Intersecting node is "<<i->value<<endl;
			return;
		}
		i = i->next;
		j = j->next;
	}
	cout<<"No intersecting node"<<endl;
	return;
}

void sort(node* head){

}

void removeDuplicates(node* head){
    node *x,*y;
    x = head;
    while(x!=NULL){
        y = x->next;
        while(y!=NULL){
            if(y->value != x->value){
                break;
            }
            y = y->next;
        }
        x = y;
    }
}

void pairwiseSwapElements(node *head){
    int temp;
    node *x,*y;
    x=head;
    y=x->next;
    while(x!=NULL && y!=NULL){
        temp = x->value;
        x->value = y->value;
        y->value = temp;
        x=y->next;
        if(y->next != NULL)y=x->next;
    }
}

int main() {
	cout<<"Linked List Insertion"<<endl;
	node* head = new node;
	head = NULL;
	append(&head,createNode(1));
	append(&head,createNode(2));
	append(&head,createNode(3));
	print(head);
	insertAfter(&head,createNode(7),2);
	insertAfter(&head,createNode(5),0);
	print(head);
	affix(&head,createNode(6));
	print(head);
	cout<<"--------------------"<<endl;
	cout<<"Finding Length"<<endl;
	cout<<LengthI(head)<<endl;
	cout<<LengthR(head)<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Linked List Deletion"<<endl;
	deleteNode(&head,4);
	print(head);
	cout<<"--------------------"<<endl;
    cout<<"Searching Elements"<<endl;
    searchI(head,5);
	searchR(head,4);
	cout<<"--------------------"<<endl;
	cout<<"Print Nth"<<endl;
	cout<<"Nth value is: "<<(getNth(head,4))->value<<endl;
	cout<<"Nth from end value is: "<<(getNthFromEnd(head,4))->value<<endl;
	cout<<"Middle Element is: "<<(middle(head))->value<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Int occuring"<<endl;
	cout<<countInts(head,6)<<endl;
	print(head);
	cout<<"--------------------"<<endl;
	cout<<"Reversing Linked List"<<endl;
	reverseI(&head);
	print(head);
	//reverseR(&head);
    print(head);
	cout<<"--------------------"<<endl;
	cout<<"Loop Detection"<<endl;
	DetectLoop(head);
	cout<<"--------------------"<<endl;
	cout<<"Deleting Linked List"<<endl;
	deleteList(&head);
	print(head);
	cout<<"--------------------"<<endl;
	append(&head,createNode(1));
	append(&head,createNode(2));
	append(&head,createNode(3));
	append(&head,createNode(4));
	append(&head,createNode(5));
	append(&head,createNode(6));
	cout<<"Palindrome Check"<<endl;
	checkPalindrome(head);
	cout<<"--------------------"<<endl;
	cout<<"Intersection Check"<<endl;
	node *head1;
	head1=NULL;
	append(&head1,createNode(7));
	append(&head1,createNode(8));
	append(&head1,createNode(9));
	append(&head1,middle(head));
	checkIntersection(head,head1);
	cout<<"--------------------"<<endl;
	cout<<"Reverse Printing the List"<<endl;
	reversePrint(head);
	cout<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Pairwise Swap Elements"<<endl;
	print(head);
	pairwiseSwapElements(head);
	print(head);
	cout<<"--------------------"<<endl;
	//removeDuplicates(head);
	cout<<"--------------------"<<endl;
	return 0;
}
