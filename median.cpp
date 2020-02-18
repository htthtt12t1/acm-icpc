#include<bits/stdc++.h>

using namespace std;
multiset<int> maxs, mins;

int answer()
{
    if (maxs.empty() && mins.empty()) return -1;
    if (maxs.size() == mins.size()){
        int temp = *maxs.begin() + *mins.rbegin();
        return temp/2;
    } else 
        cout << *mins.rbegin() << "\n";
}
void fixed_array()
{
    if (maxs.size() > mins.size()) {
        mins.insert(*maxs.begin());
        maxs.erase(maxs.begin());
    }
    if (mins.size() > maxs.size() + 1) {
        maxs.insert(*mins.rbegin());
        mins.erase(mins.find(*mins.rbegin()));
    }
}

int main()
{
    int queries, number;

    cin >> queries;
    while (queries--){
      cin >> number;
      if (mins.empty()) mins.insert(number); 
      else
            if (number > *mins.rbegin()) maxs.insert(number);
      else 
          mins.insert(number);
      fixed_array();
      cout << anwser();
    }       
}