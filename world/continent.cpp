#include <iostream>
#include <cstdint>
#include <random>
#include "continent.h"
#include "country.h"

using namespace std;

//Default constructor
continent::continent(void)
{

}

/* ***************************************************************** */

//Copy constructor
continent::continent(const continent& other)
{
    setId(other.id);
    setName(other.name);
    list = other.list;
}

/* ***************************************************************** */

// Init Constructor
continent::continent(string _name, uint8_t _id)
{
    setId(_id);
    setName(_name);
}

/* ***************************************************************** */

// Init Constructor with filled list
continent::continent(string _name, uint8_t _id, vector<country> _list)
{
    setId(_id);
    setName(_name);
    list = _list;
}

/* ***************************************************************** */

// geter and seter method
inline uint8_t continent::getId(void) const{   return id;  }
inline void continent::setId(const uint8_t newId){    id = newId;  }
inline string continent::getName (void) const{    return name; }
inline void continent::setName(const string newName){    name = newName;  }

/* ***************************************************************** */

void continent::display(void)
{
    cout<<"Continent: { ";
    cout<<"  name :"<< getName() <<","<<endl;
    cout<<"  id :"<< +getId() <<","<<endl;
    cout<<"  nb_countries :"<< list.size() <<","<<endl;
    cout<<"}"<<endl;
}

/* ***************************************************************** */

void continent::display_list(void)
{
    cout<<"Continent list : {";
    for (int i = 0; i < list.size(); i++)
    {
        list.at(i).display();
        cout<<","<<endl;
    }
    cout<<"}"<<endl;
}

/* ***************************************************************** */

void continent::display_list_country_name(void)
{
    cout<<"Continent list : { "<<endl;
    for (int i = 0; i < list.size(); i++)
    {
        list.at(i).display_name();
    }
    cout<<"}"<<endl;
}

/* ***************************************************************** */

country continent::pick(void)
{
    country a;
    if (list.empty() == false)
    {
        a = list.back();
        list.pop_back();
    }
    return a;
}

/* ***************************************************************** */

string continent::getRandomCountryName(void)
{
    // Initialiser le générateur aléatoire
    random_device rd;  // Générateur de seed
    mt19937 gen(rd()); // Générateur de nombres aléatoires Mersenne Twister

    // Distribution uniforme pour choisir un index dans la plage du vector
    uniform_int_distribution<> dis(0, list.size() - 1);

    // Sélectionner un élément aléatoire
    int random_index = dis(gen);
    return list.at(random_index).getName();
}

/* ***************************************************************** */

string continent::getRandomCapitalName(void)
{
    // Initialiser le générateur aléatoire
    random_device rd;  // Générateur de seed
    mt19937 gen(rd()); // Générateur de nombres aléatoires Mersenne Twister

    // Distribution uniforme pour choisir un index dans la plage du vector
    uniform_int_distribution<> dis(0, list.size() - 1);

    // Sélectionner un élément aléatoire
    int random_index = dis(gen);
    return list.at(random_index).getCapitalName();
}

