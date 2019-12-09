# AImazing_assignment

My reference
1.websocket and shell
https://github.com/joewalnes/websocketd
http://www.ruanyifeng.com/blog/2017/05/websocket.html

2.libtins sniff
http://libtins.github.io/tutorial/sniffing/#packet-objects

3.websocket
http://www.ruanyifeng.com/blog/2017/05/websocket.html

4.libtins api:
http://libtins.github.io/docs/latest/


step:
install libbtins
compiler AIamazing_test.cpp
note: -std=c++11 or -std=c++0x and -O3
=>
   g++ AIamazing_test.cpp -o ee -O3  -ltins

download websocked to /usr/bin
=>
websocketd --port=8080 ./count.sh

create a java script
=>test.html

run AIamazing_test app and open test.html, then enter "websocketd --port=8080 ./count.sh"

