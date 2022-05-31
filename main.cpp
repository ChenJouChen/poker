#include<iostream>
#include<string>
#include <cstdlib> 
#include<ctime>
#include"poker.h"
using namespace std;
int main() {
	Poker poker;
	int choose;
	poker.setMoney();
	poker.setBet();
	poker.newPoker();
	cout << "1.要牌 2.不要牌 3.重新開始 4.退出" << endl;
	cin >> choose;
	while (choose == 1 || choose == 2 || choose == 3 || choose == 4) {
		if (choose == 1) poker.askPokerP();
		else if (choose == 2) poker.stopGame();
		else if (choose == 3) poker.newGame();
		else if (choose == 4) return 0;
		cout << "1.要牌 2.不要牌 3.重新開始 4.退出" << endl;
		cin >> choose;
	}
}
