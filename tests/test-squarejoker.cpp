#include <iostream>
#include <cstdlib>
#include <cstdint>
#include "squarejoker.h"

using namespace std;


int main(int argc, char *argv[])
{
    cout<< "start"<<endl;

    string str1 = "Réponse A ";
    string str2 = "Réponse B ";
    string str3 = "Réponse C ";
    string str4 = "Réponse D ";
    string tempStr;

    squareJoker *myJoker = new squareJoker(0,str1,str2,str3,str4);

    cout << str1 << str2 << str3 << str4 << endl;

    //myJoker->activateSquareJoker(str1,str2,str3,str4);
    myJoker->display();

    tempStr = myJoker->pick();
    cout << tempStr << endl;
    tempStr = myJoker->pick();
    cout << tempStr<< endl;
    tempStr = myJoker->pick();
    cout << tempStr<< endl;
    tempStr = myJoker->pick();
    cout << tempStr<< endl;
    tempStr = myJoker->pick();
    cout << tempStr<< endl;
    tempStr = myJoker->pick();
    cout << tempStr<< endl;

    delete(myJoker);

    return 0;
}

