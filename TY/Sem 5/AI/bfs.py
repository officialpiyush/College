from queue import PriorityQueue

# define a node class to represent each node in the tree
class Node:
  def __init__(self, value):
    self.value = value
    self.children = []

  def __lt__(self, other):
    return self.value < other.value

  def __gt__(self, other):
    return self.value > other.value

# define a function to perform the best-first search traversal
def best_first_search(root, goal):
  # create an empty priority queue
  queue = PriorityQueue()

  # add the root node to the queue
  queue.put(root)

  # loop until the queue is empty
  while not queue.empty():
    # get the next node in the queue
    node = queue.get()

    # check if the node is the goal
    if node.value == goal:
      return True

    # add the node's children to the queue
    for child in node.children:
      queue.put(child)

  # if the goal was not found, return False
  return False

# create some nodes to use in the example
root = Node("A")
node_B = Node("B")
node_C = Node("C")
node_D = Node("D")
node_E = Node("E")

# create a tree with the nodes
root.children = [node_B, node_C, node_D]
node_B.children = [node_E]

# perform a best-first search for the goal node
goal = "E"
result = best_first_search(root, goal)
print(result) # should print True

# perform a best-first search for a non-existent node
goal = "F"
result = best_first_search(root, goal)
print(result) # should print False
