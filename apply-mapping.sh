
lang=$(basename $1)
lang=${lang#map-*}

sedopt=$(  cat map-$lang | awk "{rest=\$2; for (i=3;i<=NF;i++) {rest = rest \" \" \$i}; printf( \"-e 's@%s@%s@g' \", \$1, rest) }"  )


# remove old one
test -d $lang && rm -rf $lang

# copy git controlled files only
cd abstract
git ls-files . | while read i ; do
    mkdir -p ../$lang/$(dirname $i)
    cp $i ../$lang/$i
done
cd -

# do replacement
find $lang/ -type f | while read i; do
    echo "Processing '$i'"
    eval set -- $sedopt
    sed -i "$@" "$i"
done

# do file renaming
find $lang/ -type f | while read i; do
    eval set -- $sedopt
    ii=$(echo "$i" | sed "$@")
    if test "$i" != "$ii" ; then
        echo "Moving '$i' ==> '$ii'"
        mv "$i" "$ii"
    fi
done


# build and test
export JVMDLL=/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server/libjvm.so
#export CSWINGJAR=../CSwingJava/target/CSwingJava-1.1-SNAPSHOT.jar
unset CSWINGJAR

(cd $lang/CSwingJava/ && mvn install)
(cd $lang/CSwingJava/ && cp target/CSwingJava-*.jar ../cswing/)
(cd $lang/cswing/ && gcc -Wall -I/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ -I/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/linux/ test-cswing.c cswing.c javahelper.c -L/usr/lib/jvm/java-1.7.0-openjdk-amd64/jre/lib/amd64/server -ldl -o ,,test && ./,,test && rm -f ,,test)
