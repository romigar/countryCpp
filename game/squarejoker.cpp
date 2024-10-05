#include "squarejoker.h"
#include <iostream>
#include <algorithm>

using namespace std;

squareJoker::squareJoker()
{
    setActivated(0);
}

/* ***************************************************************** */

squareJoker::squareJoker(bool activated, string ans1, string ans2, string ans3, string ans4)
    : isActivated(activated)
{
    generateList(ans1,ans2,ans3,ans4);
}

/* ***************************************************************** */

void squareJoker::generateList(string ans1, string ans2, string ans3, string ans4)
{
    squareList.clear();
    squareList.push_back(ans1);
    squareList.push_back(ans2);
    squareList.push_back(ans3);
    squareList.push_back(ans4);
    srand(time(nullptr)); // use current time as seed for random generator
    random_shuffle(squareList.begin(),squareList.end());
}

/* ***************************************************************** */

void squareJoker::setActivated(const bool active) { isActivated = active; }

/* ***************************************************************** */

bool squareJoker::getActivated(void) const { return isActivated; }

/* ***************************************************************** */

void squareJoker::activateSquareJoker(string ans1, string ans2, string ans3, string ans4)
{
    generateList(ans1,ans2,ans3,ans4);
    setActivated(true);
}

/* ***************************************************************** */

void squareJoker::display(void)
{
    cout << squareList[0] << squareList[1] << squareList[2] << squareList[3] << endl;
}

/* ***************************************************************** */

string squareJoker::pick(void)
{
    string a = "";
    if (squareList.empty() == false)
    {
        a = squareList.back();
        squareList.pop_back();
    }
    return a;
}

/* ***************************************************************** */
