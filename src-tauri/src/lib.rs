// Learn more about Tauri commands at https://tauri.app/develop/calling-rust/
#[tauri::command]
fn install(version: &str) -> Option<String> {
    mcserverkit::install(version)
}

#[tauri::command]
fn create_server(name: &str) -> Option<String> {
    mcserverkit::create(name, true)
}

#[tauri::command]
fn start_server(name: &str) -> Option<String> {
    mcserverkit::start(name, "1024M")
}

#[cfg_attr(mobile, tauri::mobile_entry_point)]
pub fn run() {
    tauri::Builder::default()
        .plugin(tauri_plugin_opener::init())
        .invoke_handler(tauri::generate_handler![
            install,
            create_server,
            start_server
        ])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
