#include "function.h"

void deleteElement(int arr[], int position, int& n)
{
	for (int i = position; i <= n; i++)
		arr[i] = arr[i + 1];
	n--;
}

void shuffle(int card[], int n, int& r)
{
	srand((unsigned)time(NULL));
	cout << "What is your lucky number ? ";
	cin >> r;
	for (int i = 1; i <= n; i++)
	{
		r = i + (rand() % (52 - i + 1));
		swap(card[i], card[r]);
	}
}

void shuffleCards(int deck[SUITS][RANKS])
{
	int position, n = 52;
	int arr[52];
	int r;
	for (int i = 1; i <= n; i++) // Make array of 52 numbers
		arr[i] = i;
	srand((unsigned)time(NULL));
	shuffle(arr, n, r);
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			position = rand() % n + 1;
			deck[i][j] = arr[position];
			deleteElement(arr, position, n);
		}
}

void Output(int deck[SUITS][RANKS])
{
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < RANKS; j++)
			cout << deck[i][j] << " ";
		cout << "\n";
	}
}

void CopyPositionCards(int deck[SUITS][RANKS], int matrix[2][53])
{
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			matrix[0][deck[i][j]] = i;
			matrix[1][deck[i][j]] = j;
		}
}

void printCardsShuffling(int deck[SUITS][RANKS], const char* suits[], const char* faces[])
{
	int matrix[2][53];

	CopyPositionCards(deck, matrix);

	for (int i = 1; i <= 52; i++)
		cout << i << ". (" << *(suits + matrix[0][i]) << "," << *(faces + matrix[1][i]) << ")" << "\n";
}

//I.2.1.a
int** dealingForHand(int deck[SUITS][RANKS])
{
	int** result;
	result = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		result[i] = new int[2];
	}
	int number = 0;
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < RANKS; j++)
		{
			if (deck[i][j] == number + 1)
			{
				result[number][0] = i;
				result[number][1] = j;
				number++;
				i = 0;
				j = -1;
			}
			if (number == 5) 
				return result;
		}
	}
	return 0;
}

//I.2.1.b
void printHand(int** hand, const char* suits[], const char* faces[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "(" << suits[hand[i][0]] << "," << faces[hand[i][1]] << ")";
	}
	cout << endl;
}

// Straight flush
int straightFlush(int** hand)
{
	for (int i = 1; i < 5; i++)
	{
		if (hand[0][0] != hand[i][0])
			return 0;
	}
	int miniumFace = 12, posCard = -1, number = 1;
	for (int i = 0; i < 5; i++)
	{
		if (miniumFace == 0) break;
		if (miniumFace > hand[i][1])
		{
			miniumFace = hand[i][1];
			posCard = i;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (posCard != i && miniumFace == hand[i][1])
			return 0;
		if (hand[i][1] == miniumFace + 1)
		{
			number++;
			posCard = i;
			miniumFace = hand[i][1];
			i = -1;
		}
	}
	return 1;
}

//I.2.1.d
int isFourOfAKind(int** hand)
{
	int number = 1, tempNumber;
	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j < 5; j++)
			if (hand[i][1] == hand[j][1]) number++;
		if (number != 4) number = 1;
		else
		{
			tempNumber = hand[i][1];
			break;
		}
	}
	if (number != 4) return 0;
	return 1;
}

//I.2.1.e
int isFullHouse(int** hand)
{
	int number = 1, twocard = -1, threecard = -1;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i][1] == twocard || hand[i][1] == threecard)
			continue;
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				continue;
			if (hand[i][1] == hand[j][1])
				number++;
		}
		if (number == 3)
		{
			threecard = hand[i][1];
			number = 1;
		}
		if (number == 2)
		{
			twocard = hand[i][1];
			number = 1;
		}
		if (number < 2)
		{
			number = 1;
		}
		if (twocard != -1 && threecard != -1)
			break;
	}
	if (twocard == -1 || threecard == -1) return 0;
	return 1;
}

//I.2.1.f
int isFlush(int** hand)
{
	int faceNumber = hand[0][1];
	for (int i = 1; i < 5; i++)
	{
		if (hand[0][0] != hand[i][0])
			return 0;
		else
		{
			if (faceNumber == 0)
				continue;
			if (hand[i][1] == 0)
			{
				faceNumber = 0;
				continue;
			}
			if (hand[i][1] > faceNumber)
				faceNumber = hand[i][1];
		}
	}
	return 1;
}

