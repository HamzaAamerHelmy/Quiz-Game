#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel
{
    easy = 1,
    med = 2,
    hard = 3,
    mix = 4
};

enum enOpType
{
    add = 1,
    sub = 2,
    mul = 3,
    div = 4,
    mix = 5
};

void readNumberOfQuestions(int &numOfQuestions)
{
    cout << "Enter Number Of Questions: ";
    cin >> numOfQuestions;
}

enQuestionsLevel readQuestionsLevel(enQuestionsLevel questionsLevel)
{
    int userInput = 0;

    cout << "Enter Questions Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix : ";
    cin >> userInput;

    questionsLevel = (enQuestionsLevel)userInput;

    return questionsLevel;
}



int main()
{
    srand((unsigned)time(NULL));
    int numOfQuestions;

    
    readNumberOfQuestions(numOfQuestions);
    
    enQuestionsLevel questionsLevel = readQuestionsLevel(questionsLevel);

    cout << questionsLevel << endl;
    
    return 0;
}