#!/usr/bin/expect
spawn ssh zwang6@pek-lpd-ccm1
expect "zwang6@pek-lpd-ccm1's password:*"
send "33zwang6\r"
interact

exit
