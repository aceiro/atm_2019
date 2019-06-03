//!
//! @file       getChar.hpp
//! @author     Hasenfresser
//! @version    1.04
//! @date       2017-12-28
//!
//! @brief      Header file of getChar function.
//!


// include guard
#pragma once


// define LINUX or WINDOWS
#define LINUX


#include <cstdint>

//!
//! @namespace  ExternFunctions
//!
//! @brief      Namespace of extern functions.
//!
namespace ExternFunctions {

//!
//! @brief      Returns presed key without pressing return.
//!
//! @return     Char of pressed key.
//!
char getChar();

} // end namespace
