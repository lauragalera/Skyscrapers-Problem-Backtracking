# Skyscraper Problem

This program is an adaptation of the skyscraper problem presented by [David Butler](https://twitter.com/DavidKButlerUoA/status/1161523106650959872). The goal is to place buildings of different heights in every box respecting the visibility imposed by the numbers that appear in every row and column. A building may not be visible from a specific direction if there is a taller building infront.

The program reads a text file containing all the information:

```
dimension // matrix dimension nxn
vN1 vN2 ... vNn // north visibility
vS1 vS2 ... vSn // south visibility
vE1 vE2 ... vEn // east visibility
vW1 vW2 ... vWn // west visibility
max(m) // maximum height
a1 a2 ... am // availabile buildings from height 1 to m
```
It uses a backtracking algorithm to find a solution restricting the height of the buildings or the optimal solution that maximizes the sum of heights. This is specified on the parameters passed to the program:

```
-h, --help : displays this message.
-u alt : finds a solution without using buildings of a height taller than alt.
-m : finds the solution that maximizes the sum of heights.
file: file path containing all the information.
```

A few examples of execution:

```
4
1 3 2 3
4 2 2 1
3 2 2 1
1 2 2 3
6
4 4 4 4 1 2

$ ./gratacels -u 3 g4
No hi ha solucio
Temps: 0.000110659 segons

$ ./gratacels -u 4 g4
./gratacels -u 4 g4
1 3 2 3
1 4 1 3 2 3
2 3 2 4 1 2
2 2 4 1 3 2
3 1 3 2 4 1
4 2 2 1
Alçada total: 40
Temps: 0.000276068 segons


$ ./gratacels -m g4
1 3 2 3
1 4 1 3 2 3
2 3 2 5 4 2
2 2 6 1 3 2
3 1 4 2 6 1
4 2 2 1
Al¸cada total: 49
Temps: 0.027886 segons
```

Since it is a NP-complete problem, it only works for small boards. The complexity grows exponentially; O(n^2), being n the board size. It took 355 seconds to find an optimal solution for a 6x6 board. 
