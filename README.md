# my_ls

This is the implementation of ls command. For each operand that names a file of a type other than directory, my_ls displays its name as well as any requested, associated information. For each operand that names a file of type directory, my_ls displays the names of files contained within that directory, as well as any requested, associated information.

If no operands are given, the contents of the current directory are displayed. If more than one operand is given, non-directory operands are displayed first; directory and non-directory operands are sorted separately and in lexicographical order.

The following options are available:

- -a Include directory entries whose names begin with a dot (.).

- -l In addition to the name, display the file type, access permissions, number of hard links, owner and group name, size in bytes, and timestamp.

- -R Recursively display the contents of subdirectories.

- -d Display the directories with the same presentation as the files, without listing their contents

- -r Reverse sorting of directory contents.

- -t Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
