#include "Circle.h"
#include <string>

Circle::Circle(raylib::Vector2 position, raylib::Vector2 velocity, float radius,
               raylib::Color color, std::string name)
    : m_position(position), m_velocity(velocity), m_radius(radius),
      m_color(color), m_name(name) {}
Circle::~Circle() noexcept {}

// Tick <==
void Circle::Update() { m_position += m_velocity; }
void Circle::Draw() {
  DrawCircleV(m_position, m_radius, m_color);
  drawName();
}
void Circle::Tick() {
  Update();
  Draw();
}

// Collide <==
void Circle::collide(float xy, bool bX) {
  if (bX) {
    if (getNextX() + getRadius() >= xy) {
      m_position.x = xy - getRadius();
    }
    if (getNextX() - getRadius() <= 0) {
      m_position.SetX(getRadius());
    }
    if (getNextX() + getRadius() >= xy || getNextX() - getRadius() <= 0) {
      setVX(getVX() * -1);
    }
  } else {
    if (getNextY() + getRadius() >= xy) {
      m_position.y = xy - getRadius();
    }
    if (getNextY() - getRadius() <= 0) {
      m_position.SetY(getRadius());
    }
    if (getNextY() + getRadius() >= xy || getNextY() - getRadius() <= 0) {
      setVY(getVY() * -1);
    }
  }
}

void Circle::drawName() {
  float nameSize = MeasureText(m_name.c_str(), 20);
  raylib::DrawText(m_name.c_str(), getX() - nameSize / 2, getY(), 20, WHITE);
}

// Getters and Setters <==
float Circle::getX() { return m_position.x; }
float Circle::getY() { return m_position.y; }
float Circle::getVX() { return m_velocity.x; }
float Circle::getVY() { return m_velocity.y; }
float Circle::getNextX() { return m_position.x + m_velocity.x; }
float Circle::getNextY() { return m_position.y + m_velocity.y; }
float Circle::getRadius() { return m_radius; }
raylib::Vector2 Circle::getPosition() { return m_position; }
raylib::Vector2 Circle::getVelocity() { return m_velocity; }

void Circle::setX(float x) { m_position.SetX(x); }
void Circle::setY(float y) { m_position.SetY(y); }
void Circle::setVX(float x) { m_velocity.SetX(x); }
void Circle::setVY(float y) { m_velocity.SetY(y); }
