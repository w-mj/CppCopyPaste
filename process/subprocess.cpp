#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <sstream>

using namespace std;

class subprocess {
public:
    static std::string call(const std::string& cmd) {
        std::array<char, 128> buffer{};
        std::stringstream ss;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            ss << buffer.data();
        }
        return ss.str();
    }
};

int main() {
    pid_t pid = getpid();
    char buf[1024];
    snprintf(buf, 1024, "ls -la /proc/%d/fd", pid);
    cout << subprocess::call(buf) << endl;
}