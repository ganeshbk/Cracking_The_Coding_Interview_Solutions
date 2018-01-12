/******************************************************************************************************************************************/
//Problem 2.5 You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
//Filename:25.cpp //Naming Convention is 21 means Chapter 2 and problem 5
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
node * addLinkedList(node * num1, node * num2);

int main(void){	
	node * num1 =NULL, *num2 = NULL;
	num1 = createLinkedList(num1);
	cout << "The first input is : ";
	printLinkedList(num1);
	num2 = createLinkedList(num2);
	cout << "The second input is : ";
	printLinkedList(num2);
	
	node *output = NULL;	
	output = addLinkedList(num1,num2);
	cout << "\n";
	printLinkedList(output);
	return 0;
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


/// Summary:   This method finds the specified node in the linked list.
/// Parameters:Parameter 1: it is the pointer to the linked list of the first number;
///			   Parameter 2: it is the pointer to the linked list of the sexond number;
/// Returns :  Returns the head of the result linked list.
node * addLinkedList(node * num1, node * num2){
	int tempSum=0,carry = 0;
	node * result=NULL, *head ;
	head = result;
	while(num1 !=NULL || num2 != NULL || carry !=0)
	{
		tempSum = ((num1!=NULL)?num1->data:0)+((num2!=NULL)?num2->data:0)+carry;
		carry = tempSum / 10;
		//cout << " tempsum: " << tempSum%10;
		result =  insertNode(result,tempSum%10);
		num1 = ((num1!=NULL)?num1->next:NULL);
		num2 = ((num2!=NULL)?num2->next:NULL);
	}
	
	return result;
}



/****************************************************/
// EOF: 24.cpp
/****************************************************/