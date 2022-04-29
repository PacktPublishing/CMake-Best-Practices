#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char **) {

using namespace std::literals::chrono_literals;
std::this_thread::sleep_for(0.5s);

return 0;

}