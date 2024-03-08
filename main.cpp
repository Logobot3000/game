#include "engine/window.h"

void Start() {
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
}

void Update() {
    glClear(GL_COLOR_BUFFER_BIT);
}

int main() {
    Window window;
    window.Run(&Start, &Update);
    return 0;
}