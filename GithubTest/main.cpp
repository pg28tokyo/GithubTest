#include "DxLib.h"
#include <tchar.h>

namespace {
    constexpr auto WINDOW_TITLE  = _T("Github Test");
    constexpr auto DRAW_TEXT = _T("manaka");
    constexpr auto SCREEN_WIDTH  = 1280;
    constexpr auto SCREEN_HEIGHT = 720;
    constexpr auto SCREEN_DEPTH  = 32;
    constexpr auto TEST_STRING = _T("HAYATOIMAI");
    constexpr auto STRING_POS = 400;
}

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
    auto window_mode = FALSE;

#ifdef _DEBUG
    window_mode = TRUE;
#endif

    SetMainWindowText(WINDOW_TITLE);

    ChangeWindowMode(window_mode);

    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH);

    if (DxLib_Init() == -1) {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    auto textColor = GetColor(255, 255, 255);

    while (ProcessMessage() != -1) {
        if (1 == CheckHitKey(KEY_INPUT_ESCAPE)) {
            break;
        }

        ClearDrawScreen();

        DrawString(10, 10, DRAW_TEXT, textColor);
        DrawString(STRING_POS, STRING_POS, TEST_STRING, textColor);

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}