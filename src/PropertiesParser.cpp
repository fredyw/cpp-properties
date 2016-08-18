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

#include <fstream>
#include <iostream>
#include "PropertiesParser.h"
#include "PropertiesUtils.h"

namespace cppproperties {

PropertiesParser::PropertiesParser() {
}

PropertiesParser::~PropertiesParser() {
}

Properties PropertiesParser::Read(const std::string& file) {
    Properties properties;

    std::ifstream is;
    is.open(file.c_str());
    if (!is.is_open()) {
        std::string msg = "Unable to read " + file;
        throw PropertiesException(msg.c_str());
    }

    try {
        std::string line;
        while (getline(is, line)) {
            if (PropertiesUtils::IsEmptyLine(line) || PropertiesUtils::IsComment(line)) {
                // ignore it
            } else if (PropertiesUtils::IsProperty(line)) {
                std::pair<std::string, std::string> prop = PropertiesUtils::ParseProperty(line);
                properties.AddProperty(prop.first, prop.second);
            } else {
                std::string msg = "Invalid line: " + line;
                throw PropertiesException(msg.c_str());
            }
        }
        is.close();
    } catch (...) {
        // don't forget to close the ifstream
        is.close();
        throw;
    }

    return properties;
}

void PropertiesParser::Write(const std::string& file, const Properties& props) {
    std::ofstream os;
    os.open(file.c_str());
    if (!os.is_open()) {
        std::string msg = "Unable to write " + file;
        throw PropertiesException(msg.c_str());
    }

    try {
        const std::vector<std::string>& keys = props.GetPropertyNames();
        for (std::vector<std::string>::const_iterator i = keys.begin();
            i != keys.end(); ++i) {
            os << *i << " = " << props.GetProperty(*i) << std::endl;
        }
        os.close();
    } catch (...) {
        // don't forget to close the ofstream
        os.close();
        throw;
    }
}

} /* namespace cppproperties */
