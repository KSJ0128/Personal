#include <iostream>
#include <string>
using namespace std;

bool vowelCheck(char c)
{
    if(c == 'a' || c== 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else
        return false;
}

int main()
{
    string password;
    while(1)
    {
        bool pCheck = true, vowel = false;
        int threeVowel = 0, threeConso = 0;
        cin >> password;
        if(password == "end")
            break;
        
        for(int i = 0; i < password.length(); i++)
        {
            if(vowel == false && vowelCheck(password[i]))
                vowel = true;

            if(i != 0 && (password[i] == password[i-1]))
            {
                if(password[i] != 'e' && password[i] != 'o')
                {
                    pCheck = false;
                    break;
                }
            }

            if(threeVowel == 0 && threeConso == 0)
            {
                if(vowelCheck(password[i]))
                    threeVowel++;
                else
                    threeConso++;
            }
            else if(threeVowel != 0)
            {
                if(vowelCheck(password[i]))
                    threeVowel++;
                else
                {
                    threeVowel = 0;
                    threeConso = 1;
                }

                if(threeVowel == 3)
                {
                    pCheck = false;
                    break;
                }
            }
            else if(threeConso != 0)
            {
                if(!vowelCheck(password[i]))
                    threeConso++;
                else
                {
                    threeConso = 0;
                    threeVowel = 1;
                }

                if(threeConso == 3)
                {
                    pCheck = false;
                    break;
                }
            }
        }

        if(pCheck == false || vowel == false)
            cout << '<' << password << "> is not acceptable." << '\n';
        else
            cout << '<' << password << "> is acceptable." << '\n';
    }
}