#!/usr/bin/expect
spawn ssh zwang6@pek-lpd-huawei
expect "zwang6@pek-lpd-huawei's password:*"
send "ZhileiWang1!\r"
interact

exit
