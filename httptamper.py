import requests

verbs = ["GET", "PUT", "HEAD", "OPTIONS", "POST", "TRACE", "DELETE", "CONNECT"]
#url = "http://challenge01.root-me.org/realiste/ch3/admin/"
#url = "http://challenge01.root-me.org/realiste/ch7/hackers.php?page=exploits"
url = "http://challenge01.root-me.org/realiste/ch7/log/log.php"

for verb in verbs:
    print "-----------------------"
    print "Testing for " + verb
    resp = requests.request(verb, url=url)
    print resp
    print resp.content
    print "-----------------------"



