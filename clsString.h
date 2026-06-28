#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:

    string _stringValue;

    // Helper Functions

    static char ToggleCharacterCase(char Character)
    {
        if (int(Character) >= 97 && int(Character) <= 122)
        {
            return char(int(Character) - 32);
        }
        else if (int(Character) >= 65 && int(Character) <= 90)
        {
            return char(int(Character) + 32);
        }

        return Character;
    }

    static char ToLowerCharacter(char Character)
    {
        if (int(Character) >= 65 && int(Character) <= 90)
        {
            return char(int(Character) + 32);
        }

        return Character;
    }

    static char ToUpperCharacter(char Character)
    {
        if (int(Character) >= 97 && int(Character) <= 122)
        {
            return char(int(Character) - 32);
        }

        return Character;
    }

    static bool IsVowel(char Character)
    {
        Character = ToLowerCharacter(Character);

        return (
            Character == 'a' ||
            Character == 'e' ||
            Character == 'i' ||
            Character == 'o' ||
            Character == 'u'
            );
    }

    static bool IsPunctuation(char c) {
        int x = (unsigned char)c;
        return (x >= 33 && x <= 47) ||
            (x >= 58 && x <= 64) ||
            (x >= 91 && x <= 96) ||
            (x >= 123 && x <= 126);
    }

