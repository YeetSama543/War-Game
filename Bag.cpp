#include <iostream>
#include "Bag.hh"
using namespace std;

Bag::Bag()
{
    for(int i = 0; i < 52; i++)
    {
        items[i] = nullptr;
    }
}
bool Bag::add(Card* cardPtr)
{
    if(size < 52)  //only add if the bag isn't full
    {
        //add card
        items[size] = cardPtr;
        //update size
        size++;
        return true;
    }
    return false;
}
Card* Bag::grab()
{
    if(size > 0)  //only grab if there's something in the bag
    {
        int random;
        Card* cardPtr;

        //create random number between 0 and size - 1
        srand(time(0));  //set seed for RNG
        random = (rand() % (size));
        //randomly select a card
        cardPtr = items[random];
        //remove selected card from the bag
        for(int i = random + 1; i < size; i++)
        {
            items[i - 1] = items[i];
        }
        //update size of bag
        size--;
        return cardPtr;
    }
    return nullptr;
}
Card* Bag::draw()
{
    if(size > 0)
    {
        //take card from top (actually the end of the array. This makes the removal much easier)
        Card* card = items[size - 1];
        items[size - 1] = nullptr;
        //update size of deck
        size--;
        return card;
    }
    return nullptr;
}
void Bag::fillBag()
{
    char suits[] = {'c','h','s','d'};
    for(int i = 2; i <= 14; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //create card
            Card* cardPtr = new Card();
            cardPtr->value = i;
            cardPtr->suit = suits[j];
            //add card to bag
            Bag::add(cardPtr);
        }
    }
}
void Bag::show()
{
    for(int i = 0; i < size; i++)
    {
        (*(items[i])).show();
        cout << " ";
    }
}