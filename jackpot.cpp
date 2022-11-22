#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}


Jackpot::Jackpot()  {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}

// -----------------------------------------------------------
// TODO
void Jackpot::addBet(const Bet& b) {
    bets.insert(b);
}

// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;
	for (auto x : bets)
        for (auto y : x.getNumbers())
            if(y==num)
                count++;

    return count;

}

// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
	return res;
}
