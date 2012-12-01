#!/bin/python

import urllib2
import HTMLParser
import htmllib
import re
import os
import sys

class bcolors:
    ROSE = '\033[95m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    PINK = '\033[91m'
    ENDC = '\033[0m'

    @staticmethod
    def printmsg(msg, color):
        print color + msg + bcolors.ENDC


problems = []
if len(sys.argv) > 1 and sys.argv[1] == '-fresh':
    website = urllib2.urlopen("http://www.leetcode.com/onlinejudge")
    website_html = website.read()
    web = website_html.decode("utf-8")
    parser = HTMLParser.HTMLParser()
    web = parser.unescape(web)
    problems = re.findall("setJudge\([0-9]+, \"([a-zA-Z0-9\(\),\'\- ]+)\"\)", web)

    latestProblemFile = open("Latest Problem Set.txt", "w+")
    for problem in problems:
        latestProblemFile.write(problem + os.linesep)
    latestProblemFile.close()

else:
    latestProblemFile = open("Latest Problem Set.txt", "r")
    problems = latestProblemFile.read().splitlines()
    latestProblemFile.close()

bcolors.printmsg("Problem Amount = " + str(len(problems)), bcolors.PINK)
for problem in problems:
#    print(problem)
    filename = problem.replace(' ', '.') + ".cpp"
    if not os.path.exists(filename):
        bcolors.printmsg(problem, bcolors.BLUE)



