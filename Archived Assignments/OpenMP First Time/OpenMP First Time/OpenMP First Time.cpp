#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main()
{
    vector<int> a, b, result;

    //Load data into the vectors
    for (int i = 0; i < 100; i++)
    {
        a.push_back(i + 1);
        b.push_back(i * 1);
    }

    //determine number of threads
    omp_set_num_threads(3);
#pragma omp parallel for 
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