#include <iostream>
#include "util.h"

int main()
{
    std::cout << "=== Test Util::Time ===" << std::endl;
    std::cout << time(NULL) << std::endl;
    std::cout << Util::Time::Now() << std::endl;
    std::cout << Util::Time::NowMs() << std::endl;
    std::cout << Util::Time::GetFormatTime() << std::endl;
    std::cout << Util::Time::GetFormatTime(0, "%Y-%m-%d-%H-%M-%S") << std::endl;
    std::cout << Util::Time::GetFormatTimeMs() << std::endl;
    return 1;
}