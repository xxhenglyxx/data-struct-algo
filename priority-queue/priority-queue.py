
"""
    Priority Queue implement using Python
"""

class PriorityQueue:

    def __init__ ( self, priority = 0 ):

        self._queue = []
        self._length = 0
        self._priority = priority

    def enqueue ( self, element ):

        self._queue.append ( element )
        self._length += 1

        if self._priority == 1:

            self._queue.reverse ()

        else:

            self._queue.sort ()

        return element

    def dequeue ( self ):

        return self._queue.pop ()

    def peekFront ( self ):

        return self._queue[ 0 ]

pq1 = PriorityQueue ( 1 )

pq1.enqueue ( 5 )
pq1.enqueue ( 3 )
pq1.enqueue ( 11 )

print ( pq1.peekFront () )