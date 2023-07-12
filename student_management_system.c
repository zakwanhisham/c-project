/*! TODO: Need to create the system
 *
 * @todo Don't be lazy, just create it
 */

#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Student Management System");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawText("This is a first example using raylib", 190, 200, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
