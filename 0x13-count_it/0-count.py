#!/usr/bin/python3
""" recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords """
from collections import OrderedDict
import json
import requests


def count_words(subreddit, word_list, word_dict={}, count=0, after=None):
    word_dict = OrderedDict(word_dict)
    headers = {'User-agent': 'pytho'}
    parameter = {'limit': 100, 'after': after}
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    response = requests.get(url, headers=headers, params=parameter,
                            allow_redirects=False)

    if response.status_code != 200:
        return None

    data = response.json()
    rspn = data.get('data')
    child = rspn.get('children')
    after = rspn.get('after')

    for titles in child:
        postTitle = (titles.get('data')['title']).lower()
        for post in postTitle.split():
            for word in word_list:
                word = word.lower()
                if post == word:
                    if word in word_dict.keys():
                        word_dict[word] += 1
                    else:
                        word_dict[word] = 1
    if after is not None:
        return count_words(subreddit, word_list, word_dict, count, after)
    else:
        for i in sorted(word_dict, key=word_dict.get, reverse=True):
            print('{}: {}'.format(i, word_dict[i]))
