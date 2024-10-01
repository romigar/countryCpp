#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdint>
#include "world.h"
#include "country.h"
#include "continent.h"

using namespace std;

/* ***************************************************************** */
/*
 * Extract countries list from a csv file, with format is :
 * country,capital,continent
 * */
int fill_from_csv(vector<country> *_countryList)
{
    ifstream file("/home/theo/workspace/countryCpp/ressources/liste.csv");
    string line;
    string _country;
    string _capital;
    string _continent;
    uint16_t i = 0 ;

    if (!file.is_open())
    {
        cerr << "ERROR Imposible to open file" << endl;
        return 1;
    }

    while (getline(file, line))
    {
        stringstream ss(line);
        string element;
        vector<string> row;

        while (getline(ss, element, ','))
        {
            row.push_back(element);
        }
        _country = row[0];
        _capital = row[1];
        _continent = row[2];

        _countryList->push_back(*new country(i,_country,_continent,_capital));
        //countrylist->back().display();
        i++;
    }

    file.close();
    cout<<  "Init list finished. Size : " << _countryList->size() <<endl;
    return 0;
}

/* ***************************************************************** */
/*
 * From a countryList, fill a continentList
 * Read "continent" attribute for each country in the list and put it
 * in right continent.countrylist
 * Create a new continent each time a new continent-name is met
 * */
void world::fillList(vector<country> countrylist,vector<continent> *_continentList)
{
    bool known_region = false;
    _continentList->clear(); // Clear the continentList
    // Create a first continent for the first country met and put it in
    vector<vector<country>> newContList;
    vector<country> first;
    first.push_back(countrylist.at(0));
    newContList.push_back(first);

    for (int i = 1 ; i  < countrylist.size() ; i++)
    {
        known_region = false;
        // Test if this country's continent is already created, is yes, put it in
        for (int k = 0; k < newContList.size(); k++)
        {
            if (!countrylist.at(i).getContinent().compare( newContList.at(k).at(0).getContinent() ) )
            {
                newContList.at(k).push_back(countrylist.at(i));
                known_region = true;
            }
        }
        // if this continent has not been created, then create it, and put the country in
        if (!known_region)
        {
            vector<country> newContinent;
            newContinent.push_back(countrylist.at(i));
            newContList.push_back(newContinent);
        }
    }
    _continentList->push_back(*new continent("Monde",0,countrylist));
    // Init the continentList with the created lists
    for (int k = 0; k < newContList.size(); k++)
    {
        _continentList->push_back(*new continent(newContList.at(k).at(0).getContinent(),k+1,newContList.at(k)));
    }
}

/* ***************************************************************** */

/*
 * Read csv file to fill countryList
 * than sort this countryList for filling continentList
 * */
void world::fillContinentList(void)
{
    fill_from_csv(&countryList);
    fillList(countryList,&continentList);
}

/* ***************************************************************** */

// Default constructor
world::world()
{
    fillContinentList();
}

/* ***************************************************************** */

world::world(vector<continent> _continentList)
{
    continentList = _continentList;
}

/* ***************************************************************** */

world::world(vector<country> _countryList, vector<continent> _continentList)
{
    continentList = _continentList;
    countryList = _countryList;
}

/* ***************************************************************** */

world::world(vector<country> _countryList)
{
    countryList = _countryList;
}

/* ***************************************************************** */

void world::display(void)
{
    cout<<"World: { ";
    cout<<"  Countries:"<< countryList.size() <<","<<endl;
    cout<<"  Continents :"<< continentList.size() <<","<<endl;
    cout<<"  Continents:"<< countryList.size() <<"["<<endl;
    for (int i = 0 ; i < continentList.size();i++) {
        continentList.at(i).display();
    }
    cout<<"}"<<endl;
}

/* ***************************************************************** */



