#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> myList = {1, 2, 3};
    myList.remove(2);
    myList.sort();
    myList.sort(greater<int>());

    // make the sorted list with unique value and remove duplicate values
    myList.unique();


    myList.reverse();

    return 0;
}