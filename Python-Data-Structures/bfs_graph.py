#Graph Breadth first search
from stack_queue import Queue


class Vertex:
    def __init__(self,key):
        self.id = key
        self.connectedTo = {}

    def addNeighbor(self, nbr, weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id) + ' connectedTo: ' + str([x.id for x in self.connectedTo])

    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self,nbr):
        return self.connectedTo[nbr]

    def degree(self):
        return len(self.connectedTo)


class Graph:
    def __init__(self):
        self.vertList = {}
        self.numVertices = 0

    def addVertex(self, key):
        self.numVertices = self.numVertices + 1
        newVertex = Vertex(key)
        self.vertList[key] = newVertex
        return newVertex

    def getVertex(self, n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None

    def __contains__(self,n):
        return n in self.vertList

    def addEdge(self, f, t, cost=0):
        if f not in self.vertList:
            nv = self.addVertex(f)
        if t not in self.vertList:
            nv = self.addVertex(t)
        self.vertList[f].addNeighbor(self.vertList[t], cost)
        self.vertList[t].addNeighbor(self.vertList[f], cost)

    def getVertices(self):
        return self.vertList.keys()

    def __iter__(self):
        return iter(self.vertList.values())


def bfs(g, start):
    dist = {}
    pred = {}
    dist[start.getId()] = 0
    pred[start.getId()] = None
    vertQueue = Queue()
    vertQueue.enqueue(start)
    while (vertQueue.size() > 0):
        currentVert = vertQueue.dequeue()
        # print("BFS: beginning processing", currentVert.getId())
        for nbr in currentVert.getConnections():
            if nbr.getId() not in dist:
                dist[nbr.getId()] = dist[currentVert.getId()] + 1
                pred[nbr.getId()] = currentVert.getId()
                vertQueue.enqueue(nbr)
        # print("BFS: done processing", currentVert.getId())
    return (dist, pred)


def find_bfs_path(g, start, goal):
    dist = {}
    pred = {}
    dist[start.getId()] = 0
    pred[start.getId()] = None
    vertQueue = Queue()
    vertQueue.enqueue(start)
    found = start.getId() == goal.getId()
    while (not found and vertQueue.size() > 0):
        currentVert = vertQueue.dequeue()
        # print("BFS: beginning processing", currentVert.getId())
        for nbr in currentVert.getConnections():
            if nbr.getId() not in dist:
                dist[nbr.getId()] = dist[currentVert.getId()]  + 1
                pred[nbr.getId()] = currentVert.getId()
                vertQueue.enqueue(nbr)
                if nbr.getId() == goal.getId():
                    found = True
                    break
        # print("BFS: done processing", currentVert.getId())
    if not found:
        return []
    # find path from start to goal
    path = [goal.getId()]
    current_id = pred[goal.getId()]
    while not current_id is None:
        path.insert(0, current_id)
        current_id = pred[current_id]
    return path


if __name__ == "__main__":
    g = Graph()

    with open("us_states_adj.txt", 'r') as f:
        for line in f:
            edge_info = line.strip().split()
            from_vertex = edge_info[0]
            to = edge_info[1]
            # print(from_vertex, to)
            g.addEdge(from_vertex, to)

    print("\n** Print out adjacency lists")
    max = 0
    for v in g.vertList:
        print(g.vertList[v])
        num_nbrs = len(g.vertList[v].getConnections())
        if num_nbrs > max:
            max = num_nbrs
            max_st = [ v ]
        elif num_nbrs == max:
            max_st.append( v )
    print(max, max_st)


    print("\n** Demo of calling bfs()")
    (dist_from_start, parents) = bfs(g, g.getVertex('VA'))
    print("distances from start node:", dist_from_start)
    print("parents in BFS tree:", parents)

    print("\n** Demo of finding bfs paths")
    for v in ["FL", "CO", "CA"]:
        path = find_bfs_path(g, g.getVertex('VA'), g.getVertex(v))
        print("From VA to", v, path)