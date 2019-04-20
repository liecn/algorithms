# Read from the file file.txt and output all valid phone numbers to stdout.
# awk 行处理文本+正则匹配
awk '/^(([0-9]{3}-)|(\([0-9]{3}\) ))[0-9]{3}-[0-9]{4}$/' file.txt

