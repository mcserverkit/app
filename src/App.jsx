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
      </nav>
      <main>
        {page === "SERVERS" ? (
          <>
            <form
              className="row"
              onSubmit={(e) => {
                e.preventDefault();
                create_server();
              }}
            >
              <input
                id="greet-input"
                onChange={(e) => setName(e.currentTarget.value)}
                placeholder="Server Name"
              />
              <button type="submit">Create Server</button>
            </form>
            <p>{err}</p>
            <p>
              This app is not affiliated with Microsoft,{" "}
              <a href="https://github.com/mcserverkit" target="_blank">
                MCServerKit
              </a>
            </p>
          </>
        ) : (
          <>Plugins coming soon...</>
        )}
      </main>
    </>
  );
}

export default App;
