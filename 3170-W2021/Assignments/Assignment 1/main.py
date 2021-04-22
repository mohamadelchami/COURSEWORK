import collections

class Vertex:
    def __init__(self, node):
        self.id = node
        self.discover = False
        self.leafs = {}
        self.ancestors = []

    def __str__(self):
        return self.id + 'leaves: ' + str([x.id for x in self.leafs])

    def addLeaf(self, leaf, time):
        self.leafs[leaf] = time

    def addAncestor(self, node):
        self.ancestors.append(node)

    def setDiscover(self):
        self.discovered = True

    def getLeafs(self):
        return self.leafs.keys()

    def getAncestors(self):
        return self.ancestors

    def getId(self):
        return self.id

    def getTime(self, leaf):
        return self.leafs[leaf]

    def isDiscovered(self):
        return self.discover

class Graph:
    def __init__(self):
        self.vertex_dictionary= {}
        self.edges = {}
        self.num_vertices = 0
        self.traversed = {}
        self.exact = collections.deque()
        self.traversal = collections.deque()
        
    def __iter__(self):
        return iter(self.vertex_dictionary.value())

    def addVertex(self, node):
        self.num_vertices = self.num_vertices + 1
        new_vertex = Vertex(node)
        self.vertex_dictionary[node] = new_vertex
        return new_vertex

    def addEdge(self, node, leaf, time):
        self.edges[(node, leaf)] = time

    def getEdgeTime(self, node, leaf):
        return self.edges[(node.getId(), leaf.getId())]

    def getVertex(self, node):
        return self.vertex_dictionary[node]

    def connectEdges(self, node, leaf, time):
        if node not in self.vertex_dictionary:
            self.addVertex(node)
        if leaf not in self.vertex_dictionary:
            self.addVertex(leaf)
        self.addEdge(node, leaf, time)
        self.vertex_dictionary[node].addLeaf(self.vertex_dictionary[leaf], time)
        self.vertex_dictionary[leaf].addAncestor(self.vertex_dictionary[node])

    def DFS(self, u):
        u.setDiscover()
        print(u.getId(), end='')
        for leaf in u.leafs:
            if not leaf.isDiscovered():
                self.DFS(leaf)
            else:
                return

    def BFS(self, root, goal):
        print("--- BFS SEARCH ----\n")
        queue = [root]
        traversedPath = []
        exactPath = []
        ancestors = {root: None}

        while len(queue) > 0:
            current = queue.pop(0)
            current.setDiscover();
            traversedPath.append(current.getId())

            if current == goal:
                i = current
                while i is not None:
                    exactPath.append(i.getId())
                    i = ancestors[i]
                break
            for leaf in current.leafs:
                if not leaf.isDiscovered():
                    queue.append(leaf)
                    if not ancestors.__contains__(leaf):
                        ancestors[leaf] = current

        exactPath.reverse()

        print("Traversal Path: ", end='')
        for i in traversedPath:
            print(i, end='')
        print("\n")
        print("Exact Path: ", end='')
        for i in exactPath:
            print(i, end='')

    def inner(self, a, z, limit):
        flag = []
        self.traversal.append(a.getId())
        if a == z:
            return True
        if limit == 0:
            return False
        for leaf in a.leafs:
            flag.append(self.inner(leaf, z, limit - 1))
            if flag.__contains__(True):
                self.exact.appendleft(leaf.getId())
                return True

    def IDS(self, a, z, limit):
        if limit > 0:
            if self.IDS(a, z, limit-1):
                self.exact.appendleft(a.getId())
                return True
            if self.inner(a, z, limit-1):
                return True
            self.traversal.append("")

    def UCS(self, root, goal):
        opened = {root}
        closed = {}
        costs = {root: 0}
        ancestors = {}
        while opened:
            minimum = 100000
            for x in opened:
                if costs[x] < minimum:
                    minimum = costs[x]
                    i = x
            opened.remove(self.getVertex(i.getId()))
            node = i
            self.traversal.append(node.getId())
            if node == goal:
                while True:
                    self.exact.appendleft(node.getId())
                    if node == root:
                        return True
                    node = ancestors[node]

            for leaf in node.leafs:
                if not (opened.__contains__(self.getVertex(leaf.getId())) or closed.__contains__(self.getVertex(leaf.getId()))):
                    opened.add(self.getVertex(leaf.getId()))
                    costs[self.getVertex(leaf.getId())] = costs[node] + self.getEdgeTime(node, leaf)
                    ancestors[leaf] = node

                elif opened.__contains__(self.getVertex(leaf.getId())):
                    if costs[self.getVertex(leaf.getId())] > costs[node] + self.getEdgeTime(node, leaf):
                        costs[self.getVertex(leaf.getId())] = costs[node] + self.getEdgeTime(node, leaf)
                        ancestors[leaf] = node

                elif closed.__contains__(self.getVertex(leaf.getId())):
                    if costs[self.getVertex(leaf.getId())] > costs[node] + self.getEdgeTime(node, leaf):
                        opened.add(self.getVertex(leaf.getId()))
                        closed.pop(self.getVertex(leaf.getId()))
                        costs[self.getVertex(leaf.getId())] = costs[node] + self.getEdgeTime(node, leaf)
                        ancestors[leaf] = node

            closed[node] = 0
        return False
                           
            
