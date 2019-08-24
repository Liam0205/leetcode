for i in `seq $(head -1 file.txt | wc -w)`; do
  cut -d' ' -f${i} file.txt | xargs
done
