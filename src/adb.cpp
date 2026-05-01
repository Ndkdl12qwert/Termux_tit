#include "tit.hpp"
#include <unistd.h>
#include <fstream>
#include <string>

RuntimeMode detect_runtime_mode() {
    // Check if in ADB shell (on device)
    std::ifstream cmdline("/proc/cmdline");
    std::string line;
    if (cmdline.is_open()) {
        std::getline(cmdline, line);
        if (line.find("ro.debuggable=1") != std::string::npos) {
            return RuntimeMode::ADB_SHELL;
        }
    }

    // Check if running as root
    if (getuid() == 0) {
        return RuntimeMode::ROOT;
    }

    // Check if ADB is available and connected from Termux
    try {
        std::string output = run_command("adb devices 2>/dev/null", false);
        if (output.find("\tdevice") != std::string::npos) {
            return RuntimeMode::TERMUX_ADB;
        }
    } catch (...) {}

    return RuntimeMode::LIMITED;
}
