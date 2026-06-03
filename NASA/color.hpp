/*#include <windows.h>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void color(int color)
{
	SetConsoleTextAttribute(console, color);
	
}
*/


#ifndef COLOR_HPP
#define COLOR_HPP

#include <windows.h>

inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

inline void color(int color)
{
	SetConsoleTextAttribute(console, color);
}

inline void resetColor() // izbqgvame greshaka pri razdelna kompilacija.
{
	SetConsoleTextAttribute(console, 7);
}

#endif
