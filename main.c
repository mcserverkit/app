#include "webview/webview.h"
#include <stddef.h>

static const char html[] =
    "<head>\n"
    "   <style>\n"
    "       * {\n"
    "           margin: 0;\n"
    "           padding: 0;\n"
    "           color: #fff;\n"
    "           box-sizing: border-box;\n"
    "       }\n"
    "       @font-face {\n"
    "           font-family: \"Inter\";\n"
    "           src: url(\"resources/fonts/Inter-VariableFont_opsz,wght.ttf\");\n"
    "       }\n"
    "       body {\n"
    "           background-color: #000;\n"
    "           font-family: \"Inter\", Arial;\n"
    "       }\n"
    "       input {\n"
    "           width: 280px;\n"
    "           border: 2px solid #222;\n"
    "           border-radius: 5px;\n"
    "           background: #171717;\n"
    "           font-size: 14px;\n"
    "           padding: 8px;\n"
    "       }\n"
    "       button {\n"
    "           color: #000;\n"
    "           border: none;\n"
    "           padding: 8px 12px;\n"
    "           background: #fff;\n"
    "           cursor: pointer;\n"
    "           border-radius: 5px;\n"
    "           transition: 150ms ease-in-out;\n"
    "       }\n"
    "       button:hover {\n"
    "           background: #ddd;\n"
    "       }\n"
    "       section {\n"
    "           margin-top: 20px;\n"
    "           display: flex;\n"
    "           flex-direction: column;\n"
    "           align-items: center;\n"
    "       }\n"
    "       section > div {\n"
    "           display: flex;\n"
    "           flex-direction: row;\n"
    "           align-items: center;\n"
    "           gap: 8px;\n"
    "       }\n"
    "   </style>\n"
    "</head>\n"
    "<body>\n"
    "   <section>\n"
    "       <div>\n"
    "           <button>Create server</button>\n"
    "           <input type=\"text\" placeholder=\"Search Servers...\">\n"
    "       </div>\n"
    "   </section>\n"
    "</body>\n";

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