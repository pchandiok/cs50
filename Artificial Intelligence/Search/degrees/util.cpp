#include <iostream>

using namespace std;

class Node 
{
    string state;
    string parent;
    string action;

    Node(string st, string pa, string ac)
    {
              state = st;
              parent = pa;
              action = ac;
    }
};

class StackFrontier
{
    char  *frontier = {};

    void add(Node node)
    {
        int len = *(&frontier + 1) - frontier;
        frontier[len] = node;
    }
};


// class StackFrontier():
//     def __init__(self):
//         self.frontier = []

//     def add(self, node):
//         self.frontier.append(node)

//     def contains_state(self, state):
//         return any(node.state == state for node in self.frontier)

//     def empty(self):
//         return len(self.frontier) == 0

//     def remove(self):
//         if self.empty():
//             raise Exception("empty frontier")
//         else:
//             node = self.frontier[-1]
//             self.frontier = self.frontier[:-1]
//             return node