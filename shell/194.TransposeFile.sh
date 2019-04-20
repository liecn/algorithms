# Read from the file file.txt and print its transposed content to stdout.
awk '
{
    # NF:the number of field for each row, 
    # NR: the number of record(For row due to the default \n as separator)
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' file.txt
