document.addEventListener("keydown", function (event) {
  if (event.ctrlKey || event.metaKey) {
    switch (event.key) {
      case "+":
      case "-":
      case "=":
        event.preventDefault();
        break;
    }
  }
});

document.addEventListener(
  "wheel",
  function (event) {
    if (event.ctrlKey || event.metaKey) {
      event.preventDefault();
    }
  },
  { passive: false },
);

function popup() {
  const main = document.getElementById("main");
  main.classList.add("popup");
  const popup0 = document.getElementById("popup");
  popup0.classList.add("show");
  //popup0.classList.remove("show");
  // popup0
}
