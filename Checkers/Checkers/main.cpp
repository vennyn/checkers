#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Game.h"

int main()
{
	try {
		Game g1;
	}
	catch (const std::runtime_error& error)
	{
		std::cout << error.what();
	}

	system("pause");
	return 0;

	_CrtDumpMemoryLeaks();
}