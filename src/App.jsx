import { useState } from "react";
import { invoke } from "@tauri-apps/api/core";
import "./App.css";

function App() {
  const [err, setError] = useState("");
  const [servers, setServers] = useState([]);

  async function create_server(name) {
    // Learn more about Tauri commands at https://tauri.app/develop/calling-rust/
    const e = await invoke("create_server", { name });

    if (e != null) {
      setError(e);
    } else {
      setServers([...servers, name]);
    }
  }

  async function start_server(name) {
    await invoke("start_server", { name });
  }

  const [page, setPage] = useState("SERVERS");
  return (
    <>
      <nav>
        <button onClick={() => setPage("SERVERS")}>Servers</button>
        <button onClick={() => setPage("PLUGINS")}>Plugins</button>
        <a href="https://github.com/mcserverkit" target="_blank">
          <button>
            GitHub
            <svg
              width="16"
              height="16"
              viewBox="0 0 8 8"
              xmlns="http://www.w3.org/2000/svg"
            >
              <path d="M0 2H3V3H1V7H5V5H6V8H0V2Z" />
              <path d="M4 4V5H3V4H4V3H5V2H6V1H5V0H8V3H7V2H6V3H5V4H4Z" />
            </svg>
          </button>
        </a>
      </nav>
      <main>
        {page === "SERVERS" ? (
          <>
            <form
              onSubmit={(e) => {
                e.preventDefault();
                create_server(e.currentTarget.name.value);
              }}
            >
              <input
                autoComplete="off"
                id="greet-input"
                placeholder="Server Name"
              />
              <button type="submit">Create Server</button>
            </form>
            <p>{err}</p>

            {servers.map((server) => {
              return (
                <div className="card" key={server}>
                  <section>
                    <h2>{server}</h2>
                    <p>Description unavailable</p>
                  </section>
                  <section>
                    <button>Manage</button>
                    <button
                      onClick={() => {
                        start_server(server);
                      }}
                    >
                      Start
                    </button>
                  </section>
                </div>
              );
            })}
          </>
        ) : (
          <>Plugins coming soon...</>
        )}
      </main>
    </>
  );
}

export default App;
