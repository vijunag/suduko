# suduko
Suduko puzzle solver in C

Algorithm
==========
The possible fills are brute forced and backtracked whenever there is a collision or conflict. 

input
========
Input to the program a NULL terminated string with the to-be-filled cells represented as zeros. 

output
========
```A sample output of the program is as below

turchin-vbox10:~]$ ./suduko
Enter serialized suduko puzzle with unfilled cells as zero
Eg: 7000240002323.....
200300000804062003013800200000020390507000621032006000020009140601250809000001002
2 0 0 3 0 0 0 0 0
8 0 4 0 6 2 0 0 3
0 1 3 8 0 0 2 0 0
0 0 0 0 2 0 3 9 0
5 0 7 0 0 0 6 2 1
0 3 2 0 0 6 0 0 0
0 2 0 0 0 9 1 4 0
6 0 1 2 5 0 8 0 9
0 0 0 0 0 1 0 0 2
Printing the solution now...
Solution found for the puzzle....
2 7 6 3 1 4 9 5 8
8 5 4 9 6 2 7 1 3
9 1 3 8 7 5 2 6 4
4 6 8 1 2 7 3 9 5
5 9 7 4 3 8 6 2 1
1 3 2 5 9 6 4 8 7
3 2 5 7 8 9 1 4 6
6 4 1 2 5 3 8 7 9
7 8 9 6 4 1 5 3 2
End of the solution
```
