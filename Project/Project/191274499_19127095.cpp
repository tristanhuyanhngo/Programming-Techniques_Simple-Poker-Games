#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdbool>
#include<cstring>

using namespace std;

#define SUITS 4
#define RANKS 13

void shuffleCards(int deck[][RANKS]);
void Output(int deck[][RANKS]);
void printCardsShuffling(int deck[][RANKS], const char* suits[], const char* faces[]);

void deleteElement(int arr[], int position, int& n)
{
	for (int i = position; i <= n; i++)
		arr[i] = arr[i + 1];

	n--;
}

void shuffleCards(int deck[][RANKS])
{
	int position, n = 52;
	int arr[52];

	for (int i = 1; i <= n; i++) // Make array of 52 numbers
		arr[i] = i;

	srand((unsigned)time(NULL));

	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			position = rand() % n + 1;
			deck[i][j] = arr[position];

			deleteElement(arr, position, n);
		}

}


void Output(int deck[][RANKS])
{
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < RANKS; j++)
			cout << deck[i][j] << " ";
		cout << "\n";
	}
}

void CopyPositionCards(int deck[][RANKS], int matrix[][53])
{
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			matrix[0][deck[i][j]] = i;
			matrix[1][deck[i][j]] = j;
		}
}

void printCardsShuffling(int deck[][RANKS], const char* suits[], const char* faces[])
{
	int matrix[2][53];

	CopyPositionCards(deck, matrix);

	for (int i = 1; i <= 52; i++)
		cout << i << ". (" << *(suits + matrix[0][i]) << "," << *(faces + matrix[1][i]) << ")" << "\n";
}

int main()
{
	int deck[SUITS][RANKS];
	const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[] = { "Ace", "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	shuffleCards(deck);
	Output(deck);
	printCardsShuffling(deck, suits, ranks);
	return 0;
}