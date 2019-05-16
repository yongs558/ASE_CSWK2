/*
Copyright 2016 Colin Girling

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef OCL_GUARD_TEST_TESTLOG_HPP
#define OCL_GUARD_TEST_TESTLOG_HPP

#include "TestString.hpp"
#include <cstddef>

namespace ocl
{

class TestLog
{
public:
    virtual void Write(TestString const&) = 0;

    virtual void WriteEOL()
    {
        static TestString const eol("\n");
        Write(eol);
    }

    void WriteLine(TestString const& str)
    {
        Write(str);
        WriteEOL();
    }

    virtual ~TestLog()
    {
    }
};

} // namespace ocl

#endif // OCL_GUARD_TEST_TESTLOG_HPP