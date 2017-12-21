#!/usr/bin/expect
spawn ssh zwang6@pek-lpd-ccm2
expect "zwang6@pek-lpd-ccm2's password:*"
send "33zwang6\r"
interact

exit
