#ifndef JACKPOT_H_
#define JACKPOT_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Bet {
    vector<int> numbers;
    string player;
public:
    Bet(vector<int> ns, string p);
    vector<int> getNumbers() const;
    string getPlayer() const;
};

//---------------------------------

struct betHash
{
    // TODO
	int operator() (const Bet& b) const {
        vector<int> a = b.getNumbers();
        int res=0;
        for(int i=0; i<a.size();i++)
            res = res*2 + a[i];
        res = res + b.getPlayer().size();
        return res;
	}

    // TODO
	bool operator() (const Bet& b1, const Bet& b2) const {
        vector<int> a1 = b1.getNumbers(), a2 = b2.getNumbers();
        std::sort(a1.begin(), a1.end());
        std::sort(a2.begin(), a2.end());
        if(a1 == a2 && b1.getPlayer() == b2.getPlayer())
            return true;
        else
            return false;
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Jackpot
{
	tabHBet bets;
public:
	Jackpot();
	void addBet(const Bet& ap);
	unsigned betsInNumber(unsigned num) const;
	vector<string> drawnBets(vector<int> draw) const;
    unsigned getNumBets() const;
};

#endif 
