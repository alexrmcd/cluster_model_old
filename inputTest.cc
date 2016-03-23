//**.****|****.****|****.****|****.****|****.****|****.****|****.****|****.****|
// * inputTest.cc *                                              3/18/2016 
//**"****!****"****!****"****!****"****!****"****!****"****!****"****!****"****|






#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main(){


cout << "Enter 1 for default"
string input = "";

int number = 0;

getline(cin, input);
stringstream myStream(input);

myStream >> number;

cout << number << endl;


return 0;

}