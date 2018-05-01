

#include "card.hpp"


Deck get_Deck()
{
	Deck d {
		new StandardCard{0, Ace, Spades},
		new StandardCard{0, Two, Spades},
		new StandardCard{0, Three, Spades},
		new StandardCard{0, Four, Spades},
		new StandardCard{0, Five, Spades},
		new StandardCard{0, Six, Spades},
		new StandardCard{0, Seven, Spades},
		new StandardCard{0, Eight, Spades},
		new StandardCard{0, Nine, Spades},
		new StandardCard{0, Ten, Spades},
		new StandardCard{0, Jack, Spades},
		new StandardCard{0, Queen, Spades},
		new StandardCard{0, King, Spades},

		new StandardCard{0, Ace, Clubs},
		new StandardCard{0, Two, Clubs},
		new StandardCard{0, Three, Clubs},
		new StandardCard{0, Four, Clubs},
		new StandardCard{0, Five, Clubs},
		new StandardCard{0, Six, Clubs},
		new StandardCard{0, Seven, Clubs},
		new StandardCard{0, Eight, Clubs},
		new StandardCard{0, Nine, Clubs},
		new StandardCard{0, Ten, Clubs},
		new StandardCard{0, Jack, Clubs},
		new StandardCard{0, Queen, Clubs},
		new StandardCard{0, King, Clubs},

		new StandardCard{0, Ace, Diamonds},
		new StandardCard{0, Two, Diamonds},
		new StandardCard{0, Three, Diamonds},
		new StandardCard{0, Four, Diamonds},
		new StandardCard{0, Five, Diamonds},
		new StandardCard{0, Six, Diamonds},
		new StandardCard{0, Seven, Diamonds},
		new StandardCard{0, Eight, Diamonds},
		new StandardCard{0, Nine, Diamonds},
		new StandardCard{0, Ten, Diamonds},
		new StandardCard{0, Jack, Diamonds},
		new StandardCard{0, Queen, Diamonds},
		new StandardCard{0, King, Diamonds},

		new StandardCard{0, Ace, Hearts},
		new StandardCard{0, Two, Hearts},
		new StandardCard{0, Three, Hearts},
		new StandardCard{0, Four, Hearts},
		new StandardCard{0, Five, Hearts},
		new StandardCard{0, Six, Hearts},
		new StandardCard{0, Seven, Hearts},
		new StandardCard{0, Eight, Hearts},
		new StandardCard{0, Nine, Hearts},
		new StandardCard{0, Ten, Hearts},
		new StandardCard{0, Jack, Hearts},
		new StandardCard{0, Queen, Hearts},
		new StandardCard{0, King, Hearts},

		new JokerCard{0, Black},
		new JokerCard{1, Black},
		new JokerCard{0, Red},
		new JokerCard{1, Black}
	};
	return d;
}

std::ostream& operator<<(std::ostream& os, Card c)
{
	return os;
}

std::ostream& operator<<(std::ostream& os, const Deck& d)
{
	return os;
}

Card::Card(Rank r, Suit s)
	: rank(r), suit(s)
	{}

Card::Card(const Card& c)
	: rank(c.rank), suit(c.suit)
	{}

Card& Card::operator=(const Card& c) 
{
	rank = c.rank;
	suit = c.suit;
	return *this;
}