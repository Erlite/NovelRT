// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#include <NovelRT.h>

namespace NovelRT::Maths {
  GeoBounds::GeoBounds(const GeoVector<float>& position, const GeoVector<float>& size, float rotation) :
    _position(position),
    _rotation(rotation),
    _size(size) {
  }

  bool GeoBounds::pointIsWithinBounds(const GeoVector<float>& point) const {
    auto corner0 = getCornerInWorldSpace(0);
    auto corner2 = getCornerInWorldSpace(2);

    if (point.getX() >= corner0.getX() && point.getX() <= corner2.getX() && point.getY() <= corner2.getY()
      && point.getY() >= corner0.getY())
      return true;

    return false;
  }

  GeoVector<float> GeoBounds::getCornerInLocalSpace(int index) const {
    GeoVector<float> returnValue;
    auto size = getSize();
    switch (index) {
    case 0:
      returnValue = GeoVector<float>(-(size.getX() / 2), -(size.getY() / 2));
      break;
    case 1:
      returnValue = GeoVector<float>(+(size.getX() / 2), -(size.getY() / 2));
      break;
    case 2:
      returnValue = GeoVector<float>(+(size.getX() / 2), +(size.getY() / 2));
      break;
    case 3:
      returnValue = GeoVector<float>(-(size.getX() / 2), +(size.getY() / 2));
      break;
    }

    returnValue.rotateToAngleAroundPoint(getRotation(), getPosition());
    return returnValue;
  }

  GeoVector<float> GeoBounds::getCornerInWorldSpace(int index) const {
    return _position + getCornerInLocalSpace(index);
  }

  GeoVector<float> GeoBounds::getPosition() const {
    return _position;
  }

  void GeoBounds::setPosition(const GeoVector<float>& value) {
    _position = value;
  }

  GeoVector<float> GeoBounds::getSize() const {
    return _size;
  }
  void GeoBounds::setSize(const GeoVector<float>& value) {
    _size = value;
  }
  float GeoBounds::getRotation() const {
    return _rotation;
  }
  void GeoBounds::setRotation(float value) {
    _rotation = value;
  }
}
