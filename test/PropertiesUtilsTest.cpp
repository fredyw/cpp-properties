// Copyright 2014 Fredy Wijaya
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <gtest/gtest.h>
#include "PropertiesUtils.h"

using namespace testing;
using namespace cppproperties;

TEST(PropertiesUtils, TestTrim) {
    EXPECT_EQ("foo", PropertiesUtils::Trim("foo"));
    EXPECT_EQ("foo", PropertiesUtils::Trim("    foo     "));
    EXPECT_EQ("foo", PropertiesUtils::Trim("\n  foo   \r\n"));
    EXPECT_EQ("", PropertiesUtils::Trim("      \n"));
}

TEST(PropertiesUtils, TestIsProperty) {
    EXPECT_TRUE(PropertiesUtils::IsProperty("key=value"));
    EXPECT_TRUE(PropertiesUtils::IsProperty("    key   =     value   "));
    EXPECT_TRUE(PropertiesUtils::IsProperty("    key   ="));
    EXPECT_FALSE(PropertiesUtils::IsProperty("=value"));
}

TEST(PropertiesUtils, TestParseProperty) {
    std::pair<std::string, std::string> p = PropertiesUtils::ParseProperty("key=value");
    EXPECT_EQ("key", p.first);
    EXPECT_EQ("value", p.second);

    p = PropertiesUtils::ParseProperty(" key = value ");
    EXPECT_EQ("key", p.first);
    EXPECT_EQ("value", p.second);

    p = PropertiesUtils::ParseProperty(" key =  ");
    EXPECT_EQ("key", p.first);
    EXPECT_EQ("", p.second);
}

TEST(PropertiesUtils, TestIsComment) {
    EXPECT_TRUE(PropertiesUtils::IsComment("# comment"));
    EXPECT_TRUE(PropertiesUtils::IsComment("   # comment"));
}

TEST(PropertiesUtils, TestIsEmptyLine) {
    EXPECT_TRUE(PropertiesUtils::IsEmptyLine("      \r\n"));
}
