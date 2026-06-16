#include "webview/webview.h"
extern "C"
{
#include "mcserverkit.h"
}

#include <iostream>
#include <filesystem>
#include <string>

#ifdef __APPLE__
// https://stackoverflow.com/questions/42600770/chdir-to-the-location-of-the-app-bundle-in-c-macos-application
#include <unistd.h>      // for chdir
#include <libgen.h>      // for dirname
#include <mach-o/dyld.h> // for _NSGetExecutablePath
#include <limits.h>      // for PATH_MAX?
#endif
#ifdef _WIN32
int WINAPI WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/,
                   LPSTR /*lpCmdLine*/, int /*nCmdShow*/)
{
#else
int main()
{
#endif
    try
    {
        webview::webview w(false, nullptr);
        w.set_title("MCServerKit GUI");
        w.set_size(480, 480, WEBVIEW_HINT_FIXED);
#ifdef __APPLE__
        char path[PATH_MAX];
        uint32_t pathLen = sizeof(path);
        int err = _NSGetExecutablePath(path, &pathLen);
        assert(!err);

        // Switch to the directory of the actual binary
        chdir(dirname(path));
        // and then go up three directories to get to the folder of the .app bundle
        chdir("../Resources");
#endif
        auto file = std::filesystem::absolute("ui/index.html");
        auto html = std::string("file:///") + file.generic_string();
        w.bind("test", [](auto args)
               {
            std::string name = webview::json_parse(args.c_str(), "$[0]", 0);
            Start(name.data(), NULL);
            return ""; });
        w.navigate(html);
        w.run();
    }
    catch (const webview::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}