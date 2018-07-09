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
