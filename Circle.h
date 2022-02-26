#pragma once
#include "include/Vector2.hpp"
#include "include/raylib-cpp.hpp"
#include <string>

// Circle class <--
class Circle {
  raylib::Vector2 m_position;
  raylib::Vector2 m_velocity;
  raylib::Color m_color;
  std::string m_name;
  float m_radius;

public:
  Circle(raylib::Vector2 position, raylib::Vector2 velocity, float radius,
         raylib::Color color, std::string name);
  ~Circle() noexcept;

  Circle(const Circle &) = delete;
  Circle &operator=(const Circle &) = delete;

  void Update();
  void Draw();
  void Tick();

  void collide(float xy, bool bX = true);
  void collide(float x, float y);
  void collide(raylib::Vector2 point);

  float getX();
  float getY();
  float getVX();
  float getVY();
  float getNextX();
  float getNextY();
  float getRadius();
  raylib::Vector2 getPosition();
  raylib::Vector2 getVelocity();

  void setX(float x);
  void setY(float y);
  void setVX(float x);
  void setVY(float y);

  void drawName();
};
