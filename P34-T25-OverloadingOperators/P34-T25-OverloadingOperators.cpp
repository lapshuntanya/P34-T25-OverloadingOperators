#include "Date.h"

int main()
{
    Date d1; //12-09-2024
    Date d2(2000, 1, 1);
    Date d3(2024, 2, 29);
    cout << d1 << " " << d2 << " " << d3 << endl << endl;

    d2--;     //d2.prevDate();
    d3++;     //d3.nextDate();
    cout << d1 << " " << d2 << " " << d3 << endl << endl;

}
