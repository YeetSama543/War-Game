#ifndef BAG_HH
#define BAG_HH

#include <iostream>
#include "Card.hh"

class Bag
{
public:
    Card* items[52];
    int size = 0;
    Bag();
    bool add(Card*);  //adds a single card
    Card* grab();  //takes out a card-returns the card value
    Card* draw();  //draws a card from top. Good to use if the cards are in random order
    void fillBag();  //fills bag with standard deck
    void show();
};
#endif