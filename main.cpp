#include <iostream>
#include <string>
using namespace std;

string help();

int main()
{
    cout << "AHHH HELP ME!" << help();
    cout << "It's very hot today" << endl;
    return 0;
}

string help()
{
  return "help!";
}