#include "tit.hpp"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <sstream>

bool file_exists(const std::string& path) {
    std::ifstream f(path.c_str());
    return f.good();
}

std::string run_command(const std::string& cmd, bool throw_on_error) {
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        if (throw_on_error) throw std::runtime_error("popen() failed");
        return "";
    }

    std::ostringstream result;
    char buffer[128];
    while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
        result << buffer;
    }

    int status = pclose(pipe);
    if (throw_on_error && WEXITSTATUS(status) != 0) {
        throw std::runtime_error("Command failed: " + cmd);
    }

    return result.str();
}
