#include <bits/stdc++.h>
using namespace std;
int main()
{

    list<int> myList = {1, 2, 3};
    list<int> newList;

    newList = myList;

    newList.push_back(5);
    newList.push_front(10);

    for (int v : newList)
    {
        cout << v << " ";
    }
    cout << endl;

    newList.pop_back();
    newList.pop_front();

    for (int v : newList)
    {
        cout << v << " ";
    }
    cout << endl;

    newList.insert(next(newList.begin(), 3), 100);
    newList.insert(next(newList.begin(), 4), {3, 4, 9});

    for (int v : newList)
    {
        cout << v << " ";
    }

    cout << endl;

    newList.erase(next(newList.begin(), 4));

    for (int v : newList)
    {
        cout << v << " ";
    }
    cout << endl;

    replace(newList.begin(), newList.end(), 3, 300);

    for (int v : newList)
    {
        cout << v << " ";
    }
    cout << endl;

    auto it = find(myList.begin(), myList.end(), 40);

    bool found = it == myList.end() ? true : false;

    return 0;
}