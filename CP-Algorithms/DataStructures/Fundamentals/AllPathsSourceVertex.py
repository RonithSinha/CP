# Python program to print all paths from a source to destination.

from collections import defaultdict

# This class represents a directed graph
# using adjacency list representation
class Graph:

	def __init__(self, vertices):
		# No. of vertices
		self.V = vertices
		
		# default dictionary to store graph
		self.graph = defaultdict(list)

	# function to add an edge to graph
	def addEdge(self, u, v):
		self.graph[u].append(v)

	'''A recursive function to print all paths from 'u' to 'd'.
	visited[] keeps track of vertices in current path.
	path[] stores actual vertices and path_index is current
	index in path[]'''
	def printAllPathsUtil(self, u, d, visited, path,removed):

		# Mark the current node as visited and store in path
		visited[u]= True
		path.append(u)

		# If current vertex is same as destination, then print
		# current path[]
		if u == d:
			#print (path)
			toRemove=len(path)-2
			if path[toRemove] not in removed:
				removed[path[toRemove]]=True
				print("Vertex to be removed: ",path[toRemove])
				print("Removed vertices: ",removed)
			else:
				print("Vertex already removed: ",path[toRemove])
            
		else:
			# If current vertex is not destination
			# Recur for all the vertices adjacent to this vertex
			for i in self.graph[u]:
				if visited[i]== False:
					self.printAllPathsUtil(i, d, visited, path,removed)
					
		# Remove current vertex from path[] and mark it as unvisited
		path.pop()
		visited[u]= False


	# Prints all paths from 's' to 'd'
	def printAllPaths(self, s, d):

		# Mark all the vertices as not visited
		visited =[False]*(self.V)

		# Create an array to store paths
		path = []

		# Call the recursive helper function to print all paths
		removed={}
		self.printAllPathsUtil(s, d, visited, path,removed)
		print(removed,len(removed))

vertices=int(input())
graph=Graph(vertices)
vertexDict={}
for i in range(vertices):
    v=int(input())
    vertexDict[v]=i
edges=int(input())
for i in range(edges):
    x = list(map(int, input().split()))
    print(x)
    print(vertexDict[x[0]],vertexDict[x[1]])
    graph.addEdge(vertexDict[x[0]],vertexDict[x[1]])
startVertex=int(input())
endVertex=int(input())
graph.printAllPaths(vertexDict[startVertex],vertexDict[endVertex])
'''
4
2
5
7
9
4
2 9
7 2
7 9
9 5
7
9


graph.addEdge(0, 1, 4)
graph.addEdge(0, 7, 8)
graph.addEdge(1, 2, 8)
graph.addEdge(1, 7, 11)
graph.addEdge(2, 3, 7)
graph.addEdge(2, 8, 2)
graph.addEdge(2, 5, 4)
graph.addEdge(3, 4, 9)
graph.addEdge(3, 5, 14)
graph.addEdge(4, 5, 10)
graph.addEdge(5, 6, 2)
graph.addEdge(6, 7, 1)
graph.addEdge(6, 8, 6)
graph.addEdge(7, 8, 7)


10
0
1
2
3
4
5
6
7
8
9
15
0 1
0 7
1 2
1 7
2 3
2 8
2 5
3 4
3 5
4 5
5 6
6 7
6 8
7 8
9 7
0
7
'''