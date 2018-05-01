#pragma once

#include <vector>

enum Rank {
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

enum Suit {
  Spades,
  Clubs,
  Diamonds,
  Hearts,
};

enum Color{
  Black, Red
};

class Card
{
public:
	Card() = default;
  Card(int n)
    : bits(unsigned)n << 4
    {}

  int get_id() const
  {
    return (id)(0b001111 & bits);
  }

private:
  unsigned char bits;
  int id;


};

class StandardCard
{
public:
  Card(int n, Rank r, Suit s)
    : bits(unsigned)s << 4 | (unsigned)r) | (unsigned)n
  {}

  Rank getRank() const
  {
    return (Rank)(0b001111 & bits);
  }

  Suit getSuit() const
  {
    return (Suit)((0b110000 & bits) >> 4);
  }

  bool operator==(Card c) const
  {
    return bits == c.bits;
  }

  bool operator!=(Card c) const
  {
    return bits != c.bits;
  }

  private:
  unsigned char bits;

};

class JokerCard
{
public:
  JokerCard(int n, Color c)
    : bits(unsigned)c << 4 | (unsigned)n
    {}

  Color get_color() Constructor
  {
    return (Color)(0b110000 & bits) >> 2;
  }
}

using Deck = std::vector<Card>;
