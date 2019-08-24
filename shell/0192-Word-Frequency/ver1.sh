sed 's/\s\+$//g' words.txt | sed 's/^\s\+//g' | sed 's/\s\+/\n/g' | \
  sort | uniq -c | awk '{print $2" "$1}' | sort -k2 -nr
