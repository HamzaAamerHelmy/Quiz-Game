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
    int numberOfThisQuestion = 0;
    enQuestionsLevel questionsLevel;
    enOpType opType;
    char operation;
    int firstNumber = 0;
    int secondNumber = 0;
    int correctAnswer = 0;
    int userAnswer = 0;
    bool answerStatus;
};

struct stQuiz
{
    int numberOfQuestions;
    enQuestionsLevel questionsLevel;
    enOpType opType;
    stQuestionInfo questionList[100];
    short numberOfWrongAnswers = 0;
    short numberOfRightAnswers = 0;
};

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
    Beep(784, 120);
    mySleep(30);
    Beep(988, 120);
    mySleep(30);
    Beep(1175, 180);
    mySleep(30);
    Beep(1568, 350);
}

// utiy generate rando, number
int generateRandomNumber(int from, int to)
{
    to += 1;
    int randNumber = rand() % (to - from) + from;

    return randNumber;
}

// read user input: read count of question
int readNumberOfQuestions()
{
    int numOfQuestions = 0;

    do
    {
        cout << "Enter Number Of Questions (Max 10) : ";
        cin >> numOfQuestions;

        if (numOfQuestions > 10)
        {
            cout << "Wrong Input ..." << endl;
            cout << "Please Enter a vaild number!" << endl;
        }
    } while (numOfQuestions > 10);

    return numOfQuestions;
}

// read user input: read question level
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

// read user input: read operation type
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

// generate question numbers by level
int generateQuestionNumbersByLevel(enQuestionsLevel queLev)
{
    int queNumber = 0;
    switch (queLev)
    {
    case enQuestionsLevel::easy:
        queNumber = generateRandomNumber(1, 10);
        break;
    case enQuestionsLevel::med:
        queNumber = generateRandomNumber(11, 35);
        break;
    case enQuestionsLevel::hard:
        queNumber = generateRandomNumber(36, 70);
        break;
    }
    return queNumber;
}

// translate operation type to real char
char transferOpTypeToChar(enOpType opType)
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

// just print question
void printQuestion(stQuestionInfo questionInfo, int index, int numberOfQuestions)
{
    cout << "Question [" << index << "/" << numberOfQuestions << "]" << endl;
    cout << questionInfo.firstNumber << endl;
    cout << questionInfo.secondNumber << " " << questionInfo.operation << endl;
    cout << "----------------" << endl;
}

// init Real answers of question
void initRealAnswerOfQuestion(stQuestionInfo &ques)
{
    switch (ques.operation)
    {
    case '+':
        ques.correctAnswer = ques.firstNumber + ques.secondNumber;
        break;
    case '-':
        ques.correctAnswer = ques.firstNumber - ques.secondNumber;
        break;
    case 'x':
        ques.correctAnswer = ques.firstNumber * ques.secondNumber;
        break;
    case '/':
        ques.correctAnswer = ques.firstNumber / ques.secondNumber;
        break;
    }
}

void checkAndUpdateAnswerStatus(stQuestionInfo &questionInfo)
{
    if (questionInfo.userAnswer == questionInfo.correctAnswer)
    {
        questionInfo.answerStatus = true;
    }
    else
    {
        questionInfo.answerStatus = false;
    }
}

// print Single
void printAnswer(stQuestionInfo questionInfo)
{
    if (questionInfo.answerStatus)
    {
        cout << "Right Answer :)" << endl;
        system("color 2F");
    }
    else
    {
        cout << "\a";
        cout << "Wrong Answer :(" << endl;
        cout << "The Right Answer is: " << questionInfo.correctAnswer << endl;
        system("color 4F");
    }
}

void updateScore(stQuiz &quiz, int index)
{
    if (quiz.questionList[index].answerStatus)
    {
        quiz.numberOfRightAnswers++;
        return;
    }
    quiz.numberOfWrongAnswers++;
}

