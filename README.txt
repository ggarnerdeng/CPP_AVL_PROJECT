AVL ADT
    -compile executable with g++ main.cpp PrecondViolatedExcept.cpp CPersonInfo.cpp
    - ./a.out > output.txt

CHANGELOG:
    5/22/2023
    -Improving versatility of program. Changed some definitions. Works for CPokemonInfo lists as well now. 
    -Mechanic for comparison and organization are the > or < operators in the data-item implementation file.  

TODO:
    -allow arguments? 
    -menu function 
    -some implementation of bit manipulation to save memory. 

CURRENT BUGS:

    5/22/2023
    -There is a shallow pointer being deleted twice that causes a non-fatal error on Linux devices. 
        "The double free means you have a shallow copy of a pointer somewhere and it is releasing it twice."

NOTES:
Here are specific examples of real-life applications where different tree traversal methods (inorder, preorder, postorder, level order) are used:

Inorder Traversal:

    Expression Evaluation: In compilers and interpreters, inorder traversal is used to evaluate arithmetic or logical expressions. It helps in properly sequencing the operands and operators according to their precedence and associativity rules.

    Binary Search Tree (BST): Inorder traversal allows you to visit the nodes of a BST in ascending order. This property is used in applications where you need to retrieve data in sorted order, such as retrieving a sorted list of items from a database.

Preorder Traversal:

    File Systems: Preorder traversal is used to list files and directories in a file system. It starts at the root directory and visits the directories and files in the order they appear in the file system hierarchy.

    Binary Expression Trees: Preorder traversal can be used to convert an arithmetic expression into a prefix notation (also known as Polish notation) or to create a prefix expression tree.

Postorder Traversal:

    Mathematical Expression Trees: Postorder traversal is commonly used to convert an arithmetic expression into a postfix notation (also known as Reverse Polish notation) or to create a postfix expression tree. This notation is used in calculators and stack-based algorithms for evaluating expressions.

    Memory Management: In some garbage collection algorithms, postorder traversal is used to identify and deallocate unreachable objects by visiting objects in a specific order.

Level Order Traversal:

    Breadth-First Search (BFS): Level order traversal is essential in BFS algorithms used for traversing or searching in graphs or trees. BFS explores the nodes or vertices in a breadth-first manner, visiting all nodes at the same level before moving to the next level.

    Print or Display Hierarchical Structures: Level order traversal is often used to print or display hierarchical structures like organization charts, family trees, or directory structures. It allows you to visualize the levels of the hierarchy from top to bottom.

These examples highlight how different traversal methods are applied in various real-life scenarios, showcasing their specific uses and benefits in different contexts.