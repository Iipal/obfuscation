# obfuscation

## Installation:

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.
- **make**: Compile all.
- **make clean**: Delete temporal files.
- **make fclean**: Delete executable FdF file & libft library.
- **make re**: It's rules - **make fclean** & **make** in one.

## Usage:
```bash
./obfuscation source.cfg dest.cfg
```

######  Notes:
######    Second argument file should not exist, it's will created by program.
######    Deleting comments if only its looks like [this](https://github.com/Iipal/obfuscation/blob/d35d9ec319f06364fdfe496bc8664cde4620d20d/includes/obfuscation.h#L28).
######    Concate in lines which length less than [this](https://github.com/Iipal/obfuscation/blob/d35d9ec319f06364fdfe496bc8664cde4620d20d/includes/obfuscation.h#L26).
