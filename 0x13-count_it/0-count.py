#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a list containing the titles of all hot articles for a given
subreddit. If no results are found for the given subreddit, the
function should return None."""
import json
import requests
from sys import argv


def count_words(subreddit, word_list):
    """returns the number of times a word is used in a subreddit"""
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'My User Agent 1.0'}
    params = {'limit': 100}
    response = requests.get(url, headers=headers, params=params)
    if response.status_code != 200:
        return None
    data = response.json()
    children = data.get('data').get('children')
    for child in children:
        title = child.get('data').get('title')
        words = title.split()
        for word in words:
            if word.lower() in word_list:
                word_list[word.lower()] += 1
    after = data.get('data').get('after')
    if after is not None:
        params['after'] = after
        count_words(subreddit, word_list)
