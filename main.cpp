//------------------------------------------------------ Include personnel
#include <iostream>
#include "Ensemble.h"
using namespace std;

int main() 
{
    int t1[6] = {1,2,3,4};
    int t2[3] = {1,2,3};

    Ensemble em1( t1, 2 );
    Ensemble em2( t2, 3 );

    em1.Afficher( );
    cout << "\r\nem1 intersect em2\r\n";
    cout << em1.Intersection( em2 ) << "\r\n";
    em1.Afficher( );

    return 0;
}