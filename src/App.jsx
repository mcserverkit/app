import { useState } from "react";
import { invoke } from "@tauri-apps/api/core";
import "./App.css";

function App() {
  const [err, setError] = useState("");
  const [name, setName] = useState("");

  async function create_server() {
    // Learn more about Tauri commands at https://tauri.app/develop/calling-rust/
    setError(await invoke("create_server", { name }));
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
                create_server();
              }}
            >
              <input
                autoComplete="off"
                id="greet-input"
                onChange={(e) => setName(e.currentTarget.value)}
                placeholder="Server Name"
              />
              <button type="submit">Create Server</button>
            </form>
            <div>
              <p>{err}</p>
            </div>
          </>
        ) : (
          <>Plugins coming soon...</>
        )}
      </main>
    </>
  );
}

export default App;
