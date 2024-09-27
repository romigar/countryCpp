#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>

#include "country.h"
#include "continent.h"
#include "world.h"

using namespace std;

int read_file(vector<country> *countrylist)
{
    ifstream file("/home/theo/workspace/countryCpp/ressources/liste.csv");
    string line;
    string _country;
    string _capital;
    string _continent;
    uint i = 0 ;

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

        countrylist->push_back(*new country(i,_country,_continent,_capital));
        //countrylist->back().display();
        i++;
    }

    file.close();
    cout<<  "Init list finished. Size : " << countrylist->size() <<endl;
    return 0;
}


int main(int argc, char *argv[])
{
    cout<< "start test liste"<<endl;

    world *newWorld = new world();

    newWorld->display();

    delete(newWorld);

    return 0;
}

