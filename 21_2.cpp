/******************************************************************************************************************************************/
//Problem 2.1 Write code to remove duplicates from an unsorted linked list.
//Filename:21.cpp //Naming Convention is 21 means Chapter 2 and problem 1
//Author:  Ganesh Kudleppanavar
//Version:    01/12/2018 Ganesh Kudleppanavar
/******************************************************************************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#define length  100
using namespace std;

//Structure defining the node in the linked list
struct node {
	int data;
	node * next;
};

node * insertNode(node *head, int data);
node * createLinkedList(node *head);
node * getNewNode(int data);
void printLinkedList(node* head);
void removeNode(node * crawler, node * head);
node * removeDuplicateNode(node* head);

int main(void){	
	node * head =NULL;
	head = createLinkedList(head);
	printLinkedList(head);
	head = removeDuplicateNode(head);
	cout << "\nAfter removal of duplicates : \n";
	printLinkedList(head);
	return 0;
}

/// Summary:   Creates the linked list based on user input
/// Parameters: Parameter 1 is the pointer of the head of the linked list
/// Returns : Returns the pointer of the head of the linked list.

node * createLinkedList(node *head){
	char ch ='n';
	int data;
	cout << "Do you want to enter data";
	cin >> ch;
	while(ch=='y'){
		cout << "\nEnter data : ";
		cin >> data;
		head = insertNode(head , data);
		cout << "Do you wanna continue : ";
		cin >> ch;
	}
	return head;
}

/// Summary:   Inserts the data in the linked list pointed by head pointer recursively.
/// Parameters: Parameter 1 is the pointer of the head of the linked list. Parameter 2 is the data to be added in the linked list node.
/// Returns : Returns the pointer of the head of the linked list.

node * insertNode(node *head, int data){
	if(head == NULL){
		head = getNewNode(data);
	}
	else	
		head->next = insertNode(head->next, data);
	
	return head;
}

/// Summary:   Generates new node to be added in the linked list.
/// Parameters: Parameter 1 is the data to be added in the linked list node.
/// Returns : Returns the pointer of the head of the linked list.
node *getNewNode(int data){
	node * newNode = new(node);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/// Summary:   This method prints the data in all nodes of the linked list.
/// Parameters: Parameter 1 is pointer of the head node.
/// Returns : Does not return anything.

void printLinkedList(node* head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
}

/// Summary:   This method removes the duplicate nodes.
/// Parameters: Parameter 1 is pointer of the head node.
/// Returns : Returns the pointer of the head of the linked list.

node * removeDuplicateNode(node * head){
	if(head == NULL )return head;
	node * temp = head, *crawler = head->next;
	while(temp!=NULL){
		while(crawler!=NULL){
			if(temp->data == crawler->data){
				cout << "removing node\n "  << temp->data;
				removeNode(crawler,head);
			}
			crawler=crawler->next;
		}
		temp = temp->next;
		if(temp!=NULL)
			crawler = temp->next;
	}
	return head;
}


/// Summary:   This method breaks the link of the duplicate node.
/// Parameters: Parameter 1 is pointer of the node that needs to be broken/removed,  and the parameter 2 is the head node of the linked list.
/// Returns : Does not return anything.

void removeNode(node * crawler, node * head){
	while(head!=NULL){
		if(head->next == crawler){
			node *temp = crawler->next;
			head->next  = temp;
			//crawler->next = NULL;
			//crawler = NULL;
		}
		head = head->next;
	}
}

/****************************************************/
// EOF: 21.cpp
/****************************************************/