#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>

using namespace std;

/* ***************************************************************** */

static uint32_t distanceDamerauLevenshtein(const char* str1,const int size1,const char* str2,const int size2)
{
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int d[size1+1][size2+1];

    i=0;

    for (i = 0; i <= size1 ; i++) {
        d[i][0] = i;
    }

    for (j = 0; j <= size2 ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j <= size2 ; j++)
    {
        for (i = 1; i <= size1 ; i++)
        {
            if (str1[i-1] == str2[j-1]){
                coutSubstitution = 0;
            }
            else {
                coutSubstitution = 1;
            }

            d[i][j] = min( d[i-1][j] + 1 ,
                          min( d[i][j-1] + 1 ,
                              d[i-1][j-1] + coutSubstitution ));


            // transposition
            if ( (i > 1 && j > 1)
                && (str1[i-1] == str2[j-2])
                && (str1[i-2] == str2[j-1]) ) {
                d[i][j] = min( d[i][j] , d[i-2][j-2] + coutSubstitution);
            }
        }
    }
    return d[size1][size2];
}

/* ***************************************************************** */

static double relativeDistance(string reference, string candidat)
{

    cout<< "distance :\t\t" << (double)distanceDamerauLevenshtein(reference.data(),reference.size(),candidat.data(),candidat.size())<<endl;
    cout<< "distance relative :\t" << (double)distanceDamerauLevenshtein(reference.data(),reference.size(),candidat.data(),candidat.size())/(double)reference.size()<<endl;

    return (double)distanceDamerauLevenshtein(reference.data(),reference.size(),candidat.data(),candidat.size())/(double)reference.size();
}

/* ***************************************************************** */

bool validDistance(string reference, string candidat, double tolerance)
{
    return (relativeDistance(reference,candidat) <= tolerance);
}