if __name__ == '__main__':

    def initGraphA():
    
        graphA = Graph()

        graphA.addVertex('S')
        graphA.addVertex('A')
        graphA.addVertex('B')
        graphA.addVertex('C')
        graphA.addVertex('D')
        graphA.addVertex('G')

        graphA.connectEdges('S', 'A', 3)
        graphA.connectEdges('S', 'B', 2)
        graphA.connectEdges('A', 'B', 1)
        graphA.connectEdges('A', 'D', 5)
        graphA.connectEdges('B', 'C', 2)
        graphA.connectEdges('B', 'D', 3)
        graphA.connectEdges('C', 'D', 3)
        graphA.connectEdges('C', 'G', 4)
        graphA.connectEdges('D', 'G', 1)

        return graphA

    def initGraphB():
        
        graphB = Graph()

        graphB.addVertex('S')
        graphB.addVertex('A')
        graphB.addVertex('B')
        graphB.addVertex('C')
        graphB.addVertex('D')
        graphB.addVertex('E')
        graphB.addVertex('G')

        graphB.connectEdges('S', 'A', 6)
        graphB.connectEdges('S', 'B', 5)
        graphB.connectEdges('S', 'C', 10)
        graphB.connectEdges('A', 'D', 6)
        graphB.connectEdges('B', 'D', 6)
        graphB.connectEdges('B', 'E', 7)
        graphB.connectEdges('C', 'E', 6)
        graphB.connectEdges('D', 'C', 4)
        graphB.connectEdges('D', 'G', 4)
        graphB.connectEdges('E', 'A', 3)
        graphB.connectEdges('E', 'G', 6)

        return graphB

    print("--- DFS SEARCH ---")
    graphA = initGraphA()
    print("Traversed Path: ", end='')
    graphA.DFS(graphA.getVertex('S'))
    print("\n")
    graphA = None
    graphA = initGraphA()
    print("Exact Path: ", end='')
    graphA.DFS(graphA.getVertex('S'))
    graphA = None
    print("\n")
    
    graphA = initGraphA()
    graphA.BFS(graphA.getVertex('S'), graphA.getVertex('G'))
    graphA = None
    print("\n")
   
    graphA = initGraphA()
    i = len(graphA.vertex_dictionary) - 1
    print(" --- IDS SEARCH --- ")
    graphA.IDS(graphA.getVertex('S'), graphA.getVertex('G'), i)
    print("Traversed Path: ", end='')
    for i in graphA.traversal:
            print(i, end='')
    print("\n")
    print("Exact Path: ", end='')
    for j in graphA.exact:
            print(j, end='')
    graphA = None
    print("\n")

    graphA = initGraphA()
    print(" --- UCS ---- ")
    graphA.UCS(graphA.getVertex('S'), graphA.getVertex('G'))
    print("Traversal Path: ", *list(graphA.traversal))
    print("Exact Path: ", *list(graphA.exact))
    graphA = None
 
