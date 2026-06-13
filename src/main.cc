#include "webview/webview.h"

#include <iostream>

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
        w.set_html(html);
        w.run();
    }
    catch (const webview::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}