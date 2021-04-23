#pragma once
#include <string>
#include <iostream>
using namespace std;
class SubstitutionModule
{
private:
    int key;
public:
    SubstitutionModule() = delete;
    SubstitutionModule(int k);
    wstring Encode(SubstitutionModule key, wstring &data);
    wstring Decode(SubstitutionModule key, wstring &data);
};