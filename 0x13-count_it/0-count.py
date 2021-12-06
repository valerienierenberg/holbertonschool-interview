#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list after=None):
    """recursive function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    url = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(subreddit,
                                                                after)
    headers = {'User-Agent': 'Mozilla/5.0'}
    req = requests.get(url, headers=headers, allow_redirects=False)
    if req.status_code != 200:
        return 0
    data = req.json()
    children = data.get('data').get('children')
    for child in children:
        for word in word_list:
            if child.get('data').get('title').lower().find(word) != -1:
                return 1 + count_words(subreddit, word_list,
                                       child.get('data').get('after'))
    return 0
