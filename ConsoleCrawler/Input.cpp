#include "Input.h" // Header file

#include <windows.h>
#include "Game.h"

UserInput::UserInput()
{
}

UserInput::~UserInput()
{
}

void UserInput::tick_events()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

    // Make sure console generates key events
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT);

    DWORD events = 0;
    GetNumberOfConsoleInputEvents(hInput, &events);

    while (events > 0) // process all pending events
    {
        INPUT_RECORD inputRecord;
        DWORD eventsRead = 0;

        ReadConsoleInput(hInput, &inputRecord, 1, &eventsRead);

        if (inputRecord.EventType == KEY_EVENT)
        {
            KEY_EVENT_RECORD& key = inputRecord.Event.KeyEvent;

            if (key.bKeyDown) // only trigger on press
            {
                currentMenu()->takeInput(key.wVirtualKeyCode);
            }
        }

        // decrement event count after processing
        events--;
    }
}

bool UserInput::isKeyDown(const char key)
{
    const int vKey = static_cast<int>(key);
    return (GetAsyncKeyState(vKey) & 0x8000) != 0;
}