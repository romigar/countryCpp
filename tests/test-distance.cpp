#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <list>

#define DEBUG_TRACES    0

using namespace std;

static uint32_t distanceDamerauLevenshtein(const char* str1,const int size1,const char* str2,const int size2)
{
#if DEBUG_TRACES
    cout<< "size1 : " << size1 << endl;
    cout<< "size2 : " << size2 << endl;
#endif
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int d[size1+1][size2+1];
#if DEBUG_TRACES
    cout<<"_ | _ ";
    for (i = 0; i < size1 ; i++) {
        cout<<str1[i]<<" ";
    }
    cout<<" |"<<endl;
    cout<<"_ | ";
#endif

    i=0;

    for (i = 0; i <= size1 ; i++) {
        d[i][0] = i;
#if DEBUG_TRACES
        cout<<d[i][j]<<" ";
#endif
    }
#if DEBUG_TRACES
    cout<<" |"<<endl;
#endif

    for (j = 0; j <= size2 ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j <= size2 ; j++)
    {
#if DEBUG_TRACES
        cout<<str2[j-1]<<" | ";
        cout<<d[0][j]<<" ";
#endif
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
#if DEBUG_TRACES
            cout<<d[i][j]<<" ";
#endif
        }
#if DEBUG_TRACES
        cout<<" |"<<endl;
#endif
    }
#if DEBUG_TRACES
    cout<<d[size1][size2]<<endl;
#endif
    return d[size1][size2];
}



bool result(const string word1, const string word2)
{
    cout<< word1 << "|" << word2 << endl;

    float tolerance = 0.3;
    float result;
    int distance = distanceDamerauLevenshtein(word1.data(),word1.size(),word2.data(),word2.size());
    result = (float)distance/(min(word1.length(),word2.length()));

    if (result >= tolerance)
    {
        cout<< "refused " << result << endl;
    }
    else
    {
        cout<< "accepted " << result << endl;
    }
    return (result < tolerance);
}

ostream &operator<<(ostream &os, const list<string> &list)
{
    for (auto const &i: list) {
        os << i << endl;
    }
    return os;
}

template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int myrandom (int i) { return rand()%i;}


int main(int argc, char *argv[])
{
    cout<< "start"<<endl;

    string str1 = "salutations";
    string str2 = "salutatoins";
    string str3 = "salutatoin";
    string str4 = "salutatain";
    string str5 = "salut";

    result(str1,str1);
    result(str1,str2);
    result(str1,str3);
    result(str1,str4);
    result(str1,str5);

    return 0;
}

