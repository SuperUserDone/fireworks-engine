#pragma once

#include <stdint.h>

typedef uint16_t translation_handle;

namespace translation {
/**
 * \brief Load the translation file refrenced by lang_code
 *
 * \param lang_code code for the translation
 */
extern void load_translation(const char* lang_code);

/**
 * \brief Get the translated string
 *
 * \param handle translation handle to refrence a string in the DB.
 * \return const char* translated value
 */
extern std::string get_translated(const translation_handle handle);
}  // namespace translation
