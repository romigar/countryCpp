#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
#include <cstdint>
#include <vector>
#include "country.h"

using namespace std;

class country;

class continent
{
protected:
public:
    vector<country> list;
    string name;
    uint8_t id;

    continent();
    continent(const continent&);
    continent(string _name, uint8_t _id);
    continent(string _name, uint8_t _id, vector<country> _list);

    uint8_t getId(void) const;
    void setId(const uint8_t newId);
    string getName(void) const;
    void setName(const string newName);

    void display(void);
    void display_list(void);
    void display_list_country_name(void);

    country pick(void);

    string getRandomCountryName(void);
    string getRandomCapitalName(void);


private:

};

#endif // CONTINENT_H
