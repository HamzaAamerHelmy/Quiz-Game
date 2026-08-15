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
    int answer = 0;
    char operation;
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

enQuestionsLevel readQuestionsLevel()
{
    enQuestionsLevel questionsLevel;
    int userInput = 0;

    do
    {
        cout << "\nSelect Questions Level:" << endl;
        cout << "    [1]:Easy\n    [2]:Med\n    [3]:Hard\n    [4]:Mix" << endl;
        cout << "Enter Choose: ";
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

enOpType readOperationType()
{
    enOpType opType;
    int userInput = 0;

    
    do
    {
        cout << "\nSelect Operation Type:" << endl;
        cout << "   [1]:Add\n   [2]:Sub\n   [3]:Mul\n   [4]:Div\n   [5]:Mix" << endl;
        cout << "Enter Choose: ";
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

stQuestionInfo checkDifficulty(enQuestionsLevel questionsLevel, stQuestionInfo questionInfo)
{
    switch (questionsLevel)
    {
    case enQuestionsLevel::easy:
        questionInfo.firstNumber = randomNumber(1, 11);
        questionInfo.secondNumber = randomNumber(1, 11);
        break;
    case enQuestionsLevel::med:
        questionInfo.firstNumber = randomNumber(10, 51);
        questionInfo.secondNumber = randomNumber(10, 51);
        break;
    case enQuestionsLevel::hard:
        questionInfo.firstNumber = randomNumber(50, 101);
        questionInfo.secondNumber = randomNumber(50, 101);
        break;
    }
    return questionInfo;
}

char checkOpType(enOpType opType)
{
    char operation;
    switch (opType)
    {
    case enOpType::Add:
        operation = '+';
        break;
    case enOpType::Sub:
        operation = '-';
        break;
    case enOpType::Mul:
        operation = 'x';
        break;
    case enOpType::Div:
        operation = '/';
        break;
    }

    return operation;
}

stQuestionInfo readQuestion(stQuestionInfo questionInfo, int numOfQuestions)
{
    enOpType opType;
    enQuestionsLevel questionsLevel;
    if (questionInfo.opType == enOpType::Mix)
    {
        opType = randomOpType(enOpType::Add, enOpType::Mix);
    }
    questionInfo.operation = checkOpType(opType);

    if (questionInfo.questionsLevel == enQuestionsLevel::mix)
    {
        questionsLevel = randomQuestionsLevel(enQuestionsLevel::easy, enQuestionsLevel::mix);
    }
    questionInfo = checkDifficulty(questionsLevel, questionInfo);

    cout << "\nQuestion [" << questionInfo.numberOfThisRound << "/" << numOfQuestions << "]" << endl;
    cout << questionInfo.firstNumber << endl;
    cout << questionInfo.secondNumber << " " << questionInfo.operation << endl;
    cout << "----------------" << endl;
    cin >> questionInfo.answer;

    return questionInfo;
}

int getAnswerOfQuestion(stQuestionInfo questionInfo)
{
    int answer = 0;
    switch (questionInfo.operation)
    {
    case '+':
        answer = questionInfo.firstNumber + questionInfo.secondNumber;
        break;
    case '-':
        answer = questionInfo.firstNumber - questionInfo.secondNumber;
        break;
    case 'x':
        answer = questionInfo.firstNumber * questionInfo.secondNumber;
        break;
    case '/':
        answer = questionInfo.firstNumber / questionInfo.secondNumber;
        break;
    }

    return answer;
}

bool checkAnswer(int answer, stQuestionInfo questionInfo)
{
    if (answer == getAnswerOfQuestion(questionInfo))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printCheckAnswer(stQuestionInfo questionInfo)
{
    if (checkAnswer(questionInfo.answer, questionInfo))
    {
        cout << "Right Answer :)" << endl;
        system("color 2F");
    }
    else
    {
        cout << "Wrong Answer :(" << endl;
        cout << "The Right Answer is: " << getAnswerOfQuestion(questionInfo) << endl;

        system("color 4F");
    }
}

void readAndPrintMultipleQuestions(stQuestionInfo questionInfo, int numOfQuestions)
{
    for (int i = 1; i <= numOfQuestions; i++)
    {
        questionInfo.numberOfThisRound = i;
        
        questionInfo = readQuestion(questionInfo, numOfQuestions);
        
        printCheckAnswer(questionInfo);
    }
}

int main()
{
    system("color 0F");
    srand((unsigned)time(NULL));
    int numOfQuestions;

    stQuestionInfo questionInfo;
    
    readNumberOfQuestions(numOfQuestions);
    
    questionInfo.questionsLevel = readQuestionsLevel();

    questionInfo.opType = readOperationType();

    readAndPrintMultipleQuestions(questionInfo, numOfQuestions);     
    
    return 0;
}