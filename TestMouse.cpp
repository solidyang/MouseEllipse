// TestMouse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <math.h>

int main()
{
	RegisterHotKey(nullptr, 0, MOD_ALT | MOD_CONTROL | MOD_SHIFT | MOD_NOREPEAT, 'K');
	RegisterHotKey(nullptr, 1, MOD_ALT | MOD_CONTROL | MOD_SHIFT | MOD_NOREPEAT, 'A');
	RegisterHotKey(nullptr, 2, MOD_ALT | MOD_CONTROL | MOD_SHIFT | MOD_NOREPEAT, 'D');
	RegisterHotKey(nullptr, 3, MOD_ALT | MOD_CONTROL | MOD_SHIFT | MOD_NOREPEAT, 'W');
	RegisterHotKey(nullptr, 4, MOD_ALT | MOD_CONTROL | MOD_SHIFT | MOD_NOREPEAT, 'S');

	float cx = 960, cy = 600.6;	// eclipse center;
	float a = 126, c = 168.5;	// eclipse radius;

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		if (msg.message == WM_HOTKEY)
		{
			if (msg.wParam == 0)
			{
				for (int i = 0; i < 720; ++i)
				{
					float x = 0.5f + a * sin(3.1415926f * 2 * i / 720) + cx;
					float y = 0.5f + c * cos(3.1415926f * 2 * i / 720) + cy;

					SetCursorPos(x, y);
					mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					Sleep(4);
				}

				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
			else if (msg.wParam == 1) {
				a -= 0.5f;
			}
			else if (msg.wParam == 2) {
				a += 0.5f;
			}
			else if (msg.wParam == 3) {
				c -= 0.5f;
			}
			else if (msg.wParam == 4) {
				c += 0.5f;
			}
			
		}
	}
	
    return 0;
}

