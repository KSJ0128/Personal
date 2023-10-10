#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string str1, string str2)
{
	if(str1.length() == str2.length())
	{
		if(str1.compare(str2) < 0)
			return true;
		else
			return false;
	}
	return str1.length() < str2.length();
}

int main()
{
    int N;
    vector<string> str;
    cin >> N;
    str.resize(N);

    for(int i = 0; i < N; i++)
        cin >> str[i];

	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end()); // 중복 요소 제거
	
	sort(str.begin(), str.end(), compare);
	for(int i = 0; i < str.size(); i++)
		cout << str[i] << '\n';
}