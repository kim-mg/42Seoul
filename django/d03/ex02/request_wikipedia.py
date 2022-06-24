#!/usr/bin/python3

import requests
import json
import sys
import dewiki

if __name__ == '__main__':
    arg = sys.argv
    URL = 'https://en.wikipedia.org/w/api.php'
    
    # if len(arg) != 2:
    #     print("put search word")
    #     exit(1)
    # else:
    #     search_wiki = URL + arg[1]
    
    
    # search_wiki = URL + arg[1]
    response = requests.get(URL)
    # wiki = dewiki.from_string()
    con = response.iter_content()
    for line in con:
        print(line)
    # j = response.json()
    # print(j)


    # print (response.text)
    # print (wiki)