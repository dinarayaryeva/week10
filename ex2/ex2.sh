#!/bin/sh

mkdir week01
touch week01/file.txt
echo "Dinara Yaryeva" >> week01/file.txt
mkdir week10 
link week01/file.txt week10/_ex2.txt

inodenumber=$(ls -i week01/file.txt | cut -d " " -f1)

find -inum $inodenumber

find -inum $inodenumber -exec rm {} \;
