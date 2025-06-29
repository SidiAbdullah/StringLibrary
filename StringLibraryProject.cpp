#include <iostream>
#include "clsString.h"
using namespace std;



int main()
{
    clsString str;
    str.setValue("Sidi Abdullah Mohamed");
    clsString str1("Ibrahim Abdullah");

    cout << "string1 = " << str.getValue() << endl;
    cout << "string2 = " << str1.getValue() << endl;

    vector <string> v = { "sidi", "abdullah", "ibrahim" };
    cout << clsString::joinVectorWords(v, "###") << endl;
}