//I.2.1.g
int isStraight(int** hand)
{
	int miniumFace = 12, posCard = -1, number = 1;
	for (int i = 0; i < 5; i++)
	{
		if (miniumFace == 0) break;
		if (miniumFace > hand[i][1])
		{
			miniumFace = hand[i][1];
			posCard = i;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (posCard != i && miniumFace == hand[i][1])
			return 0;
		if (hand[i][1] == miniumFace + 1)
		{
			number++;
			posCard = i;
			miniumFace = hand[i][1];
			i = -1;
		}
	}
	if (number != 5) return 0;
	return 1;
}

//I.2.1.i
int isThreeOfAKind(int** hand)
{
	int number = 1, faceNumber = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
			if (hand[i][1] == hand[j][1] && i != j)
				number++;
		if (number == 3)
		{
			faceNumber = hand[i][1];
			break;
		}
		number = 1;
	}
	if (number != 3) return 0;
	return 1;
}

//I.2.1.j
int isTwoPairs(int** hand)
{
	int faceFirstNumber = -1, faceSecondNumber = -1, number = 1;
	for (int i = 0; i < 5; i++)
	{
		if (faceFirstNumber == hand[i][1])
			continue;
		for (int j = 0; j < 5; j++)
			if (hand[i][1] == hand[j][1])
				number++;
		if (number == 2)
		{
			if (faceFirstNumber == -1)
			{
				faceFirstNumber = hand[i][1];
				number = 0;
				continue;
			}
			else
			{
				faceSecondNumber = hand[i][1];
				break;
			}
		}
	}
	if (faceFirstNumber == -1 || faceSecondNumber == -1) return 0;
	return 1;
}

//I.2.1.k
int isPair(int** hand)
{
	int number = 1, faceNumber = -1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
			if (hand[i][1] == hand[j][1])
			{
				faceNumber = hand[i][1];
				break;
			}
		if (faceNumber != -1)
			break;
	}
	if (faceNumber == -1) return 0;
	return 1;
}

//I.2.2.l
int getHighestCard(int** hand)
{
	int highestCard = -1;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i][1] == 0)
			highestCard = 0;
		if (highestCard == 0)
			break;
		if (highestCard < hand[i][1])
			highestCard = hand[i][1];
	}
	return 1;
}

int** createHandTest(int deck[SUITS][RANKS], int a[])
{
	int index = 1;

	int** result;
	result = new int* [5];

	for (int i = 0; i < 5; i++)
	{
		result[i] = new int[2];
	}

	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			if (deck[i][j] == a[index])
			{
				result[index][0] = i;
				result[index][1] = j;
				index++;
				i = 0;
				j = 0;
			}
			if (index == 5) return result;
		}
	return 0;
}

//I.2.2.a	
int*** dealingForHands(int deck[SUITS][RANKS], int n)
{
	int*** result = new int** [n];
	for (int i = 0; i < n; i++)
		result[i] = new int* [5];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			result[i][j] = new int[2];

	int numberCard = n * 5;
	int number = 1;
	int x = 0;

	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < RANKS; j++)
		{
			if (deck[i][j] == number)
			{
				result[x % n][x / n][0] = i;
				result[x % n][x / n][1] = j;
				number++;
				x++;
				i = 0;
				j = -1;
			}
			if (number == numberCard + 1) j = RANKS;
		}
		if (number == numberCard + 1) break;
	}
	return result;
}

//I.2.2.b
int getStatusOfHand(int** hand)
{
	if (straightFlush(hand))
		return 8;
	if (isFourOfAKind(hand))
		return 7;
	if (isFullHouse(hand))
		return 6;
	if (isFlush(hand))
		return 5;
	if (isStraight(hand))
		return 4;
	if (isThreeOfAKind(hand))
		return 3;
	if (isTwoPairs(hand))
		return 2;
	if (isPair(hand))
		return 1;
	if (getHighestCard(hand))
		return 0;
	return 0;
}

//I.2.2.c
int* rankingHands(int*** hands, int n)
{
	int point[10][2];
	for (int i = 0; i < n; i++)
	{
		point[i][0] = getStatusOfHand(hands[i]);
		point[i][1] = i;
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (point[i][0] < point[j][0])
			{
				swap(point[i][0], point[j][0]);
				swap(point[i][1], point[j][1]);
			}
		}

	int* rankOfPlayer = new int[n];
	for (int i = 0; i < n; i++)
	{
		rankOfPlayer[i] = point[i][1];
	}
	return rankOfPlayer;
}

//I.2.2.d
int* evaluatehands(int* ranked_hands, int n)
{
	int* ranked = new int[n];
	for (int j = 0; j < n; j++)
	{
		for (int z = 0; z < n; z++)
		{
			if (ranked_hands[j] == z)
			{
				ranked[z] = (n - j);
				break;
			}
		}
	}
	return ranked;
}

