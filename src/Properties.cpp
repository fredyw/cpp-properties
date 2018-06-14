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
#include <algorithm>
#include "Properties.h"

namespace cppproperties {

Properties::Properties() {
}

Properties::~Properties() {
}

std::string Properties::GetProperty(const std::string& key) const {
    if (properties.find(key) == properties.end()) {
        throw PropertyNotFoundException(key + " does not exist");
    }
    return properties.at(key);
}

std::string Properties::GetProperty(const std::string& key, const std::string& defaultValue) const {
    if (properties.find(key) == properties.end()) {
        return defaultValue;
    }
    return properties.at(key);
}

std::vector<std::string> Properties::GetPropertyNames() const {
    return keys;
}

void Properties::AddProperty(const std::string& key, const std::string& value) {
    if (properties.find(key) == properties.end()) {
        keys.push_back(key);
    }
    properties[key] = value;
}

void Properties::RemoveProperty(const std::string& key) {
    if (properties.find(key) == properties.end()) {
        throw PropertyNotFoundException(key + " does not exist");
    }
    keys.erase(std::remove(keys.begin(), keys.end(), key), keys.end());
    properties.erase(key);
}

} /* namespace cppproperties */
