#include "SubstitutionModule.h"
//#include <locale>
#include <string>
int main()
{
    bool op = true;
	wstring str, mode, key;
    wcout << L"This is Substitution Cipher program! Created by Kirill Koltunov 20PT1." << endl;
    wcout << L"Type \"Encode\" to create a ciphered text or \"Decode\" to get original text from Encoded one. Type \"exit\" to stop it." << endl;
    do {
//        locale loc("ru_RU.UTF-8");
//        locale::global(loc); // If we will use Russian lang.
        wcout << L"Select program mode:";
        wcin >> mode;
        if (mode == L"Encode") {
            wcout << L"Input text to Encode:";
            wcin.get();
            getline(wcin, str);

            wcout << L"Input cipher key:";
            wcin >> key;
			int ckey = std::stoi(key);

            SubstitutionModule Cipher(ckey);
           
			wcout << Cipher.Encode(Cipher,str) << endl;
        }
        if (mode == L"Decode") {
            wcout << L"Input text to Decode:";
            wcin.get();
            getline(wcin, str);

            wcout << L"Input cipher key:";
            wcin >> key;
			int ckey = std::stoi(key);

            SubstitutionModule Cipher(ckey);
           
			wcout << Cipher.Decode(Cipher,str) << endl;
        }
        if (mode == L"exit") {
            wcout << "The program has terminated." << endl;
            op = false;
            break;
        }

    } while (op != false);
    return 0;
}