//cloneFunction
void sum(int* ranked, int* rankedLast, int n)
{
	for (int i = 0; i < n; i++)
	{
		rankedLast[i] += ranked[i];
	}
}
void point(int* ranked, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "player " << i + 1 << " : " << ranked[i] << " point" << endl;
	}
}
void congratulation(int* ranked, int n)
{
	int maxPoint = 0, winner = -1;
	for (int i = 0; i < n; i++)
	{
		if (ranked[i] > maxPoint)
		{
			maxPoint = ranked[i];
			winner = i;
		}
	}
	cout << "//////////////////////////////////" << endl;
	cout << "Player " << winner + 1 << " Won the poker game " << endl;
	cout << "//////////////////////////////////" << endl;
}

//I.2.2.3

int*** dealingForHandsAndDealer(int deck[SUITS][RANKS], int n)
{
	int*** result = new int** [n + 1];
	for (int i = 0; i < n + 1; i++)
		result[i] = new int* [5];
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < 5; j++)
			result[i][j] = new int[2];

	int numberCard = (n + 1) * 5;
	int number = 1;
	int x = 0;

	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < RANKS; j++)
		{
			if (deck[i][j] == number)
			{
				result[x % (n + 1)][x / (n + 1)][0] = i;
				result[x % (n + 1)][x / (n + 1)][1] = j;
				number++;
				x++;
				i = 0;
				j = -1;
			}
			if (number == numberCard + 1) j = RANKS;
		}
		if (number == numberCard + 1) break;
	}
	return result;
}

//int getStatusOfHand(int** hand)

int* rankingHandsAndDealer(int*** hands, int n)
{
	int point[10][2];
	for (int i = 0; i < n + 1; i++)
	{
		point[i][0] = getStatusOfHand(hands[i]);
		point[i][1] = i;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n + 1; j++)
		{
			if (point[i][0] < point[j][0])
			{
				swap(point[i][0], point[j][0]);
				swap(point[i][1], point[j][1]);
			}
		}

	int* rankOfPlayer = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		rankOfPlayer[i] = point[i][1];
	}
	return rankOfPlayer;
}

int* evaluatehandsAndDealer(int* ranked_hands, int n)
{
	int* ranked = new int[n + 1];
	for (int j = 0; j < n + 1; j++)
	{
		for (int z = 0; z < n + 1; z++)
		{
			if (ranked_hands[j] == z)
			{
				ranked[z] = (n + 1 - j);
				break;
			}
		}
	}
	return ranked;
}


int** drawCard(int deck[SUITS][RANKS], int** hand, int n)
{
	char a;
	cout << "Draw(1) or not (any key else 1)" << endl;
	cin >> a;
	if (a != '1') return hand;
	int** handAfterDraw = new int* [5];
	for (int i = 0; i < 5; i++)
		handAfterDraw[i] = new int[2];
	for (int i = 0; i < 5; i++)
	{
		handAfterDraw[i][0] = hand[i][0];
		handAfterDraw[i][1] = hand[i][1];
	}
	//enter number card want to draw
	int number;
	do
	{
		cout << "Draw one, two or three: ";
		cin >> number;
	} while (number > 3 || number < 0);
	//Choice random replace or not
	int choice;
	do
	{
		cout << "(1) random replacement or (2) replace to get better situation: ";
		cin >> choice;
	} while (choice != 2 && choice != 1);
	int* x = new int[number];
	int numberOfCard = (n + 1) * 5;
	if (choice == 1)
	{
		//remove card from hand random replacement
		cout << "repalce card random " << endl;
		for (int i = 0; i < number; i++)
		{
			x[i] = rand() % 5;
		}
	}
	else
	{
		//remove card from hand replace
		for (int i = 0; i < number; i++)
		{
			do
			{
				cout << "replace Card " << i + 1 << "th: ";
				cin >> x[i];
				x[i] = x[i] - 1;
			} while (x[i] + 1 > 5 || x[i] + 1 < 0);
		}
	}
	//draw card from deck
	int** drawTheCard = new int* [number];
	for (int i = 0; i < number; i++)
		drawTheCard[i] = new int[2];
	int posNumber = (n + 1) * 5;
	int count = 0;
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)

		{
			if (count == number)
			{
				i = SUITS;
				break;
			}
			if (deck[i][j] == posNumber + 1)
			{
				drawTheCard[count][0] = i;
				drawTheCard[count][1] = j;
				count++;
				posNumber++;
				i = 0;
				j = -1;
			}
		}
	//switch card
	for (int i = 0; i < number; i++)
	{
		handAfterDraw[x[i]][0] = drawTheCard[i][0];
		handAfterDraw[x[i]][1] = drawTheCard[i][1];
	}
	return handAfterDraw;
}

