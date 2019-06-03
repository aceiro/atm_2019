//!
//! @file       MenuTemplate.hpp
//! @author     Hasenfresser
//! @version    1.04
//! @date       2017-12-28
//!
//! @brief      Header file of MenuTemplate class.
//!

// include guard
#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

// define LINUX or WINDOWS
#define LINUX

//!
//! @namespace  MenuTemplate
//!
//! @brief      Main namespace of MenuTemplate.
//!
//! The namespace MenuTemplate contains the class MenuTemplate, the subclass Entry and some definitions.
//!
namespace MenuTemplate {

// Definitions:
//!
//! @brief      Escape sequence to clear screen in Linux.
//!
const string CLEAR_SCREEN_LINUX = "\033[2J\033[1;1H";

#ifdef LINUX

const char ENTRY_UP = 'A';
const char ENTRY_DOWN = 'B';
const char ENTRY_SELECT = '\n';

#elif defined WINDOWS

const char ENTRY_UP = 72;
const char ENTRY_DOWN = 80;
const char ENTRY_SELECT = 13;

#else

#error: No OS defined!

#endif // LINUX

//!
//! @class      MenuTemplate
//!
//! @brief      Main class of MenuTemplate.
//!
//! A menu contains a dynamic number of entries. Each entry is unique.
//! The menu itself can be edited.
//! Entries and their position in the menu can be edited.
//!
class MenuTemplate {
private:
    //!
    //! @class      Entry
    //!
    //! @brief      Class of Entry.
    //!
    //! An entry contains a unique name (for clearly identification) and a text, which is later displayed in the menu.
    //! Name and text can be edited.
    //!
    class Entry {
        private:
        string Name;
        string Text;

        protected:

        public:

        //!
        //! @brief      Default constructor.
        //!
        //! @param      Name of entry.
        //! @param      Text of entry.
        //!
        //! Entry name must be unique and not empty.
        //! Entry text must not be empty.
        //!
        Entry(const string &Name, const string &Text);

        //!
        //! @brief      Default destructor.
        //!
        ~Entry();

        //!
        //! @brief      Setter of Name.
        //!
        //! @param      String of new name.
        //!
        //! New entry name must be unique and not empty.
        //!
        void setName(const string &Name);

        //!
        //! @brief      Setter of Text.
        //!
        //! @param      String of new text.
        //!
        //! New entry text must not empty.
        //!
        void setText(const string &Name);

        //!
        //! @brief      Getter of Name.
        //!
        //! @return     String of Name.
        //!
        string getName();

        //!
        //! @brief      Getter of Text.
        //!
        //! @return     String of Text.
        //!
        string getText();
    };

    //!
    //! @brief      Start position of cursor when menu is displayed.
    //!
    //! Position must be a value from 0 to number of entries - 1.
    //! Initial value is 0.
    //!
    int CursorStartPosition = 0;

    //!
    //! @brief      Cursor of menu.
    //!
    //! Cursor must not be empty or containg ony spaces.
    //! Initial cursor is "> ".
    //!
    string Cursor = "> ";

    //!
    //! @brief      List of all menu entries.
    //!
    vector<Entry> Entries;

    //!
    //!  @brief      Clears screen and resets cursor.
    //!
    //! There must be an OS set. Choose between LINUX or WINDOWS.
    //!
    void clearScreen();

    protected:

    public:

    //!
    //! @brief      Title of menu. If empty, it will be not displayed.
    //!
    string Title;

    //!
    //! @brief      Description of menu. If empty, it will be not displayed.
    //!
    string Description;

    //!
    //! @brief      Default constructor.
    //!
    MenuTemplate();

    //!
    //! @brief      Default destructor.
    //!
    ~MenuTemplate();

    //!
    //! @brief      Adds new entry to the menu at the end.
    //!
    //! @param      String of name.
    //! @param      String of text.
    //!
    //! New entry name must be unique and not empty.
    //! New entry text must not be empty.
    //!
    void addEntry(const string &Name, const string &Text);

    //!
    //! @brief      Adds new entry to the menu.
    //!
    //! @param      String of name.
    //! @param      String of text.
    //! @param      Position of entry in the menu.
    //!
    //! New entry name must be unique and not empty.
    //! New entry text must not be empty.
    //! New entry position must be a value from 0 to number of entries - 1. If set bigger, it will be added to the end.
    //!
    void addEntry(const string &Name, const string &Text, const int &Position);

    //!
    //! @brief      Deletes entry from menu by name.
    //!
    //! @param      String of entry name to be deleted.
    //!
    //! If entry name was not found, it will be not deleted.
    //!
    void deleteEntry(const string &Name);

