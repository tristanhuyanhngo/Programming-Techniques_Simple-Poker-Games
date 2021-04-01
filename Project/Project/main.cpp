#include "function.h"

int main()
{
	int deck[SUITS][RANKS];
	const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[] = { "Ace", "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

/* 
	//I.2.3
	int*** hands;
	int n;
	do
	{
		cout << "Enter Player(1<=player<=8): ";
		cin >> n;
	} while (n < 1 || n>8);
	int s;
	cout << "enter turn: ";
	cin >> s;
	int* ranked_hands = new int[n + 1];
	int* ranked = new int[n + 1];
	int* rankedLast = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		rankedLast[i] = 0;
	for (int i = 0; i < s; i++)
	{
		cout << endl << endl;
		cout << "turn " << i + 1 << " : " << endl;
		shuffleCards(deck);
		Output(deck);
		printCardsShuffling(deck, suits, ranks);
		hands = dealingForHandsAndDealer(deck, n);
		for (int j = 0; j < n + 1; j++)
		{
			if (j == n)
			{
				cout << "Card of Dealer" << " :";
				printHand(hands[j], suits, ranks);
				break;
			}
			cout << "Card of player " << j + 1 << " :";
			printHand(hands[j], suits, ranks);
		}
		ranked_hands = rankingHandsAndDealer(hands, n);
		hands[n] = drawCard(deck, hands[n], n);
		cout << "Card of Dealer After draw" << " :";
		printHand(hands[n], suits, ranks);
		for (int j = 0; j < n + 1; j++)
		{
			cout << "Top " << j + 1 << " : " << "player " << ranked_hands[j] + 1 << endl;
		}
		ranked = evaluatehandsAndDealer(ranked_hands, n);
		sumDealer(ranked, rankedLast, n);
		pointDealer(ranked, n);
	}
	cout << endl << endl << endl << endl;
	for (int i = 0; i < n + 1; i++)
	{
		if (i == n)
		{
			cout << "Dealer have " << rankedLast[i] << " point" << endl;
			break;
		}
		cout << "Player " << i + 1 << " have " << rankedLast[i] << " point" << endl;
	}
	congratulationDealer(rankedLast, n);
	*/
	
	Menu(deck, suits, ranks);
	return 0;
}