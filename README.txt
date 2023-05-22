AVL ADT
    -compile executable with g++ main.cpp PrecondViolatedExcept.cpp CPersonInfo.cpp
    - ./a.out > output.txt

CHANGELOG:
    5/22/2023
    -Improving versatility of program. Changed some definitions.

CURRENT BUGS:

    5/22/2023
    -There is a shallow pointer being deleted twice that causes a non-fatal error on Linux devices. 
        "The double free means you have a shallow copy of a pointer somewhere and it is releasing it twice."