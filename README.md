kdTree
======

C++ templated KD-Tree implementation

This is a header only implementation of a KD-Tree spatial data structure.  You just need to provide a 
vector type with a known-at-compile-time "dimension" field, and a double getDimension(size_t dimension) method.

Currently the following operations are supported:
- Create from vector of points
- Find points within cube centered at a point
- Delete Point from tree (but not from the internal list of points)
- A traversal method taking an arbitrary function parameter

I've used it successfully to prune a set of points by removing neighbors that are too close.
