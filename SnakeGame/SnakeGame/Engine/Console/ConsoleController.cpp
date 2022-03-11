#include "ConsoleController.h"

#include <iomanip>
#include <iostream>

namespace Lamter
{
    COORD ConsoleController::consolePixelSize;
    COORD ConsoleController::consoleBufferSize;

    HANDLE ConsoleController::stdHandle;
    CONSOLE_SCREEN_BUFFER_INFO ConsoleController::csbi;

    void ConsoleController::Init(COORD _consoleBufferSize, bool showCursor)
    {
        stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        _SMALL_RECT Rect;
        Rect.Top = 0;
        Rect.Left = 0;
        Rect.Bottom = _consoleBufferSize.Y - 1;
        Rect.Right = _consoleBufferSize.X - 1;

        SetConsoleWindowInfo(stdHandle, TRUE, &Rect);
        SetConsoleScreenBufferSize(stdHandle, _consoleBufferSize);

        consoleBufferSize.X = _consoleBufferSize.X - 1;
        consoleBufferSize.Y = _consoleBufferSize.Y - 1;

        SetCursorVisible(showCursor);
    }

    void ConsoleController::Delete()
    {
    }

    /**
     * \brief Checks if console is changing.
     * \return true if console is changing.
     */
    bool ConsoleController::HasConsoleChangedSize()
    {
        GetConsoleScreenBufferInfo(stdHandle, &csbi);
        if (consoleBufferSize.X != csbi.dwSize.X || consoleBufferSize.Y != csbi.dwSize.Y)
        {
            consoleBufferSize.X = csbi.dwSize.X;
            consoleBufferSize.Y = csbi.dwSize.Y;

            return true;
        }

        return false;
    }

    void ConsoleController::GetWindowPos(int* x, int* y) {
        RECT rect = { NULL };
        if (GetWindowRect(GetConsoleWindow(), &rect)) {
            *x = rect.left;
            *y = rect.top;
        }
    }

    void ConsoleController::GetWindowSize(int* x, int* y) {
        RECT rect = { NULL };
        if (GetWindowRect(GetConsoleWindow(), &rect)) {
            *x = rect.right - rect.left;
            *y = rect.bottom - rect.top;
        }
    }

    void ConsoleController::SetCursorVisible(bool visibility)
    {
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.dwSize = 50;
        GetConsoleCursorInfo(stdHandle, &cursorInfo);
        cursorInfo.bVisible = visibility;
        SetConsoleCursorInfo(stdHandle, &cursorInfo);
    }

    void ConsoleController::SetConsoleColor(Color color)
    {
        SetConsoleTextAttribute(stdHandle, WORD(color));
    }

    COORD ConsoleController::GetConsoleBufferSize()
    {
        return consoleBufferSize;
    }

    void ConsoleController::SetConsoleSize(int width, int heigh)
    {
        HWND hwnd = GetConsoleWindow();
        int x, y;
        GetWindowPos(&x, &y);
        MoveWindow(hwnd, x, y, width, heigh, true);
    }

    void ConsoleController::SetCursorPosition(int x, int y)
    {
        SetCursorPosition({ (short)x, (short)y });
    }

    void ConsoleController::SetCursorPosition(COORD coord)
    {
        std::cout.flush();
        SetConsoleCursorPosition(stdHandle, coord);//{coord.Y, coord.X});
    }

    void ConsoleController::CLS()
    {
        const COORD topLeft = { 0, 0 };

        std::cout.flush();

        DWORD length = consoleBufferSize.X * consoleBufferSize.Y;
        DWORD written;

        // Flood-fill the console with spaces to clear it
        FillConsoleOutputCharacter(stdHandle, TEXT(' '), length, topLeft, &written);
        // This clears all background colour formatting
        FillConsoleOutputAttribute(stdHandle, csbi.wAttributes, length, topLeft, &written);
        // Move the cursor back to the top left for start again
        SetCursorPosition(topLeft);
    }

    void ConsoleController::DrawAt(char character, COORD position)
    {
        SetCursorPosition(position);
        std::cout << character;
    }

    void ConsoleController::DrawAt(std::string text, COORD position)
    {
        SetCursorPosition(position);
        std::cout << text;
    }

    void ConsoleController::DrawAt(char character, int x, int y)
    {
        DrawAt(character, { (short)x, (short)y });
    }

    void ConsoleController::DrawAt(std::string text, int x, int y)
    {
        DrawAt(text, { (short)x, (short)y });
    }

    void ConsoleController::Fill(char character, int fillAmount)
    {
        std::cout << std::setfill(character) << std::setw(fillAmount - 1) << character;
    }
}

