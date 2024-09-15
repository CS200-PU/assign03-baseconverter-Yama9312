//******************************************************************************
// File name:   main.cpp
// Author:      Nathan Yamashiro
// Date:        09/13/2024 (Replace xx/xx/xxxx with month/day/year)
// Class:       CS150-xx (Replace xx with your section number)
// Assignment:  Base Converter
// Purpose:     Display the message Hello World to the screen
// Hours:       0.25
//******************************************************************************

#include <iostream>

using namespace std;
int hexCharToInt (char hexDigit);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);
string reverseString (const string& strNumber);

const char BINARY = 'b',
           HEX = 'x',
           DECIMAL = 'd';

/**************************************************************************
 Function: 	 	main

 Description: drive for base converter

 Parameters:	none

 Returned:	 	exit status
 *************************************************************************/
int main () {
  const string QUIT = "q";
  const string PROMPT = "Enter your string to convert (q to quit): ";
  string input;
  string convert;
  char base = 'a';

  printTitle("*");
  while (QUIT != input) { 
    input = getNumber(PROMPT);
    if (input != QUIT){
      base = getBase(input);
      if (base == HEX){
        cout << "the decimal conversion is: " << hexToDecimal (input) << endl;
        cout << "the binary converstion is: " << hexToBinary (input) << endl;
      }
      else if (base == BINARY){
        cout << "the decimal conversion is: " << binaryToDecimal (input) 
             << endl;
        cout << "the hexadecimal converstion is: " << binaryToHex (input) 
             << endl;
      }
      else if (base == DECIMAL) {
        cout << "the binary converstion is: " << decimalToBinary (input) 
             << endl;
        cout << "the hexadecimal converstion is: " << decimalToHex (input) 
             << endl;
      }
    }
  }
  
  return EXIT_SUCCESS;
}
/**************************************************************************
 Function: 	 	hexCharToInt

 Description: turns a hex letter value to an integer

 Parameters:	hexDigit - The letter that must be converted

 Returned:	 	number value of the hex letter
 *************************************************************************/
int hexCharToInt (char hexDigit) {
  const int NUM_SHIFT = 11;
  int num = 0;

  if (hexDigit >= 'A' && hexDigit <= 'F'){ // if digit is a letter
    num = (static_cast <int> (hexDigit - 'A')) + NUM_SHIFT;
  }
  else { // if digit is a number
    num = static_cast <int> (hexDigit);
  }

  return num;
}
/**************************************************************************
 Function: 	 	getBase

 Description: finds the base of the string

 Parameters:	strNumber - the string that is checked
 
 Returned:	 	the base of the number
 *************************************************************************/
char getBase (const string& strNumber) {
  char base;

  if (strNumber[1] == BINARY){
    base = BINARY;
  }
  else if (strNumber[1] == HEX){
    base = HEX;
  }
  else {
    base = DECIMAL;
  }
  return base;
}
/**************************************************************************
 Function: 	 	getNumber

 Description: gets the users input

 Parameters:	prompt - the message printed to the user
 
 Returned:	 	number from user input
 *************************************************************************/
string getNumber (const string& prompt) {
  string num;
    cout << prompt;
    cin >> num;
  return num;
}
/**************************************************************************
 Function: 	 	printTitle

 Description: prints the tile to the screen

 Parameters:	none
 
 Returned:	 	none
 *************************************************************************/
void printTitle (const string& myTitle) {
  cout << "**************************************\n";
  cout << "*****HEX-DECIMAL-BINARY CONVERTER*****\n";
  cout << "**************************************\n";
}
/**************************************************************************
 Function: 	 	binaryToDecimal

 Description: converts a binary string to decimal

 Parameters:	strNumber - the string that is converted
 
 Returned:	 	the number after conversion
 *************************************************************************/
string binaryToDecimal (const string& strNumber) {
  string dec;

  for (int i = 0; i < strNumber.length(); i++) {

  }
  return dec;
}
/**************************************************************************
 Function: 	 	decimalToBinary

 Description: converts a binary string to decimal

 Parameters:	strNumber - the string that is converted
 
 Returned:	 	the number after conversion
 *************************************************************************/
string decimalToBinary (const string& strNumber) {
  const int BASE_TWO = 2;
  string bin = "0b";
  int remain = 0;
  int solution = stoi (strNumber);

  while (solution) {
    solution /= BASE_TWO;
    remain = solution % BASE_TWO;
    bin += to_string (remain);
  }
  return bin;
}
/**************************************************************************
 Function: 	 	decimalToHex

 Description: converts a binary string to decimal

 Parameters:	strNumber - the string that is converted
 
 Returned:	 	the number after conversion
 *************************************************************************/
string decimalToHex (const string& strNumber) {
  string hex;

  for (int i = 0; i < strNumber.length(); i++) {

  }
  return hex;
}
/**************************************************************************
 Function: 	 	hexToDecimal

 Description: converts a binary string to decimal

 Parameters:	strNumber - the string that is converted
 
 Returned:	 	the number after conversion
 *************************************************************************/
string hexToDecimal (const string& strNumber) {
  string dec;

  for (int i = 0; i < strNumber.length(); i++) {

  }
  return dec;
}
/**************************************************************************
 Function: 	 	hexToBinary

 Description: converts a binary string to decimal

 Parameters:	strNumber - the string that is converted
 
 Returned:	 	the number after conversion
 *************************************************************************/
string hexToBinary (const string& strNumber) {
  string bin;
  bin = hexToDecimal(strNumber);
  bin = decimalToBinary (bin);
  return bin;
}
/**************************************************************************
 Function: 	 	binaryToHex

 Description: converts a binary string to decimal

 Parameters:	strNumber - the string that is converted
 
 Returned:	 	the number after conversion
 *************************************************************************/
string binaryToHex (const string& strNumber) {
  string hex;
  hex = binaryToDecimal (strNumber);
  hex = decimalToHex (hex);
  return hex;
}
/**************************************************************************
 Function: 	 	reverseString

 Description: reverses a string

 Parameters:	strNumber - the string that is reversed
 
 Returned:	 	the reversed string
 *************************************************************************/
string reverseString (const string& strNumber) {
  string reverse;
  int count = strNumber.length() - 1;
  for (int i = 0; i < strNumber.length(); i++){
    reverse[i] = strNumber[count];
    count --;
  }
  return reverse;
}