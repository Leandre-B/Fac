
for f in $(ls); do
    g=$( file -i $f | grep 'charset=iso-8859-1')
    if [[ ${#g} -gt 0 ]];then
        iconv -f latin1 -t utf8 -o "utf8_"$f $f
    fi
done
