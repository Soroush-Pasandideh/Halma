#include <windows.h>
#include "general.h"
void setTextColor(int textColor, int backColor = 0){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
