/******************************************************************************************************************************************/
//Problem 1.5 Write a method to replace all spaces in a string with ‘%20’
//Filename:15.cpp //Naming Convention is 11 means Chapter 1 and problem 5
//Author:  Ganesh Kudleppanavar
//Version:    01/11/2018 Ganesh Kudleppanavar
/******************************************************************************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#define length  100
using namespace std;

char * replaceSpace(string str, int newLength);

int main(void){	
	char str[length], *modStr;
	gets(str);
	
	int size=0,whiteSpace=0;;
	while(str[size++]){
		if(str[size] == ' ')
			whiteSpace++;
	}
	cout << "Whitespace count" << whiteSpace <<"  size"<< size <<  " new space count " << size+(whiteSpace*2) << " ";
	modStr = replaceSpace(str, size+(whiteSpace*2));
	cout << "\nModfied string  " << modStr << endl;
	return 0;
}



/// Summary:   This method comapres the two strings
/// Parameters:There are two parameters string1 and string2
/// Returns : Returns true if two strings are equal.

char * replaceSpace(string str, int newLength){
	char * newStr = (char*)malloc(sizeof(char)*newLength);
	int i=0,j=0;
	while(str[i] != '\0'){
		if(str[i] == ' '){
			newStr[j++]='%';
			newStr[j++]='2';
			newStr[j]='0';
		}
		else
		    newStr[j]=str[i];
        ++i;++j;
    }
	newStr[j]='\0';
	return newStr;
	
}

/****************************************************/
// EOF: 15.cpp
/****************************************************/