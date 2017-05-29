'''
Paige Eckstein
Applied Discrete Mathematics
5/29/17
Dijkstra's Algorithm to find shortest path
'''

import sys  #for maxint
import heapq  #heapq = priority queue


#==============================================================================
#================================  Vertex  ====================================
#==============================================================================
class Vertex:
    #initializer
    def __init__(self, node):
        self.id = node

        #empty dictionary to hold neighboring nodes in the form id : cost
        self.adjacent = {}

        #initialize to max distance for all nodes
        self.distance = sys.maxint

        #mark all nodes as unvisited
        self.visited = False

        #predecessor node
        self.previous = None

    def add_neighbor(self, neighbor, weight=0):
        self.adjacent[neighbor] = weight

    #get adjacent node ids
    def get_connections(self):
        return self.adjacent.keys()

    #id is node letter ('a', 'b', etc)
    def get_id(self):
        return self.id

    #weight = cost to travel
    def get_weight(self, neighbor):
        return self.adjacent[neighbor]

    def set_distance(self, dist):
        self.distance = dist

    def get_distance(self):
        return self.distance

    def set_previous(self, prev):
        self.previous = prev

    def set_visited(self):
        self.visited = True


#==============================================================================
#================================  Graph  =====================================
#==============================================================================
class Graph:
    #initializer
    def __init__(self):
        #empty dictionary that will hold vertices
        self.vertices = {}
        self.num_vertices = 0

    def __iter__(self):
        return iter(self.vertices.values())

    def add_vertex(self, node):
        self.num_vertices += 1
        new_vertex = Vertex(node)
        self.vertices[node] = new_vertex
        return new_vertex

    def get_vertex(self, n):
        if n in self.vertices:
            return self.vertices[n]
        else:
            return None

    def add_edge(self, frm, to, cost=0):
        if frm not in self.vertices:
            self.add_vertex(frm)
        if to not in self.vertices:
            self.add_vertex(to)
        self.vertices[frm].add_neighbor(self.vertices[to], cost)
        self.vertices[to].add_neighbor(self.vertices[frm], cost)

    def get_vertices(self):
        return self.vertices.keys()

    def set_previous(self, current):
        self.previous = current

    def get_previous(self):
        return self.previous


#==============================================================================
#================================  Dijkstra  ==================================
#==============================================================================
def dijkstra(aGraph, start, target):
    #initial distance for start node
    start.set_distance(0)
    #put tuple pair into priority queue
    unvisited = [(v.get_distance(), v) for v in aGraph]
    #heapify converts list to heap
    heapq.heapify(unvisited)

    while len(unvisited):
        #pop vertex with smallest distance
        uv = heapq.heappop(unvisited)
        current = uv[1]
        #once all neighbors have been considered, mark current node as visited
        current.set_visited()

        for next in current.adjacent:
            #if visited, skip
            if next.visited:
                continue
            new_dist = current.get_distance() + current.get_weight(next)

            if new_dist < next.get_distance():
                #if previous distance was greater, change distance to smaller
                next.set_distance(new_dist)
                next.set_previous(current)


#==============================================================================
#==================================  Main  ====================================
#==============================================================================
def shortest_path(v, path):
    if v.previous:
        path.append(v.previous.get_id())
        shortest_path(v.previous, path)
    return


def main():
    g = Graph()

    g.add_vertex('a')
    g.add_vertex('b')
    g.add_vertex('c')
    g.add_vertex('d')
    g.add_vertex('e')

    g.add_edge('a', 'b', 2)
    g.add_edge('a', 'c', 3)
    g.add_edge('a', 'd', 1)
    g.add_edge('b', 'e', 5)
    g.add_edge('c', 'e', 3)
    g.add_edge('d', 'e', 6)

    dijkstra(g, g.get_vertex('a'), g.get_vertex('e'))

    target = g.get_vertex('e')
    path = [target.get_id()]
    shortest_path(target, path)
    print('The shortest path: %s' % (path[::-1]))


main()