    //!
    //! @brief      Deletes entry from menu by position
    //!
    //! @param      Position of entry to be deleted.
    //!
    //! If entry position was not found, it will be not deleted.
    //!
    void deleteEntry(const int &Position);

    //!
    //! @brief      Edits entry text.
    //!
    //! @param      Name of entry to be edited.
    //! @param      New text of entry to be edited.
    //!
    //! If entry name was not found or if new entry text is empty, it will be not edited.
    //!
    void editEntry(const string &Name, const string &Text);

    //!
    //! @brief      Edits entry position.
    //!
    //! @param      Name of entry to be edited.
    //! @param      New position of entry to be edited.
    //!
    //! New entry position must be a value from 0 to number of entries - 1.
    //! If entry name was not found or if new entry position is not valid, it will be not edited.
    //!
    void editEntry(const string &Name, const int &Position);

    //!
    //! @brief      Edits entry text and position.
    //!
    //! @param      Name of entry to be edited.
    //! @param      New text of entry to be edited.
    //! @param      New position of entry to be edited.
    //!
    //! New entry position must be a value from 0 to number of entries - 1.
    //! If entry name was not found, if new entry text is empty or if new entry position is not valid, it will be not edited.
    //!
    void editEntry(const string &Name, const string &Text, const int &Position);

    //!
    //! @brief      Renames entry name.
    //!
    //! @param      Name of entry to be renamed.
    //! @param      New name of entry to be renamed.
    //!
    //! If entry name was not found, if new entry name is not unique or if new entry name is empty, it will be not renamed.
    //!
    void renameEntry(const string &Name, const string &newName);

    //!
    //! @brief      Swaps two entries by name.
    //!
    //! @param      Name of entry A to be swapped.
    //! @param      Name of entry B to be swapped.
    //!
    //! If entry name A or entry name B were not found found, they will be not swapped.
    //!
    void swapEntries(const string &NameA, const string &NameB);

    //!
    //! @brief      Swaps two entries by name and position.
    //!
    //! @param      Name of entry A to be swapped.
    //! @param      Position of entry B to be swapped.
    //!
    //! If entry name A or entry position B were not found found, they will be not swapped.
    //!
    void swapEntries(const string &NameA, const int &PositionB);

    //!
    //! @brief      Swaps two entries by position and name.
    //!
    //! @param      Position of entry A to be swapped.
    //! @param      Name of entry B to be swapped.
    //!
    //! If entry position A or entry name B were not found found, they will be not swapped.
    //!
    void swapEntries(const int &PositionA, const string &NameB);

    //!
    //! @brief      Swaps two entries by position.
    //!
    //! @param      Position of entry A to be swapped.
    //! @param      Position of entry B to be swapped.
    //!
    //! If entry position A or entry position B were not found found, they will be not swapped.
    //!
    void swapEntries(const int &PositionA, const int &PositionB);

    //!
    //! @brief      Sets Cursor.
    //!
    //! @param      String of Cursor.
    //!
    //! If cursor is empty or contains only spaces, it will not be set.
    //!
    void setCursor(const string &Cursor);

    //!
    //! @brief      Sets startposition of cursor.
    //!
    //! @param      Startposition of cursor.
    //!
    //! If cursor start position is not a value from 0 to number of entries - 1, it will not be set.
    //!
    void setCursorStartPosition(const int &CursorStartPosition);

    //!
    //! @brief      Returns actual cursor startposition.
    //!
    int getCursorStartPosition();

    //!
    //! @brief      Returns actual cursor as string.
    //!
    string getCursor();

    //!
    //! @brief      Displays menu. User can select entry now.
    //!
    //! @return     Name of chosen entry.
    //!
    //! Entry can be chosen by pressing the up and down arrow and selecting with return.
    //! If there is only one entry in the menu, the name will be returned instantly without displaying the menu.
    //! If there are no entries in the menu, the returned name is an empty string.
    //!
    string displayGetName();

    //!
    //! @brief      Displays menu. User can select entry now.
    //!
    //! @return     Position of chosen entry.
    //!
    //! Entry can be chosen by pressing the up and down arrow and selecting with return.
    //! If there is only one entry in the menu, the position 0 will be returned instantly without displaying the menu.
    //! If there are no entries in the menu, the returned position is -1.
    //!
    int displayGetPosition();

    //!
    //! @brief      Returns number of entries.
    //!
    //! @return     Number of entries.
    //!
    //! Size is always a value from 0 to number of entries.
    //!
    int getNumberOfEntries();
};
} // end namespace
