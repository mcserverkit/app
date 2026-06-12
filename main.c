#include "webview/webview.h"
#include <stddef.h>

static const char html[] =
    "<head>"
    "   <style>"
    "       * {"
    "           margin: 0;"
    "           padding: 0;"
    "           color: #fff;"
    "           box-sizing: border-box;"
    "       }"
    "       @font-face {"
    "           font-family: \"Inter\";"
    "           src: url(\"resources/fonts/Inter-VariableFont_opsz,wght.ttf\");"
    "       }"
    "       body {"
    "           background-color: #000;"
    "           font-family: \"Inter\", Arial;"
    "       }"
    "       input {"
    "           width: 280px;"
    "           border: 2px solid #222;"
    "           border-radius: 5px;"
    "           background: #171717;"
    "           font-size: 14px;"
    "           padding: 8px;"
    "       }"
    "       button {"
    "           color: #000;"
    "           border: none;"
    "           padding: 8px 12px;"
    "           background: #fff;"
    "           cursor: pointer;"
    "           border-radius: 5px;"
    "           transition: 150ms ease-in-out;"
    "       }"
    "       button:hover {"
    "           background: #ddd;"
    "       }"
    "       section {"
    "           display: flex;"
    "           flex-direction: column;"
    "           align-items: center;"
    "       }"
    "       section > div {"
    "           display: flex;"
    "           flex-direction: row;"
    "           align-items: center;"
    "           gap: 8px;"
    "       }"
    "   </style>"
    "</head>"
    "<body>"
    "   <section>"
    "       <div>"
    "           <button>Create server</button>"
    "           <input type=\"text\" placeholder=\"Search Servers...\">"
    "       </div>"
    "   </section>"
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
    webview_set_size(w, 800, 500, WEBVIEW_HINT_NONE);
    webview_set_html(w, html);
    webview_run(w);
    webview_destroy(w);
    return 0;
}