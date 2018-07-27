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
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <map>

int main()
{
  std::map<std::string, std::uint_fast16_t> data_counter {};
  for (std::string content_line; getline(std::cin, content_line);) {
    std::string date_line;
    if (!getline(std::cin, date_line)) {
      std::cerr << "Wrong input size\n";
      return EXIT_FAILURE;
    }

    using namespace std::literals::string_view_literals;
    constexpr auto target_content_str {"\"data_str\":{\""sv};
    const auto content_pos {content_line.find(target_content_str)};
    if (content_pos == decltype(content_line)::npos) {
      std::cerr << "Wrong input format: odd line must has " << target_content_str << '\n';
      return EXIT_FAILURE;
    }
    const auto content_char {content_line.at(content_pos + target_content_str.size())};

    constexpr auto target_date_str {"\"date\":\""sv};
    const auto date_pos {date_line.find(target_date_str)};
    if (date_pos == decltype(date_line)::npos) {
      std::cerr << "Wrong input format: even line must has " << target_date_str << '\n';
      return EXIT_FAILURE;
    }
    constexpr auto date_size {"0000-00-00"sv.size()};
    const auto date_str {date_line.substr(date_pos + target_date_str.size(), date_size)};

    ++data_counter[date_str + ',' + content_char];

    getline(std::cin, content_line);
  }
  for (const auto& e : data_counter)
    std::cout << e.first << ',' << e.second << '\n';
}
