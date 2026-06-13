#include "webview/webview.h"

#include <iostream>
#include <filesystem>
#include <string>

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
        w.set_size(480, 320, WEBVIEW_HINT_FIXED);

        auto file = std::filesystem::absolute("ui/index.html");
        auto html = std::string("file:///") + file.generic_string();
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