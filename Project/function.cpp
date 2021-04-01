#include"function.h"

void deleteElement(int arr[], int position, int& n)
{
	for (int i = position; i <= n; i++)
		arr[i] = arr[i + 1];

	n--;
}

// I.1 1
void shuffleCards(int deck[SUITS][RANKS])
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

// I.1 2
void CopyPositionCards(int deck[][RANKS], int matrix[][53])
{
	for (int i = 0; i < SUITS; i++)
		for (int j = 0; j < RANKS; j++)
		{
			matrix[0][deck[i][j]] = i;
			matrix[1][deck[i][j]] = j;
		}
}

void printCardsShuffling(int deck[][RANKS],const char* suits[],const char* faces[])
{
	int matrix[2][53];
	
	CopyPositionCards(deck, matrix);

	for (int i = 1; i <= 52; i++)
			cout << i << ". (" << *(suits + matrix[0][i]) << "," << *(faces + matrix[1][i]) << ")" << "\n";
}

int** createHandTest(int a[])
{
	int index = 0;

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
				j = -1;
			}
		}

	return result;
}