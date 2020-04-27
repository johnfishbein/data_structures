import csv

# -------------------------------------------------------------------
class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


# -------------------------------------------------------------------
# -------------------------------------------------------------------
class Junction:
    def __init__(self, label):
        self.label = label
        # references to Junction object reached if we go in that direction
        self.east = None
        self.south = None
        self.west = None
        self.north = None
        # flags to remember if a search has tried a given direction
        self.tried_north = False
        self.tried_east = False
        self.tried_south = False
        self.tried_west = False

    def __str__(self):  # keeping this simple by just printing label
        return "<" + self.label + ">"

    def clear_path_tried_values(self):
        """ When a search is executed, each Junction searched remembers which paths have been tried.
            In case we want to do another search, this function can be called to clear that history. """
        self.tried_north = self.tried_east = self.tried_south = self.tried_west = False

# -------------------------------------------------------------------
# -------------------------------------------------------------------
class Maze:

    def __init__(self):
        # Maze stores a dictionary: each key is a Junction label (a string), and each value is a Junction object
        self.junctions = {}

    # -------------------------------------------------------------------
    def search(self, start_label, goal_label):
        path_stack = Stack()
        start = self.get_junction(start_label)
        goal = self.get_junction(goal_label)
        current = start
        failed = False
        num_steps = 0
        max_steps = 30
        fail_count = 1

        path_stack.push((current, ''))
        while current != goal and not failed:
            num_steps += 1
            if num_steps > max_steps:
                print("*Aborting search after too many steps*")
                return

            if (not current.tried_north) and (current.north is not None) and (current.north != path_stack.peek()[0]):
                current.tried_north = True
                path_stack.push((current, 'north'))
                current = current.north

            elif (not current.tried_east) and (current.east is not None) and (current.east != path_stack.peek()[0]):
                current.tried_east = True
                path_stack.push((current, 'east'))
                current = current.east

            elif (not current.tried_south) and (current.south is not None) and (current.south != path_stack.peek()[0]):
                current.tried_south = True
                path_stack.push((current, 'south'))
                current = current.south

            elif (not current.tried_west) and (current.west is not None) and (current.west != path_stack.peek()[0]):
                current.tried_west = True
                path_stack.push((current, 'west'))
                current = current.west

            else:  # if current == "deadend" or cant go anywhere else
                if current == start:
                    failed = True
                else:
                    current = path_stack.pop()[0]

        if failed:
            print("** Search failed. **")
        else:
            print("** Path found: **")
            path_stack.push((self.get_junction(goal_label), 'Arrived!'))
            path_found = Stack()
            for i in range(path_stack.size()-1):
                path_found.push(path_stack.pop())

            for i in range(path_found.size()):
                loc = path_found.pop()
                print(loc[0], loc[1])

        # In case we run another search on this maze, let's clear history of paths tried in each junction
        for key in self.junctions:
            j = self.get_junction(key)
            j.clear_path_tried_values()

    # -------------------------------------------------------------------
    def get_junction(self, junction_label):
        """ Given a junction-label, returns the Junction object in the maze.
            To simplify some codeing, if the label is None, return None. """
        if junction_label is None:
            return None
        return self.junctions[junction_label]

    # -------------------------------------------------------------------
    def load_file(self, filename):
        """ Reads data from a CSV file. Converts string 'None' from file to object None.
            Builds list from file data and calls our other load function. """
        with open(filename, 'r') as csvfile:
            reader = csv.reader(csvfile)
            junction_list = []
            for row in reader:
                # Use list comprehension to replace string with object for None
                junction_list.append([None if item == 'None' else item for item in row])
            # print("++Debug:", junction_list)
            self.load_from_list(junction_list)

    # -------------------------------------------------------------------
    def load_from_list(self, list_junction_info):
        # First, remove any existing Junction objects
        self.junctions = {}

        # First, need to create Junction objects for each item
        for tup in list_junction_info:
            j = Junction(tup[0])
            self.junctions[tup[0]] = j

        # Each maze has a special DeadEnd Junction object, used for all dead-ends
        j = Junction("DeadEnd")
        self.junctions["DeadEnd"] = j

        # Now that we have all Junctions as objects, we need to set their connections to point
        #   to the other Junction objects
        for tup in list_junction_info:
            j = self.junctions[tup[0]]
            j.north = self.get_junction(tup[1])
            j.east = self.get_junction(tup[2])
            j.south = self.get_junction(tup[3])
            j.west = self.get_junction(tup[4])

        # The following is for debugging, so we can see that the data loaded correctly
        # for k in self.junctions:
        #     j = self.getNode(k)
        #     print(k, j.north, j.east, j.south, j.west)


# -------------------------------------------------------------------
# -------------------------------------------------------------------

if __name__ == "__main__":
    # Here's some demo code that tries out our maze searches

    # Sample maze #1 for demo purposes
    maze1_data = [
        ("S",None,"A",None,None),
        ("A","B","DeadEnd",None,"S"),
        ("B","D","C","A",None),
        ("C","E",None,"B","DeadEnd"),
        ("D","DeadEnd","B","DeadEnd",None),
        ("E",None,"C","DeadEnd","G"),
        ("G",None,"E",None,None)
    ]

    maze = Maze()
    maze.load_from_list(maze1_data)
    # maze.load_file('maze1.txt')  # this line reads same maze in from a CSV file
    maze.search("S", "G")


    # Just like maze #1 but can't get from C to E, so search should fail
    maze2_data = [
        ("S",None,"A",None,None),
        ("A","B","DeadEnd",None,"S"),
        ("B","D","C","A",None),
        ("C",None,None,"B","DeadEnd"),
        ("D","DeadEnd","B","DeadEnd",None),
        ("E",None,"C","DeadEnd","G"),
        ("G",None,"E",None,None)
    ]
    maze2 = Maze()
    maze2.load_from_list(maze2_data)
    print("\n** This search should fail!**")
    maze2.search("S", "G")

    print()

    maze3 = Maze()
    maze3.load_file('maze2.txt')
    maze3.search('A','GG')


    print()

    maze4_data = [
        ("S", 'A', None, None, None),
        ("A", None, None, 'B', "S"),
        ("B", "A", "C", None, None),
        ("C", 'D', "DeadEnd", None, "B"),
        ("D", None, None, "C", 'E'),
        ("E", 'F', "D", None, "DeadEnd"),
        ("F", 'G', None, 'E', "DeadEnd"),
        ("G", 'DeadEnd', None, 'F', "H"),
        ("H", 'I', 'G', None, None),
        ("I", None, 'DeadEnd', 'H', None),
        ("J", None, None, None, "I")
    ]

    maze4 = Maze()
    maze4.load_from_list(maze4_data)
    maze4.search('S','J')


