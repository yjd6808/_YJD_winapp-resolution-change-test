#include <iostream>
#include <cmath>
#include <Windows.h>
#include <WinUser.h>


// 0x00C40000
int main() {

    // 0x14ca
    // auto handle = FindWindowA(NULL, "Rise of Kingdoms");

    DWORD st =  WS_OVERLAPPED   | 
                WS_MINIMIZE     | 
                WS_VISIBLE      | 
                WS_CLIPSIBLINGS | 
                WS_CAPTION      | 
                WS_SYSMENU      | 
                WS_GROUP;
    /*
    #define WS_OVERLAPPED       0x00000000L
    #define WS_POPUP            0x80000000L
    #define WS_CHILD            0x40000000L
    #define WS_MINIMIZE         0x20000000L
    #define WS_VISIBLE          0x10000000L
    #define WS_DISABLED         0x08000000L
    #define WS_CLIPSIBLINGS     0x04000000L
    #define WS_CLIPCHILDREN     0x02000000L
    #define WS_MAXIMIZE         0x01000000L
    #define WS_CAPTION          0x00C00000L     // WS_BORDER | WS_DLGFRAME  
    #define WS_BORDER           0x00800000L
    #define WS_DLGFRAME         0x00400000L
    #define WS_VSCROLL          0x00200000L
    #define WS_HSCROLL          0x00100000L
    #define WS_SYSMENU          0x00080000L
    #define WS_THICKFRAME       0x00040000L
    #define WS_GROUP            0x00020000L
    #define WS_TABSTOP          0x00010000L
    */
    const char k = '[';
    const char k = 'a';
    HWND hWnd = FindWindowA(NULL, "[#] [6] Rise of Kingdoms [#]");
   
    if (hWnd == NULL) {
        return GetLastError();
    }

    DWORD dwStyle= GetWindowLongA(hWnd, GWL_STYLE);

    if (dwStyle == 0) {
        return GetLastError();
    }

    std::cout << std::hex;
    std::cout << dwStyle << "\n";

    // 사이즈 변경가능한 속성 부여
    if (SetWindowLongA(hWnd, GWL_STYLE, dwStyle | WS_SIZEBOX) == 0L) {
        return GetLastError();
    }

    dwStyle = GetWindowLongA(hWnd, GWL_STYLE);
    std::cout << dwStyle << "\n";

    if (dwStyle == 0) {
        return GetLastError();
    }

	return 0;
}
