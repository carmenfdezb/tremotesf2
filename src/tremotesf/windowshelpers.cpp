#include "windowshelpers.h"

#include <stdexcept>

#include <windows.h>
#include <VersionHelpers.h>

#include "libtremotesf/formatters.h"

namespace tremotesf {
    namespace {
        bool isWindowsVersionOrGreater(DWORD major, DWORD minor, DWORD build) {
            OSVERSIONINFOEXW info{};
            info.dwOSVersionInfoSize = sizeof(info);
            info.dwMajorVersion = major;
            info.dwMinorVersion = minor;
            info.dwBuildNumber = build;
            const auto conditionMask = VerSetConditionMask(
                VerSetConditionMask(
                    VerSetConditionMask(
                        0, VER_MAJORVERSION, VER_GREATER_EQUAL
                    ),
                    VER_MINORVERSION, VER_GREATER_EQUAL
                ),
                VER_BUILDNUMBER, VER_GREATER_EQUAL
            );
            return VerifyVersionInfoW(&info, VER_MAJORVERSION | VER_MINORVERSION | VER_BUILDNUMBER, conditionMask) != FALSE;
        }
    }

    bool isRunningOnWindows10OrGreater() {
        static const bool is = IsWindows10OrGreater();
        return is;
    }

    bool isRunningOnWindows10_1607OrGreater() {
        static const bool is = isWindowsVersionOrGreater(10, 0, 14393);
        return is;
    }

    bool isRunningOnWindows10_1809OrGreater() {
        static const bool is = isWindowsVersionOrGreater(10, 0, 17763);
        return is;
    }

    bool isRunningOnWindows10_2004OrGreater() {
        static const bool is = isWindowsVersionOrGreater(10, 0, 19041);
        return is;
    }

    bool isRunningOnWindows11OrGreater() {
        static const bool is = isWindowsVersionOrGreater(10, 0, 22000);
        return is;
    }

    void checkWin32Bool(int win32BoolResult, std::string_view functionName) {
        if (win32BoolResult != FALSE) return;
        const auto error = GetLastError();
        const winrt::hstring message = winrt::hresult_error(HRESULT_FROM_WIN32(error)).message();
        throw std::system_error(
            static_cast<int>(error),
            std::system_category(),
            fmt::format("{} failed with: {}", functionName, message)
        );
    }

    void checkHResult(int32_t hresult, std::string_view functionName) {
        if (hresult == S_OK) return;
        const winrt::hstring message = winrt::hresult_error(hresult).message();
        throw winrt::hresult_error(
            hresult,
            QString::fromStdString(fmt::format("{} failed with: {}", functionName, message)).toStdWString()
        );
    }
}
