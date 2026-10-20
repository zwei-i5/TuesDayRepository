#include "Game.h"
#include<iostream>
#include"Config.h"

Game::Game()
{
	card.CreateCard();
	card.ShuffleCard();
}
