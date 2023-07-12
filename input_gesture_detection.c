#include <raylib.h>

#define MAX_GESTURE_STRINGS 20

int main(void) {
    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "Input Gesture Detection");

    Vector2 touch_position = {0, 0};
    Rectangle touch_area = {220, 10, screen_width - 230.0f,
                            screen_height - 20.0f};

    int gestures_count = 0;
    char gesture_strings[MAX_GESTURE_STRINGS][32];

    int current_gesture = GESTURE_NONE;
    int last_gesture = GESTURE_NONE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        last_gesture = current_gesture;
        current_gesture = GetGestureDetected();
        touch_position = GetTouchPosition(0);

        if (CheckCollisionPointRec(touch_position, touch_area) &&
            (current_gesture != GESTURE_NONE)) {
            if (current_gesture != last_gesture) {
                switch (current_gesture) {
                case GESTURE_TAP:
                    TextCopy(gesture_strings[gestures_count], "GESTURE TAP");
                    break;
                case GESTURE_DOUBLETAP:
                    TextCopy(gesture_strings[gestures_count],
                             "GESTURE DOUBLE TAP");
                    break;
                case GESTURE_HOLD:
                    TextCopy(gesture_strings[gestures_count], "GESTURE HOLD");
                    break;
                case GESTURE_DRAG:
                    TextCopy(gesture_strings[gestures_count], "GESTURE DRAG");
                    break;
                case GESTURE_SWIPE_RIGHT:
                    TextCopy(gesture_strings[gestures_count],
                             "GESTURE SWIPE RIGHT");
                    break;
                case GESTURE_SWIPE_LEFT:
                    TextCopy(gesture_strings[gestures_count],
                             "GESTURE SWIPE LEFT");
                    break;
                case GESTURE_SWIPE_UP:
                    TextCopy(gesture_strings[gestures_count],
                             "GESTURE SWIPE UP");
                    break;
                case GESTURE_SWIPE_DOWN:
                    TextCopy(gesture_strings[gestures_count],
                             "GESTURE SWIPE DOWN");
                    break;
                case GESTURE_PINCH_IN:
                    TextCopy(gesture_strings[gestures_count],
                             "GESTURE PINCH IN");
                    break;
                case GESTURE_PINCH_OUT:
                    TextCopy(gesture_strings[gestures_count],
                             "GESTURE PINCH OUT");
                    break;
                default:
                    break;
                }
                gestures_count++;

                if (gestures_count >= MAX_GESTURE_STRINGS) {
                    for (int i = 0; i < MAX_GESTURE_STRINGS; ++i) {
                        TextCopy(gesture_strings[i], "\0");
                    }

                    gestures_count = 0;
                }
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangleRec(touch_area, GRAY);
        DrawRectangle(225, 15, screen_width - 240, screen_height - 30,
                      RAYWHITE);

        DrawText("GESTURE TEST AREA", screen_width - 270, screen_height - 40,
                 20, Fade(GRAY, 0.5f));

        for (int i = 0; i < gestures_count; ++i) {
            if (i % 2 == 0) {
                DrawRectangle(10, 30 + 20 * i, 200, 20, Fade(LIGHTGRAY, 0.5f));
            } else {
                DrawRectangle(10, 30 + 20 * 1, 200, 20, Fade(LIGHTGRAY, 0.3f));
            }

            if (i < gestures_count - 1) {
                DrawText(gesture_strings[i], 35, 36 + 20 * i, 10, DARKGRAY);
            } else {
                DrawText(gesture_strings[i], 35, 36 + 20 * i, 10, MAROON);
            }
        }

        DrawRectangleLines(10, 29, 200, screen_height - 50, GRAY);
        DrawText("DETECTED GESTURES", 50, 15, 10, GRAY);

        if (current_gesture != GESTURE_NONE) {
            DrawCircleV(touch_position, 30, MAROON);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
