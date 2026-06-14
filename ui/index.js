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

function open() {
  const main = document.getElementsByName("section")[0];
  main.classList.add("popup");
  const popup = document.getElementById("popup");
  popup.classList.add("show");
}
