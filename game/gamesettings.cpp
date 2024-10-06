#include <iostream>
#include <cstdint>
#include "gamesettings.h"

using namespace std;

gameSettings::gameSettings()
{
    setTimeLimit(0);
    setBestScore(0);
    setPlayerName("player1");
    setBestScoreName("");
    setCountriesTotal(0);
}

/* ***************************************************************** */

uint32_t gameSettings::getBestScore(void) const{ return bestScore; }
uint32_t gameSettings::getTimeLimit(void) const{ return timeLimit; }
uint8_t gameSettings::getCountriesTotal(void) const{ return countriesTotal; }
string gameSettings::getPlayerName(void) const{ return playerName; }
string gameSettings::getBestScoreName(void) const{ return bestScoreName; }

/* ***************************************************************** */

void gameSettings::setBestScore(const uint32_t val)
{
    bestScore = val;
}

/* ***************************************************************** */

void gameSettings::setTimeLimit(const uint32_t val)
{
    timeLimit = val;
}

/* ***************************************************************** */

void gameSettings::setCountriesTotal(const uint8_t val)
{
    countriesTotal = val;
}

/* ***************************************************************** */

void gameSettings::setPlayerName(const string val)
{
    playerName = val;
}

/* ***************************************************************** */

void gameSettings::setBestScoreName(const string val)
{
    bestScoreName = val;
}

/* ***************************************************************** */
