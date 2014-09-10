/*
Gaurav Sheni
CSC 221
Project 1 - Infix to Postfix 
1/31/14
 */
#include <iostream>
#include "List.h"
#include <cstdlib>
#include <stdlib.h>
#include <cstring>

using namespace std;

int precedence(string); //to find order of operations

int main (int argc, char **argv){
	if (argc <= 1){
		cout << "\n";
		exit(1);//no command line arguments
	}
	// to see if the number of rightparenthesis match the left parenthesis
	int rightbracket = 0; 
	int leftbracket = 0;
	//go through all the command line arguments 
	for (int i = 1; i < argc; i++){
	string currentcharacter = argv[i]; 

		if (currentcharacter == "("){
		rightbracket++;
		}
		if (currentcharacter == ")"){
		leftbracket++;
		}
	}
	//if the number of parenthesis doesn't match up.
	if (leftbracket != rightbracket){
		cout << "\n";
		exit(1);//parenthesis mismatch
	}
	//go through all command line arguments and make sure operators are legal.
	for (int i = 1; i < argc; i++){
	string checkcharacter = argv[i];
	int number = atoi(checkcharacter.c_str()); //Convert the string to a number.
	int alphacheck = -1; //check for alphabetic illegal characters, it starts at -1, which will be changed if their is an alphabetic letter
	alphacheck = checkcharacter.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"); // Look in the string for any of these characters, and return the location.
		if (checkcharacter == "("){
		goto leave;
		}
		else if (checkcharacter == ")"){
		goto leave;
		}
		else if (checkcharacter == "+"){
		goto leave;
		}
		else if (checkcharacter == "-"){
		goto leave;
		}
		else if (checkcharacter == "*"){
		goto leave;
		}
		else if (checkcharacter == "/"){
		goto leave;
		}
		else if (checkcharacter == "\\"){
		goto leave;
		}
		else if (alphacheck >= 0){ //if the alphacheck number got changed to 0 or to anything higher, indicating the location of an alphabetic character, then exit the program.
		cout << "\n";
		exit(1);//illegal character
		}
		else if (number > 0) {
		goto leave;
		}
		else {
		cout << "\n";
		exit(1);//non atomic operator
		}
	leave:; //come here if legal character.
	}

	List<string> stack; // create a list, called stack, for strings
	for (int i = 1; i < argc; i++){
		string currentcharacter = argv[i];
		int number = atoi(currentcharacter.c_str()); //Convert the string to a number.
		if (number > 0){
		//If it is an operand, output it.
			cout << number << " ";
		}
		if (currentcharacter == "("){
		//If it is a left parenthesis, put it on the stack.
			stack.push_front(currentcharacter);
		}
		if (currentcharacter == ")"){
		//If it is a right parenthesis, pop each operator and output it until the left parenthesis is reached. Pop left parenthesis, but 				ignore it.
			while (stack.front() != "(" ){
				cout << stack.front() << " ";
				stack.pop_front();
			}
			//There would be mismatch of parenthesis check, but it already occured above, so not needed
		stack.pop_front();
		}
		if (currentcharacter == "+" || currentcharacter == "-" || currentcharacter == "/" || currentcharacter == "*"){
			//If it is an operator, compare its precedence to the operator currently at the top of the stack. If the stack is 					empty, automatically push it on the stack.
			if (stack.empty()){
				stack.push_front(currentcharacter);
				goto done; //for first time, since stack will be empty, stack just needs to be filled, 
			}

			int checkstacktop = precedence (stack.front());

			int opetarorrank = precedence (currentcharacter);

			//If the operator is greater in precedence (as compared to the stack top), push it on the stack.
			if (opetarorrank > checkstacktop ){
				stack.push_front(currentcharacter);
			}
			//If the operator is less than or equal in precedence than the operator at the top of the stack,
			if (opetarorrank <= checkstacktop ){
				keeptrying: //Keep popping operators and output
				cout << stack.front() << " ";
				stack.pop_front();

				int checkstackagain = 0;
				checkstackagain = precedence (stack.front());
					//the original operator is lower in precedence than the operator at the top of the stack
					if (opetarorrank < checkstacktop ){
						stack.push_front(currentcharacter);
						goto done;
					}
					//the left parenthesis is reached,
					if (stack.front() == "("){
						stack.push_front(currentcharacter);

goto done;
					}
					//the stack is empty.
					if (stack.empty()){
						stack.push_front(currentcharacter);
						goto done;
					}
				//Keep popping operators and output
				goto keeptrying;
			}
		}
		done:; //for first time, since stack will be empty, stack just needs to be filled, 
	}
		cout << stack.front() << " ";
		//stack.pop_front(); //not necessary to pop last front, caused segmentation error.
		cout << "\n"; //to make the output looking neat.
}

int precedence(string currentoperator){ //return the order of operations, according to the input of string.
	int precedence;
	if (currentoperator == "*" || currentoperator =="/"){
		precedence = 2;
		return precedence;
	}
	if (currentoperator == "+" || currentoperator =="-"){
		precedence = 1;
		return precedence;
	}
}

