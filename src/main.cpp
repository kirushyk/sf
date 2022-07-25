/*
 * (c) 2009, 2010 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#include "sf.hpp"

int main(int argc, char** argv)
{
	Application * StrangeFruits = new Application();
	StrangeFruits->Run();
	delete StrangeFruits;
	return 0;
}
