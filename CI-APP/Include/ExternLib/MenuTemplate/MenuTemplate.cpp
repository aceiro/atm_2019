//!
//! @file       MenuTemplate.cpp
//! @author     Hasenfresser
//! @version    1.04
//! @date       2017-12-28
//!
//! @brief      Source file of MenuTemplate class.
//!


#include "MenuTemplate.hpp"
#include "ExternFunctions/getChar.hpp"
#include <iostream>
#include <sstream>
#include <string>

#ifdef WINDOWS

#include <cstdlib>

#endif // WINDOWS

using std::cout;
using std::endl;
using std::cin;
using std::find;
using std::stringstream;

namespace MenuTemplate {

MenuTemplate::MenuTemplate() { }

MenuTemplate::~MenuTemplate() { }

void MenuTemplate::clearScreen() {
    #if defined LINUX

    cout << CLEAR_SCREEN_LINUX;

    #elif defined WINDOWS

    system("cls");

    #else

    #error: No OS defined!

    #endif
}

void MenuTemplate::addEntry(const string &Name, const string &Text) {
    // Calling addEntry with new entry at end (position = number of entries) of menu.
    addEntry(Name, Text, Entries.size());
}

void MenuTemplate::addEntry(const string &Name, const string &Text, const int &Position) {
    try {
        // Testing, if Name is empty. If true: exception.
        if(Name.empty())
            throw string("Entry name must not be empty!");

        // Testing, if Text is emptry. If true: exception.
        if(Text.empty())
            throw string("Entry text must not be empty!");

        // Testing, if Name is unique. If false: exception
        for(int Counter = 0; Counter < Entries.size(); ++Counter)
            if(Entries[Counter].getName() == Name)
                throw string("Entry name must be unique!\nTriggering entry name: " + Name);

        // If Position is smaller than 0 or bigger than number of entries, adding new entry at the end.
        if(Position < 0 or Position > Entries.size())
            Entries.push_back(Entry(Name, Text));
        // If not, insert new entry at Position
        else
            Entries.insert(Entries.begin() + Position, Entry(Name, Text));
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::deleteEntry(const string &Name) {
    try {
        // Testing, if Name is empty. If true: exception.
        if(Name.empty())
            throw string("Entry name must not be empty!");

        // Searching for entry to be deleted.
        for(int Counter = 0; Counter < Entries.size(); ++Counter)
            // If entry was found, deleting from Entries and return.
            if(Entries[Counter].getName() == Name) {
                Entries.erase(Entries.begin() + Counter);
                return;
            }
        // If entry was not found: exception.
        throw string("The entry name to be deleted does not exist!\nTriggering entry name: " + Name);
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::deleteEntry(const int &Position) {
    try {
        // Testing, if Position to be deleted is valid. If not: exception.
        if(Position < 0 or Position >= Entries.size()) {
            stringstream Stream;
            Stream << Position;

            throw string("Position of entry to be deleted does not exist!\nTriggering position: " + Stream.str());
        }

        // If valid: deleting entry.
        Entries.erase(Entries.begin() + Position);
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::editEntry(const string &Name, const string &Text) {
    try {
        // Testing, if Name is empty. If true: exception.
        if(Name.empty())
            throw string("Entry name must not be empty!");

        // Testing, if Text is emptry. If true: exception.
        if(Text.empty())
            throw string("Entry text must not be empty!");

        // Searching for entry to be edited.
        for(int Counter = 0; Counter < Entries.size(); ++Counter)
            // If entry was found, setting new Text and return.
            if(Entries[Counter].getName() == Name) {
                Entries[Counter].setText(Text);
                return;
            }
        // If entry was not found: exception.
        throw string("The entry name to be edited does not exist!\nTriggering entry name: " + Name);
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::editEntry(const string &Name, const int &Position) {
    try {
        // Testing, if Name is empty. If true: exception.
        if(Name.empty())
            throw string("Entry name must not be empty!");

        // Testing, if Position to be edited is valid. If not: exception.
        if(Position < 0 or Position >= Entries.size()) {
            // Creating stringstream for typecasting.
            stringstream Stream;
            Stream << Position;

            throw string("Position of entry to be edited does not exist!\nTriggering position: " + Stream.str());
        }

        // Searching for entry to be edited.
        for(int Counter = 0; Counter < Entries.size(); ++Counter)
            // If entry was found, setting new Text and return.
            if(Entries[Counter].getName() == Name) {
                // Creating copy of entry to be edited.
                Entry EntryCopy = Entries[Counter];

                // Deleting entry from old position.
                Entries.erase(Entries.begin() + Counter);

                // Insert entry into new position.
                Entries.insert(Entries.begin() + Position, EntryCopy);

                return;
            }
        // If entry was not found: exception.
        throw string("The entry name to be edited does not exist!\nTriggering entry name: " + Name);
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::editEntry(const string &Name, const string &Text, const int &Position) {
    // Calling editEntry with Name and Text.
    editEntry(Name, Text);

    // Calling editEntry with Name and Position.
    editEntry(Name, Position);
}

void MenuTemplate::renameEntry(const string &Name, const string &newName) {
    try {
        // Testing, if Name is empty. If true: exception.
        if(Name.empty())
            throw string("Entry name must not be empty!");

        // Testing, if newName is empty. If true: exception.
        if(newName.empty())
            throw string("New entry name must not be empty!");

        bool Check = false;
        int Position;

        // Searching for entry to be edited and testing if newName is unique.
        for(int Counter = 0; Counter < Entries.size(); ++Counter) {
            // If entry was found: incrementing Check.
            if(Entries[Counter].getName() == Name) {
                Check = true;
                Position = Counter;
            }

            if(Entries[Counter].getName() == newName)
                throw string("New entry name is not unique!\nTriggering new entry name: " + newName);
        }

        if(!Check)
            throw string("Entry name to be renamed does not exist!\nTriggering entry name: " + Name);

        Entries[Position].setName(newName);
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::swapEntries(const string &NameA, const string &NameB) {
    try {
        // Testing, if NameA is empty. If true: exception.
        if(NameA.empty())
            throw string("EntryA name must not be empty!");

        // Testing, if NameB is empty. If true: exception.
        if(NameB.empty())
            throw string("EntryB name must not be empty!");

        // Testing, if NameA and NameB are equal. If true: exception.
        if(NameA == NameB)
            throw string("Entry names must not be equal!\nTriggering entry name: " + NameA);

        int CounterA;

        // Searching for EntryA to be swapped.
        for(CounterA = 0; CounterA < Entries.size(); ++CounterA)
            // If EntryA name was found: break.
            if(Entries[CounterA].getName() == NameA)
                break;

        // Testing, if EntryA was found.
        if(CounterA == Entries.size())
            // Exception, if EntryA was not found.
            throw string("EntryA name was not found!\nTriggering entry name: " + NameA);

        int CounterB;

        // Searching for EntryB to be swapped.
        for(CounterB = 0; CounterB < Entries.size(); ++CounterB)
            // If EntryB name was found: break.
            if(Entries[CounterB].getName() == NameB)
                break;

        // Testing, if EntryB was found.
        if(CounterB == Entries.size())
            // Exception, if EntryB was not found.
            throw string("EntryB name was not found!\nTriggering entry name: " + NameB);

        // Creating copy of EntryA
        Entry EntryACopy = Entries[CounterA];

        // Swapping both entries.
        Entries[CounterA] = Entries[CounterB];
        Entries[CounterB] = EntryACopy;
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::swapEntries(const string &NameA, const int &PositionB) {
    try {
        // Testing, if NameA is empty. If true: exception.
        if(NameA.empty())
            throw string("EntryA name must not be empty!");

        // Testing, if PositionB is valid. If not: exception.
        if(PositionB < 0 or PositionB >= Entries.size()) {
            stringstream Stream;
            Stream << PositionB;

            throw string("PositionA is not valid!\nTriggering entry position: " + Stream.str());
        }

        int CounterA;

        // Searching for EntryA to be swapped.
        for(CounterA = 0; CounterA < Entries.size(); ++CounterA)
            // If EntryA name was found: break.
            if(Entries[CounterA].getName() == NameA)
                break;

        // Testing, if EntryA was found.
        if(CounterA == Entries.size())
            // Exception, if EntryA was not found.
            throw string("EntryA name was not found!\nTriggering entry name: " + NameA);

        // Testing, if EntryA and EntryB are the same. If true, exception.
        if(CounterA == PositionB) {
            stringstream Stream;

            Stream << PositionB;

            throw string("EntryA and EntryB must not be the same!\nTriggering entry name: " + NameA + "\nTriggering entry position: " + Stream.str());
        }

        // Creating copy of EntryA
        Entry EntryACopy = Entries[CounterA];

        // Swapping both entries.
        Entries[CounterA] = Entries[PositionB];
        Entries[PositionB] = EntryACopy;
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::swapEntries(const int &PositionA, const string &NameB) {
    // Calling swapEntries with NameB and PositionA.
    swapEntries(NameB, PositionA);
}

void MenuTemplate::swapEntries(const int &PositionA, const int &PositionB) {
    try {
        // Testing, if PositionA is valid. If not: exception.
        if(PositionA < 0 or PositionA >= Entries.size()) {
            stringstream Stream;
            Stream << PositionA;

            throw string("PositionA is not valid!\nTriggering entry position: " + Stream.str());
        }

        // Testing, if PositionB is valid. If not: exception.
        if(PositionB < 0 or PositionB >= Entries.size()) {
            stringstream Stream;
            Stream << PositionB;

            throw string("PositionA is not valid!\nTriggering entry position: " + Stream.str());
        }

        // Testing, if PositionA and PositionB are equal. If true: exception.
        if(PositionA == PositionB) {
            stringstream Stream;
            Stream << PositionA;

            throw string("PositionA and PositionB must not be equal!\nTriggering entry position: " + Stream.str());
        }

        // Creating copy of EntryA
        Entry EntryACopy = Entries[PositionA];

        // Swapping both entries.
        Entries[PositionA] = Entries[PositionB];
        Entries[PositionB] = EntryACopy;
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::setCursor(const string &Cursor) {
    try {
        // Testing, if new Cursor equals old Cursor. If true: return.
        if(this->Cursor == Cursor)
            return;

        // Testing, if cursor is emptry. If true: exception.
        if(Cursor.empty())
            throw string ("Cursor must not be empty!");

        int Counter;

        // Testing, if cursor contains only spaces.
        for(Counter = 0; Counter < Cursor.length(); ++Counter)
            if(Cursor[Counter] != ' ')
                break;
        // If cursor contains only spaces: exception.
        if(Counter == Cursor.length())
            throw string ("Cursor must not contain only spaces!");

        this->Cursor = Cursor;
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

void MenuTemplate::setCursorStartPosition(const int &CursorStartPosition) {
    try{
        // Testing, if there are more than one entries. If not: exception.
        if(Entries.size() < 2)
            throw string ("There must be more than one entry to set CursorStartPosition!");

        // Testing, if new startposition is invalid. If true: exception.
        if(CursorStartPosition < 0 or CursorStartPosition >= Entries.size()) {
            stringstream Stream;
            Stream << Entries.size() - 1;

            throw string("CursorStartPosition is not valid! Must be a value from 0 to " + Stream.str());
        }

        // Setting new CursorStartPosition.
        this->CursorStartPosition = CursorStartPosition;
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }
}

int MenuTemplate::getCursorStartPosition() {
    return CursorStartPosition;
}

string MenuTemplate::displayGetName() {
    // Getting selected entry position.
    int Position = displayGetPosition();

    // If selected position is -1 (error): returning emtpy string.
    if(Position == -1)
        return "";

    // Returning name of entry by chosen position.
    return Entries[Position].getName();
}

int MenuTemplate::displayGetPosition() {
    try {
        // If there are no entries: exception.
        if(Entries.size() == 0)
            throw string("There must at least one entry to display the menu!");

        // If there is only one entry: return 0.
        if(Entries.size() == 1)
            return 0;

        // Actual selected entry position is set to cursor start position.
        int SelectedEntryPosition = CursorStartPosition;

        // Endless loop until return.
        while(true) {
            // Clearing screen.
            clearScreen();

            // Testing, if Title is empty. If true, it will be not displayed.
            if(!Title.empty())
                cout << Title << endl << endl;

            // Testing, if Description is empty. If true, it will be not displayed.
            if(!Description.empty())
                cout << Description << endl << endl;

            for(int CounterA = 0; CounterA < Entries.size(); ++CounterA) {
                if(CounterA == SelectedEntryPosition)
                    cout << Cursor;
                else
                    for(int CounterB = 0; CounterB < Cursor.length(); ++CounterB)
                        cout << ' ';

                cout << Entries[CounterA].getText() << endl;
            }

            // Getting pressed key and converting it into capital letter.
            char PressedKey = ExternFunctions::getChar();

            if(PressedKey == ENTRY_UP)
                SelectedEntryPosition = (SelectedEntryPosition + Entries.size() - 1) % Entries.size();
            else if(PressedKey == ENTRY_DOWN)
                SelectedEntryPosition = (SelectedEntryPosition + 1) % Entries.size();

            if(PressedKey == ENTRY_SELECT) {
                clearScreen();
                return SelectedEntryPosition;
            }
        }
    }
    catch(string Exception) {
        cout << Exception << endl;
        cin.get();
        clearScreen();
    }

    // Error: returning -1.
    return -1;
}

int MenuTemplate::getNumberOfEntries() {
    return Entries.size();
}
} // end namespace
