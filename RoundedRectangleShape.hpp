#ifndef SFML_ROUNDEDRECTANGLESHAPE_HPP
#define SFML_ROUNDEDRECTANGLESHAPE_HPP

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <cmath>

class RoundedRectangleShape : public sf::Shape
{
public:
    explicit RoundedRectangleShape(const sf::Vector2f& size = sf::Vector2f(0, 0), float radius = 0, unsigned int cornerPointCount = 10);

    void setSize(const sf::Vector2f& size);
    const sf::Vector2f& getSize() const;
    void setCornersRadius(float radius);
    float getCornersRadius() const;
    void setCornerPointCount(unsigned int count);
    virtual std::size_t getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;

private:
    sf::Vector2f m_size;
    float m_radius;
    unsigned int m_cornerPointCount;
};

// Realization

inline RoundedRectangleShape::RoundedRectangleShape(const sf::Vector2f& size, float radius, unsigned int cornerPointCount) :
m_size(size),
m_radius(radius),
m_cornerPointCount(cornerPointCount)
{
    update();
}

inline void RoundedRectangleShape::setSize(const sf::Vector2f& size)
{
    m_size = size;
    update();
}

inline const sf::Vector2f& RoundedRectangleShape::getSize() const
{
    return m_size;
}

inline void RoundedRectangleShape::setCornersRadius(float radius)
{
    m_radius = radius;
    update();
}

inline float RoundedRectangleShape::getCornersRadius() const
{
    return m_radius;
}

inline void RoundedRectangleShape::setCornerPointCount(unsigned int count)
{
    m_cornerPointCount = count;
    update();
}

inline std::size_t RoundedRectangleShape::getPointCount() const
{
    return m_cornerPointCount * 4;
}

inline sf::Vector2f RoundedRectangleShape::getPoint(std::size_t index) const
{
    static const float pi = 3.141592654f;

    // determining angle (0-3)
    std::size_t corner = index / m_cornerPointCount;
    
    // Progress inside the current corner (0.0 до 1.0)
    float delta = (float)(index % m_cornerPointCount) / (m_cornerPointCount - 1);
    
    // Go around clockwise, starting from the upper-left corner
    float startAngle;
    sf::Vector2f center;

    switch (corner)
    {
        case 0: // left top (180° - 270°)
            center.x = m_radius;
            center.y = m_radius;
            startAngle = 180.f;
            break;
        case 1: // right top (270° - 360°)
            center.x = m_size.x - m_radius;
            center.y = m_radius;
            startAngle = 270.f;
            break;
        case 2: // right bottom (0° - 90°)
            center.x = m_size.x - m_radius;
            center.y = m_size.y - m_radius;
            startAngle = 0.f;
            break;
        case 3: // left bottom (90° - 180°)
            center.x = m_radius;
            center.y = m_size.y - m_radius;
            startAngle = 90.f;
            break;
    }

    // Calculating the angle for the current point
    float angle = (startAngle + delta * 90.f) * pi / 180.f;
    
    // Calculating the offset from the center
    float x = m_radius * std::cos(angle);
    float y = m_radius * std::sin(angle);

    return center + sf::Vector2f(x, y);
}

#endif // SFML_ROUNDEDRECTANGLESHAPE_HPP