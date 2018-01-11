/******************************************************************************************************************************************/
//Problem 1.2 Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.
//Filename:12.cpp //Naming Convention is 11 means Chapter 1 and problem 2
//Author:  Ganesh Kudleppanavar
//Version:    01/11/2018 Ganesh Kudleppanavar
/******************************************************************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

//Method signature to reverse string
string reverseString(string str);

int main(void){
	string str;
	getline(cin, str);
	str =  reverseString(str);
	cout << "The reveresed string is : " << str;
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

string reverseString(string str){
	int length = str.size()-1;
	char temp;
	for( int i=0 ;i<(length/2);i++)
	{
		temp = str[i];
		str[i] = str[length-i];
		str[length-i] = temp;
	}
	return str;
}

/****************************************************/
// EOF: 12.cpp
/****************************************************/