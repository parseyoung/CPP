﻿// std::string 과 std::wsting
#include <string>
#include <cstddef>
#include <iostream>
#include <locale>
using std::wcout;
using std::endl;

int main()
{
    {
        const std::wstring texts[] =
        {
          L"안녕하세요", //Korean
          L"Ñá", //Spanish
          L"forêt intérêt", //French
          L"Gesäß", //German
          L"取消波蘇日奇諾", //Chinese
          L"日本人のビット", //Japanese
          L"немного русский", //Russian
          L"ένα κομμάτι της ελληνικής", // Greek
          L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
          L"کمی از ایران ", // Persian (I know it, from 300 movie)
          L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
          L"Но какво, по дяволите, е това?" //Bulgarian
        };

        std::locale::global(std::locale(""));
        std::wcout.imbue(std::locale());

        for (size_t i = 0; i < 11; ++i)
            std::wcout << texts[i] << std::endl;
    }

    return 0;
}


// c-style string example
    /*{
        char* strHello = new char[7];
        strcpy_s(strHello, sizeof(char) * 7, "hello!");
        std::cout << strHello << std::endl;
    }*/

    // basic_string<>, string, wstring
//{
//    std::string string;
//    std::wstring wstrng;
//
//    wchar_t wc; // wide chariter/unicode
//}
