#!/bin/bash
# REV02: Thu Feb  6 23:24:38 WIB 2020
# REV01: Thu Feb  6 21:08:03 WIB 2020
# START: Thu Feb  6 11:56:35 WIB 2020
# 
# Copyright (C) 2020 Rahmat M. Samik-Ibrahim
# http://RahmatM.Samik-Ibrahim.vLSM.org/
# This is a free script/software.

# INFO: This will generate file 000-READ-THIS-FIRST.txt

FILE="000-READ-THIS-FIRST.txt"
FALLOC=16
PREFIX="^# INFO: "

function INFO() {
   [ -e $1 ] && {
      RESULT=`grep "$PREFIX" "$1" | cut -c9-`
      [ -z "$RESULT" ] || printf "[%${FALLOC}s] %s\n" "$1" "$RESULT"
   }
}

[ -z "$1" ]               || { INFO $1 ; exit 0; }
[ -f .zzw-memo.txt ]      && cat .zzw-memo.txt       > $FILE
for II in `ls` ; do [ -f $II ] && INFO $II          >> $FILE ; done
[ -f .zzx-thanks.txt ]    && cat .zzx-thanks.txt    >> $FILE
[ -f .zzy-copyright.txt ] && cat .zzy-copyright.txt >> $FILE

exit 0

