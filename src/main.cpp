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
#include <cmath>

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
string reverseString (string& strNumber);

const char BINARY = 'b',
           HEX = 'x',
           DECIMAL = 'd';
const string HEX_VALS = "0123456789ABCDEF";

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
        cout << "The decimal conversion is: " << hexToDecimal (input) 
             << endl;
        cout << "The binary converstion is: " << hexToBinary (input) 
             << endl << endl;
      }
      else if (base == BINARY){
        cout << "The decimal conversion is: " << binaryToDecimal (input) 
             << endl;
        cout << "The hexadecimal converstion is: " << binaryToHex (input) 
             << endl << endl;
      }
      else if (base == DECIMAL) {
        cout << "The binary converstion is: " << decimalToBinary (input) 
             << endl;
        cout << "The hexadecimal converstion is: " << decimalToHex (input) 
             << endl << endl;
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
  int num = 0;

  for (int i = 0; i < HEX_VALS.length(); i++){
    if (hexDigit == HEX_VALS[i]){
      num = i;
      break;
    }
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
  const int BASE_TWO = 2;
  int dec = 0;
  int location = strNumber.length() - 3;
  for (int i = 2; i < strNumber.length(); i++) {
    if (strNumber[i] == '1'){
      dec += pow(BASE_TWO, location);
    }
    location--;
  }
  return to_string(dec);
}
/**************************************************************************
 Function: 	 	decimalToBinary

 Description: converts a binary string to decimal

 Parameters:	strNumber - the string that is converted
 
 Returned:	 	the number after conversion
 *************************************************************************/
string decimalToBinary (const string& strNumber) {
  const int BASE_TWO = 2;
  string bin;
  int remain = 0;
  int solution = stoi (strNumber);

  while (solution) {
    remain = solution % BASE_TWO;
    solution /= BASE_TWO;
    bin += to_string (remain);
  }
  bin += "b0";
  reverseString (bin);
  if (bin.length() < 3){
    bin += "0";
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
  const int BASE_SIXTEEN = 16;
  string hex;
  string insertVal;
  int remain = 0;
  int solution = stoi (strNumber);

  while (solution) {
    remain = solution % BASE_SIXTEEN;
    solution /= BASE_SIXTEEN;
    hex += HEX_VALS[remain];
  }
  hex += "x0";
  reverseString (hex);
  if (hex.length() < 3){
    hex += "0";
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
  const int BASE_SIXTEEN = 16;
  int dec = 0;
  int location = strNumber.length() - 3;
  int currentVal = 0;

  for (int i = 2; i < strNumber.length(); i++) {
    currentVal = hexCharToInt (strNumber[i]);
    dec += currentVal * (pow(BASE_SIXTEEN, location));
    location--;
  }

  return to_string (dec);
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
string reverseString (string& strNumber) {
  string reverse;
  reverse.resize(strNumber.length());
  int count = strNumber.length() - 1;
  for (int i = 0; i < strNumber.length(); i++){
    reverse[i] = strNumber[count];
    count --;
  }
  strNumber = reverse;
  return reverse;
}