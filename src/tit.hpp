#ifndef TIT_HPP
#define TIT_HPP

#include <string>
#include <vector>
#include <stdexcept>

enum class RuntimeMode {
    ADB_SHELL,
    TERMUX_ADB,
    ROOT,
    LIMITED
};

RuntimeMode detect_runtime_mode();
void print_help();

void handle_install(const std::vector<std::string>& args);
void handle_uninstall(const std::vector<std::string>& args);
void handle_devices();

bool file_exists(const std::string& path);
std::string run_command(const std::string& cmd, bool throw_on_error = true);

#endif