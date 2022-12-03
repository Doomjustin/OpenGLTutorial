#ifndef OPENGL_TUTORIAL_SILENCE_UTILITY_H
#define OPENGL_TUTORIAL_SILENCE_UTILITY_H

#include <algorithm>
#include <string>
#include <iterator>


namespace sil {

// 抄袭自Qt的QT_DISABLE_COPY
#define SIL_DISABLE_COPY(Class) \
  Class(const Class& other) = delete;\
  Class& operator=(const Class& other) = delete;

// 抄袭自Qt的QT_DISABLE_COPY_MOVE
#define SIL_DISABLE_COPY_MOVE(Class) \
  SIL_DISABLE_COPY(Class) \
  Class(Class&& other) noexcept = delete; \
  Class& operator=(Class&& other) noexcept = delete;

#define SIL_DEFAULT_MOVE(Class) \
  Class(Class&& other) noexcept = default; \
  Class& operator=(Class&& other) noexcept = default;

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> trim(const std::basic_string<CharT, Traits>& str)
{
  std::basic_string<CharT, Traits> result{};
  std::back_insert_iterator<std::string> str_iter{ result };
  std::copy_if(str.cbegin(), str.cend(), str_iter, [] (char c) { return !std::isspace(c); });
  
  return result;
}

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> left_trim(const std::basic_string<CharT, Traits>& str)
{
  decltype(str.size()) start_index = 0;
  for (; start_index != str.size(); ++start_index)
    if (!std::isspace(str[start_index]))
      break;

  return str.substr(start_index);
}

template<typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_string<CharT, Traits> right_trim(const std::basic_string<CharT, Traits>& str)
{
  auto end_index = str.size() - 1;

  for (; end_index >= 0; --end_index)
    if (!std::isspace(str[end_index]))
      break;

  if (end_index == 0) return std::string{};

  return str.substr(0, end_index + 1);
}
  
} // namespace sil 

#endif // OPENGL_TUTORIAL_SILENCE_UTILITY_H 