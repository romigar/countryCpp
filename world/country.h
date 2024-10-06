#ifndef COUNTRY_H
#define COUNTRY_H

#include <cstdint>
#include <string>
#include "city.h"

using namespace std;

class city;

class country
{
protected:
    string name;
    uint8_t id;
    uint32_t population;
    string continent;
    uint8_t continentId;
    city* capital;
public:
    country();
    country(const country&);
    country(uint8_t _id, string _name, uint32_t _population,
                     string _continent, city capital);
    country(uint8_t _id, string _name, string _continent, string _capital);
    ~country();

    uint8_t getId(void) const;
    void setId(const uint8_t newId);
    string getName(void) const;
    void setName(const string newName);
    uint32_t getPopulation(void) const;
    void setPopulation(const uint32_t newPopulation);
    string getContinent(void) const;
    void setContinent(const string newContinent);
    uint8_t getContinentId(void) const;
    void setContinentId(const uint8_t newContinentId);

    string getCapitalName(void) const;

    void display(void);
    void display_name(void);

};


#endif // COUNTRY_H
