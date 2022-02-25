#include "logger.hpp"
#include "paths.hpp"
#include "translation.hpp"

static std::string translation_db[UINT16_MAX];

namespace translation {

void load_translation(const char *lang_code) {
  auto bp = paths::get_config().m_base_path / "lang" /
            fmt::format("{}.csv", lang_code);

  FILE *file = fopen(bp.string().c_str(), "r");

  while (!feof(file)) {
    uint32_t code;
    char str[65536];
    fgets(str, sizeof(str), file);

    int n = sscanf(str, "%u;%65536[^\n]", &code, &str);

    if (n != 2)
      continue;

    // Take the code MOD 16 bit unsigned int limit to avoid OOB memory writes
    uint16_t code16 = code % UINT16_MAX;
    translation_db[code16] = std::string(str);
  }

  // Output 1st value in DB as "greeting"
  LOG_I("[Translation] {}", translation_db[0]);

  fclose(file);
}

std::string get_translated(const translation_handle handle) {
  std::string str = translation_db[handle];

  if (!str.empty()) {
    return str;
  } else {
    // Generate a placeholder if value does not exist
    std::string placeholder = "text." + std::to_string(handle);

    LOG_W("Could not find string for code {}! Using placeholder {}!", handle,
          placeholder);
    return placeholder;
  }
}

} // namespace translation