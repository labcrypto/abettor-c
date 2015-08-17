for f in `find $PWD/lib`; do sudo rm -rfv /usr/local/lib/`basename $f`; sudo ln -vs $f /usr/local/lib/`basename $f`; done
