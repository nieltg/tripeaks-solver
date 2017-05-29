/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#pragma once

#include <cstdint>
#include <iostream>

class Card
{
public:
	// Constructors

	Card (uint8_t _val)
		: val (_val) {}

	Card (void)
		: Card (0) {}

	// Getter and Setter

	uint8_t value (void) const
	{ return val; }

	void value (uint8_t _val)
	{ val = _val; }

	// Misc. Methods

	friend bool is_adjacent (const Card& _lhs, const Card& _rhs)
	{
		const uint8_t a = _lhs.value ();
		const uint8_t b = _rhs.value ();

		const uint8_t ba = (b == 13) ? 1 : (b + 1);
		const uint8_t bb = (b == 1) ? 13 : (b - 1);

		return (a == ba) || (a == bb);
	}

	friend std::ostream& operator<< (std::ostream& _os, const Card& _rhs)
	{
		char ch;

		// Value.

		ch = '?';

		const uint8_t val = _rhs.value ();

		if ((val >= 2) && (val <= 9))
			ch = val + '0';
		else
		{
			switch (val)
			{
			case ACE:
				ch = 'A'; break;
			case TEN:
				ch = 'T'; break;
			case JACK:
				ch = 'J'; break;
			case QUEEN:
				ch = 'Q'; break;
			case KING:
				ch = 'K'; break;
			}
		}

		_os << ch;

		return _os;
	}

	friend std::istream& operator>> (std::istream& _is, Card& _rhs)
	{
		char ch;

		_is >> std::ws;

		// Value.

		if (_is >> ch)
		{
			const uint8_t val = ch - '0';

			if ((val >= 2) && (val <= 9))
				_rhs.value (val);
			else
			{
				switch (ch)
				{
				case 'A':
					_rhs.value (ACE); break;
				case 'T':
					_rhs.value (TEN); break;
				case 'J':
					_rhs.value (JACK); break;
				case 'Q':
					_rhs.value (QUEEN); break;
				case 'K':
					_rhs.value (KING); break;

				default:
					_is.setstate (std::ios::failbit);
				}
			}
		}

		return _is;
	}

	// Constants

	static const uint8_t ACE   = 1;
	static const uint8_t TEN   = 10;
	static const uint8_t JACK  = 11;
	static const uint8_t QUEEN = 12;
	static const uint8_t KING  = 13;

private:
	uint8_t val;
};
