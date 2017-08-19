/*
 * Copyright (c) 2014 Fredy Wijaya
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef PROPERTIESUTILS_H_
#define PROPERTIESUTILS_H_

#include <string>
#include <utility>

namespace cppproperties {
namespace PropertiesUtils {

/**
 * Left trims a string.
 * This function doesn't modify the given str.
 */
std::string LeftTrim(const std::string& str);

/**
 * Right trims a string.
 * This function doesn't modify the given str.
 */
std::string RightTrim(const std::string& str);

/**
 * Trims a string (perform a left and right trims).
 * This function doesn't modify the given str.
 */
std::string Trim(const std::string& str);

/**
 * Is a given string a property. A property must have the following format:
 * key=value
 */
bool IsProperty(const std::string& str);

/**
 * Parses a given property into a pair of key and value.
 *
 * ParseProperty assumes a given string has a correct format.
 */
std::pair<std::string, std::string> ParseProperty(const std::string& str);

/**
 * Is a given string a comment? A comment starts with #
 */
bool IsComment(const std::string& str);

/**
 * Is a given string empty?
 */
bool IsEmptyLine(const std::string& str);

} // namespace PropertiesUtils
} // namespace cppproperties

#endif /* PROPERTIESUTILS_H_ */
