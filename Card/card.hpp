//card class to use Inheritance Hierarchy

#pragma once

#include <iostream>

//user defined type
//rank = card value Ace - King
enum Rank
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

//Suit = represent the suit of the card
enum Suit
{
	Hearts,
	Diamonds,
	Clubs,
	Spades,
};

enum Color
{
	Black, Red
};

//card class to represent the base class of the card
class Card
{
public:
	//Constructor
	Card(int n)
		: id(n)
		{}

	//a pure virtual function
	virual Card* clone() = 0;

	int get_id() const
	{
		return id;
	}

	int id;
};

//standard card class derived from base class of card
//will define the standard card of Spades, Clubs, Diamonds, Hearts
//	and Ace - King
class StandardCard : public Card
{
public:
	StandCard(int n, Rank r, Suit s)
		: Card(n), rank(r), suit(s)
		{}

	//Since pure vitual function in base class, the function must
	//be overridden in derived class
	Card* clone() override
	{
		return new StandardCard(*this);
	}

	//to get cards Rank and Suit
	Rank rank;
	Suit suit;

	Rank get_rank() const
	{
		return rank;
	}

	Suit get_suit() const
	{
		return suit;
	}

};

//Joker Card class will represent the joker card in the deck
//it is only represented with an ID and Color
//this class is another derived class from the base class:Card
class JokerCard : public Card
{
public:
	JokerCard(int n, Color c)
		: Card(n), color(c)
		{}

	Color get_color() Constructor
	{
		return color;
	}

	Card* clone() override
	{
		return new JokerCard(*this);
	}

private:
	Color color;
}

//see if two cards are the same
inline bool operator==(Card a, Card b)
{
	return a.getRank() == b.getRank() &&
		   a.getSuit() == b.getSuit();
}

//see if two cards are not the same
inline bool operator!=(Card a, Card b)
{
	return !(a == b);
}
