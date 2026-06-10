#include "webview/webview.h"
#include <stddef.h>

static const char html[] =
    "<body style=\"background-color:#222;color:white;font-family:Arial;\">"
    "<nav style=\"background:#111;top:0;left:0;position:fixed;width:100%;height:64px;\">"
    "<div>"
    "<button>"
    "MCServerKit"
    "</button>"
    "</div>"
    "</nav>"
    "</body>";

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow)
{
    (void)hInst;
    (void)hPrevInst;
    (void)lpCmdLine;
    (void)nCmdShow;
#else
int main(void)
{
#endif
    webview_t w = webview_create(0, NULL);
    webview_set_title(w, "MCServerKit GUI");
    webview_set_size(w, 480, 320, WEBVIEW_HINT_NONE);
    webview_set_html(w, html);
    webview_run(w);
    webview_destroy(w);
    return 0;
}