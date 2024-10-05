#ifndef SQUAREJOKER_H
#define SQUAREJOKER_H

#include <iostream>
#include <vector>


using namespace std;

class squareJoker
{
public:
    squareJoker();
    squareJoker(bool activated, string ans1, string ans2, string ans3, string ans4);

    void activateSquareJoker(string ans1, string ans2, string ans3, string ans4);
    void generateList(string ans1, string ans2, string ans3, string ans4);
    void setActivated(const bool active);
    bool getActivated(void) const;
    void display(void);
    string pick(void);
private :
    bool isActivated;
    vector<string> squareList;
};

#endif // SQUAREJOKER_H
