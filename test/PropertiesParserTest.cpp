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
#include <cstdio>
#include <algorithm>
#include "PropertiesParser.h"

using namespace testing;
using namespace cppproperties;

TEST(PropertiesParser, TestRead) {
    Properties props = PropertiesParser::Read("test/test1.properties");
    EXPECT_EQ("foo", props.GetProperty("name1"));
    EXPECT_EQ("hello", props.GetProperty("msg1"));

    EXPECT_EQ("bar", props.GetProperty("name2"));
    EXPECT_EQ("bye", props.GetProperty("msg2"));
}

TEST(PropertiesParser, TestReadInvalidFile) {
    EXPECT_THROW(PropertiesParser::Read("test/test2.properties"), PropertiesException);
}

TEST(PropertiesParser, TestReadFileNotFound) {
    EXPECT_THROW(PropertiesParser::Read("somewhere"), PropertiesException);
}

TEST(PropertiesParser, TestWrite) {
    Properties inProps;
    inProps.AddProperty("key1", " value1");
    inProps.AddProperty("key2", "value2");
    inProps.AddProperty("key3", "value3");
    inProps.AddProperty("key4", "value4");
    inProps.AddProperty("key5", " value5 ");

    PropertiesParser::Write("test/out.properties", inProps);

    Properties outProps = PropertiesParser::Read("test/out.properties");

    std::vector<std::string> names = outProps.GetPropertyNames();
    EXPECT_EQ(5, names.size());
    EXPECT_EQ("value1", outProps.GetProperty("key1"));
    EXPECT_EQ("value2", outProps.GetProperty("key2"));
    EXPECT_EQ("value3", outProps.GetProperty("key3"));
    EXPECT_EQ("value4", outProps.GetProperty("key4"));
    EXPECT_EQ("value5 ", outProps.GetProperty("key5"));

    // delete the file at the end
    std::remove("../test/out.properties");
}
