#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <iostream>
#include <cstdint>

using namespace std;

class gameSettings
{
public:
    explicit gameSettings();

    uint32_t getBestScore(void) const;
    uint32_t getTimeLimit(void) const;
    uint8_t getCountriesTotal(void) const;
    string getBestScoreName(void) const;
    string getPlayerName(void) const;
    void setBestScore(const uint32_t val);
    void setTimeLimit(const uint32_t val);
    void setCountriesTotal(const uint8_t val);
    void setBestScoreName(const string val);
    void setPlayerName(const string val);

protected :
    uint32_t bestScore;
    string bestScoreName;
    string playerName;
    uint32_t timeLimit;
    uint8_t countriesTotal;
    string region;


};

#endif // GAMESETTINGS_H
