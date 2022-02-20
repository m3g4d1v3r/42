#!/bin/sh
cat /etc/passwd | grep -v "#" | awk 'NR % 2 == 0' | cut -d : -f1 | rev | tail -n +$FT_LINE1 | head -n $(($FT_LINE2 - $FT_LINE1 + 1)) | tr -s '\n' ',' | sed -E 's/,/, /g' | sed -E 's/, $/\./g'
