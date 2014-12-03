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
#include <algorithm>
#include "Properties.h"

using namespace std;
using namespace testing;
using namespace cppproperties;

TEST(Properties, TestAddProperty) {
    Properties props;
    props.AddProperty("key1", "value1");
    props.AddProperty("key2", "value2");
    props.AddProperty("key3", "value3");
    EXPECT_EQ("value1", props.GetProperty("key1"));
    EXPECT_EQ("value2", props.GetProperty("key2"));
    EXPECT_EQ("value3", props.GetProperty("key3"));
    EXPECT_EQ("default", props.GetProperty("foo", "default"));
    EXPECT_THROW(props.GetProperty("foo"), PropertyNotFoundException);

    vector<string> names = props.GetPropertyNames();
    EXPECT_EQ(3, names.size());
    EXPECT_TRUE(find(names.begin(), names.end(), "key1") != names.end());
    EXPECT_TRUE(find(names.begin(), names.end(), "key2") != names.end());
    EXPECT_TRUE(find(names.begin(), names.end(), "key3") != names.end());
}

TEST(Properties, TestAddPropertyOvewrite) {
    Properties props;
    props.AddProperty("key1", "value1");
    props.AddProperty("key2", "value2");
    props.AddProperty("key3", "value3");
    props.AddProperty("key3", "value333");
    EXPECT_EQ("value1", props.GetProperty("key1"));
    EXPECT_EQ("value2", props.GetProperty("key2"));
    EXPECT_EQ("value333", props.GetProperty("key3"));
    EXPECT_EQ("default", props.GetProperty("foo", "default"));
    EXPECT_THROW(props.GetProperty("foo"), PropertyNotFoundException);

    vector<string> names = props.GetPropertyNames();
    EXPECT_EQ(3, names.size());
    EXPECT_TRUE(find(names.begin(), names.end(), "key1") != names.end());
    EXPECT_TRUE(find(names.begin(), names.end(), "key2") != names.end());
    EXPECT_TRUE(find(names.begin(), names.end(), "key3") != names.end());
}

TEST(Properties, TestRemoveProperty) {
    Properties props;
    props.AddProperty("key1", "value1");
    props.AddProperty("key2", "value2");
    props.AddProperty("key3", "value3");
    props.RemoveProperty("key3");
    EXPECT_THROW(props.RemoveProperty("foo"), PropertyNotFoundException);
    EXPECT_EQ("value1", props.GetProperty("key1"));
    EXPECT_EQ("value2", props.GetProperty("key2"));

    vector<string> names = props.GetPropertyNames();
    EXPECT_EQ(2, names.size());
    EXPECT_TRUE(find(names.begin(), names.end(), "key1") != names.end());
    EXPECT_TRUE(find(names.begin(), names.end(), "key2") != names.end());
}
