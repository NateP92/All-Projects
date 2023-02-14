// (CS303) Assignment 2 - Nate Purcell - Due: 28 Feb 22

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    vector<int> a, b, result;

    //Load data into the vectors
    for (int i = 0; i < 100; i++)
    {
        a.push_back(i+1);
        b.push_back(i*1);
    }

    //compute dot product and place answer inside result vector
    for (int i = 0; i < 100; i++)
    {
        int ans;
        ans = a.at(i) * b.at(i);
        result.push_back(ans);
    }

    for (int i = 0; i < 100; i++)
    {
        cout << result.at(i) << endl;
    }
}

