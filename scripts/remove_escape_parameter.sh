#!/bin/sh
set -eu

find -type f | while read file
do
  mv "$file" "$file.bak"
  remove_escape < "$file.bak" > "$file" &
done
