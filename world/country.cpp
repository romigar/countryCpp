#include <iostream>
#include <cstdint>
#include "country.h"
#include "city.h"

using namespace std;

country::country()
{
}

/* ***************************************************************** */

country::country(const country& other)
    : capital(new city(*other.capital))
{
    setId(other.id);
    setName(other.name);
    setPopulation(other.population);
    setContinent(other.continent);
}

/* ***************************************************************** */

country::country(uint8_t _id, string _name, uint32_t _population,
                 string _continent, city capital)
    : capital(new city(capital))
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
    setContinent(_continent);
}

/* ***************************************************************** */

country::country(uint8_t _id, string _name, string _continent, string _capital)
    : capital(new city(_id,_capital,0))
{
    setId(_id);
    setName(_name);
    setPopulation(0);
    setContinent(_continent);
}

/* ***************************************************************** */

country::~country()
{
}

/* ***************************************************************** */

uint8_t country::getId(void) const{   return id;  }
void country::setId(const uint8_t newId){    id = newId;  }
string country::getName(void) const{    return name; }
void country::setName(const string newName){    name = newName;  }
uint32_t country::getPopulation(void) const{  return population;  }
void country::setPopulation(const uint32_t newPopulation){    population = newPopulation; }
string country::getContinent(void) const{    return continent;   }
void country::setContinent(const string newContinent){   continent = newContinent;   }
uint8_t country::getContinentId(void) const{    return continentId;   }
void country::setContinentId(const uint8_t newContinentId){   continentId = newContinentId;   }
string country::getCapitalName(void) const{ return capital->getName(); };

/* ***************************************************************** */

void country::display(void)
{
    cout<<"Country:{ ";
    cout<<"  name : "<< getName() <<","<<endl;
    cout<<"  population : "<< getPopulation() <<","<<endl;
    cout<<"  id : "<< +getId() <<","<<endl;
    cout<<"  continent : "<< getContinent() <<","<<endl;
    cout<<"  continentId : "<< +getContinentId() <<","<<endl;
    cout<<"  capital : ";
    this->capital->display();
    cout<<"}"<<endl;
}

/* ***************************************************************** */

void country::display_name(void)
{
    cout<<getName()<<endl;
}
