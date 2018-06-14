/*
 * Copyright (c) 2018 Mario Emmenlauer (mario@emmenlauer.de)
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

#ifndef PROPERTIESEXCEPTION_H_
#define PROPERTIESEXCEPTION_H_

#include <string>
#include <exception>

namespace cppproperties {

class PropertiesException : public std::exception {
public:
    PropertiesException() {}
    PropertiesException(const std::string& msg) throw() : message(msg) {}

    virtual ~PropertiesException() throw() {}

    const std::string& str() const throw() { return message; }

    virtual const char* what() const throw() { return message.c_str(); }

private:
    std::string message;
};

} /* namespace cppproperties */

#endif /* PROPERTIESEXCEPTION_H_ */
