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
    vector<country> list;
    string name;
    uint8_t id;
public:
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

private:

};

#endif // CONTINENT_H
