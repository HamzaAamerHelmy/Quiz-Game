#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

void resetScreen()
{
    system("color 0F");
    system("cls");
}

void mySleep(int duration)
{
    Sleep(duration);
}

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

int numOfRightAnswers = 0;
int numOfWrongAnswers = 0;

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
            cout << "Please Enter a vaild Number!" << endl
                 << endl;
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
            cout << "Please Enter a vaild Number!" << endl
                 << endl;
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

stQuestionInfo readQuestion(stQuestionInfo questionInfo, int numOfQuestions, enOpType opType, enQuestionsLevel questionsLevel)
{
    if (questionInfo.opType == enOpType::Mix)
    {
        opType = randomOpType(enOpType::Add, enOpType::Mix);
        questionInfo.operation = checkOpType(opType);
    }
    else
    {
        questionInfo.operation = checkOpType(questionInfo.opType);
    }

    if (questionInfo.questionsLevel == enQuestionsLevel::mix)
    {
        questionsLevel = randomQuestionsLevel(enQuestionsLevel::easy, enQuestionsLevel::mix);
        questionInfo = checkDifficulty(questionsLevel, questionInfo);
    }
    else
    {
        questionInfo = checkDifficulty(questionInfo.questionsLevel, questionInfo);
    }

    cout << "Question [" << questionInfo.numberOfThisRound << "/" << numOfQuestions << "]" << endl;
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
        numOfRightAnswers++;
    }
    else
    {
        cout << "\a";
        cout << "Wrong Answer :(" << endl;
        cout << "The Right Answer is: " << getAnswerOfQuestion(questionInfo) << endl;
        system("color 4F");
        numOfWrongAnswers++;
    }
}

void readAndPrintMultipleQuestions(stQuestionInfo questionInfo, int numOfQuestions)
{
    enOpType opType;
    enQuestionsLevel questionsLevel;
    for (int i = 1; i <= numOfQuestions; i++)
    {
        questionInfo.numberOfThisRound = i;

        cout << "\n==============================" << endl;

        questionInfo = readQuestion(questionInfo, numOfQuestions, opType, questionsLevel);

        printCheckAnswer(questionInfo);
        cout << "==============================" << endl;
    }
    if (questionInfo.opType == enOpType::Mix)
    {
        return;
    }

    questionInfo.opType = opType;

    if (questionInfo.questionsLevel == enQuestionsLevel::mix)
    {
        return;
    }

    questionInfo.questionsLevel = questionsLevel;
}

string getQuestionsLevel(enQuestionsLevel questionsLevel)
{
    switch (questionsLevel)
    {
    case enQuestionsLevel::easy:
        return "Easy";
    case enQuestionsLevel::med:
        return "Medium";
    case enQuestionsLevel::hard:
        return "Hard";
    case enQuestionsLevel::mix:
        return "Mix";
    }

    return "Wrong";
}

string getOpType(enOpType opType)
{
    switch (opType)
    {
    case enOpType::Add:
        return "+";
    case enOpType::Sub:
        return "-";
    case enOpType::Mul:
        return "x";
    case enOpType::Div:
        return "/";
    case enOpType::Mix:
        return "Mix";
    }

    return "Wrong";
}

void playLoseSound()
{
    mySleep(1000);

    Beep(650, 250);
    mySleep(70);

    Beep(500, 250);
    mySleep(70);

    Beep(300, 900);
}

void playDrawSound()
{
    Beep(550, 300);
    Sleep(250);
    Beep(550, 300);
    Sleep(250);
    Beep(450, 500);
}

void playWinSound()
{
    mySleep(1000);

    Beep(784, 120);
    mySleep(30);
    Beep(988, 120);
    mySleep(30);
    Beep(1175, 180);
    mySleep(30);
    Beep(1568, 350);
}

bool restartGame()
{
    string userInput = "";

    cout << "Do you want To play Again (y = yes, any key = no): ";
    cin >> userInput;

    if (userInput == "y" || userInput == "Y")
    {
        return true;
    }
    return false;
}

void printPassOrFail(stQuestionInfo questionInfo, int numOfQuestions)
{
    cout << "\n-----------------------------------" << endl
         << endl;
    if (numOfRightAnswers > numOfWrongAnswers)
    {
        playWinSound();
        system("color 2F");
        cout << "    Final Results is PASS :)    " << endl
             << endl;
    }
    else if (numOfRightAnswers == numOfWrongAnswers)
    {
        playDrawSound();
        system("color 6F");
        cout << "    Final Results is EQUAL :)    " << endl
             << endl;
    }
    else
    {
        playLoseSound();
        system("color 4F");
        cout << "    Final Results is FAIL :(    " << endl
             << endl;
    }
    cout << "-----------------------------------" << endl
         << endl;

    cout << "Number Of Questions: " << numOfQuestions << endl;
    cout << "Questions Level    : " << getQuestionsLevel(questionInfo.questionsLevel) << endl;
    cout << "OpType             : " << getOpType(questionInfo.opType) << endl;
    cout << "Number Of Right Answers: " << numOfRightAnswers << "/" << numOfQuestions << endl;
    cout << "Number Of Wrong Answers: " << numOfWrongAnswers << "/" << numOfQuestions << endl
         << endl;
    cout << "-----------------------------------" << endl
         << endl;
}

void StartGame()
{
    srand((unsigned)time(NULL));
    do
    {
        resetScreen();
        int numOfQuestions;

        stQuestionInfo questionInfo;

        readNumberOfQuestions(numOfQuestions);

        questionInfo.questionsLevel = readQuestionsLevel();

        questionInfo.opType = readOperationType();

        readAndPrintMultipleQuestions(questionInfo, numOfQuestions);

        printPassOrFail(questionInfo, numOfQuestions);
        
    } while (restartGame());
    
}

int main()
{
    StartGame();

    return 0;
}