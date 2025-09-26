# Copilot Instructions for dzstep

This project contains a set of homework tasks, primarily implemented in JavaScript and C++. The structure is organized by task number, with each task typically having its own directory and script file. The main focus is on algorithmic exercises and interactive browser-based solutions.

## Project Structure
- `dz2.cpp`, `dz3.cpp`, ...: C++ solutions for some tasks.
- `html/dz1/`, `html/dz2/`, ...: Each folder contains a separate JavaScript solution (e.g., `script.js`) and sometimes an `index.html` for browser interaction.
- `html/dz6/script.js`: Contains all tasks 1-10 as commented functions, plus task10 implemented and active.
- `README.md`: Minimal project description.

## Key Patterns & Conventions
- **Task Functions**: Each task is implemented as a separate function (e.g., `task1`, `task2`, ...). Functions are often commented out except the current focus.
- **User Interaction**: Uses `prompt`, `alert`, and `console.log` for input/output. No advanced UI frameworks.
- **No Build System**: JavaScript runs directly in the browser; C++ files are standalone and not integrated.
- **No Automated Tests**: Manual testing via browser console and prompts.
- **No External Dependencies**: Pure JavaScript and C++ only.

## How to Add or Update Tasks
- For new tasks, add a new function in the relevant `script.js` file and comment/uncomment as needed.
- For C++ tasks, add a new `.cpp` file at the root.
- Keep user prompts and console output in Ukrainian for consistency.

## Example: Adding a New JS Task
```js
function task11() {
    // ...implementation...
}
```
Add to `html/dz6/script.js` or create a new folder under `html/` for a separate task.

## Debugging & Testing
- Open the relevant `index.html` in a browser and use the console for interaction.
- Use `console.log` for output and debugging.

## Integration Points
- No cross-file imports or module systems.
- Each script is self-contained.

## References
- See `html/dz6/script.js` for the most complete set of task patterns.
- See `README.md` for project intent.

---
*Update this file if project structure or conventions change.*
