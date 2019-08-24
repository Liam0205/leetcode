tr -s ' ' '\n' words.txt | sort | uniq -c | awk '{print $2" "$1}' | sort -k2 -nr
