#ifndef CARD_HH
#define CARD_HH
#include <iostream>
using namespace std;

struct Card
{
public:
    char suit;  // c=clubs h=hearts s=spades d=diamonds
    int value;  //between 2 and 14. 11=Jack, 12=Queen, 13=King, 14=Ace
    void show()
    {
        if(value <= 10)
        {
            cout << value << flush;
        }
        else if(value == 11)
        {
            cout << 'J' << flush;
        }
        else if(value == 12)
        {
            cout << 'Q' << flush;
        }
        else if(value == 13)
        {
            cout << 'K' << flush;
        }
        else if(value == 14)
        {
            cout << 'A' << flush;
        }
        else
        {
            cout << "invalid" << flush;
        }
    }
};
#endif