#include <iostream>
#include <cstdint>
#include "city.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    city Mtp = *new city(0,"Montpellier",300000);

    Mtp.display();

    return 0;
}
