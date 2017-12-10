
from modules.linked_list import LinkedList

link_list = LinkedList ()

link_list.add ( 5 )
link_list.add ( "Hello" )
link_list.add ( 3.8 )
link_list.add ( 2, 1 )

print ( link_list.remove ( 5 ) )
print ( link_list.find( 2 ) )
print ( link_list.find ( 3.8 ) )
print ( link_list.find ( "Hello" ) )