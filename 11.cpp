/******************************************************************************************************************************************/
//Problem 1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
//Filename:11.cpp //Naming Convention is 11 means Chapter 1 and problem 1
//Author:  Ganesh Kudleppanavar
//Version:    01/11/2018 Ganesh Kudleppanavar
/******************************************************************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

//Method signature to determing if the string are unique
bool hasUniqueCharacters(string str);

int main(void){
	string str;
	getline(cin, str);
	if(hasUniqueCharacters(str)){
		cout<< " The Input string has all unique character" ;
	}
	else{
		cout<< " The input string does not have unique characters";
	}
	return 0;
}

/// <summary>
///     Implements the method hasUniqueCharacters to check if the input string has unique characters
/// </summary>
/// <Assumption>
///     This method assumes that all the characters in the input string are ASCII characters and the method uses a boolean array and makes the index of the ASCII equivalent field true. and traverses the whole string to veirfy if there are no duplicates.
/// </Assumption>
/// <param name="str">
///    This is the input string which needs to be checked.
/// </param>
///	<return datatype = boolean>
///		This method would return true if all the characters are unique in the input string.
///	</return datatype>

bool hasUniqueCharacters(string str){
	int strLength = str.size();
	bool characters[256];
	for(int i=0;i<256;i++){
		characters[i] = false;
	}
	for(int i=0;i<strLength-1;i++){
		if(characters[int(str[i])])
			return false;
		else 
			characters[int(str[i])] = true;
	}
	return true;
}








/****************************************************/
// EOF: 11.cpp
/****************************************************/