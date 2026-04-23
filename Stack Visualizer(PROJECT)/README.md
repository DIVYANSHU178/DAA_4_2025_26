# Stack Visualizer

A simple stack visualizer built with C++ and WebAssembly using Emscripten.

## Project Structure

- src/ - C++ source code
- web/ - HTML, CSS, JS for the UI
- emsdk/ - Emscripten SDK (cloned and installed)
- uild/ - (empty, compiled files are in web/)

## Requirements

- Emscripten SDK (already included in emsdk/)

## Setup

1. Activate Emscripten:
   cd emsdk
   .\emsdk_env.ps1

## Build

From the project root:

emcc src/stack.cpp -o web/stack.js -s EXPORTED_FUNCTIONS=\"['_initStack','_isEmpty','_isFull','_push','_pop','_peek','_getStack']\" -s EXPORTED_RUNTIME_METHODS=\"['ccall','cwrap']\"

## Run

Open web/index.html in a web browser.

## Usage

1. Set max stack size (1-20)
2. Click 'Initialize Stack'
3. Enter a number and click 'Push'
4. Use 'Pop', 'Peek', 'Is Empty' buttons

## Data Flow

1. User interacts with HTML UI
2. JavaScript calls WebAssembly functions via Module.ccall
3. C++ executes stack operations
4. JavaScript updates UI display

## Features

- Manual C++ stack implementation
- Push, Pop, Peek, IsEmpty operations
- Visual stack display with animations
- Error handling for overflow/underflow
- Configurable stack size

## Optional: Undo/Redo

To add undo/redo, maintain a history stack in C++.

Extend the Stack class with a history Stack<Stack*> or something.

On each operation, save current state.

For undo, restore previous state.
