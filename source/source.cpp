/*

You are free to use and distribute this code without asking me and without crediting me. Do not however claim credit yourself. (That would not be very nice.)

*/

#include "windows.h"

void Fix(DISPLAY_DEVICE dd) {
	DEVMODE Gsyncfix;
	EnumDisplaySettings(dd.DeviceName, ENUM_CURRENT_SETTINGS, &Gsyncfix); // Fill Gsyncfix variables

	{ // scope this
		DEVMODE dm;
		for (int iModeNum = 0; EnumDisplaySettings(dd.DeviceName, iModeNum, &dm) != 0; iModeNum++) { // Scan all possible display settings
			if (Gsyncfix.dmPelsWidth == dm.dmPelsWidth && Gsyncfix.dmPelsHeight == dm.dmPelsHeight && Gsyncfix.dmDisplayFrequency != dm.dmDisplayFrequency) { // finding same resolution different frequency
				Gsyncfix.dmDisplayFrequency = dm.dmDisplayFrequency; // This really forces the display to change settings
				break;
			}
		}
	}

	Gsyncfix.dmFields = DM_DISPLAYFREQUENCY; // This should do
	ChangeDisplaySettingsEx(dd.DeviceName, &Gsyncfix, NULL, CDS_FULLSCREEN | CDS_RESET, NULL); // Set application to fullscreen
	ChangeDisplaySettingsEx(dd.DeviceName, NULL, NULL, 0, NULL); // reset back to normal
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// Basic script scans videocard outputs and sees if there is a screen connected to it

	DISPLAY_DEVICE VideoCardSlot;
	VideoCardSlot.cb = sizeof(DISPLAY_DEVICE);

	DWORD i = 0;
	while (EnumDisplayDevices(NULL, i, &VideoCardSlot, 0)) {
		DISPLAY_DEVICE Display = { 0 };
		Display.cb = sizeof(DISPLAY_DEVICE);
		if (EnumDisplayDevices(VideoCardSlot.DeviceName, 0, &Display, 0)) Fix(VideoCardSlot);
		i++;
	}

}
