#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    Mix = 4
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