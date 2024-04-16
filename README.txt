ex1 - shapes calculator
=====================================
* Yehu Raccah - 315346726

* A shapes calculator, able to create, draw, stack, duplicate, enlarge and reduce
  shapes of types - squares, triangles, rectangles.

* Files -- Controller - handles user input and calling the appropriate command
           Shape - abstract base class for all types of shapes
           Triangle - class that creates and draws triangles
           Square - class that creates and draws squares
           Rectangle - class that creates and draws rectangles
           StackedShape - a class that holds multiple shapes stacked on each other
           DupedShape - a class that hold a duplicated shape and its amount
           Commands - holds data for command types(used maps as an exercise)

* Data structures  -- Shapes vector - holds shared_ptr to different types of shapes, our access to
                      every shape created.
                      appears both in Controller and StackedShape, since StackedShape
                      is essentially just many shapes in a vector.

* Algorithms - 

* Design - abstract base class Shape of which all types of shapes are derived from
           DupedShape and StackedShape both hold object of the type shape.
           
           Controller - handles all the user interface and main loop.

* Bugs - 
* Other - 
  
