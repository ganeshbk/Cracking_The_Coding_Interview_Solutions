/******************************************************************************************************************************************/
//Problem 1.4 Write a method to decide if two strings are anagrams or not.
//Filename:12.cpp //Naming Convention is 11 means Chapter 1 and problem 2
//Author:  Ganesh Kudleppanavar
//Version:    01/11/2018 Ganesh Kudleppanavar
/******************************************************************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

//Method signature to reverse string
string removeDuplication(char *str);

int main(void){
	string str;
	getline(cin, str);
	str =  removeDuplication(str);
	cout << "The duplicate removed string is : " << str;
	return 0;
}

/// <summary>
///     Reverses the input string.
/// </summary>
/// <param name="str">
///    This is the input string which needs to be reversed.
/// </param>
///	<return datatype = string>
///		This method would return the reversed string
///	</return datatype>

string removeDuplication(char  *str){
	int next=0,
}

/****************************************************/
// EOF: 12.cpp
/****************************************************/