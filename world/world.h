#ifndef WORLD_H
#define WORLD_H

#include <vector>

using namespace std;

class country;
class continent;

class world
{
protected:
    vector<country> countryList;
    vector<continent> continentList;
public:
    world();
    world(vector<continent> _continentList);
    world(vector<country> _countryList);
    world(vector<country> _countryList, vector<continent> _continentList);

    void fillContinentList(void);
    void fillList(vector<country> countrylist,vector<continent> *_continentList);
    void display();
private:



};

#endif // WORLD_H
