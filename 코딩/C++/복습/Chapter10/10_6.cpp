#include <iostream>
#include <string>
using namespace std;

int countLetters(const string& s)
{
    int count = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s.at(i) >= 'A' && s.at(i) <= 'Z')
            count++;
        else if(s.at(i) >= 'a' && s.at(i) <= 'z')
            count++;
    }
    return count;
}

int main()
{
    string s("");
    cout << "문자열을 입력해주세요: ";
    // string 띄어쓰기 포함해서 입력받을 때
    getline(cin, s); 

    // cin.getline(): char*, char[] 입력받을 때


    cout << "문자의 개수: " << countLetters(s);
}
