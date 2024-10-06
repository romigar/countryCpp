#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <cstdint>
#include "gamesettings.h"

class gameSettings;
class squareJoker;
class world;
class continent;
class country;

class engine : public gameSettings
{

public:
    explicit engine(gameSettings *parent = nullptr);

    squareJoker* square;
    world* m_world;
    continent* m_continent;
    country* m_country;
    string question;
    string rightAnswer;
    string RightAnswerContinent;

    int score;
    int chrono;
    int timeRemaining;
    int countriesFound;
    bool questionFinished;
    bool displayGood;
    bool squareJokerActivated;

    int getScore(void);
    int getChrono(void);
    int getTimeRemaining(void);
    int getCountriesFound(void);
    string getRightAnswer(void);
    string getQuestion(void);
    void setScore(int val);
    void setChrono(int val);
    void setTimeRemaining(int val);
    void setCountriesFound(int val);
    void setRightAnswer(string val);
    void setQuestion(string val);

    bool getQuestionFinished(void);
    void setQuestionFinished(bool val);
    bool getDisplayGood(void);
    void setDisplayGood(bool val);
    void setSquareJokerActivated(bool val);
    bool getSquareJokerActivated(void);

    void setNewQuestion(void);
    void setNewGame(string continentName);

    void setNewSquareJoker(void);

    void onGoodAnswer(int points);
    void onBadAnswer(int points);
    void onJokerAsked(void);
    void onButtonAnswerClicked(string answer);
    void onButtonNextClicked(void);
    void onButtonNewGameClicked(string continentName);


private:
};

#endif // ENGINE_H
