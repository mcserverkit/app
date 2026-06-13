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
