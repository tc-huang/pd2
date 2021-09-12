# 03 File IO
[![hackmd-github-sync-badge](https://hackmd.io/nLQxlK4yQO-m4RiNe99ILw/badge)](https://hackmd.io/nLQxlK4yQO-m4RiNe99ILw)

## Write file
```cpp
#include <fstream>
int main(){
    ofstreamoutFile("OutFileName", ios::out);
    if(!outFile) {
        cerr<< "Failed opening" << endl;
        exit(1);
    }
    outFile << "Some Input DATA";
}
```

- `if(!outFile)`uses the overloaded iosmember function `operator!` to determine whether the openoperation succeeded.

- Some possible errors are
    - attempting to open a nonexistent file for reading
    - attempting to open a file for reading or writing without permission
    - opening a file for writingwhen no disk space is available

- `outFile <<` writes a set of data to the file outfile, using the stream insertion operator `<<` and the outFileobject associated with the file at the beginning of the program.

- The end of `main` function implicitly invokes `outFile`’s destructor, which closes the outfilefile.

- Can close the ofstreamobject explicitly, using member function `close` in the statement.






## Creating a Sequential File
- Two arguments are passed to an **ofstream** object’s constructor—the **filename and the file-open mode**.

- Existing files opened with mode `ios::out` are **truncated**—all data in the file is discarded.

- If the specified file does not yet exist, then the ofstreamobject creates the file, using that filename.310 ofstreamoutFile("outfile", ios::out);

- An ofstreamobject can be created without opening a specific file—a file can be attached to the object later. e.g. `ofstream outFile;outFile.open(“outfile", ios::out);`

| Mode        |Description|
| ----------- | --- |
| ios::app    |Append all output to the end of the file     |
| ios::ate    |Open a file for output and move to the end of the file (normally used to append data to a file). Data can be written anywhere in the file.     |
| ios::in     |Open a file for input.     |
| ios::out    | Open a file for output.    |
| ios::trunc  | Discard the file’s contents (this also is the default action for ios::out).|
| ios::binary | Open a file for binary (i.e., nontext) input or output.|

## `EOF`
- When `EOF` (end-of-file) is encountered or bad data is entered, the `while(cin>>...)` statement terminates.
- Ctrl-Din Unixand Ctrl-Zin Windowsrepresent end-of-file.

## Reading Data from a Sequential File
- Creating an `ifstream` object opens a file for input.

- The `ifstream` constructor can receive the **filename** and the file open mode as **arguments**. e.g. `ifstream inFile("infile", ios::in

- Objects of class `ifstream` are opened for input by default.
    - We could have used the statement
`ifstream inFile("infile");` to open infilefor input.

- Just as with an ofstreamobject, an ifstreamobject can be created without opening a specific file, because a file can be attached to it later.

- When the end of file has been reached, the `ifstream` destructor function closes the file and the program terminates.