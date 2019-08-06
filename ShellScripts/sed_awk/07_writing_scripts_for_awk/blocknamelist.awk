# change field separator to newline,
# and record separator to blank line
BEGIN { FS = "\n"; RS = "" }
{ print $1, $NF }
