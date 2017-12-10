
class ListNode:

    def __init__ ( self, data = None, prev_node = None, next_node = None ):

        self._prev = prev_node
        self._data = data
        self._next = next_node

    def getNext ( self ):

        return self._next

    def getPrevious ( self ):

        return self._prev

    def getData ( self ):

        return self._data

    def setNext ( self, node ):

        self._next = node

    def setPrevious ( self, node ):

        self._prev = node

class LinkedList:

    def __init__ ( self, data = None ):

        self._root = data
        self._size = 0

    def add ( self, data, index = -1 ):

        if index == -1 :
            
            new_node = ListNode ( data, None, self._root )

            if self._root:

                self._root.setPrevious ( new_node )

            self._root = new_node

        if ( index != -1 or index != 0 ) and index <= self._size :

            temp = self._root
            loop_index = 0

            while index >= loop_index :

                if index == loop_index :
                    
                    temp2 = temp.getPrevious ()

                    new_node = ListNode ( data, temp2, temp )
                    
                    temp.setPrevious ( new_node )
                    
                    temp2.setNext ( new_node )

                    break

                temp = temp.getNext ()
                loop_index += 1

        elif index != -1 :

            print ( "Index out of bounds bro/sis !!!" )
            return
        
        self._size += 1
            
    def getSize ( self ):

        return self._size

    def find ( self, data ):

        index = 0

        current_node = self._root

        while current_node:

            if current_node.getData () == data:

                return index

            current_node = current_node.getNext ()
            index += 1

        return -1

    def remove ( self, data, index = -1 ):

        if self._root == False:

            return -1

        temp_node = self._root
        prev_node = None

        while temp_node :

            if temp_node.getData () == data :

                prev_node.setNext ( temp_node.getNext () )

                if temp_node.getNext () :

                    temp_node.getNext ().setPrevious ( prev_node )

                self._size -= 1

                return 1

            index += 1
            prev_node = temp_node
            temp_node = temp_node.getNext ()

        return -1