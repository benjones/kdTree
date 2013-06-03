#include "kdTree.h"


struct simplePoint3{
  double x,y,z;
  const static int dimension = 3;
  double getDimension(int dim) const{
    switch(dim){
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    default:
      return std::numeric_limits<double>::quiet_NaN();
    }
  }
};

std::ostream& operator <<(std::ostream& outs, const simplePoint3& p){
  outs << p.x << ' ' << p.y << ' ' << p.z;
  return outs;
}

int main(int argc, char** argv){
  
  KDTree<simplePoint3> tree;
  std::vector<simplePoint3> pts{ {0,0,0},{1,1,1}, {-1, 3, 4}, {5, 6, 7}, {2, -6, 8}, {4, 5, -4},
										       {2, 3, 4}, 
											 {2, 5, 6}};
  tree.buildTree(pts);
  tree.dumpTreeInorder();
  
  std::cout << "searching near 0,0,0.1" << std::endl;
  auto closeNodes = tree.getPointsWithinCube({0, 0, 0.1}, 0.2);
  std::cout << "found" << std::endl;
  for(auto n : closeNodes){
    tree.dumpNode(n);
  }

  std::cout << "searching near 0.5,0.5,0.5" << std::endl;
  closeNodes = tree.getPointsWithinCube({0.5, 0.5, 0.5}, 0.7);
  std::cout << "found" << std::endl;
  for(auto n : closeNodes){
    tree.dumpNode(n);
  }

  std::cout << "min, x: " << std::endl;
  tree.dumpNode(tree.findMin(0));

  std::cout << "min, y: " << std::endl;
  tree.dumpNode(tree.findMin(1));
  std::cout << "min, z: " << std::endl;
  tree.dumpNode(tree.findMin(2));

  for(auto i = 0; i < pts.size() -1; ++i){
    std::cout << "deleting node " << i << std::endl;
    tree.deletePoint(i);
    tree.dumpTreeInorder();
  }

  std::cout << "inserting 2 points" << std::endl;
  tree.insertPoint({1, 4, 5});
  tree.dumpTreeInorder();
  tree.insertPoint({3, 8, 6});
  tree.dumpTreeInorder();
}
