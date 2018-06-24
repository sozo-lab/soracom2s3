/*
MIT License

Copyright (c) 2018 Doi Yusuke

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>

using namespace std;

int main()
{
  for (string s {}; getline(cin, s);) {
    constexpr array<string_view, 2> targets {R"("data_str":)", R"("content": )"};

    for (const auto& target_str : targets) {
      if (const auto found_pos {s.find(target_str)}; found_pos != decltype(s)::npos) {
        s.erase(found_pos + target_str.size(), 1); // delete " as start string
        s.erase(s.size() - 2, 1); // delete " as end string
        s.erase(remove(s.begin(), s.end(), '\\'), s.end()); // delete all escape charactor
        break;
      }
    }
    cout << s << '\n';
  }
}
