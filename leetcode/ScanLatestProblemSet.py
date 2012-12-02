#!/bin/python

import urllib2
import HTMLParser
import htmllib
import re
import os
import sys
import datetime

class bcolors:
    ROSE = '\033[95m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    PINK = '\033[91m'
    GREY = '\033[90m'
    LIGHTBLUE = '\033[96m'
    WHITE = '\033[97m'
    ENDC = '\033[0m'

    @staticmethod
    def printmsg(msg, color):
        print color + msg + bcolors.ENDC


updateDate = datetime.datetime.now()
problems = []
if len(sys.argv) > 1 and sys.argv[1] == '-fresh':
    website = urllib2.urlopen("http://www.leetcode.com/onlinejudge")
    website_html = website.read()
    web = website_html.decode("utf-8")
    parser = HTMLParser.HTMLParser()
    web = parser.unescape(web)
    problems = re.findall("setJudge\([0-9]+, \"([a-zA-Z0-9\(\),\'\- ]+)\"\)", web)

    latestProblemFile = open("Latest Problem Set.txt", "w+")
    latestProblemFile.write(updateDate.strftime("%Y-%m-%d %H:%M:%S") + os.linesep)
    for problem in problems:
        latestProblemFile.write(problem + os.linesep)
    latestProblemFile.close()

else:
    latestProblemFile = open("Latest Problem Set.txt", "r")
    updateDateStr = latestProblemFile.readline()
    updateDate = datetime.datetime.strptime(updateDateStr[:-1], "%Y-%m-%d %H:%M:%S")
    problems = latestProblemFile.read().splitlines()
    latestProblemFile.close()

bcolors.printmsg("Problem Amount = " + str(len(problems)), bcolors.BLUE)
bcolors.printmsg("Updated on " + updateDate.strftime("%Y-%m-%d %H:%M:%S"), bcolors.BLUE)
count = 0
for problem in problems:
#    print(problem)
    filename = problem.replace(' ', '.') + ".cpp"
    if not os.path.exists(filename):
        count = count + 1

solvedProblems = []
for files in os.listdir("."):
    if files.endswith(".cpp"):
        solvedProblems.append(files)

bcolors.printmsg(str(count) + " problems not solved ", bcolors.GREEN)
for problem in problems:
    filename = problem.replace(' ', '.') + ".cpp"
    if not os.path.exists(filename):
        bcolors.printmsg("\t" + problem, bcolors.LIGHTBLUE)
    else:
        solvedProblems.remove(filename)


bcolors.printmsg(str(len(solvedProblems)) + " problems might changed", bcolors.GREEN)
for problem in solvedProblems:
    bcolors.printmsg("\t" + problem, bcolors.YELLOW)

