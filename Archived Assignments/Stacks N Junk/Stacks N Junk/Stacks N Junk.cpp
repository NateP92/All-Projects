#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    //Var or Data Structure Declarations
    stack<int> myStack;
    int numToInsert = 15;
    vector<int> savedNums;

    //Load 5 ints into the stack
    for (int i = 1; i < 6; i++)
    {
        myStack.push(i);
    }

    //Determine size of stack
    int numPops = myStack.size();
    if (numPops % 2 == 1)                       //if the stack has an odd number of items, use this
    {
        numPops = numPops - (numPops / 2);
        for (int i = 0; i < numPops; i++)
        {
            savedNums.push_back(myStack.top());
            myStack.pop();
        }
        myStack.push(numToInsert);
        for (int i = 0; i < numPops; i++)
        {
            int temp = savedNums.back();
            myStack.push(temp);
            savedNums.pop_back();
        }
    }
    else {                                      //if the stack has an even number of items, use this
        numPops = numPops / 2;
        for (int i = 0; i < numPops; i++)
        {
            savedNums.push_back(myStack.top());
            myStack.pop();
        }
        myStack.push(numToInsert);
        for (int i = 0; i < numPops; i++)
        {
            int temp = savedNums.back();
            myStack.push(temp);
            savedNums.pop_back();
        }
    }

    //Print Stack
    for (int i = 0; i < 5; i++)
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    return 0;
}
