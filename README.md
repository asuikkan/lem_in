# Lem_in

The goal of this project is to make an algorithm that finds the shortest possible way for a number of ants to traverse a map from start to finish. This is measured by the number of lines the program outputs as a solution.

## Rules

### Map

An example of a valid map looks like this:

```
10
##start
00 0 0
01 1 1
##command
02 2 2
03 3 3
04 4 4
##end
05 5 5
00-02
00-01
#comment
02-03
03-05
01-04
01-03
04-05
```

where

- lines starting with a single ‘#’ are comments that are ignored, for example `#comment`
- lines starting with ‘##’ are commands that modify the properties of the next non-command line
    - line `##start` dictates that the next line read is the starting room
    - line `##end` dictates that the next line read is the end room
    - unknown commands are ignored
- the first line indicates the number of ants
- lines formatted similarly to `04 4 4` are rooms, where
    - the first field is the name of the room: `04`
    - the second field is the X coordinate: `4`
    - the third field is the Y coordinate: `4`
- lines formatted similarly to `02-03` are links between rooms: room `02` is linked to room `03`

### Solution

The program displays the map and the ants’ movements as output. The movements are formatted as follows:

```
L1-01 L2-02
L1-04 L3-01 L2-03 L4-02
L1-05 L3-04 L5-01 L2-05 L4-03 L6-02
L3-05 L5-04 L7-01 L4-05 L6-03 L8-02
L5-05 L7-04 L9-01 L6-05 L8-03 L10-02
L7-05 L9-04 L8-05 L10-03
L9-05 L10-05
```

One field of the output, `L1-01` 

- always starts with an ‘L’
- followed by the ant’s number
- followed by a dash ‘-’
- followed by the name of the room the ant moved to

The rules of the output are:

- each ant can only move once in one line, i.e. turn
- an ant can only move to a room which is empty (there are no other ants in that room)
    - as exceptions, start and end rooms have unlimited capacity
- all ants have to be in the end room at the end of the output

## How to run

Create the executable with

```bash
make
```

Run the program with a map as input

```bash
./lem-in [OPTIONS] < [path_to_map_file]
```

### Generator

There is a map generator in `maps/` . The generator’s commands can be checked with

```bash
./generator --help
```

### Script

The script `run.sh` located in the `maps/` directory will run the program N number of times with maps created by the generator with its big-superposition command. The script should be moved to the repository’s root directory before running it. Example

```bash
./run.sh 20
```

will run the program with 20 big-superposition maps.

<aside>
💡 The script is made by GitHub user reviisori, all credit go to them

</aside>

## Known issues

The program will not find the absolute optimal solution for every single map. There are cases where the generator generates a big-superposition map that the program solves with an output of one to two lines over the optimal amount. Moreover, it is certain that a map can be created manually which the program will solve with multiple lines over the optimal amount. The program will, however, find a solution with every valid map.
