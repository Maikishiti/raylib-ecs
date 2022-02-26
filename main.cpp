#include "Circle.h"
#include "include/raylib-cpp.hpp"
#include "include/raylib.h"
#include <fstream>
#include <iostream>
#include <string>

const bool DEBUG = 1;

// Main class <==--==--==--==--==
int main(void) {
  const int wWidth = 640;
  const int wHeight = 480;

  raylib::Window window(wWidth, wHeight, "Raylib");
  SetTargetFPS(60);

  Circle circle({370, 370}, {-3, -3}, 100.f, RED, "Circle 1");

  while (!window.ShouldClose()) {

    circle.Update();

    circle.collide(wWidth);
    circle.collide(wHeight, false);

    BeginDrawing();

    window.ClearBackground(RAYWHITE);
    circle.Draw();
    DrawFPS(0, 0);

    // if (DEBUG) {
    //   char text[20];
    //   sprintf(text, "%.2f : %.2f", circle.getX(), circle.getY());
    //   float textSize = MeasureText(text, 20);

    //   raylib::DrawText(text, circle.getX() - textSize / 2, circle.getY(), 20,
    //                    WHITE);
    // }

    EndDrawing();
  }

  return 0;
}
