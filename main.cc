#include "webview/webview.h"

#include <iostream>

constexpr const auto html =
    R"html(<head>
       <style>
           * {
               margin: 0;
               padding: 0;
               color: #fff;
               box-sizing: border-box;
           }
           @font-face {
               font-family: "Inter";
               src: url("resources/fonts/Inter-VariableFont_opsz,wght.ttf");
           }
           body {
               background-color: #000;
               font-family: "Inter", Arial;
           }
           input {
               width: 280px;
               border: 1px solid #222;
               border-radius: 5px;
               background: #171717;
               font-size: 14px;
               padding: 12px 14px;
           }
           input:hover {
               border-color: #444;
           }
           input:focus {
               outline: none;"
               border-color: #666;
           }
           button {
               color: #000;
               border: none;
               padding: 12px 14px;
               background: #fff;
               cursor: pointer;
               border-radius: 5px;
               transition: 150ms ease-in-out;
           }
           button:hover {
               background: #ddd;
           }
           section {
               margin-top: 20px;
               display: flex;
               flex-direction: column;
               align-items: center;
           }
           section > div {
               display: flex;
               flex-direction: row;
               align-items: center;
               gap: 8px;
           }
       </style>
    </head>
    <body>
       <section>
           <div>
               <button>Create server</button>
               <input type="text" placeholder="Search Servers...">
           </div>
       </section>
    </body>)html";

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
        w.set_size(480, 320, WEBVIEW_HINT_NONE);
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