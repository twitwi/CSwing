


## Looking for things to replace

    cd abstract
    grep -r A___ | sed 's@A___@\nA___@g'|grep '^A___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort |uniq
    grep -r a___ | sed 's@a___@\na___@g'|grep '^a___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort |uniq

    grep -r A___ | sed 's@A___@\nA___@g'|grep '^A___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort -r |uniq >  ,,list
    grep -r a___ | sed 's@a___@\na___@g'|grep '^a___'| sed 's@[^a-zA-Z0-9_].*@@g'|sort -r |uniq >> ,,list

