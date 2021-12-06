#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list):
    """count_words function"""
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'My User Agent 1.0'}
    response = requests.get(url, headers=headers)
    if response.status_code == 404:
        return 0
    data = response.json()
    children = data.get('data').get('children')
    for child in children:
        title = child.get('data').get('title')
        for word in word_list:
            if word in title:
                return 1 + count_words(subreddit, word_list)
    return 0
