#include <iostream>
#include "clsString.h"
using namespace std;



int main()
{
    clsString str1 = clsString("       Sidi    Abdullah       ");
    clsString str2("Ibrahim Mohamed");

    //cout << str1.TrimAndNormalizeSpaces();

    vector <string> words = str1.Split();
    for (string word : words) {
        cout << word << " ";
    }


    //vector <string> v = { "sidi", "abdullah", "ibrahim" };
    //cout << clsString::joinVectorWords(v, "###") << endl;
}

