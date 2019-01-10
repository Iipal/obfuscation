# obfuscation

## Installation:

Use [make](https://en.wikipedia.org/wiki/Makefile) for compiling all files.
- **make**: Compile all.
- **make clean**: Delete temporary files.
- **make fclean**: Delete executable `./obf` file & `libft.a` library.
- **make re**: It's rules - **make fclean** & **make** in one.

## Usage:
```bash
./obf [flags] [files]
```
### Flags:
- `-w`: Delete [whitespaces](https://en.wikipedia.org/wiki/Whitespace_character) and [commentary](https://github.com/Iipal/obfuscation/blob/085e45e39ea9dcbf4c4b4fd6cb3bbdc54def867e/includes/obfuscation.h#L45) from files.
- `-o`: Obfuscate all lines in file(concatenate lines to one if result line length less than [this value](https://github.com/Iipal/obfuscation/blob/085e45e39ea9dcbf4c4b4fd6cb3bbdc54def867e/includes/obfuscation.h#L43)).
- `-r`: Rename all [variables](https://github.com/Iipal/obfuscation/blob/085e45e39ea9dcbf4c4b4fd6cb3bbdc54def867e/includes/obfuscation.h#L48-L53) in files using Caesar Cipher with this [value](https://github.com/Iipal/obfuscation/blob/085e45e39ea9dcbf4c4b4fd6cb3bbdc54def867e/includes/obfuscation.h#L46).

##### Note: Minimum arguments for program is 2. Flags in first argument and minimum 1 file for correct work.

#### Examples:

##### Example #1:
```bash
$ ./obf -wro file1.cfg file2.cfg
        file1.cfg:
Source file reading: OK.
Cuting whitespaces: OK.
Encrypting: OK.
Obfuscating: OK.
Saving to file 'obf_file1.cfg': OK.
        file2.cfg:
Source file reading: OK.
Cuting whitespaces: OK.
Encrypting: OK.
Obfuscating: OK.
Saving to file 'obf_file2.cfg': OK.
```
Program will create 2 obfuscated files(`obf_file1.cfg` & `obf_file2.cfg`) where will be deleted whitespaces from all files, renamed all variables and obfuscated lines.
##### Example #2:
```bash
$ ./obf -wr file1.cfg file2.cfg file3.cfg file4.cfg
        file1.cfg:
Source file reading: OK.
Cuting whitespaces: OK.
Encrypting: OK.
Saving to file 'obf_file1.cfg': OK.
        file2.cfg:
Source file reading: OK.
Cuting whitespaces: OK.
Encrypting: OK.
Saving to file 'obf_file2.cfg': OK.
        file3.cfg:
Source file reading: OK.
Cuting whitespaces: OK.
Encrypting: OK.
Saving to file 'obf_file3.cfg': OK.
        file4.cfg:
Source file reading: OK.
Cuting whitespaces: OK.
Encrypting: OK.
Saving to file 'obf_file4.cfg': OK.
```
Program will create 4 obfuscated files(the same files like in example above), but if `obf_file1.cfg` (or the same program outputed files from program) already exist its will re-writed with new data where will be deleted whitespaces and renaming variables in all files.