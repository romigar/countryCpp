#include <iostream>
#include <cstdint>
#include "city.h"

using namespace std;

// constructor
city::city(uint8_t _id, string _name, uint32_t _population)
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
}

/* ***************************************************************** */

// Copy constructor
city::city(const city& other)
{
    setName(other.name);
    setPopulation(other.population);
    setId(other.id);
}

/* ***************************************************************** */

//default constructor
city::city(){ }

//default destructor
city::~city(){ }


/* ***************************************************************** */

uint8_t city::getId(void) const{   return id;  }
string city::getName(void) const{   return name;  }
uint32_t city::getPopulation(void) const{   return population;  }
void city::setPopulation(uint32_t newPopulation){   population = newPopulation;  }
void city::setName(string newName){   name = newName;  }
void city::setId(uint8_t newId){   id = newId;  }

/* ***************************************************************** */

void city::display(void)
{
    cout<<"City:{ "<<endl;
    cout<<"  name : "<< this->getName() <<","<<endl;
    cout<<"  population : "<< this->getPopulation() <<","<<endl;
    cout<<"  id : "<< +this->getId() <<endl;
    cout<<"}"<<endl;
}

/* ***************************************************************** */

void city::display_name(void)
{
    cout<<getName()<<endl;
}
