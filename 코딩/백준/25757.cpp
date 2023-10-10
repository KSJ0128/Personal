#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> person;
    char game;
    int N;
    cin >> N >> game;
    person.resize(N);

    for(int i = 0; i < N; i++)
        cin >> person[i];
    
    sort(person.begin(), person.end());
    person.erase(unique(person.begin(), person.end()), person.end());
    
    if(game == 'Y')
        cout << person.size();
    else if(game == 'F')
        cout << person.size() / 2;
    else if(game == 'O')
        cout << person.size() / 3;
}