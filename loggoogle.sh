#!/usr/bin/expect
spawn ssh -D 7095 -qTfnN zwang6@ala-lpggp4.wrs.com
expect "zwang6@ala-lpggp4.wrs.com's password:*"
send "33zwang6\r"
expect eof

exit
