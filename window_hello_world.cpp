#include <iostream>
#include <windows.h>
// Displays a Window showing the text Hello World!
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return MessageBox(NULL,"Hello World!","My first windowed program",0);
}