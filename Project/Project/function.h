#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdbool>
#include<cstring>

#define SUITS 4
#define RANKS 13
using namespace std;

//I.1
void shuffleCards(int deck[SUITS][RANKS]);
void Output(int deck[SUITS][RANKS]);
void CopyPositionCards(int deck[SUITS][RANKS], int matrix[2][53]);
void printCardsShuffling(int deck[SUITS][RANKS], const char* suits[], const char* faces[]);
//I.2.1
int** dealingForHand(int deck[SUITS][RANKS]);
void printHand(int** hand, const char* suits[], const char* faces[]);
int** createHandTest(int deck[SUITS][RANKS], int a[]);
int straightFlush(int** hand);
int isFourOfAKind(int** hand);
int isFullHouse(int** hand);
int isFlush(int** hand);
int isStraight(int** hand);
int isThreeOfAKind(int** hand);
int isTwoPairs(int** hand);
int isPair(int** hand);
int getHighestCard(int** hand);
//I.2.2
int*** dealingForHands(int deck[SUITS][RANKS], int n);
int getStatusOfHand(int** hand);
int* rankingHands(int*** hands, int n);
int* evaluatehands(int* ranked_hands, int s);
//I.2.3
int*** dealingForHandsAndDealer(int deck[SUITS][RANKS], int n);
int* rankingHandsAndDealer(int*** hands, int n);
int* evaluatehandsAndDealer(int* ranked_hands, int s);
int** drawCard(int deck[SUITS][RANKS], int** hand, int n);
void congratulationDealer(int* ranked, int n);
void pointDealer(int* ranked, int n);
void sumDealer(int* ranked, int* rankedLast, int n);
// Others Function
void shuffle(int card[], int n, int& r);
void sum(int* ranked, int* rankedLast, int n);
void congratulation(int* ranked, int n);
void point(int* ranked, int n);
void deleteElement(int arr[], int position, int& n);

// Menu
void Menu(int deck[SUITS][RANKS], const char* suits[], const char* ranks[]);
void Menu0(int choice2, int deck[SUITS][RANKS], const char* suits[], const char* ranks[]);
void Menu1(int choice3, int deck[SUITS][RANKS], const char* suits[], const char* ranks[]);
void Menu2(int choice5, int deck[SUITS][RANKS], const char* suits[], const char* ranks[], int n);
void Menu3(int choice6, int deck[SUITS][RANKS], const char* suits[], const char* ranks[], int n);
