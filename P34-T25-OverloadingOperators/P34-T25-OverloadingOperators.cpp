#include "Date.h"

int main()
{
    Date d1; //12-09-2024
    Date d2(2000, 1, 1);
    Date d3(2024, 2, 29);
    cout << d1 << " " << d2 << " " << d3 << endl << endl;

    d2--; 
    --d2;     //d2.prevDate();
    d3++;     //d3.nextDate();
    cout << d1 << " " << d2 << " " << d3 << endl << endl;
    cout << "=====================================\n\n";

    cout << d2 << " == " << d3 << (d2 == d3 ? " true" : " false") << endl;
    cout << d2 << " != " << d3 << (d2 != d3 ? " true" : " false") << endl;
    cout << d2 << " > " << d3 << (d2 > d3 ? " true" : " false") << endl;
    cout << d2 << " < " << d3 << (d2 <  d3 ? " true" : " false") << endl;
    cout << d2 << " >= " << d3 << (d2 >=  d3 ? " true" : " false") << endl;
    cout << d2 << " <= " << d3 << (d2 <=  d3 ? " true" : " false") << endl;
    cout << "=====================================\n\n";

    cout << d3 << " + 65 days  = ";
    d3 += 65;
    cout << d3 << endl;

    cout << d3 << " + 5 years  = ";
    d3 += 5.0; //5.0f => float,  5l => long    
    cout << d3 << endl;



    cout << d2 << " - 34 days  = ";
    d2 -= 34;
    cout << d2 << endl;

    cout << d2 << " - 7 years  = ";
    d2 -= 7.0; //5.0f => float,  5l => long    
    cout << d2 << endl;
    cout << "=====================================\n\n";


    cout << d2 + 5 << " == " << 5 + d2 << endl; // add days
    cout << d2 - 5 << " == " << 5 - d2 << endl;

    cout << d3 + 5.0 << " == " << 5.0 + d3 << endl; // add years
    cout << d3 - 5.0 << " == " << 5.0 - d3 << endl;

}
