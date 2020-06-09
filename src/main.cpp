/*
 * (c) 2009, 2010 Kyrylo Polezhajev
 *
 * Strange fruits
 *
 */

#include "sf.hpp"

int main(int argc, char** argv)
{
	PApplication StrangeFruits = new Game();
	StrangeFruits->Run();
	delete StrangeFruits;
	return 0;
}
