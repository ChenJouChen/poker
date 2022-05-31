#include<iostream>
#include<string>
#include <cstdlib> 
#include<ctime>
#include"Poker.h"
using namespace std;
Poker::Poker() {
	for (int i = 0; i <= 12; i++) {
		poker[i] = i + 1;
		poker[i + 13] = i + 1;
		poker[i + 26] = i + 1;
		poker[i + 39] = i + 1;
	}
	for (int i = 0; i <= 52; i++) {
		if (poker[i] <= 10) pokerValue[i] = poker[i];
		else pokerValue[i] = 0.5;
	}
	for (int i = 0; i < 13; i++) {
		pokerName[0 + 4 * i] = "黑桃";
		pokerName[1 + 4 * i] = "紅心";
		pokerName[2 + 4 * i] = "方塊";
		pokerName[3 + 4 * i] = "梅花";
	}
	for (int i = 0; i < 4; i++) {
		pokerName[0 + 13 * i] += "A ";
		pokerName[1 + 13 * i] += "2 ";
		pokerName[2 + 13 * i] += "3 ";
		pokerName[3 + 13 * i] += "4 ";
		pokerName[4 + 13 * i] += "5 ";
		pokerName[5 + 13 * i] += "6 ";
		pokerName[6 + 13 * i] += "7 ";
		pokerName[7 + 13 * i] += "8 ";
		pokerName[8 + 13 * i] += "9 ";
		pokerName[9 + 13 * i] += "10 ";
		pokerName[10 + 13 * i] += "J ";
		pokerName[11 + 13 * i] += "Q ";
		pokerName[12 + 13 * i] += "K ";
	}

	numOfB = 0;
	numOfP = 0;
}
void Poker::newPoker() {
	srand((int)time(0));
	pokerB[0] = rand() % 52;
	pokerP[0] = rand() % 52;

	numOfB = 1;
	numOfP = 1;

	cout << "你的牌為:" << getPokerP() << "點數為:" << getSumP() << endl;
}
string Poker::getPokerB() {
	string cardB = "";
	for (int i = 0; i < numOfB; i++) {
		cardB += pokerName[pokerB[i]];
	}
	return cardB;
}
string Poker::getPokerP() {
	string cardP = "";
	for (int i = 0; i < numOfP; i++) {
		cardP += pokerName[pokerP[i]];
	}
	return cardP;
}
double Poker::getSumB() {
	double pointB = 0;
	for (int i = 0; i < numOfB; i++) {
		pointB += pokerValue[pokerB[i]];
	}
	return pointB;
}
double Poker::getSumP() {
	double pointP = 0;
	for (int i = 0; i < numOfP; i++) {
		pointP += pokerValue[pokerP[i]];
	}
	return pointP;
}
void Poker::askPokerB() {
	if (numOfB < 5 && getSumB() < 10.5) {
		pokerB[numOfB] = rand() % 52;
		numOfB++;
	}

}
void Poker::askPokerP() {
	if (getSumB() < 10) {
		askPokerB();
	}
	if (numOfP < 5 && getSumP() < 10.5) {
		pokerP[numOfP] = rand() % 52;
		numOfP++;
		cout << "你的牌為:" << getPokerP() << "點數為:" << getSumP() << endl;
		cout << "莊家的牌為:" << getPokerB() << "點數為:" << getSumB() << endl;
		if (getSumP() == 10.5) {
			cout << "你贏了 ";
			money += bet;
			cout << "剩下" << money << "元" << endl;
			cout << "結束" << endl;
		}
		else if (getSumP() > 10.5) {
			cout << "你輸了,超過十點半 ";
			money -= bet;
			cout << "剩下" << money << "元" << endl;
			cout << "結束" << endl;
		}
		else if (numOfP == 5 && getSumP() == 10.5) {
			cout << "你贏了 ";
			money += bet * 3;
			cout << "剩下" << money << "元" << endl;
			cout << "結束" << endl;
		}
		else if (numOfP == 5 && getSumP() < 10.5 && numOfB < 5) {
			cout << "你贏了 ";
			money += bet * 5;
			cout << "剩下" << money << "元" << endl;
			cout << "結束" << endl;
		}
		else if (getSumB() == 10.5) {
			cout << "莊家贏了 ";
			money -= bet;
			cout << "剩下" << money << "元" << endl;
			cout << "結束" << endl;
		}
		else if (getSumB() > 10.5) {
			cout << "莊家的點數:" << getSumB() << " 玩家的點數:" << getSumP() << endl;
			cout << "莊家輸了,超過十點半 ";
			money += bet;
			cout << "剩下" << money << "元" << endl;
			cout << "結束" << endl;
		}
		else if (numOfP == 5 && numOfB == 5 && getSumB() < 10.5 && getSumP() < 10.5) {
			cout << "平手 " << endl;
			cout << "剩下" << money << "元" << endl;
			cout << "結束" << endl;
		}
	}
	else if (numOfP >= 5) {
		cout << "無法要牌" << endl;
		stopGame();
	}
}
void Poker::setMoney() {
	cout << "輸入本金:";
	cin >> money;
}
int Poker::getMoney() {
	return money;
}
void Poker::setBet() {
	cout << "輸入賭注:";
	cin >> bet;
	while (money < bet) {
		cout << "本金不夠,重新下注" << endl;
		cout << "輸入賭注:";
		cin >> bet;
	}
}
int Poker::getBet() {
	return bet;
}
void Poker::newGame() {
	setBet();
	newPoker();
}

void  Poker::stopGame() {
	if (getSumB() < 10) {
		askPokerB();
		if (getSumB() == 10.5) {
			cout << "莊家的點數:" << getSumB() << " 玩家的點數:" << getSumP() << endl;
			cout << "莊家贏了 ";
			money -= bet;
		}
		else if (getSumB() > 10.5) {
			cout << "莊家的點數:" << getSumB() << " 玩家的點數:" << getSumP() << endl;
			cout << "莊家輸了,超過十點半 ";
			money += bet;
		}
		else if (numOfP == 5 && numOfB == 5 && getSumB() < 10.5 && getSumP() < 10.5) {
			cout << "平手 " << endl;
		}
		else if (getSumB() >= getSumP()) {
			cout << "莊家的點數:" << getSumB() << " 玩家的點數:" << getSumP() << endl;
			cout << "莊家贏 " << endl;
			money -= bet;
		}
		cout << "剩下" << money << "元" << endl;
		cout << "結束" << endl;
	}
	else {
		cout << "莊家的點數:" << getSumB() << " 玩家的點數:" << getSumP() << endl;
		if (getSumB() >= getSumP()) {
			cout << "莊家贏 " << endl;
			money -= bet;
		}
		else {
			cout << "玩家贏 " << endl;
			money += bet;
		}
		cout << "剩下" << money << "元";
		cout << "結束" << endl;
	}
}