// generate entire question
stQuestionInfo generateQuestion(stQuiz quiz)
{
    stQuestionInfo ques;

    if (quiz.opType == enOpType::Mix)
    {
        ques.opType = (enOpType)generateRandomNumber(enOpType::Add, enOpType::Div);
        ques.operation = transferOpTypeToChar(ques.opType);
    }
    else
    {
        ques.operation = transferOpTypeToChar(quiz.opType);
    }

    if (quiz.questionsLevel == enQuestionsLevel::mix)
    {
        ques.questionsLevel = (enQuestionsLevel)generateRandomNumber(enQuestionsLevel::easy, enQuestionsLevel::mix);
        ques.firstNumber = generateQuestionNumbersByLevel(ques.questionsLevel);
        ques.secondNumber = generateQuestionNumbersByLevel(ques.questionsLevel);
    }
    else
    {
        ques.firstNumber = generateQuestionNumbersByLevel(quiz.questionsLevel);
        ques.secondNumber = generateQuestionNumbersByLevel(quiz.questionsLevel);
    }

    initRealAnswerOfQuestion(ques);

    return ques;
}

void runQuestionsList(stQuiz &quiz)
{
    cout << "\nLoading Questions ..." << endl;
    mySleep(2000);
    resetScreen();

    for (int i = 0; i < quiz.numberOfQuestions; i++)
    {
        cout << "\n==============================" << endl;

        quiz.questionList[i] = generateQuestion(quiz);

        printQuestion(quiz.questionList[i], i+1, quiz.numberOfQuestions);

        cin >> quiz.questionList[i].userAnswer;

        checkAndUpdateAnswerStatus(quiz.questionList[i]);

        updateScore(quiz, i);

        printAnswer(quiz.questionList[i]);

        cout << "==============================" << endl;

        mySleep(1500);

        resetScreen();
    }
}

bool readAndCheckForRestart()
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

void printFinalResults(stQuiz quiz)
{
    char stat;
    cout << "\n-----------------------------------" << endl
         << endl;
    if (quiz.numberOfRightAnswers > quiz.numberOfWrongAnswers)
    {
        system("color 2F");
        cout << "    Final Results is PASS :)    " << endl
        << endl;
        stat = 'W';
    }
    else if (quiz.numberOfRightAnswers == quiz.numberOfWrongAnswers)
    {
        system("color 6F");
        cout << "    Final Results is NEUTRAL :)    " << endl
        << endl;
        stat = 'D';
    }
    else
    {
        system("color 4F");
        cout << "    Final Results is FAIL :(    " << endl
        << endl;
        stat = 'L';
    }
    cout << "-----------------------------------" << endl
         << endl;

    cout << "Number Of Questions: " << quiz.numberOfQuestions << endl;
    cout << "Questions Level    : " << getQuestionsLevel(quiz.questionsLevel) << endl;
    cout << "OpType             : " << getOpType(quiz.opType) << endl;
    cout << "Number Of Right Answers: " << quiz.numberOfRightAnswers << "/" << quiz.numberOfQuestions << endl;
    cout << "Number Of Wrong Answers: " << quiz.numberOfWrongAnswers << "/" << quiz.numberOfQuestions << endl
         << endl;
    cout << "-----------------------------------" << endl
         << endl;

    if (stat == 'W')
    {
        playWinSound();
    }
    else if (stat == 'L')
    {
        playLoseSound();
    }
    else
    {
        playDrawSound();
    }
    
}

void StartGame()
{
    srand((unsigned)time(NULL));
    do
    {
        resetScreen();

        stQuiz quiz;

        quiz.numberOfQuestions = readNumberOfQuestions();

        quiz.questionsLevel = readQuestionsLevel();

        quiz.opType = readOperationType();

        runQuestionsList(quiz);

        printFinalResults(quiz);

    } while (readAndCheckForRestart());
}

int main()
{
    StartGame();

    return 0;
}