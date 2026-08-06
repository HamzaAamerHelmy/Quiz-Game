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
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mix = 5
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

enOpType readOperationType(enOpType opType)
{
    int userInput = 0;

    cout << "Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix : ";
    cin >> userInput;

    opType = (enOpType)userInput;
    
    return opType;
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