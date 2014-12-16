/*! \author  Kenta Goto
 *	\class  MCS 360
 *	\instructor Professor Lowman
 * 	\assignment Project 3
 *	\file main.cpp
 *	\brief Contains main function calling other functions.  Also has a long algorithmic function to insert spaces where needed.
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <typeinfo>
#include "postfix.h"
#include "infix.h"
#include "stack.h"


using namespace std;
void preprocessInfix(string &line);
int main(){
	string line;
	string anotherline;
	cout << endl << "*******    Infix-To-Postfix Program    ********" << endl << endl;
	cout << "Enter your Infix expression: ";
	getline(cin, line);
	cout << endl <<  "------ Before Preprocess ------" << endl;
	cout << line << endl;
	preprocessInfix(line);
	cout << endl <<  "------ After Preprocess ------" << endl;
	cout << line << endl;
	string teststring = "";
	teststring = infix2postfix(line);
	cout << endl <<  "------ Infix to Postfix Expression ------" << endl;
	cout << teststring << endl;
	cout << endl <<  "------ Evaluating Postfix Expression ------" << endl;
	double numb = eval_postfix(teststring);
	cout << numb << endl;







	return 0;
}

void preprocessInfix(string &line){
	line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

	int index0 = line.find('(');
	while (index0!=std::string::npos){
	line.insert(index0, " ");
	line.insert(index0+2, " ");
	index0 = line.find("(",index0+2);
	}

	int index00 = line.find(')');
	while (index00!=std::string::npos){
	line.insert(index00, " ");
	index00 = line.find(")",index00+2);
	}
	
	
	int index = line.find('+');
	while (index!=std::string::npos){
	line.insert(index, " ");
	line.insert(index+2, " ");
	index = line.find("+",index+2);
	}

	int index1 = line.find('*');
	while (index1!=std::string::npos){
	line.insert(index1, " ");
	line.insert(index1+2, " ");
	index1 = line.find("*",index1+2);
	}

	int index2 = line.find('^');
	while (index2!=std::string::npos){
	line.insert(index2, " ");
	line.insert(index2+2, " ");
	index2 = line.find("^",index2+2);
	}

	int index3 = line.find('/');
	while (index3!=std::string::npos){
	line.insert(index3, " ");
	line.insert(index3+2, " ");
	index3 = line.find("/",index3+2);
	}

	int index4 = line.find('%');
	while (index4!=std::string::npos){
	line.insert(index4, " ");
	line.insert(index4+2, " ");
	index4 = line.find('%',index4+2);
	}
	
	int index14 = line.find('-');
	while (index14!=std::string::npos){
		if (index14==0){
			index14 = line.find('-',index14+2);
		}
		else if (index14==1){
			line.insert(index14, " ");
			line.insert(index14+2, " ");

		}
		else if (line.at(index14-2)==' ' || line.at(index14+1)=='-' || line.at(index14-1)=='0' || line.at(index14-1)=='1' || line.at(index14-1)=='2' || line.at(index14-1)=='3' || line.at(index14-1)=='4' || line.at(index14-1)=='5' || line.at(index14-1)=='6' || line.at(index14-1)=='7' || line.at(index14-1)=='8'|| line.at(index14-1)=='9'){
			line.insert(index14, " ");
			line.insert(index14+2, " ");
		}
	//line.insert(index14, " ");
	//line.insert(index14+2, " ");
	index14 = line.find('-',index14+2);
	
		}



	
	



}