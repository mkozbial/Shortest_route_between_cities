# Shortest path between cities
This console application was created for the course on algorithms and data structures. Krzysztof Ocetkiewicz is the author of the original instructions. 
##### Map
```
.........GDANSK.....
........*...........
........#...........
........#...........
*##################.
#SZCZECIN.........#.
#.................#.
##................#.
.############*#####.
.#...WARSZAWA.......
.#..................
.#############......
.#...........#......
.#..WROCLAW.##......
.#..*.......*.......
.####.......#KIELCE.
......*##.#########.
.OPOLE..#.*.......#.
........#.KRAKOW..#.
........###########.
```
. - an empty field that is impassable \
\* - city's localization (passable) \
\# - passable path \
any letter - city's impassable name field \
##### Input Form
```
<width and height of the map>
<map>
<number k  representing the number airports>
<k lines in form CITY DESTINATION TIME>
<integer q representing the number of queries>
<q lines in form CITY DESTINATION 0/1> # 0 - show only length of the path, 1 - show path
```

### Example
##### Input
```
20 20
.........GDANSK.....
........*...........
........#...........
........#...........
*##################.
#SZCZECIN.........#.
#.................#.
##................#.
.############*#####.
.#...WARSZAWA.......
.#..................
.#############......
.#...........#......
.#..WROCLAW.##......
.#..*.......*.......
.####.......#KIELCE.
......*##.#########.
.OPOLE..#.*.......#.
........#.KRAKOW..#.
........###########.
0
3
KIELCE KRAKOW 0
KRAKOW GDANSK 0
KRAKOW GDANSK 1
```
### Output
```
5
40
40 KIELCE SZCZECIN
```
Output is one line for one query, in the form NUMBER \<CITIES\>. The number indicates the quickest route between the cities (the number of # or * between the city and destination or 'time' in the case of aeroplanes). The next strings are intermediate cities (apart from the beginning and ending cities) listed in the order they were visited, only if at the end of query 1 occurred.
