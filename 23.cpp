/******************************************************************************************************************************************/
//Problem 2.3 Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
//Filename:23.cpp //Naming Convention is 21 means Chapter 2 and problem 3
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
node * findNthNode(node * head,int);
void removeSpecifiedNode(node * targerRemovalNode);

int main(void){	
	node * head =NULL;
	head = createLinkedList(head);
	printLinkedList(head);
	int n=0;
	cout << " \nEnter the node you want to find: ";
	cin >> n;
	cout << "\nThe nth Node is : ";
	node * temp = findNthNode(head, n);
	if(temp!= NULL)
		cout << temp->data;
	else  
		cout << " no nth node available";
	removeSpecifiedNode(temp);
	cout << " \nthe linked list after removal of the target node is ";
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


/// Summary:   This method finds the nth node in the linked list.
/// Parameters: Parameter 1 is pointer of the head node and 
///				Parameter 2 is the nth node that needs to be found.
/// Returns : Returns the pointer of the nth node avaialbe. If no Nth node is available returns NULL.

node * findNthNode(node * head,int n){
	if(head == NULL) return head;
	int count =0;
	while(head!=NULL){
		count++;
		if(count == n){
			return head;
		}
		else
		{
			head = head->next;
		}
	}
	return head;
	
}


/// Summary:   This method finds the specified node in the linked list.
/// Parameters: Parameter 1 is pointer of the node to be deleted. You cannot remove the last node as a result if you pass the last node the function returns without deleting the node.
/// Returns : Does not return anything.
void removeSpecifiedNode(node * targetRemovalNode){
	if(targetRemovalNode == NULL || targetRemovalNode->next == NULL)
		return ;
	
	else 
	{
		targetRemovalNode->data = targetRemovalNode->next->data;
		targetRemovalNode->next = targetRemovalNode->next->next;
	}
}



/****************************************************/
// EOF: 23.cpp
/****************************************************/