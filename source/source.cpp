/*

You are free to use and distribute this code without asking me and without crediting me. Do not however claim credit yourself. (That would not be very nice.)

*/

#include "windows.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	DEVMODE Gsyncfix;
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &Gsyncfix); // get variables
	ChangeDisplaySettings(&Gsyncfix, CDS_FULLSCREEN); // set fullscreen with current variables
	Sleep(50); // This is not even needed but doing it just in case
	ChangeDisplaySettings(NULL, 0); // reset back to normal
}