//cloneFunction 
void sumDealer(int* ranked, int* rankedLast, int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		rankedLast[i] += ranked[i];
	}
}
void pointDealer(int* ranked, int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		if (i == n)
		{
			cout << "Dealer : " << ranked[i] << " point" << endl;
			return;
		}
		cout << "player " << i + 1 << " : " << ranked[i] << " point" << endl;
	}
}
void congratulationDealer(int* ranked, int n)
{
	int maxPoint = 0, winner = -1;
	for (int i = 0; i < n + 1; i++)
	{
		if (ranked[i] > maxPoint)
		{
			maxPoint = ranked[i];
			winner = i;
		}
	}
	if (winner == n)
	{
		cout << "//////////////////////////////////" << endl;
		cout << "Dealer Won the poker game " << endl;
		cout << "//////////////////////////////////" << endl;
		return;
	}
	cout << "//////////////////////////////////" << endl;
	cout << "Player " << winner + 1 << " Won the poker game " << endl;
	cout << "//////////////////////////////////" << endl;
}

void MakeArrayForTest(int a[6])
{
	int arr[53], n = 52, position;

	for (int i = 1; i <= n; i++)
		arr[i] = i;

	srand((unsigned)time(NULL));
	for (int i = 1; i <= 5; i++)
	{
		position = rand() % n + 1;
		a[i] = position;
		deleteElement(arr, position, n);
	}
}

void PrintOutTestCase(int** a, const char* suits[], const char* ranks[])
{
	for (int i = 1; i <= 5; i++)
		cout << i << ". (" << *(suits + a[0][i]) << "," << *(ranks + a[1][i]) << ")" << "\n";
}

void Menu2(int choice5, int deck[SUITS][RANKS], const char* suits[], const char* ranks[], int n)
{
	system("cls");
	int*** b = dealingForHands(deck, n);
	int s;
	int* ranked_hands = new int[n];
	int* ranked = new int[n];
	int* rankedLast = new int[n];
	for (int i = 0; i < n; i++)
		rankedLast[i] = 0;

	switch (choice5)
	{
	case 1:
		cout << 5 * n << " cards has been distributed to " << n << " players ! " << "\n";
		break;

	case 2:
		for (int i = 0; i < n; i++)
		{
			cout << "Cards of player " << i + 1 << " :";
			printHand(b[i], suits, ranks);
		}
		break;

	case 3:
		for (int i = 0; i < n; i++)
			cout << "Player " << i + 1 << ": " << getStatusOfHand(b[i]) << " points ! " << "\n";

		cout << "\n";

		ranked_hands = rankingHands(b, n);
		for (int i = 0; i < n; i++)
		{
			cout << "Top " << i + 1 << " : " << "player " << ranked_hands[i] + 1 << endl;
		}
		break;

	case 4:
		cout << "How many turn do you want ? ";
		cin >> s;
		for (int i = 0; i < s; i++)
		{
			cout << endl << endl;
			cout << "Turn " << i + 1 << " : " << endl;
			shuffleCards(deck);
			Output(deck);
			printCardsShuffling(deck, suits, ranks);
			b = dealingForHands(deck, n);
			ranked_hands = rankingHands(b, n);
			for (int i = 0; i < n; i++)
			{
				cout << "Card of player " << i + 1 << " :";
				printHand(b[i], suits, ranks);
			}
			for (int i = 0; i < n; i++)
			{
				cout << "Top " << i + 1 << " : " << "player " << ranked_hands[i] + 1 << endl;
			}
			ranked = evaluatehands(ranked_hands, n);
			sum(ranked, rankedLast, n);
			point(ranked, n);
		}
		cout << endl << endl << endl << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Player " << i + 1 << " have " << rankedLast[i] << " point" << endl;
		}
		congratulation(rankedLast, n);
		break;
	}

	system("pause");
}

