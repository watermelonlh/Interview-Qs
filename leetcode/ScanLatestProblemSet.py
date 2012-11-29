#!/bin/python

import urllib2
import HTMLParser
import re

website = urllib2.urlopen("http://leetcode.com/onlinejudge")
website_html = website.read()
parser = HTMLParser.HTMLParser()
web = parser.unescape(website_html)
print(web)

#print website_html

problems = re.findall("setJudge\([0-9]+, \"([a-zA-Z0-9\(\),\- ]+)\"\)", web)
print(problems)

print("total=", len(problems))
for problem in problems:
    print(problem)

