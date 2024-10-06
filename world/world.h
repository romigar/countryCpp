#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class country;
class continent;

class world
{
protected:

public:
    vector<country> countryList;
    vector<continent> continentList;

    world();
    world(vector<continent> _continentList);
    world(vector<country> _countryList);
    world(vector<country> _countryList, vector<continent> _continentList);

    void fillContinentList(void);
    void fillList(vector<country> countrylist,vector<continent> *_continentList);
    void display();
    uint8_t getContinentId(const string continentName);


private:



};

#endif // WORLD_H
