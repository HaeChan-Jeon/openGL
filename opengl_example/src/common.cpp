#include "common.h"
#include <fstream>
#include <sstream>

std::optional<std::string> LoadTextFile(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        spdlog::debug(FMT_STRING("Loading text file: {}"), filename);
        return {};
    }

    std::stringstream text;
    text << fin.rdbuf();
    return text.str();
}