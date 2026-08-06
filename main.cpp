#include <iostream>
#include <cstdlib>
using namespace std;

void readNumberOfQuestions(int &numOfQuestions)
{
    cout << "Enter Number Of Questions: ";
    cin >> numOfQuestions;
}

int main()
{
    int numOfQuestions;

    readNumberOfQuestions(numOfQuestions);
    
    return 0;
}