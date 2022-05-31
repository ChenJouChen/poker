#ifndef POKER
#define POKER
#include<string>
using namespace std;
class Poker {
private:
	int poker[52];
	double pokerValue[52];
	string pokerName[52];
	int money;
	int bet;
	int pokerB[5] = {};
	int pokerP[5] = {};
	int numOfB;
	int numOfP;
public:
	Poker();
	void newPoker();
	string getPokerB();
	string getPokerP();
	double getSumB();
	double getSumP();
	void askPokerB();
	void askPokerP();
	void setMoney();
	int getMoney();
	void setBet();
	int getBet();
	void newGame();
	void  stopGame();
};
#endif // !POKER
