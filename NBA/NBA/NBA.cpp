// NBA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;
class NBAPlayer
{
private:
	char* Name;
	char Team[40];
	double AveragePoints;
	double AverageAssists;
	double AverageJumps;
	void copy(const NBAPlayer &p)
	{
		this->Name = new char[strlen(p.Name) + 1];
		strcpy(this->Name, p.Name);
		strcpy(this->Team, p.Team);
		this->AveragePoints = p.AveragePoints;
		this->AverageAssists = p.AverageAssists;
		this->AverageJumps = p.AverageJumps;
	}
public:
	NBAPlayer() { Name = new char[0]; }
	NBAPlayer(char* Name, char* Team, double AveragePoints, double AverageAssists, double AverageJumps)
	{
		this->Name = new char[strlen(Name) + 1];
		strcpy(this->Name, Name);
		strcpy(this->Team, Team);
		this->AveragePoints = AveragePoints;
		this->AverageJumps = AverageJumps;
		this->AverageAssists = AverageAssists;
	}
	NBAPlayer(const NBAPlayer &p)
	{
		copy(p);
	}
	NBAPlayer &operator=(const NBAPlayer &p)
	{
		if (this != &p)
		{
			delete[]Name;
			copy(p);
		}
		return *this;
	}
	~NBAPlayer() { delete[] Name; }
	double rating()
	{
		return AveragePoints*0.45 + AverageAssists*0.30 + AverageJumps*0.25;
	}
	void print()
	{
		cout << Name << " - " << Team << endl;
		cout << "Points: " << AveragePoints << endl;
		cout << "Assists: " << AverageAssists << endl;
		cout << "Rebounds: " << AverageJumps << endl;
		cout << "Rating: " << rating() << endl;
	}
};
class AllStarPlayer : public NBAPlayer
{
private:
	double AveragePoints;
	double AverageAssists;
	double AverageJumps;
	void copy(const AllStarPlayer &p)
	{
		this->AveragePoints =p.AveragePoints;
		this->AverageJumps = p.AverageJumps;
		this->AverageAssists = p.AverageAssists;
	}
public:
	AllStarPlayer() {}
	AllStarPlayer(char* name, char* team, double points, double assists, double rebounds, double allstarpoints, double allstarassists, double allstarrebounds) : NBAPlayer(name, team, points, assists, rebounds)
	{
		this->AveragePoints = allstarpoints;
		this->AverageJumps = allstarrebounds;
		this->AverageAssists = allstarassists;
	}
	AllStarPlayer(NBAPlayer player, double points, double assists, double rebounds) : NBAPlayer(player)
	{
		
		this->AveragePoints = points;
		this->AverageJumps = rebounds;
		this->AverageAssists = assists;
	}
	AllStarPlayer(const AllStarPlayer &p) : NBAPlayer(p)
	{
		copy(p);
	}
	AllStarPlayer &operator=(const AllStarPlayer &p)
	{
		NBAPlayer::operator=(p);
		if (this != &p)
		{
			copy(p);
		}
		return *this;
	}
	~AllStarPlayer() {}
	double allStarRating()
	{
		return AllStarPlayer::AveragePoints*0.30 + AllStarPlayer::AverageAssists*0.40 + AllStarPlayer::AverageJumps*0.30;
	}
	void print()
	{
		this->NBAPlayer::print();
		cout << "All Star Rating: " << allStarRating() << endl;
		cout << "New Rating: " << (NBAPlayer::rating() + allStarRating()) / 2 << endl;
	}
};
int main()
{
	char name[50];
	char team[40];
	double points;
	double assists;
	double rebounds;
	double allStarPoints;
	double allStarAssists;
	double allStarRebounds;

	NBAPlayer * players = new NBAPlayer[5];
	AllStarPlayer * asPlayers = new AllStarPlayer[5];
	int n;
	cin >> n;

	if (n == 1) {

		cout << "NBA PLAYERS:" << endl;
		cout << "=====================================" << endl;
		for (int i = 0; i < 5; ++i) {
			cin >> name >> team >> points >> assists >> rebounds;
			players[i] = NBAPlayer(name, team, points, assists, rebounds);
			players[i].print();
		}
	}
	else if (n == 2) {

		for (int i = 0; i < 5; ++i) {
			cin >> name >> team >> points >> assists >> rebounds;
			cin >> allStarPoints >> allStarAssists >> allStarRebounds;
			players[i] = NBAPlayer(name, team, points, assists, rebounds);
			asPlayers[i] = AllStarPlayer(players[i], allStarPoints, allStarAssists, allStarRebounds);
		}

		cout << "NBA PLAYERS:" << endl;
		cout << "=====================================" << endl;
		for (int i = 0; i < 5; ++i)
			players[i].print();

		cout << "ALL STAR PLAYERS:" << endl;
		cout << "=====================================" << endl;
		for (int i = 0; i < 5; ++i)
			asPlayers[i].print();

	}
	else if (n == 3) {

		for (int i = 0; i < 5; ++i) {
			cin >> name >> team >> points >> assists >> rebounds;
			cin >> allStarPoints >> allStarAssists >> allStarRebounds;
			asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
				allStarPoints, allStarAssists, allStarRebounds);
		}
		cout << "ALL STAR PLAYERS:" << endl;
		cout << "=====================================" << endl;
		for (int i = 0; i < 5; ++i)
			asPlayers[i].print();

	}

	delete[] players;
	delete[] asPlayers;
	system("pause");
}

