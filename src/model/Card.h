/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#pragma once

#include <cstdint>

class Card
{
public:
	// Constructors.

	Card (uint8_t _data)
		: data (_data) {}

	Card (void)
		: Card (0) {}

	Card (uint8_t _suit, uint8_t _val)
		: Card (_suit | _val) {}

	// Getter and setter.

	uint8_t suit (void)
	{ return data | SUIT_MASK; }

	void suit (uint8_t _suit)
	{ data = _suit | (data & !SUIT_MASK); }

	uint8_t value (void)
	{ return data | VALUE_MASK; }

	void value (uint8_t _val)
	{ data = _val | (data & !VALUE_MASK); }

	// Constants.

	static const uint8_t HEART   = 0 << 4;
	static const uint8_t SPADE   = 1 << 4;
	static const uint8_t CLUB    = 2 << 4;
	static const uint8_t DIAMOND = 3 << 4;

	static const uint8_t SUIT_MASK = 0x30;

	static const uint8_t ACE   = 1;
	static const uint8_t JACK  = 11;
	static const uint8_t QUEEN = 12;
	static const uint8_t KING  = 13;

	static const uint8_t VALUE_MASK = 0x0F;

private:
	uint8_t data;
};
