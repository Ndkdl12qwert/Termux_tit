#include "tit.hpp"
#include <iostream>

void print_help() {
    std::cout <<
R"(tit - Termux Tools InsTall

Usage:
  tit install <apk_file>     Install APK (auto-select pm/adb)
  tit uninstall <package>    Uninstall package
  tit devices                List ADB devices
  tit help                   Show this help

Environment auto-detected: ADB shell, Termux+ADB, root, or limited.
)";
}
