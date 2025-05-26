# so_long

A simple 2D game where you need to collect all items and reach the exit.

## Requirements

- MiniLibX library
- GCC compiler
- Make

## Building

```bash
make
```

## Running

```bash
./so_long maps/map.ber
```

## Controls

- W: Move up
- A: Move left
- S: Move down
- D: Move right
- ESC: Quit game

## Map Format

Maps must be rectangular and use these characters:
- `0`: Empty space
- `1`: Wall
- `C`: Collectible
- `E`: Exit
- `P`: Player starting position

Example map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
