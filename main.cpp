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

struct stQuestionInfo
{
    int firstNumber = 0;
    enOpType opType;
    int secondNumber = 0;
    enQuestionsLevel questionsLevel;
    int numberOfThisRound
};


void readNumberOfQuestions(int &numOfQuestions)
{
    cout << "Enter Number Of Questions: ";
    cin >> numOfQuestions;
}

enQuestionsLevel readQuestionsLevel(enQuestionsLevel questionsLevel)
{
    int userInput = 0;

    do
    {
        cout << "Enter Questions Level [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix : ";
        cin >> userInput;
    
        if (userInput < 1 || userInput > 4)
        {
            cout << "\nWrong Input!" << endl;
            cout << "Please Enter a vaild Number!" << endl << endl;
            continue;
        }   
    
        questionsLevel = (enQuestionsLevel)userInput;
    } while (userInput < 1 || userInput > 4);
    

    return questionsLevel;
}

enOpType readOperationType(enOpType opType)
{
    int userInput = 0;

    
    do
    {
        cout << "Enter Operation Type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix : ";
        cin >> userInput;

        if (userInput < 1 || userInput > 5)
        {
            cout << "\nWrong Input!" << endl;
            cout << "Please Enter a vaild Number!" << endl << endl;
            continue;
        }
        
        opType = (enOpType)userInput;
    } while (userInput < 1 || userInput > 5);
    

    
    return opType;
}

int main()
{
    srand((unsigned)time(NULL));
    int numOfQuestions;

    
    readNumberOfQuestions(numOfQuestions);

    cout << numOfQuestions << endl;
    
    enQuestionsLevel questionsLevel = readQuestionsLevel(questionsLevel);

    cout << questionsLevel << endl;

    enOpType opType = readOperationType(opType);

    cout << opType << endl;
    
    return 0;
}