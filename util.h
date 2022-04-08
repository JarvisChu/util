#include <string>
#include <cstdint>

namespace Util {
    namespace Directory {
        bool CreateDir(const std::string& path, bool force = true);
        bool CopyDir(const std::string& from, const std::string& to, bool force = true);
        bool MoveDir(const std::string& from, const std::string& to, bool force = true);
        bool DeleteDir(const std::string& path);
        bool IsDirExists(const std::string& path);
    }

    namespace File {
        bool CreateFile(const std::string& path, bool force = true);
        bool CopyFile(const std::string& from, const std::string& to, bool force = true);
        bool MoveFile(const std::string& from, const std::string& to, bool force = true);
        bool DeleteFile(const std::string& path);
        bool IsFileExists(const std::string& path);
        uint64_t GetFileSize(const std::string& path);
    }

    namespace Time {

        // get current unix timestamp in seconds
        uint64_t Now();

        // get current unix timestamp in milliseconds
        uint64_t NowMs();

        // t: time to format, 0 indicates now
        // format: strftime format
        // return "2022-04-08 14:15:16"
        std::string GetFormatTime(time_t t = 0, std::string format = "%Y-%m-%d %H:%M:%S");

        // t: time to format, 0 indicates now
        // format: strftime format + split-char + %MS
        //         e.g %Y-%m-%d %H:%M:%S.%MS => 2022-04-08 14:15:16.123
        //             %Y-%m-%d %H:%M:%S-%MS => 2022-04-08 14:15:16-123
        // return "2022-04-08 14:15:16.123"
        std::string GetFormatTimeMs(time_t t = 0, std::string format = "%Y-%m-%d %H:%M:%S.%MS");
    }

}