public:

    // Constructors

    clsString()
    {
        _stringValue = "";
    }

    clsString(string Text)
    {
        _stringValue = Text;
    }

    // Setter / Getter

    void SetValue(string Text)
    {
        _stringValue = Text;
    }

    string GetValue()
    {
        return _stringValue;
    }

    // =========== (2) Read ===========

    static void PrintVowels(string Text)
    {
        for (char& Character : Text)
        {
            if (IsVowel(Character))
            {
                cout << "   " << Character;
            }
        }
    }

    void PrintVowels()
    {
        PrintVowels(_stringValue);
    }

    static void PrintFirstLetterOfEachWord(string Text)
    {
        Text = TrimAndNormalizeSpaces(Text);

        if (!Text.empty())
            cout << Text[0] << '\n';

        for (int Index = 1; Index < Text.length() - 1; ++Index)
        {
            if (Text[Index] == ' ')
            {
                cout << Text[Index + 1] << '\n';
            }
        }
    }

    void PrintFirstLetterOfEachWord()
    {
        PrintFirstLetterOfEachWord(_stringValue);
    }

    static void PrintWords(string Text)
    {
        Text = TrimAndNormalizeSpaces(Text);

        for (short Index = 0; Index < Text.length(); Index++)
        {
            if (Text[Index] != ' ')
            {
                cout << Text[Index];
            }
            else
            {
                cout << endl;
            }
        }
    }

    void PrintWords()
    {
        PrintWords(_stringValue);
    }

    // =========== (3) Update ===========

    // === Trimming Functions ====

    static string TrimAndNormalizeSpaces(string Text)
    {
        for (int Index = 0; Index < Text.length() - 1;)
        {
            if (Text[Index] == ' ' && Text[Index + 1] == ' ')
                Text.erase(Index, 1);
            else
                Index++;
        }

        if (!Text.empty() && Text.front() == ' ')
            Text.erase(0, 1);

        if (!Text.empty() && Text.back() == ' ')
            Text.pop_back();

        return Text;
    }

    string TrimAndNormalizeSpaces()
    {
        TrimAndNormalizeSpaces(_stringValue);
    }

    static string TrimLeft(string Text)
    {
        while (!Text.empty() && Text.front() == ' ')
        {
            Text.erase(0, 1);
        }

        return Text;
    }

    string TrimLeft()
    {
        TrimLeft(_stringValue);
    }

    static string TrimRight(string Text)
    {
        while (!Text.empty() && Text.back() == ' ')
        {
            Text.pop_back();
        }

        return Text;
    }

    string TrimRight()
    {
        TrimRight(_stringValue);
    }
    
    // === Conversion Functions ===

    static string ConvertToUpperCase(string Text)
    {
        for (int Index = 0; Index < Text.length(); Index++)
        {
            if (int(Text[Index]) >= 97 && int(Text[Index]) <= 122)
            {
                Text[Index] = char(int(Text[Index]) - 32);
            }
        }

        return Text;
    }

    string ConvertToUpperCase()
    {
        return ConvertToUpperCase(_stringValue);
    }

    static string ConvertToLowerCase(string Text)
    {
        for (char& Character : Text)
        {
            if (int(Character) >= 65 && int(Character) <= 90)
            {
                Character = char(int(Character) + 32);
            }
        }

        return Text;
    }

    string ConvertToLowerCase()
    {
        return ConvertToLowerCase(_stringValue);
    }

    // === Split / Join Functions ===

    static vector<string> Split(
        string Text,
        char Separator = ' ')
    {
        Text = TrimAndNormalizeSpaces(Text);

        Text += Separator;

        string CurrentWord;
        vector<string> Words;

        for (char& Character : Text)
        {
            if (Character != Separator)
            {
                CurrentWord += Character;
            }
            else if (CurrentWord != "")
            {
                Words.push_back(CurrentWord);
                CurrentWord = "";
            }
        }

        return Words;
    }

    vector<string> Split(char Separator = ' ')
    {
        return Split(_stringValue, Separator);
    }

    static string JoinStrings(
        vector<string>& Words,
        string Separator)
    {
        string Result;

        for (string& Word : Words)
        {
            if (Word != Words.back())
            {
                Result += Word + Separator;
            }
            else
            {
                Result += Word;
            }
        }

        return Result;
    }

    // === Replace Functions ===

    static string InvertCharacterCases(string Text)
    {
        for (char& Character : Text)
        {
            Character = ToggleCharacterCase(Character);
        }

        return Text;
    }

    string InvertCharacterCases() {
        return InvertCharacterCases(_stringValue);
    }

    string ReplaceWord(
        string Text,
        string OldWord,
        string NewWord,
        bool CaseSensitive = true)
    {
        vector<string> Words = Split(Text, ' ');

        for (string& Word : Words)
        {
            if (CaseSensitive)
            {
                if (Word == OldWord)
                {
                    Word = NewWord;
                }
            }
            else
            {
                if (
                    ConvertToLowerCase(Word) ==
                    ConvertToLowerCase(OldWord)
                    )
                {
                    Word = NewWord;
                }
            }
        }

        return JoinStrings(Words, " ");
    }

    // =========== (4) Delete ===========

    // === remove all punctuations ===
    static string RemoveAllPunctuations(string Text) {

        string NoPunctuations = "";

        for (char ch : Text) {
            if (!IsPunctuation(ch)) {
                NoPunctuations += ch;
            }
        }

        return NoPunctuations;
    }
    
    // ==== (?) Computation Functions ===

    static short CountWords(string Text)
    {
        Text = TrimAndNormalizeSpaces(Text);

        short WordCount = 0;

        for (char& Character : Text)
        {
            if (Character == ' ')
            {
                ++WordCount;
            }
        }

        return WordCount + 1;
    }

    short CountWords()
    {
        return CountWords(_stringValue);
    }

    static short CountLowercaseLetters(string Text)
    {
        short LowercaseCount = 0;

        for (char& Character : Text)
        {
            if (int(Character) >= 97 && int(Character) <= 122)
            {
                ++LowercaseCount;
            }
        }

        return LowercaseCount;
    }

    short CountLowercaseLetters()
    {
        return CountLowercaseLetters(_stringValue);
    }

    static short CountUppercaseLetters(string Text)
    {
        short UppercaseCount = 0;

        for (char& Character : Text)
        {
            if (int(Character) >= 65 && int(Character) <= 90)
            {
                ++UppercaseCount;
            }
        }

        return UppercaseCount;
    }

    short CountUppercaseLetters()
    {
        return CountUppercaseLetters(_stringValue);
    }

    static int CountCharacter(
        string Text,
        char Character,
        bool ExactMatch = true)
    {
        short CharacterCount = 0;

        if (!ExactMatch)
        {
            Text = ConvertToLowerCase(Text);
            for (char& CurrentCharacter : Text)
            {
                if (CurrentCharacter == Character)
                {
                    ++CharacterCount;
                }
            }
        }
        else
        {
            for (char& CurrentCharacter : Text)
            {
                if (CurrentCharacter == Character)
                {
                    ++CharacterCount;
                }
            }
        }

        return CharacterCount;
    }

    short CountCharacter(
        char Character,
        bool ExactMatch = true)
    {
        return CountCharacter(
            _stringValue,
            Character,
            ExactMatch);
    }

    static short CountVowels(string Text)
    {
        short VowelCount = 0;

        for (char& Character : Text)
        {
            if (IsVowel(Character))
            {
                ++VowelCount;
            }
        }

        return VowelCount;
    }

    short CountVowels()
    {
        return CountVowels(_stringValue);
    }

};
