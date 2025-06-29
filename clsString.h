#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString {

private:
    string _value;
    // used functions
    static char convertCharCase(char ch)
    {
        if (int(ch) >= 97 && int(ch) <= 122)
        {
            return char(int(ch) - 32);
        }
        else if (int(ch) >= 65 && int(ch) <= 90)
        {
            return char(int(ch) + 32);
        }
        return ch;
    }
    static char convertToLower(char ch) {
        if (int(ch) >= 65 && int(ch) <= 90)
        {
            return char(int(ch) + 32);
        }
        return ch;
    }
    static char convertToUper(char ch) {
        if (int(ch) >= 97 && int(ch) <= 122)
        {
            return char(int(ch) - 32);
        }
        return ch;
    }
    static bool isVowel(char ch)
    {
        ch = convertToLower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'u' || ch == 'i' || ch == 'o');
    }

public:
    clsString() {
        _value = "";
    }
    clsString(string s) {
        _value = s;
    }
    void setValue(string s) {
        _value = s;
    }
    string getValue() {
        return _value;
    }
    
    // 1. for static versions
    // triming (deleting white spaces ' ')
    static string cleanSpaces(string s)
    {
        for (int i = 0; i < s.length() - 1;)
        {
            if (s[i] == ' ' && s[i + 1] == ' ')
                s.erase(i, 1);
            else
                i++;
        }
        if (!s.empty() && s.front() == ' ')
            s.erase(0, 1);
        if (!s.empty() && s.back() == ' ')
            s.pop_back();
        return s;
    }
    static string trimLeft(string s)
    {
        while (!s.empty() && s.front() == ' ')
        {
            s.erase(0, 1);
        }
        return s;
    }
    static string trimRight(string s)
    {
        while (!s.empty() && s.back() == ' ')
        {
            s.pop_back();
        }
        return s;
    }
    
    // counting
    static short countWords(string s)
    {
        cleanSpaces(s);
        short counter = 0;
        for (char& ch : s)
        {
            if (ch == ' ')
            {
                ++counter;
            }
        }
        return counter + 1;
    }
    static short countSmallLetters(string str)
    {
        short SmallCounter = 0;
        for (char& ch : str)
        {
            if (int(ch) >= 97 && int(ch) <= 122)
            {
                ++SmallCounter;
            }
        }
        return SmallCounter;
    }
    static short countCapitalLetters(string str)
    {
        short capitalCounter = 0;
        for (char& ch : str)
        {
            if (int(ch) >= 65 && int(ch) <= 90)
            {
                ++capitalCounter;
            }
        }
        return capitalCounter;
    }
    static string convertCases(string str)
    {
        for (char &ch : str)
        {
            ch = convertCharCase(ch);
        }
        return str;
    }
    static int countLetter(string str, char letter, bool justTheMatches = true)
    {
        short counter = 0;
        if (!justTheMatches)
        {
            for (char& ch : str)
            {
                if (ch == letter or letter == convertCharCase(ch))
                {
                    ++counter;
                }
            }
        }
        else
        {
            for (char& ch : str)
            {
                if (ch == letter)
                {
                    ++counter;
                }
            }
        }
        return counter;
    }
    static short countVowels(string str)
    {
        short counter = 0;
        for (char& ch : str)
        {
            if (isVowel(ch))
            {
                ++counter;
            }
        }
        return counter;
    }
    
    // converting
    static string allToUpper(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (int(str[i]) >= 97 && int(str[i]) <= 122)
            {
                str[i] = char(int(str[i]) - 32);
            }
        }
        return str;
    }
    static string allToLower(string str)
    {
        for (char& ch : str)
        {
            if (int(ch) >= 65 && int(ch) <= 90)
            {
                ch = char(int(ch) + 32);
            }
        }
        return str;
    }
    
    // printing
    static void printVowels(string str)
    {
        for (char& ch : str)
        {
            if (isVowel(ch))
            {
                cout << "   " << ch;
            }
        }
    }
    static void printFirstLetters(string s)
    {
        cleanSpaces(s);
        if (!s.empty())
            cout << s[0] << '\n';
        for (int i = 1; i < s.length() - 1; ++i)
            if (s[i] == ' ')
                cout << s[i + 1] << '\n';
    }
    static void printWords(string str)
    {
        cleanSpaces(str);
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                cout << str[i];
            }
            else
            {
                cout << endl;
            }
        }
    }
    
    // spliting string words
    static  vector<string> vSplit(string s, char seperator)
    {
        cleanSpaces(s);
        s += seperator;
        string word;
        vector<string> v;
        for (char& ch : s)
        {
            if (ch != seperator)
            {
                word += ch;
            }
            else if (word != "")
            {
                v.push_back(word);
                word = "";
            }
        }
        return v;
    }
    
    // joining string words
    static string joinVectorWords(vector <string>& vStr, string seperator) {
        string newStr;
        for (string& str : vStr) {
            if (str != vStr.back()) {
                newStr += str + seperator;
            }
            else {
                newStr += str;
            }
        }
        return newStr;
    }



    // 2. for non static versions
    // counting
    short countWords() {
        return countWords(_value);
    }
    string convertCases()
    {
        return convertCases(_value);
    }
    short countSmallLetters()
    {
        return countSmallLetters(_value);
    }
    short countCapitalLetters()
    {
        return countCapitalLetters(_value);
    }
    short countLetter(char letter, bool justTheMatches = true)
    {
        return countLetter(_value, letter, justTheMatches);
    }
    short countVowels()
    {
        return countVowels(_value);
    }

    // converting
    string allToUpper()
    {
        return allToUpper(_value);
    }
    string allToLower()
    {
        return allToLower(_value);
    }
    
    // triming (deleting white spaces ' ')
    string cleanSpaces()
    {
        for (int i = 0; i < _value.length() - 1;)
        {
            if (_value[i] == ' ' && _value[i + 1] == ' ')
                _value.erase(i, 1);
            else
                i++;
        }
        if (!_value.empty() && _value.front() == ' ')
            _value.erase(0, 1);
        if (!_value.empty() && _value.back() == ' ')
            _value.pop_back();
        return _value;
    }
    string trimLeft()
    {
        while (!_value.empty() && _value.front() == ' ')
        {
            _value.erase(0, 1);
        }
        return _value;
    }
    string trimRight()
    {
        while (!_value.empty() && _value.back() == ' ')
        {
            _value.pop_back();
        }
        return _value;
    }

    // printing
    void printVowels()
    {
        printVowels(_value);
    }
    void printFirstLetters()
    {
        printFirstLetters(_value);
    }
    void printWords()
    {
        printWords(_value);
    }

    // spliting string words
    vector<string> vSplit(char seperator)
    {
        return vSplit(_value, seperator);
    }
};