void Menu1(int choice3, int deck[SUITS][RANKS], const char* suits[], const char* ranks[])
{
	system("cls");
	int** b = dealingForHand(deck);

	switch (choice3)
	{
	case 1:
		cout << "5 Cards has been distributed to player !" << "\n";
		break;
	case 2:
		cout << "5 Cards assigned to player: " << "\n";
		printHand(b, suits, ranks);
		break;
	case 3:
		if (isFourOfAKind(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 4:
		if (isFullHouse(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 5:
		if (isFlush(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 6:
		if (isStraight(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 7:
		if (straightFlush(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 8:
		if (isThreeOfAKind(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 9:
		if (isTwoPairs(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 10:
		if (isPair(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	case 11:
		if (getHighestCard(b))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;
	}
	
	system("pause");
}

void Menu0(int choice2, int deck[SUITS][RANKS], const char* suits[], const char* ranks[])
{
	system("cls");
	
	switch (choice2)
	{
	case 1: 
		shuffleCards(deck);
		cout << "A deck of 52 cards has been shuffled ! " << "\n";
		break;
	case 2:
		printCardsShuffling(deck, suits, ranks);
		break;
	case 3: 
		Output(deck);
		cout << "\n";
		printCardsShuffling(deck, suits, ranks);
		break;
	}
	
	system("pause");
}

void Menu(int deck[SUITS][RANKS], const char* suits[], const char* ranks[])
{
	int choice = 0, choice2, choice3, choice4, choice5;
	int n;
	while (choice != 3)
	{
		do
		{
			system("cls");
			cout << " 1. Card Shuffling & Dealing " << "\n";
			cout << " 2. Card Game: Five-card Poker " << "\n";
			cout << " 3. Exit ! " << "\n";
			cout << " Your choice ? ";
			cin >> choice;
		} while (choice > 3 || choice < 1);

		switch (choice)
		{
		case 1:
			choice2 = 0;
			while (choice2 != 4)
			{
				do
				{
					system("cls");
					cout << " 1. Shuffle Cards " << "\n";
					cout << " 2. Print out the resulting shuffling " << "\n";
					cout << " 3. Print out the matrix deck stores The shuffled cards && The resulting shuffling " << "\n";
					cout << " 4. Exit !" << "\n";
					cout << " Your choice ? ";
					cin >> choice2;
				} while (choice2 > 4 || choice2 < 1);
				
				if (choice2 != 4)
					Menu0(choice2, deck, suits, ranks);
			}
			break;
		
		case 2:
			choice3 = 0;
			while (choice3 != 4)
			{
				do
				{
					system("cls");
					cout << " 1. One player only  " << "\n";
					cout << " 2. N players (2 <= N <= 10) " << "\n";
					cout << " 3. A dealer & N players (2 <= N <= 8) " << "\n";
					cout << " 4. Exit " << "\n";
					cout << " Your choice ? ";
					cin >> choice3;
				} while (choice3 > 4 || choice3 < 1);

				if (choice3 == 1)
				{
					choice4 = 0;
					while (choice4 != 12)
					{
						do
						{
							system("cls");
							cout << " 1. Distribute cards to a player " << "\n";
							cout << " 2. Print out five cards assigned to a player. " << "\n";
							cout << " 3. Check Four of a kind " << "\n";
							cout << " 4. Check Full house " << "\n";
							cout << " 5. Check Flush " << "\n";
							cout << " 6. Check Straight " << "\n";
							cout << " 7. Check Straight flush " << "\n";
							cout << " 8. Check Three of a kind " << "\n";
							cout << " 9. Check Two pairs " << "\n";
							cout << "10. Check Pair " << "\n";
							cout << "11. Check the value of the highest card " << "\n";
							cout << "12. Turn back " << "\n";
							cout << "Your choice ? ";
							cin >> choice4;
						} while (choice4 > 12 || choice4 < 1);

						if (choice4 != 12)
							Menu1(choice4, deck, suits, ranks);
					}
				}

				else if (choice3 == 2)
				{
					system("cls");
					cout << "How many player that you want to play ? ";
					cin >> n;
					choice5 = 0;
					while (choice5 != 5)
					{
						system("cls");
						do
						{
							cout << " 1. Distribute cards to N players : " << "\n";
							cout << " 2. Print out five cards assigned to " << n << " players" << "\n";
							cout << " 3. Return the hand-ranking of five cards && Ranks N players in 1 turn " << "\n";
							cout << " 4. For s times of dealing cards " << "\n";
							cout << " 5. Turn back " << "\n";
							cout << " Your choice ? ";
							cin >> choice5;
						} while (choice5 > 5 || choice5 < 1);

						if (choice5 != 5)
							Menu2(choice5, deck, suits, ranks, n);
					}
				}
				else if (choice3 == 3)
				{
					system("cls");
					cout << "How many player that you want to play ? ";
					cin >> n;
					choice = 0;
				}
			}
			break;
		case 3: 
			break;
		}
		
		cout << endl;
		system("pause");
	}
		cout << "Thanks for using my Program ! ";
}