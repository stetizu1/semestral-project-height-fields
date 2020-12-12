#include "HeightMap.h"


HeightMap::HeightMap(const HeightMapReader &reader, unsigned width, unsigned height, unsigned depth, const Material &material)
  : height(height), width(width), depth(depth), material(material) {
  auto imgHeight = reader.getImageHeight(), imgWidth = reader.getImageWidth();
  map = std::vector<std::vector<Cell>>(imgHeight - 1);
  for (auto row = 0; row < imgHeight - 1; row++) {
    map[row] = std::vector<Cell>(imgWidth - 1);
    for (auto col = 0; col < imgWidth - 1; col++) {
      float values[] = {
        reader.getIntensityAt(row, col),
        reader.getIntensityAt(row, col + 1),
        reader.getIntensityAt(row + 1, col),
        reader.getIntensityAt(row + 1, col + 1)
      };
      map[row][col] = {
        values[0], values[1], values[2], values[3],
        std::max(std::max(values[0], values[1]), std::max(values[2], values[3]))
      };
    }
  }
}

std::string HeightMap::to_string() const {
  auto H = std::to_string(height), W = std::to_string(width), D = std::to_string(depth);
  std::string s = "heightMap(\r\n";
  for (const auto &row : map) {
    s += "  ";
    for (const auto &val : row) {
      s += "{"
        + std::to_string(val.topLeft).substr(0, 4) + ","
        + std::to_string(val.topRight).substr(0, 4) + ","
        + std::to_string(val.bottomLeft).substr(0, 4) + ","
        + std::to_string(val.bottomRight).substr(0, 4) + " --> "
        + std::to_string(val.maxHeight).substr(0, 4) + "} ";
    }
    s += "\r\n";
  }
  s += ") with parameters (height, width, depth) set to " + H;
  return s;
}
std::ostream &operator<<(std::ostream &out, const HeightMap &h) {
  out << h.to_string();
  return out;
}

void HeightMap::setPosition(Point3d &point3D) {
  position = point3D;
}

const Point3d &HeightMap::getPosition() const {
  return position;
}

const Material &HeightMap::getMaterial() const {
  return material;
}

HasIntersection HeightMap::findIntersection(const Ray &ray) const {
  // todo
  // find intersection with bounding box of the height map
    // if there is none, return t
  // find sequence of cells
  // find if there is intersection with bounding box of the cell (min ray height < max cell height)
    // if there is none, continue
    // if there is, find intersection with triangles, if there is, return, else continue in sequence




  // delete this
  static float counter = 0;
  counter += 0.01f;

  if(counter < 100) {
    return HasIntersection::doesNotIntersect();
  }

  return HasIntersection(counter, Vector3d(counter, counter, counter).normalized());
}
