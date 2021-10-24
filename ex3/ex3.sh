#!/bin/sh

touch _ex3.txt
echo "Dinara Yaryeva" >> _ex3.txt
chmod ugo-x _ex3.txt -v
chmod uo+rwx _ex3.txt -v
chmod  g=u _ex3.txt -v
chmod 660 _ex3.txt -v #only read-write for user and group
chmod 775 _ex3.txt -v #full access for all, except write for others
chmod 777 _ex3.txt -v #full access for all
