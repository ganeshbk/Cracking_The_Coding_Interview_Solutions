/******************************************************************************************************************************************/
//Problem 1.4 Write a method to decide if two strings are anagrams or not.
//Filename:12.cpp //Naming Convention is 11 means Chapter 1 and problem 4
//Author:  Ganesh Kudleppanavar
//Version:    01/11/2018 Ganesh Kudleppanavar
/******************************************************************************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

//Method to sort the string;
void sortStr(char *str, int start , int end);
int partition(char *str, int start , int end);
bool compareStrings(char *str1, char *str2);
void printStr(char *str);

int main(void){
	char str1[100],str2[100];
	int length1=0, length2 = 0;
	
	cout << "Enter first string: ";
	gets(str1);	
	while(str1[length1++]);
	sortStr(str1,0,length1-1);
	printStr(str1);
	
	
	cout << "Enter second string: ";
	gets(str2);
	while(str2[length2++]);
	sortStr(str2,0,length2-1);
	printStr(str2);
	
	
	bool result;
	
	result = compareStrings(str1,str2);
	
	if(result)
		cout << "The strings are anagrams";
	else
		cout << "The strings not are anagrams";
	return 0;
}


void printStr(char * str)
{
	int length=0;
	while(str[length]!='\0'){
		cout << str[length++] << " ";
	}
}



/// Summary:   This method comapres the two strings
/// Parameters:There are two parameters string1 and string2
/// Returns : Returns true if two strings are equal.

bool compareStrings(char *str1, char *str2){
	int length1=0, length2 = 0;
	while(str1[length1++]);
	while(str2[length2++]);
	if(length1 != length2)
		return false;
	else{
		for(int i=0;i<length1;i++)
		{
			if(str1[i]== str2[i])
				continue;
			else 
				return false;
		}
	}
	return true;
	
}


/// Summary:   This method is the standard method to generate the partition index in quicksort
/// Parameters: The standard paramerts the array to be sorted, lower index and upper index.
/// Returns : Returns the partition index

int partition(char *str, int start , int end){
	char pivot = str[end];
	int pIndex = start;
	for(int i=start;i<end-1;i++){
		if(str[i]<=pivot){
			swap(str[i],str[pIndex]);
			pIndex++;
		}
		swap(str[pIndex],str[end]);
	}
	return pIndex;
}

/// Summary:   This method is the entry point for the quicksort to sort the string
/// Parameters: The standard paramerts the array to be sorted, lower index and upper index.
/// Returns : does not return anything as the sorting is done inplace and using pointers

void sortStr(char *str, int start , int end){
	int pIndex;
	if(start<end){
		pIndex =  partition(str, start, end);
		sortStr(str, start, pIndex-1);
		sortStr(str, pIndex+1, end);
	}
}
/****************************************************/
// EOF: 14.cpp
/****************************************************/