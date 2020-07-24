class Stack():
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)
        print(f'{item} pushed to stack')

    def pop(self,item):
        self.items.pop()
        print(f'{item} popped from stack')

    def is_empty(self):
        return self.items == []

    def peek(self):
        if not self.is_empty():
            return self.items[-1]

    def get_stack(self):
        return self.items

def main():
    s = Stack()
    s.push(10)
    s.push(20)
    s.push(30)
    #print(s.get_stack())
    s.pop(30)
    #print(s.get_stack())

if __name__ == "__main__":
    main()