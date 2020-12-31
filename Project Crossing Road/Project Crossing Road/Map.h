#ifndef Map_h
#define Map_h

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cmath>
#include "Player.h"
#include "Position.h"
#include "Lanes.h"
#include "Level.h"
#include "Obstacle.h"
using namespace std;


class Map {
	//old figure: width=height =300
	const int width = 115, height = 36;
	char map[40][125];
	Player player;
	Lanes rowsData;
	Level level;
	int t = 0;
public:
	Map();
	~Map() = default;

	void resetMap(); // reset the map to default with no enemy and no player
	void printMap(); // print map to screen
	void drawMap(); // draw all enemies and player
	void redrawMap();
	int draw(Position pos, char** shape, int w, int h); // draw from position pos(x, y) shape(w, h) | 1: ok, 0: go out of map
	void deleteOldPlayer();
	void drawPlayer(); // draw player to map, check if crash => kill player
	void drawEnemies(Obstacle* obstacle); // draw enemy to map
	void randomNextState(); // generate new enemies base on level and push to rows
	void initializeNewState(); // intialize a new map base on level, reset player state
							   //    void handleKeyInput(); // receive key input from cGame and call appropriate function
	void updatePosPlayer(char moving);

	void saveGame(string file);
	bool loadGame(string file);

	void printBorder();

	void printCongrats();
	bool printLevelUp();
	//check endgame
	bool isEnd();
	//check isWin
	bool isWin();
	void nextLevel();

	void printInt(int x, ofstream& outfile);
	int readInt(ifstream& infile);
};


#endif