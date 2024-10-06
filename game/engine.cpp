#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

#include "engine.h"
#include "gamesettings.h"
#include "world.h"
#include "continent.h"
#include "country.h"
#include "squarejoker.h"
#include "tools.h"

using namespace std;

engine::engine(gameSettings *parent)
    : gameSettings()
    , square(new squareJoker())
    , m_world(new world())
    , m_continent(new continent())
    , m_country(new country())
{
    setChrono(0);
    setTimeRemaining(0);
    setCountriesFound(0);
    setScore(0);
    setNewQuestion();
    setQuestionFinished(0);
    setDisplayGood(0);
    setSquareJokerActivated(0);
}

/* ***************************************************************** */

void engine::setNewGame(string continentName)
{
    cout<< "selected: "<< continentName <<endl;

    for (int i = 0; i < m_world->continentList.size() ; i++)
    {
        if (m_world->continentList.at(i).getName() == continentName)
        {
            *m_continent = m_world->continentList.at(i);
            // Générateur de nombres aléatoires basé sur l'heure actuelle
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            shuffle(m_continent->list.begin(), m_continent->list.end(), std::default_random_engine(seed));
            break;
        }
    }
    setChrono(0);
    setTimeRemaining(0);
    setCountriesFound(0);
    setScore(0);
    setNewQuestion();
    setQuestionFinished(0);
    setDisplayGood(0);
    setSquareJokerActivated(0);
}

/* ***************************************************************** */

void engine::setNewQuestion(void)
{
    setDisplayGood(0);
    setSquareJokerActivated(0);
    setQuestionFinished(false);
    if (m_continent->list.empty())
    {
        cout<<"Empty list"<<endl;
        return;
    }

    *m_country = m_continent->pick();

    setQuestion(m_country->getName());
    setRightAnswer(m_country->getCapitalName());

    RightAnswerContinent = m_country->getContinent();
}

static bool hasDouble4(const string str1, const string str2, string str3, const string str4)
{
    return ( (str1 == str2) || (str1 == str3) || (str1 == str4) ||
             (str2 == str3) || (str2 == str4) || (str3 == str4));
}

void engine::setNewSquareJoker(void)
{
    cout<<"Joker asked : "<<endl;
    setSquareJokerActivated(true);
    // Pick 3 capital from the same continent
    uint8_t id = m_world->getContinentId(RightAnswerContinent);
    uint8_t size = m_world->continentList.at(id).list.size();
    bool hasDouble = true;
    string ans1;
    string ans2;
    string ans3;

    if (size > 3)
    {
        // Check if all 4 answers are different
        while(hasDouble)
        {
            ans1 = m_world->continentList.at(id).getRandomCapitalName();
            ans2 = m_world->continentList.at(id).getRandomCapitalName();
            ans3 = m_world->continentList.at(id).getRandomCapitalName();
            hasDouble = hasDouble4(ans1, ans2, ans3, rightAnswer);
        }
        square->activateSquareJoker(ans1, ans2, ans3, rightAnswer);
    }
}

/* ***************************************************************** */

int engine::getScore(void){ return score; }
int engine::getChrono(void){ return chrono; }
int engine::getTimeRemaining(void){ return timeRemaining; }
int engine::getCountriesFound(void){ return countriesFound; }
string engine::getRightAnswer(void){ return rightAnswer; }
string engine::getQuestion(void){ return question; }
bool engine::getQuestionFinished(void){ return questionFinished; }
bool engine::getDisplayGood(void){ return displayGood; }
bool engine::getSquareJokerActivated(void){ return squareJokerActivated;}

/* ***************************************************************** */

void engine::setQuestionFinished(bool val){    questionFinished = val; }
void engine::setRightAnswer(string val){    rightAnswer = val; }
void engine::setQuestion(string val) {     question = val; }
void engine::setScore(int val){    score = val; }
void engine::setChrono(int val){    chrono = val; }
void engine::setTimeRemaining(int val){    timeRemaining = val; }
void engine::setCountriesFound(int val){    countriesFound = val; }

/* ***************************************************************** */

void engine::setDisplayGood(bool val)
{
    displayGood = val;
}

/* ***************************************************************** */

void engine::setSquareJokerActivated(bool val)
{
    squareJokerActivated = val;
}

/* ***************************************************************** */

void engine::onButtonNextClicked(void)
{
    setNewQuestion();
}


void engine::onBadAnswer(int points)
{
    setScore(score-points);
}

/* ***************************************************************** */

void engine::onGoodAnswer(int points)
{
    setScore(score+points);
    setCountriesFound(getCountriesFound()+1);

    //afficher bonne réponse
    setDisplayGood(true);
}

/* ***************************************************************** */

void engine::onButtonNewGameClicked(string continentName)
{
    setNewGame(continentName);
}

/* ***************************************************************** */

void engine::onButtonAnswerClicked(string answer)
{
    cout<<"Answer : "<< answer <<endl;
    cout<<"RightAnswer : "<< rightAnswer <<endl;
    setQuestionFinished(true);
    int points = square->getActivated() ? 3 : 5;

    if (validDistance(rightAnswer, answer, 0.4))
    {
        cout<<"Bonne réponse"  <<endl;
        onGoodAnswer(points);
    }
    else
    {
        cout<<"Mauvaise réponse"  <<endl;
        onBadAnswer(points);
    }
}
