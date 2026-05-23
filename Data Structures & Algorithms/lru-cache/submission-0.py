class Node:

    def __init__(self,key:int,value:int):
        self.value=value
        self.prev=None
        self.next=None
        self.key=key

class LRUCache:

    def __init__(self, capacity: int):
        # need a way to get key in (O(1)) time -> hashing
        # need a way to store Least Recenly used Keys and access them in O(1)
        # thinking of using a hashmap and heap
        # heap fails beacsue it can pop in o(1) but i cant restructure
        # doubly linked list can add and remove in o(1) in this case
        self.capacity=capacity
        self.left=Node(0,0)
        self.right=Node(0,0)

        # we need a way to find if key exists and if so return the ndoe that stores it?
        self.cache={}

        self.left.next=self.right
        self.right.prev=self.left

        

    def get(self, key: int) -> int:
        if key in self.cache:
            #update linked list 
            #lets just say the key for the thing returns node itself
            # remove the node 
            node=self.cache[key]
            self.remove(node)
            # add it to the head 
            self.insert(node)
            return self.cache[key].value
        else:
            return -1
    

    def remove(self,node):
        node.prev.next=node.next
        node.next.prev=node.prev
    
    def insert(self,node):
        #find what the lftmost is pointting to 
        prev_node=self.left
        next_node=self.left.next

        prev_node.next=node
        next_node.prev=node

        node.prev=prev_node
        node.next=next_node

        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])

        new_node=Node(key,value)
        self.cache[key]=new_node
        self.insert(new_node)

        if len(self.cache)>self.capacity:
            # need to remove the rightmost node
            tail_node=self.right
            prev_node=tail_node.prev

            # the least recently node we remove 
            self.remove(prev_node)
            del self.cache[prev_node.key]

            


        
