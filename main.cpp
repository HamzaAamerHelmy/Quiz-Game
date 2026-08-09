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
    int numberOfThisRound = 0;
};

int randomNumber(int from, int to)
{
    int randNumber = rand() % (to - from) + from;

    return randNumber;
}

enOpType randomOpType(int from, int to)
{
    int randOpType = rand() % (to - from) + from;

    return (enOpType)randOpType;
}

enQuestionsLevel randomQuestionsLevel(int from, int to)
{
    int randQuestionsLevel = rand() % (to - from) + from;

    return (enQuestionsLevel)randQuestionsLevel;
}

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

void checkDifficulty(enQuestionsLevel questionsLevel, int random)
{
    if (questionsLevel == enQuestionsLevel::easy)
    {
        random = randomNumber(1, 11);
    }
    else if (questionsLevel == enQuestionsLevel::med)
    {
        random = randomNumber(10, 51);
    }
    else if (questionsLevel == enQuestionsLevel::hard)
    {
        random = randomNumber(50, 101);
    }
}

stQuestionInfo readRound(stQuestionInfo questionInfo, int numOfQuestions)
{
    int random = 0;
    if (readOperationType(questionInfo.opType) == enOpType::Mix)
    {
        questionInfo.opType = randomOpType(enOpType::Add, enOpType::Mix);
    }

    if (readQuestionsLevel(questionInfo.questionsLevel) == enQuestionsLevel::mix)
    {
        questionInfo.questionsLevel = randomQuestionsLevel(enQuestionsLevel::easy, enQuestionsLevel::mix);
        
        checkDifficulty(questionInfo.questionsLevel, random);
        
        questionInfo.firstNumber = random;
        questionInfo.secondNumber = random;
    }

    checkDifficulty(questionInfo.questionsLevel, random);

    questionInfo.firstNumber = random;
    questionInfo.secondNumber = random;
    
    cout << "Question [" << questionInfo.numberOfThisRound << "/" << numOfQuestions << "]" << endl << endl;
    cout << questionInfo.firstNumber << endl;
    cout << questionInfo.secondNumber << " " << questionInfo.opType << endl;
    
    return questionInfo;
}

int main()
{
    srand((unsigned)time(NULL));
    int numOfQuestions;

    stQuestionInfo questionInfo;
    
    readNumberOfQuestions(numOfQuestions);

    cout << numOfQuestions << endl;
    
    enQuestionsLevel questionsLevel = readQuestionsLevel(questionsLevel);

    cout << questionsLevel << endl;

    enOpType opType = readOperationType(questionInfo.opType);

    cout << opType << endl;

    questionInfo = readRound(questionInfo, numOfQuestions);
    
    return 0;
}