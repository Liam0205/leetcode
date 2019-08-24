seq $(head -1 file.txt | wc -w) | xargs -I '{}' bash -c "cut -d' ' -f{} file.txt | xargs"
