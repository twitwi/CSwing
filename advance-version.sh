#!/bin/bash

ver=$(cat ./abstract/CSwingJava/pom.xml | grep SNAPSHOT | head -1 | sed 's@.*>\(.*\)-SNAPSHOT.*@\1@g')

vver=${ver/[.]/\\.}

echo "Found version $ver ($vver)"
echo "Which version comes next?"
read repl

for i in $(git ls-files) ; do
    echo Work on $i
    sed -i 's@'$vver'-@'$repl'-@g' $i
done
