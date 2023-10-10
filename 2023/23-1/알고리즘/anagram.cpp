#include <iostream>
#include <string>
using namespace std;

bool isAnagram(const string& s1, const string& s2)
{
    string s3 = s1;
    string s4 = s2;

    int len1 = s3.length();
    int len2 = s4.length();
    if (len1 == len2) 
    {
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (s3[i] == s4[j])
                {
                    s4[j] = '0';
                    break;
                }
            }
           
        }

        for (int i = 0; s4[i] != '0'; i++) {
            if (s4[i] != '0') {
                return  0;
                break;
            }
        }
        return 1;
    }
    else
        return 0;
}

int main() 
{
	string new1;
	string new2;

	cout << "Enter a string s1: ";
	cin >> new1;
	cout << "Enter a string s2: ";
	cin >> new2;

	if (isAnagram(new1,new2))
		cout << new1 << " and " << new2 << " are anagrams";
    
    else
        cout << new1 << " and " << new2 << " are not anagrams";


	return 0;

}