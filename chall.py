class linked_list:
    def __init__(self):
        self.head = None
        self.size = 0

    @classmethod
    def create_node(cls, value):
        return { "value": value, "next": None }

    def insert(self, value):
        if not self.head or value < self.head.get('value'):
            self.insert_at_begin(value)
            return

        new_node = self.create_node(value)
        current = self.head
        prev = None
        while current and value > current.get("value"):
            prev = current
            current = current["next"]
        if prev: prev["next"] = new_node
        new_node["next"] = current
        current = new_node
        self.size += 1

    def insert_at_begin(self, value):
        node = self.create_node(value)
        node["next"] = self.head
        self.head = node
        self.size += 1

    def display(self):
        current = self.head
        while (current):
            print(current.get("value"))
            current = current["next"]

linked = linked_list()
linked.insert(5)
linked.insert(2)
linked.insert(6)
linked.display()