#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <string_view>

int main()
{
  using namespace std;

  map<string, uint_fast16_t> date_counter {};
  for (string s; getline(cin, s);) {
    using namespace literals::string_view_literals;
    constexpr auto target_str {"\"date\":\""sv};
    const auto data_pos {s.find(target_str)};
    if (data_pos == decltype(s)::npos)
      continue;
    constexpr auto date_size {"0000-00-00"sv.size()};
    const auto date_str {s.substr(data_pos + target_str.size(), date_size)};
    ++date_counter[date_str];
  }
  for (const auto& e : date_counter)
    std::cout << e.first << ' ' << e.second << '\n';
}
