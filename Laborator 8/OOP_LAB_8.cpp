#include <iostream>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
ifstream fin("text.txt");

struct compare {
    bool operator() (pair<string, int> const& p1, pair<string, int> const& p2)
    {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

int main()
{
    map<string, int> words;
    string str;
    char c;
    while (fin.get(c)) 
    {
        if (c == ' ' || c == ',' || c == '?' || c == '!' || c == '.') {
            if (!str.empty()) {
                words[str]++;
                str.clear();
            }
        }
        else {
            str += tolower(c);
        }
    }
    if (!str.empty()) {
        words[str]++;
    }

    priority_queue<pair<string,int>, vector<pair<string, int>>, compare> pq;
    map<string, int>::iterator it;

    for (it = words.begin(); it != words.end(); it++)
        pq.push(*it);

    while (!pq.empty()) {
        cout << pq.top().first << " => " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}