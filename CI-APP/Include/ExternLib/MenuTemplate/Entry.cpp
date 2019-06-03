//!
//! @file       Entry.cpp
//! @author     Hasenfresser
//! @version    1.04
//! @date       2017-12-28
//!
//! @brief      Source file of subclass Entry.
//!


#include "MenuTemplate.hpp"
#include <iostream>

using std::cout;
using std::endl;


namespace MenuTemplate {

MenuTemplate::Entry::Entry(const string &Name, const string &Text) : Name(Name), Text(Text) { }

MenuTemplate::Entry::~Entry() { }

void MenuTemplate::Entry::setName(const string &Name) {
    this->Name = Name;
}

void MenuTemplate::Entry::setText(const string &Text) {
    this->Text = Text;
}

string MenuTemplate::Entry::getName() {
    return Name;
}

string MenuTemplate::Entry::getText() {
    return Text;
}
} // end namespace
