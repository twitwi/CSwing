


## Looking for things to replace

    cd abstract
    grep -r A___ | sed 's@A___@\nA___@g'|grep '^A___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort |uniq
    grep -r a___ | sed 's@a___@\na___@g'|grep '^a___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort |uniq

    grep -r A___ | sed 's@A___@\nA___@g'|grep '^A___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort -r |uniq >  ,,list
    grep -r a___ | sed 's@a___@\na___@g'|grep '^a___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort -r |uniq >> ,,list

    for i in $(cat ,,list ) ; do echo " ============ "$i; cat map-fr-fr |grep $i;done
    for i in $(cat ,,list ) ; do cat map-fr-fr |grep -q $i || echo $i;done | sort -r
