/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#include <cstdlib>

#include <model/Card.h>

int main (void)
{
	Card card (0);

	if (std::cin >> card)
		std::cout << card << std::endl;
	else
		std::cout << "fail." << std::endl;

	return EXIT_SUCCESS;
}

