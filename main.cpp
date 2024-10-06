#include <iostream>
#include <cstdint>
#include "city.h"
#include "tools.h"

using namespace std;

int main()
{
    cout<< "start"<<endl;

    string str1 = "limas";
    string str2 = "lamis";
    string str3 = "malis";
    string str4 = "laims";
    string str5 = "liams";
    float tolerance = 0.3;

    validDistance(str1,str1,tolerance);
    validDistance(str1,str2,tolerance);
    validDistance(str1,str3,tolerance);
    validDistance(str1,str4,tolerance);
    validDistance(str1,str5,tolerance);

    return 0;
}
