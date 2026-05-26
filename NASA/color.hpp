#include <windows.h>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void color(int color)
{
	SetConsoleTextAttribute(console, color);
	//hey, its niya!
}

