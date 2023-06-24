#include <bits/stdc++.h>
using namespace std;



int main()
{

    list<int>myList(0, 4);
    list<int>myList_2{1, 2, 3, 4 ,5 };
    list<int>myList_3(myList_2);

    // for(auto it = myList_3.begin(); it != myList_3.end(); it++){
    //     cout<<*it<<endl;
    // }
   
    for(int v: myList_3){
        cout<<v<<endl;
    }
   

    return 0;
}