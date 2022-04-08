#include "util.h"

#include <iostream>
#include <chrono>

namespace Util {
    namespace Directory {
    }

    namespace File {
    }

    namespace Time {

        uint64_t Now() {
            return time(NULL);
        }

        uint64_t NowMs(){
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
            return ms.count();
        }

        std::string GetFormatTime(time_t t /*= 0*/, std::string format /*= "%Y-%m-%d %H:%M:%S"*/){
            if(t == 0) t = time(NULL);

            char ch[64] = { 0 };
            strftime(ch, sizeof(ch) - 1, format.c_str(), localtime(&t));
            return std::string(ch);
        }

        std::string GetFormatTimeMs(time_t t /*= 0*/, std::string format /*= "%Y-%m-%d %H:%M:%S.%MS"*/){
            if(format.size() <= 4) {
                std::cerr << "invalid format" << std::endl;
                return "";
            }

            std::string formatSec = format.substr(0, format.size()-4); // %Y-%m-%d %H:%M:%S
            std::string splitChar = format.substr(format.size()-4, 1);   // .
            std::string formatMs = format.substr(format.size()-3);           // %MS

            if(formatMs != "%MS") {
                std::cerr << "invalid format" << std::endl;
                return "";
            }

            if(t == 0) t = time(NULL);
            char ch[64] = { 0 };
            strftime(ch, sizeof(ch) - 1, formatSec.c_str(), localtime(&t));

            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

            return std::string(ch) + splitChar + std::to_string(ms.count() - t*1000);
        }
    }
}