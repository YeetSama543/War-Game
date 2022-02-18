#include <iostream>
#include "Bag.hh"

using namespace std;
Card* drawCard(Bag&, Bag&);  //draw a card from player's deck
int main()
{
    int choice;
    bool gameOver = false;
    Bag deck = Bag();
    Bag hand1 = Bag();
    Bag hand2 = Bag();
    Bag used1 = Bag();
    Bag used2 = Bag();
    //create deck
    deck.fillBag();
    //deal cards randomly until each player has half the deck
    while(hand1.size != 26)
    {
        //deral card to p1
        Card* card1 = deck.grab();
        hand1.add(card1);
        //deal card to p2
        Card* card2 = deck.grab();
        hand2.add(card2);
    }

    //prompt user for input
    cout << "1: Play a single turn.\n2: Play the whole game." << endl;
    cin >> choice;

    while(choice == 1 && !gameOver)
    {
        Card* card1;
        Card* card2;

        //draw a card from each
        card1 = drawCard(hand1, used1);
        card2 = drawCard(hand2, used2);

        //display card matchup
        cout << "p1 p2" << endl;
        card1->show();
        cout << " ";
        card2->show();
        cout << endl;
        //compare the cards and place accordingly
        if(card1->value > card2->value)  //both cards go to p1
        {
            used1.add(card1);
            used1.add(card2);
        }
        else if(card1->value < card2->value)  //both cards go to p2
        {
            used2.add(card1);
            used2.add(card2);
        }
        else  //war
        {
            cout << "War!" << endl;
            //create bag to carry bounty cards
            Bag bounty = Bag();

            while(card1->value == card2->value)
            {
                //emergency break for when a player doesn't have sufficient cards for war
                if(hand1.size + used1.size < 2)
                {
                    cout << endl;
                    cout << "Player 2 wins" << endl;
                    gameOver = true;
                    return 0;
                }
                if(hand2.size + used2.size < 2)
                {
                    cout << "Player 1 wins" << endl;
                    gameOver = true;
                    return 0;
                }
                //face up cards that match get added
                bounty.add(card1);
                bounty.add(card2);
                //face down cards get added too
                bounty.add(drawCard(hand1, used1));
                bounty.add(drawCard(hand2, used2));
                //draw two more cards face up and compare
                card1 = drawCard(hand1, used1);
                card2 = drawCard(hand2, used2);
            }
            //now the cards are not equal

            
            if(card1->value > card2->value)  //bounty goes to p1
            {
                //show bounty
                bounty.show();
                card1->show();
                cout << " ";
                card2->show();
                cout << " goes to player 1" << endl;
                //give bounty to p1
                while(bounty.size > 0)
                {
                    used1.add(bounty.draw());
                }
                //need to also give the unequal cards at the end
                used1.add(card1);
                used1.add(card2);
            }
            else  //bounty goes to p2
            {
                //show bounty
                bounty.show();
                card1->show();
                cout << " ";
                card2->show();
                cout << " goes to player 2" << endl;
                while(bounty.size > 0)
                {
                    used2.add(bounty.draw());
                }
                //need to also give the unequal cards at the end
                used2.add(card1);
                used2.add(card2);
            }
        }
            
        //check for win
        if(hand1.size + used1.size == 52)
        {
            gameOver = true;
            cout << endl;
            cout << "Player 1 wins!" << endl;
            break;
        }
        if(hand2.size + used2.size == 52)
        {
            gameOver = true;
            cout << endl;
            cout << "Player 2 wins!" << endl;
            break;
        }

        //display card counts
        cout << endl;
        cout << "player 1 has " << hand1.size + used1.size << " cards" << endl;
        cout << "player 2 has " << hand2.size + used2.size << " cards" << endl;
        cout << "--------------------" << endl;

        //gather choice once more
        cout << "1: Play a single turn.\n2: Play the whole game." << endl;
        cin >> choice;
    }
    while(choice == 2 && !gameOver)
    {
        Card* card1;
        Card* card2;

        //draw a card from each
        card1 = drawCard(hand1, used1);
        card2 = drawCard(hand2, used2);

        //display card matchup
        cout << "p1 p2" << endl;
        card1->show();
        cout << " ";
        card2->show();
        cout << endl;
        //compare the cards and place accordingly
        if(card1->value > card2->value)  //both cards go to p1
        {
            used1.add(card1);
            used1.add(card2);
        }
        else if(card1->value < card2->value)  //both cards go to p2
        {
            used2.add(card1);
            used2.add(card2);
        }
        else  //war
        {
            cout << "War!" << endl;
            //create bag to carry bounty cards
            Bag bounty = Bag();

            while(card1->value == card2->value)
            {
                //emergency break for when a player doesn't have sufficient cards for war
                if(hand1.size + used1.size < 3)
                {
                    cout << endl;
                    cout << "Player 2 wins" << endl;
                    gameOver = true;
                    return 0;
                }
                if(hand2.size + used2.size < 3)
                {
                    cout << "Player 1 wins" << endl;
                    gameOver = true;
                    return 0;
                }
                //face up cards that match get added
                bounty.add(card1);
                bounty.add(card2);
                //face down cards get added too
                bounty.add(drawCard(hand1, used1));
                bounty.add(drawCard(hand2, used2));
                //draw two more cards face up and compare
                card1 = drawCard(hand1, used1);
                card2 = drawCard(hand2, used2);
            }
            //now the cards are not equal
            if(card1->value > card2->value)  //bounty goes to p1
            {
                //show bounty
                bounty.show();
                card1->show();
                cout << " ";
                card2->show();
                cout << " goes to player 1" << endl;
                //give bounty to p1
                while(bounty.size > 0)
                {
                    used1.add(bounty.draw());
                }
                //need to also give the unequal cards at the end
                used1.add(card1);
                used1.add(card2);
            }
            else  //bounty goes to p2
            {
                //show bounty
                bounty.show();
                card1->show();
                cout << " ";
                card2->show();
                cout << " goes to player 2" << endl;
                //give bounty to p2
                while(bounty.size > 0)
                {
                    used2.add(bounty.draw());
                }
                //need to also give the unequal cards at the end
                used2.add(card1);
                used2.add(card2);
            }
        }
            
        //check for win
        if(hand1.size + used1.size == 52)
        {
            gameOver = true;
            cout << endl;
            cout << "Player 1 wins!" << endl;
            break;
        }
        if(hand2.size + used2.size == 52)
        {
            gameOver = true;
            cout << endl;
            cout << "Player 2 wins!" << endl;
            break;
        }

        //display card counts
        cout << endl;
        cout << "player 1 has " << hand1.size + used1.size << " cards" << endl;
        cout << "player 2 has " << hand2.size + used2.size << " cards" << endl;
        cout << "--------------------" << endl;
    }
    return 0;
}
Card* drawCard(Bag& hand, Bag& used)
{
    Card* card;
    if(hand.size != 0) 
        {
            card = hand.draw();
        }
        else  //hand is empty, but still some cards in used pile
        {
            //replenish hand with randomly ordered cards from used pile
            while(used.size != 0)
            {
                Card* card = used.grab();  //the grab makes the order random
                hand.add(card);
            }
            //now that the hand is full again, draw a card
            card = hand.draw();
        }
    return card;
}