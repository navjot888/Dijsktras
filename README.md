# Title :Dijsktras Algorithm
#
#
# Purpose :
# C++ Program for Dijkstra's shortest path algorithm for adjacency list representation of grap
#
#
# Algorithm:
# The program calculates shortest distance.
# The program is for calculating the shortest distance of the undirected graphs.
# The program finds shortest distances from the source to all the other vertices.
#
#
# Testing :
# To test the program, we will be using two lists. 
# One list is for storing vertices which have been considered as the shortest path tree.
# And the other will hold the vertices which are not considered yet. 
# In each phase of the algorithm, we will find the unconsidered vertex and which has the minimum distance from the source.
#
#
# As an example:
# 0 --> 1 3 --> 2 6
# 1 --> 0 3 --> 2 2 --> 3 1
# 2 --> 1 6 --> 1 2 --> 3 1 --> 4 4 --> 5 2
# 3 --> 1 1 --> 2 1 --> 4 2 --> 6 4
# 4 --> 2 4 --> 3 2 --> 5 2 --> 6 1
# 5 --> 2 2 --> 4 2 --> 6 1
# 6 --> 3 4 --> 4 1 --> 5 1
#
#
#
#
# Output: 
# 0 to 1, Cost: 3 Previous: 0
# 0 to 2, Cost: 5 Previous: 1
# 0 to 3, Cost: 4 Previous: 1
# 0 to 4, Cost: 6 Previous: 3
# 0 to 5, Cost: 7 Previous: 2
# 0 to 6, Cost: 7 Previous: 4
#
#
#
#
### Author:
### NAvjot Kaur
