//Discriminated Union-based card class.

#pragma once

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


union card
{
public:
  //Constructor
  Card(int n)
    : id(n)
    {}
  int get_id() const
  {
    return id;
  }
private:
  int id;
}card;


union StandardCard
{
public:
  StandCard(int n, Rank r, Suit s)
    : Card(n), rank(r), suit(s)
    {}


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
}card;

union JokerCard
{
public:
  JokerCard(int n, Color c)
    : Card(n), color(c)
    {}

  Color get_color() Constructor
  {
    return color;
  }

private:
  Color color;
}ca8rd;
